open BsReactDates__Utils;
open MomentRe;

[@bs.module "react-dates"][@react.component]
external make:
  (
    ~onDatesChange: Dates.tJs => unit,
    ~onFocusChange: Js.nullable(string) => unit,
    ~startDate: Moment.t=?,
    ~endDate: Moment.t=?,
    ~focusedInput: [@bs.string] [ | `startDate | `endDate]=?,
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
    ~navPrev: ReasonReact.reactElement=?,
    ~navNext: ReasonReact.reactElement=?,
    ~onPrevMonthClick: Moment.t => unit=?,
    ~onNextMonthClick: Moment.t => unit=?,
    ~transitionDuration: int=?, /* todo: not negative */
    ~renderCalendarDay: Moment.t => StrOrNode.t=?,
    ~renderDayContents: Moment.t => StrOrNode.t=?,
    ~minimumNights: int=?,
    ~isOutsideRange: Moment.t => bool=?,
    ~isDayBlocked: Moment.t => bool=?,
    ~isDayHighlighted: Moment.t => bool=?,
    ~monthFormat: string=?,
    ~weekDayFormat: string=?,
    ~phrases: BsReactDates__DateRangePickerPhrases.t=?,
    ~dayAriaLabelFormat: string=?,
  ) =>
  React.element =
  "DayPickerRangeController";