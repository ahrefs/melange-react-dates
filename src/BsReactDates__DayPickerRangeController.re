open BsReactDates__Utils;
open MomentRe;

[@bs.obj]
external makeProps:
  (
    ~onDatesChange: Dates.tJs => unit,
    ~onFocusChange: Js.nullable(string) => unit,
    ~startDate: Moment.t=?,
    ~endDate: Moment.t=?,
    ~focusedInput: [@bs.string] [ | `startDate | `endDate]=?,
    /* calendar presentation and interaction related props */
    ~enableOutsideDays: bool=?,
    ~numberOfMonths: int=?,
    ~orientation: [@bs.string] [ | `horizontal | `vertical]=?,
    ~withPortal: bool=?,
    ~initialVisibleMonth: unit => Moment.t=?,
    ~renderCalendarInfo: unit => StrOrNode.t=?,
    ~onOutsideClick: ReactEventRe.Mouse.t => unit=?,
    ~keepOpenOnDateSelect: bool=?,
    ~noBorder: bool=?,
    ~hideKeyboardShortcutsPanel: bool=?,
    /* navigation related props */
    ~navPrev: ReasonReact.reactElement=?,
    ~navNext: ReasonReact.reactElement=?,
    ~onPrevMonthClick: Moment.t => unit=?,
    ~onNextMonthClick: Moment.t => unit=?,
    ~transitionDuration: int=?, /* todo: not negative */
    /* day presentation and interaction related props */
    ~renderCalendarDay: Moment.t => StrOrNode.t=?,
    ~renderDayContents: Moment.t => StrOrNode.t=?,
    ~minimumNights: int=?,
    ~isOutsideRange: Moment.t => bool=?,
    ~isDayBlocked: Moment.t => bool=?,
    ~isDayHighlighted: Moment.t => bool=?,
    /* internationalization props */
    ~monthFormat: string=?,
    ~weekDayFormat: string=?,
    ~phrases: BsReactDates__DateRangePickerPhrases.t=?,
    ~dayAriaLabelFormat: string=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "react-dates"]
external dayPickerRangeControllerAbs: ReasonReact.reactClass =
  "DayPickerRangeController";

let dayPickerRangeController =
  ReasonReact.statelessComponent("DayPickerRangeController");

let make =
    (
      ~onDatesChange,
      ~onFocusChange,
      ~startDate=?,
      ~endDate=?,
      ~focusedInput=?,
      ~enableOutsideDays=?,
      ~numberOfMonths=?,
      ~orientation=?,
      ~withPortal=?,
      ~initialVisibleMonth=?,
      ~renderCalendarInfo=?,
      ~onOutsideClick=?,
      ~keepOpenOnDateSelect=?,
      ~noBorder=?,
      ~hideKeyboardShortcutsPanel=?,
      ~navPrev=?,
      ~navNext=?,
      ~onPrevMonthClick=?,
      ~onNextMonthClick=?,
      ~transitionDuration=?,
      ~renderCalendarDay=?,
      ~renderDayContents=?,
      ~minimumNights=?,
      ~isOutsideRange=?,
      ~isDayBlocked=?,
      ~isDayHighlighted=?,
      ~monthFormat=?,
      ~weekDayFormat=?,
      ~phrases=?,
      ~dayAriaLabelFormat=?,
      children,
    ) => {
  let handleDatesChange = v => v->Dates.fromJs->onDatesChange;
  let handleFocusChange = v => v->nullableFocusedInputToJs->onFocusChange;
  {
    ...dayPickerRangeController,
    render: _self =>
      ReasonReact.element(
        ReasonReact.wrapJsForReason(
          ~reactClass=dayPickerRangeControllerAbs,
          ~props=
            makeProps(
              ~onDatesChange=handleDatesChange,
              ~onFocusChange=handleFocusChange,
              ~startDate?,
              ~endDate?,
              ~focusedInput?,
              ~enableOutsideDays?,
              ~numberOfMonths?,
              ~orientation?,
              ~withPortal?,
              ~initialVisibleMonth?,
              ~renderCalendarInfo?,
              ~onOutsideClick?,
              ~keepOpenOnDateSelect?,
              ~noBorder?,
              ~hideKeyboardShortcutsPanel?,
              ~navPrev?,
              ~navNext?,
              ~onPrevMonthClick?,
              ~onNextMonthClick?,
              ~transitionDuration?,
              ~renderCalendarDay?,
              ~renderDayContents?,
              ~minimumNights?,
              ~isOutsideRange?,
              ~isDayBlocked?,
              ~isDayHighlighted?,
              ~monthFormat?,
              ~weekDayFormat?,
              ~phrases?,
              ~dayAriaLabelFormat?,
              (),
            ),
          children,
        ),
      ),
  };
};
