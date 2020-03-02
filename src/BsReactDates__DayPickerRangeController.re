open BsReactDates__Utils;
open MomentRe;

[@bs.module "react-dates"] [@react.component]
external make:
  (
    ~className: string=?,
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
    ~onOutsideClick: ReactEvent.Mouse.t => unit=?,
    ~keepOpenOnDateSelect: bool=?,
    ~noBorder: bool=?,
    ~hideKeyboardShortcutsPanel: bool=?,
    ~daySize: int=?,
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
  React.element =
  "DayPickerRangeController";

module Jsx2 = {
  let component = ReasonReact.statelessComponent(__MODULE__);

  let make =
      (
        ~className=?,
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
        ~daySize=?,
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
    ReasonReactCompat.wrapReactForReasonReact(
      make,
      makeProps(
        ~className?,
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
        ~daySize?,
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
      React.array(children),
    );
  };
};