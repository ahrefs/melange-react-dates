open Belt;
module Moment = MomentRe.Moment;

/* Have to call initialize in order this to work
 * https://github.com/airbnb/react-dates#initialize */
let _ = BsReactDates__Initialize.initialize;

/* Utils */
let fromOpt = Js.Nullable.fromOption;

let toOpt = Js.Nullable.toOption;

let optMap = Js.Nullable.toOption;

[@bs.deriving jsConverter]
type focusedInput = [ | `startDate | `endDate];

type dates = {
  startDate: option(Moment.t),
  endDate: option(Moment.t),
};

module StrOrNode = {
  type t;
  type arg =
    | Str(string)
    | Node(React.element);
  let encode: arg => t =
    fun
    | Str(v) => Obj.magic(v)
    | Node(v) => Obj.magic(v);
  let encodeOpt = Option.map(_, encode);
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
  let encodeOpt = Option.map(_, encode);
};

let nullableFocusedInputToJs = v => v->Js.toOption->(Option.map(focusedInputFromJs))->(Option.flatMap(x => x));
