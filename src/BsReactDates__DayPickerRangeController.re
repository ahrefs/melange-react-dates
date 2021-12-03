// https://github.com/airbnb/react-dates#daypickerrangecontroller

open BsReactDates__Utils;
module Moment = MomentRe.Moment;

[@bs.module "react-dates"] [@react.component]
external make:
  (
    ~className: string=?,
    ~daySize: int=?,
    ~onDatesChange: Dates.tJs => unit,
    ~onFocusChange: Js.nullable(string) => unit,
    ~startDate: Js.Nullable.t(Moment.t)=?,
    ~endDate: Js.Nullable.t(Moment.t)=?,
    // calendar presentation and interaction related props
    ~enableOutsideDays: bool=?,
    ~numberOfMonths: int=?,
    ~orientation: [ | `horizontal | `vertical]=?,
    ~withPortal: bool=?,
    ~initialVisibleMonth: unit => Moment.t=?,
    ~renderCalendarInfo: unit => StrOrNode.t=?,
    ~onOutsideClick: ReactEvent.Mouse.t => unit=?,
    ~keepOpenOnDateSelect: bool=?,
    ~noBorder: bool=?,
    // navigation related props
    ~hideKeyboardShortcutsPanel: bool=?,
    ~navPrev: React.element=?,
    ~navNext: React.element=?,
    ~onPrevMonthClick: Moment.t => unit=?,
    ~onNextMonthClick: Moment.t => unit=?,
    ~transitionDuration: int=?, /* todo: not negative */
    // day presentation and interaction related props
    ~renderCalendarDay: Moment.t => StrOrNode.t=?,
    ~renderDayContents: Moment.t => StrOrNode.t=?,
    ~minimumNights: int=?,
    ~isFocused: bool=?,
    ~minDate: Moment.t=?,
    ~maxDate: Moment.t=?,
    ~isOutsideRange: Moment.t => bool=?,
    ~isDayBlocked: Moment.t => bool=?,
    ~isDayHighlighted: Moment.t => bool=?,
    // internationalization props
    ~monthFormat: string=?,
    ~phrases: BsReactDates__DateRangePickerPhrases.t=?,
    ~dayAriaLabelFormat: string=?
  ) =>
  React.element =
  "DayPickerRangeController";
