/* Have to call initialize in order this to work
 * https://github.com/airbnb/react-dates#initialize */
let _ = Initialize.initialize;

open MomentRe;

type day;

[@bs.deriving jsConverter]
type focusedInput = [ | `startDate | `endDate];

let nullableFocusedInputToJs = v =>
  v
  |> Js.toOption
  |> Js.Option.map((. b) => focusedInputFromJs(b))
  |> Belt.Option.flatMap(_, x => x);

type datesObj = {
  .
  "startDate": Js.nullable(Moment.t),
  "endDate": Js.nullable(Moment.t),
};

let fromOpt = Js.Nullable.fromOption;

let optBoolToOptBoolean = v =>
  Js.Option.map((. b) => Js.Boolean.to_js_boolean(b), v);

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