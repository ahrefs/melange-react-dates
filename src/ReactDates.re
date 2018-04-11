open MomentRe;

/* Have to call initialize in order this to work
 * https://github.com/airbnb/react-dates#initialize */
let _ = Initialize.initialize;

/* Utils */
let wrapOptCbToReturnBoolean = optCallback =>
  Js.Option.map(
    (. func) => {
      let res = v => v |> func |> Js.Boolean.to_js_boolean;
      res;
    },
    optCallback,
  );

let fromOpt = Js.Nullable.fromOption;

let toOpt = Js.Nullable.toOption;

let optMap = Js.Nullable.toOption;

let optBoolToOptBoolean = v =>
  Js.Option.map((. b) => Js.Boolean.to_js_boolean(b), v);

/* core types */
type day;

[@bs.deriving jsConverter]
type focusedInput = [ | `startDate | `endDate];

let nullableFocusedInputToJs = v =>
  v
  |> Js.toOption
  |> Js.Option.map((. b) => focusedInputFromJs(b))
  |> Belt.Option.flatMap(_, x => x);

module Dates = {
  type t = {
    startDate: option(Moment.t),
    endDate: option(Moment.t),
  };
  type tJs = {
    .
    "startDate": Js.nullable(Moment.t),
    "endDate": Js.nullable(Moment.t),
  };
  let toJs: t => tJs =
    v => {
      "startDate": v.startDate |> fromOpt,
      "endDate": v.endDate |> fromOpt,
    };
  let fromJs: tJs => t =
    v => {startDate: v##startDate |> toOpt, endDate: v##endDate |> toOpt};
};

module StrOrNode = {
  type t;
  type arg =
    | Str(string)
    | Node(ReasonReact.reactElement);
  external fromStr : string => t = "%identity";
  external fromNode : ReasonReact.reactElement => t = "%identity";
  let encode = v =>
    switch (v) {
    | Str(v) => fromStr(v)
    | Node(v) => fromNode(v)
    };
  let encodeOpt = v => Js.Option.map((. b) => encode(b), v);
};

module DisplayFormat = {
  type t;
  type formatFunc = unit => string;
  type arg =
    | Str(string)
    | Func(formatFunc);
  external fromStr : string => t = "%identity";
  external fromFunc : formatFunc => t = "%identity";
  let encode = v =>
    switch (v) {
    | Str(v) => fromStr(v)
    | Func(v) => fromFunc(v)
    };
  let encodeOpt = v => Js.Option.map((. b) => encode(b), v);
};