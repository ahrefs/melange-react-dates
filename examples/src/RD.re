open MomentRe;

/* Have to call initialize in order this to work
 * https://github.com/airbnb/react-dates#initialize */
[@bs.module "react-dates/initialize"] external initialize : unit = "default";

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

[@bs.module "react-dates"]
external dateRangePicker : ReasonReact.reactClass = "DateRangePicker";

[@bs.obj]
external makeProps :
  (
    ~startDate: Moment.t,
    ~startDateId: string,
    ~endDate: Moment.t,
    ~endDateId: string,
    ~onDatesChange: {
                      .
                      "startDate": Moment.t,
                      "endDate": Moment.t,
                    } =>
                    unit,
    ~focusedInput: Js.Nullable.t(string),
    ~onFocusChange: Js.nullable(string) => unit,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~startDate,
      ~startDateId,
      ~endDate,
      ~endDateId,
      ~onDatesChange,
      ~focusedInput,
      ~onFocusChange,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=dateRangePicker,
    ~props=
      makeProps(
        ~startDate,
        ~startDateId,
        ~endDate,
        ~endDateId,
        ~onDatesChange,
        ~focusedInput=focusedInput |> FocusedInput.toJS,
        ~onFocusChange,
        (),
      ),
    children,
  );