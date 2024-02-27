open Utils;
module Moment = MomentReMjs.Moment;

[@mel.module "react-dates"] [@react.component]
external make:
  (
    ~className: string=?,
    ~onDateChange: Moment.t => unit,
    ~onFocusChange: {. "focused": bool} => unit,
    ~focused: bool,
    ~date: Moment.t=?,
    /* input related props */
    ~noBorder: bool=?,
    ~block: bool=?,
    ~small: bool=?,
    ~regular: bool=?,
    /* calendar presentation and interaction related props */
    ~initialVisibleMonth: unit => Moment.t=?,
    ~numberOfMonths: int=?,
    ~reopenPickerOnClearDate: bool=?,
    ~hideKeyboardShortcutsPanel: bool=?,
    ~horizontalMonthPadding: int=?,
    ~daySize: int=?, /* todo: not negative */
    ~isRTL: bool=?,
    /* navigation related props */
    ~navPrev: React.element=?,
    ~navNext: React.element=?,
    /* day presentation and interaction related props */
    ~renderDayContents: Moment.t => StrOrNode.t=?,
    ~isOutsideRange: Moment.t => bool=?,
    unit
  ) =>
  React.element =
  "DayPickerSingleDateController";
