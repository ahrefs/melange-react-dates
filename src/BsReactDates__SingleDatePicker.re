open BsReactDates__Utils;
open MomentRe;

[@bs.module "react-dates"][@react.component]
external make:
  (
    ~onDateChange: Moment.t => unit,
    ~onFocusChange: {. "focused": bool} => unit,
    ~focused: bool,
    ~id: string,
    ~date: Moment.t=?,
    ~placeholder: string=?,
    ~disabled: bool=?,
    ~required: bool=?,
    ~readOnly: bool=?,
    ~screenReaderInputMessage: string=?,
    ~showClearDate: bool=?,
    ~customCloseIcon: ReasonReact.reactElement=?,
    ~showDefaultInputIcon: bool=?,
    ~customInputIcon: ReasonReact.reactElement=?,
    ~inputIconPosition: [@bs.string] [ | `before | `after]=?,
    ~noBorder: bool=?,
    ~block: bool=?,
    ~small: bool=?,
    ~regular: bool=?,
    ~renderMonth: Moment.t => StrOrNode.t=?,
    ~orientation: [@bs.string] [ | `horizontal | `vertical]=?,
    ~anchorDirection: [@bs.string] [ | `left | `right]=?,
    ~horizontalMargin: int=?,
    ~withPortal: bool=?,
    ~withFullScreenPortal: bool=?,
    ~appendToBody: bool=?,
    ~disableScroll: bool=?,
    ~initialVisibleMonth: unit => Moment.t=?,
    ~firstDayOfWeek: [@bs.int] [
                       | `Sun
                       | `Mon
                       | `Tue
                       | `Wed
                       | `Thu
                       | `Fri
                       | `Sat
                     ]
                       =?,
    ~numberOfMonths: int=?,
    ~keepOpenOnDateSelect: bool=?,
    ~reopenPickerOnClearDate: bool=?,
    ~renderCalendarInfo: unit => StrOrNode.t=?,
    ~hideKeyboardShortcutsPanel: bool=?,
    ~daySize: int=?, /* todo: not negative */
    ~isRTL: bool=?,
    ~navPrev: ReasonReact.reactElement=?,
    ~navNext: ReasonReact.reactElement=?,
    ~onPrevMonthClick: Moment.t => unit=?,
    ~onNextMonthClick: Moment.t => unit=?,
    ~onClose: Moment.t => unit=?,
    ~transitionDuration: int=?, /* todo: not negative */
    ~renderCalendarDay: Moment.t => StrOrNode.t=?,
    ~renderDayContents: Moment.t => StrOrNode.t=?,
    ~enableOutsideDays: bool=?,
    ~isDayBlocked: Moment.t => bool=?,
    ~isOutsideRange: Moment.t => bool=?,
    ~isDayHighlighted: Moment.t => bool=?,
    ~displayFormat: DisplayFormat.t=?,
    ~monthFormat: string=?,
    ~weekDayFormat: string=?,
    ~phrases: BsReactDates__DateRangePickerPhrases.t=?,
    ~dayAriaLabelFormat: string=?
  ) =>
  React.element =
  "SingleDatePicker";
