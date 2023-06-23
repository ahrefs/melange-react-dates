open Belt;
module Moment = MomentRe.Moment;

/* Have to call initialize in order this to work
 * https://github.com/airbnb/react-dates#initialize */
let _ = Initialize.initialize;

/* Utils */
[@deriving jsConverter]
type focusedInput = [ | `startDate | `endDate];

/*
  Unfortunately, lots of times, your JavaScript value might be both null or undefined. In that case, you unfortunately can't type such value as e.g. option<int>, since our option type only checks for undefined and not null when dealing with a None.

  Solution: More Sophisticated undefined & null Interop
  To solve this, we provide access to more elaborate null and undefined helpers through the Js.Nullable module. This somewhat works like an option type, but is different from it.
 */
type dates = {
  startDate: Js.nullable(Moment.t),
  endDate: Js.nullable(Moment.t),
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
