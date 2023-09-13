open Utils;
module Moment = MomentRe.Moment;

[@mel.module "react-dates"] [@react.component]
external make:
  (
    ~className: string=?,
    ~onDateChange: Moment.t => unit,
    ~onFocusChange: {. "focused": bool} => unit,
    ~focused: bool,
    ~id: string,
    ~date: Moment.t=?,
    /* input related props */
    ~placeholder: string=?,
    ~disabled: bool=?,
    ~required: bool=?,
    ~readOnly: bool=?,
    ~screenReaderInputMessage: string=?,
    ~showClearDate: bool=?,
    ~customCloseIcon: React.element=?,
    ~showDefaultInputIcon: bool=?,
    ~customInputIcon: React.element=?,
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
    ~appendToBody: bool=?,
    ~disableScroll: bool=?,
    ~initialVisibleMonth: unit => Moment.t=?,
    ~firstDayOfWeek: [@mel.int] [ | `Sun | `Mon | `Tue | `Wed | `Thu | `Fri | `Sat]=?,
    ~numberOfMonths: int=?,
    ~keepOpenOnDateSelect: bool=?,
    ~reopenPickerOnClearDate: bool=?,
    ~renderCalendarInfo: unit => StrOrNode.t=?,
    ~hideKeyboardShortcutsPanel: bool=?,
    ~daySize: int=?, /* todo: not negative */
    ~isRTL: bool=?,
    /* navigation related props */
    ~navPrev: React.element=?,
    ~navNext: React.element=?,
    ~onPrevMonthClick: Moment.t => unit=?,
    ~onNextMonthClick: Moment.t => unit=?,
    ~onClose: Moment.t => unit=?,
    ~transitionDuration: int=?, /* todo: not negative */
    /* day presentation and interaction related props */
    ~renderCalendarDay: Moment.t => StrOrNode.t=?,
    ~renderDayContents: Moment.t => StrOrNode.t=?,
    ~enableOutsideDays: bool=?,
    ~isDayBlocked: Moment.t => bool=?,
    ~isOutsideRange: Moment.t => bool=?,
    ~isDayHighlighted: Moment.t => bool=?,
    /* internationalization props */
    ~displayFormat: DisplayFormat.t=?,
    ~monthFormat: string=?,
    ~weekDayFormat: string=?,
    ~phrases: DateRangePickerPhrases.t=?,
    ~dayAriaLabelFormat: string=?,
    ~children: React.element=?,
    unit
  ) =>
  React.element =
  "SingleDatePicker";
