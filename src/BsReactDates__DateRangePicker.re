open BsReactDates__Utils;
open MomentRe;
let handleDatesChange = v => v->Dates.fromJs;
let handleFocusChange = v => v->nullableFocusedInputToJs;

[@bs.module "react-dates"][@react.component]
external make:
  (
    ~onDatesChange: Dates.tJs => unit,
    ~onFocusChange: Js.nullable(string) => unit,
    ~startDate: Moment.t=?,
    ~startDateId: string=?,
    ~endDate: Moment.t=?,
    ~endDateId: string=?,
    ~focusedInput: [@bs.string] [ | `startDate | `endDate]=?,
    ~startDatePlaceholderText: string=?,
    ~endDatePlaceholderText: string=?,
    ~disabled: [@bs.string] [ | `startDate | `endDate]=?,
    ~required: bool=?,
    ~readOnly: bool=?,
    ~screenReaderInputMessage: string=?,
    ~showClearDates: bool=?,
    ~showDefaultInputIcon: bool=?,
    ~customInputIcon: ReasonReact.reactElement=?,
    ~customArrowIcon: ReasonReact.reactElement=?,
    ~customCloseIcon: ReasonReact.reactElement=?,
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
    ~daySize: int=?, /* todo: not negative */
    ~isRTL: bool=?,
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
    ~reopenPickerOnClearDates: bool=?,
    ~renderCalendarInfo: unit => StrOrNode.t=?,
    ~hideKeyboardShortcutsPanel: bool=?,
    ~navPrev: ReasonReact.reactElement=?,
    ~navNext: ReasonReact.reactElement=?,
    ~onPrevMonthClick: Moment.t => unit=?,
    ~onNextMonthClick: Moment.t => unit=?,
    ~onClose: Dates.tJs => unit=?,
    ~transitionDuration: int=?, /* todo: not negative */
    ~renderCalendarDay: Moment.t => StrOrNode.t=?,
    ~renderDayContents: Moment.t => StrOrNode.t=?,
    ~minimumNights: int=?,
    ~enableOutsideDays: bool=?,
    ~isDayBlocked: Moment.t => bool=?,
    ~isOutsideRange: Moment.t => bool=?,
    ~isDayHighlighted: Moment.t => bool=?,
    ~displayFormat: DisplayFormat.t=?,
    ~monthFormat: string=?,
    ~weekDayFormat: string=?,
    ~phrases: BsReactDates__DateRangePickerPhrases.t=?,
    ~dayAriaLabelFormat: string=?,
    unit
  ) =>
  React.element =
  "DateRangePicker";
