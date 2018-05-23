/* Have to call initialize in order this to work
 * https://github.com/airbnb/react-dates#initialize */
let _ = BsReactDates__Initialize.initialize;

open MomentRe;

/* Utils */
let fromOpt = Js.Nullable.fromOption;

let toOpt = Js.Nullable.toOption;

let optMap = Js.Nullable.toOption;

[@bs.deriving jsConverter]
type focusedInput = [ | `startDate | `endDate];

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
    v => {"startDate": fromOpt(v.startDate), "endDate": fromOpt(v.endDate)};
  let fromJs: tJs => t =
    v => {startDate: toOpt(v##startDate), endDate: toOpt(v##endDate)};
};

module StrOrNode = {
  type t;
  type arg =
    | Str(string)
    | Node(ReasonReact.reactElement);
  let encode: arg => t =
    fun
    | Str(v) => Obj.magic(v)
    | Node(v) => Obj.magic(v);
  let encodeOpt = Belt.Option.map(_, encode);
};

module DisplayFormat = {
  type t;
  type formatFunc = unit => string;
  type arg =
    | Str(string)
    | Func(formatFunc);
  let encode: arg => t =
    fun
    | Str(v) => Obj.magic(v)
    | Func(v) => Obj.magic(v);
  let encodeOpt = Belt.Option.map(_, encode);
};
