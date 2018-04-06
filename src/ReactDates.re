/* Have to call initialize in order this to work
 * https://github.com/airbnb/react-dates#initialize */
let _ = Initialize.initialize;

open MomentRe;

type day;

module FocusedInput = {
  type t =
    | StartDate
    | EndDate
    | Null;
  let toJS = v =>
    switch (v) {
    | StartDate => "startDate" |> Js.Nullable.return
    | EndDate => "endDate" |> Js.Nullable.return
    | Null => Js.Nullable.null
    };
  let fromJS = v =>
    switch (Js.Nullable.toOption(v)) {
    | Some("startDate") => StartDate
    | Some("endDate") => EndDate
    | Some(_)
    | None => Null
    };
};

type datesObj = {
  .
  "startDate": Moment.t,
  "endDate": Moment.t,
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