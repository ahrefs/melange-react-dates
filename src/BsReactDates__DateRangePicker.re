// https://github.com/airbnb/react-dates#daterangepicker

open BsReactDates__Utils;
module Moment = MomentRe.Moment;

[@bs.module "react-dates"] [@react.component]
external make:
  (
    ~className: string=?,
    ~onDatesChange: dates => unit,
    ~onFocusChange: Js.nullable(string) => unit,
    ~startDate: Moment.t=?,
    ~startDateId: string=?,
    ~endDate: Moment.t=?,
    ~endDateId: string=?,
    ~focusedInput: [ | `startDate | `endDate]=?,
    /* input related props */
    ~startDatePlaceholderText: string=?,
    ~endDatePlaceholderText: string=?,
    ~disabled: [ | `startDate | `endDate]=?,
    ~required: bool=?,
    ~readOnly: bool=?,
    ~screenReaderInputMessage: string=?,
    ~showClearDates: bool=?,
    ~showDefaultInputIcon: bool=?,
    ~customInputIcon: React.element=?,
    ~customArrowIcon: React.element=?,
    ~customCloseIcon: React.element=?,
    ~inputIconPosition: [ | `before | `after]=?,
    ~noBorder: bool=?,
    ~block: bool=?,
    ~small: bool=?,
    ~regular: bool=?,
    /* calendar presentation and interaction related props */
    ~renderMonth: Moment.t => StrOrNode.t=?,
    ~orientation: [ | `horizontal | `vertical]=?,
    ~anchorDirection: [ | `left | `right]=?,
    ~horizontalMargin: int=?,
    ~withPortal: bool=?,
    ~withFullScreenPortal: bool=?,
    ~daySize: int=?, /* todo: not negative */
    ~isRTL: bool=?,
    ~initialVisibleMonth: unit => Moment.t=?,
    ~firstDayOfWeek: [@bs.int] [ | `Sun | `Mon | `Tue | `Wed | `Thu | `Fri | `Sat]=?,
    ~numberOfMonths: int=?,
    ~keepOpenOnDateSelect: bool=?,
    ~reopenPickerOnClearDates: bool=?,
    ~renderCalendarInfo: unit => StrOrNode.t=?,
    ~hideKeyboardShortcutsPanel: bool=?,
    /* navigation related props */
    ~navPrev: React.element=?,
    ~navNext: React.element=?,
    ~onPrevMonthClick: Moment.t => unit=?,
    ~onNextMonthClick: Moment.t => unit=?,
    ~onClose: dates => unit=?,
    ~transitionDuration: int=?, /* todo: not negative */
    /* day presentation and interaction related props */
    ~renderCalendarDay: Moment.t => StrOrNode.t=?,
    ~renderDayContents: Moment.t => StrOrNode.t=?,
    ~minimumNights: int=?,
    ~enableOutsideDays: bool=?,
    ~isDayBlocked: Moment.t => bool=?,
    ~isOutsideRange: Moment.t => bool=?,
    ~isDayHighlighted: Moment.t => bool=?,
    /* internationalization props */
    ~displayFormat: DisplayFormat.t=?,
    ~monthFormat: string=?,
    ~weekDayFormat: string=?,
    ~phrases: BsReactDates__DateRangePickerPhrases.t=?,
    ~dayAriaLabelFormat: string=?,
    unit
  ) =>
  React.element =
  "DateRangePicker";
