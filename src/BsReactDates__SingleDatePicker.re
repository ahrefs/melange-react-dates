open BsReactDates__Utils;

open MomentRe;

let nullableFocusedInputToJs = v =>
  v
  |. Js.toOption
  |. Belt.Option.map(focusedInputFromJs)
  /* upwrap option(option(..)) */
  |. Belt.Option.flatMap(x => x);

[@bs.obj]
external makeProps :
  (
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
    ~customCloseIcon: ReasonReact.reactElement=?,
    ~showDefaultInputIcon: bool=?,
    ~customInputIcon: ReasonReact.reactElement=?,
    ~inputIconPosition: [@bs.string] [ | `before | `after]=?,
    ~noBorder: bool=?,
    ~block: bool=?,
    ~small: bool=?,
    ~regular: bool=?,
    /* calendar presentation and interaction related props */
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
    /* navigation related props */
    ~navPrev: ReasonReact.reactElement=?,
    ~navNext: ReasonReact.reactElement=?,
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
    ~phrases: BsReactDates__DateRangePickerPhrases.t=?,
    ~dayAriaLabelFormat: string=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "react-dates"]
external singleDatePickerAbs : ReasonReact.reactClass = "SingleDatePicker";

let singleDatePicker = ReasonReact.statelessComponent("SingleDatePicker");

let make =
    (
      ~date=?,
      ~onDateChange,
      ~onFocusChange,
      ~focused,
      ~id,
      ~placeholder=?,
      ~disabled=?,
      ~required=?,
      ~readOnly=?,
      ~screenReaderInputMessage=?,
      ~showClearDate=?,
      ~customCloseIcon=?,
      ~showDefaultInputIcon=?,
      ~customInputIcon=?,
      ~inputIconPosition=?,
      ~noBorder=?,
      ~block=?,
      ~small=?,
      ~regular=?,
      ~renderMonth=?,
      ~orientation=?,
      ~anchorDirection=?,
      ~horizontalMargin=?,
      ~withPortal=?,
      ~withFullScreenPortal=?,
      ~appendToBody=?,
      ~disableScroll=?,
      ~initialVisibleMonth=?,
      ~firstDayOfWeek=?,
      ~numberOfMonths=?,
      ~keepOpenOnDateSelect=?,
      ~reopenPickerOnClearDate=?,
      ~renderCalendarInfo=?,
      ~hideKeyboardShortcutsPanel=?,
      ~daySize=?,
      ~isRTL=?,
      ~navPrev=?,
      ~navNext=?,
      ~onPrevMonthClick=?,
      ~onNextMonthClick=?,
      ~onClose=?,
      ~transitionDuration=?,
      ~renderCalendarDay=?,
      ~renderDayContents=?,
      ~enableOutsideDays=?,
      ~isDayBlocked=?,
      ~isOutsideRange=?,
      ~isDayHighlighted=?,
      ~displayFormat=?,
      ~monthFormat=?,
      ~weekDayFormat=?,
      ~phrases=?,
      ~dayAriaLabelFormat=?,
      children,
    ) => {
  ...singleDatePicker,
  render: _self => {
    ReasonReact.element(
      ReasonReact.wrapJsForReason(
        ~reactClass=singleDatePickerAbs,
        ~props=
          makeProps(
            ~onDateChange,
            ~onFocusChange=isFocussed => onFocusChange(isFocussed##focused),
            ~focused,
            ~id,
            ~date?,
            ~placeholder?,
            ~disabled?,
            ~required?,
            ~readOnly?,
            ~screenReaderInputMessage?,
            ~showClearDate?,
            ~customCloseIcon?,
            ~showDefaultInputIcon?,
            ~customInputIcon?,
            ~inputIconPosition?,
            ~noBorder?,
            ~block?,
            ~small?,
            ~regular?,
            ~renderMonth?,
            ~orientation?,
            ~anchorDirection?,
            ~horizontalMargin?,
            ~withPortal?,
            ~withFullScreenPortal?,
            ~appendToBody?,
            ~disableScroll?,
            ~initialVisibleMonth?,
            ~firstDayOfWeek?,
            ~numberOfMonths?,
            ~keepOpenOnDateSelect?,
            ~reopenPickerOnClearDate?,
            ~renderCalendarInfo?,
            ~hideKeyboardShortcutsPanel?,
            ~daySize?,
            ~isRTL?,
            ~navPrev?,
            ~navNext?,
            ~onPrevMonthClick?,
            ~onNextMonthClick?,
            ~onClose?,
            ~transitionDuration?,
            ~renderCalendarDay?,
            ~renderDayContents?,
            ~enableOutsideDays?,
            ~isDayBlocked?,
            ~isOutsideRange?,
            ~isDayHighlighted?,
            ~displayFormat=?displayFormat |. DisplayFormat.encodeOpt,
            ~monthFormat?,
            ~weekDayFormat?,
            ~phrases?,
            ~dayAriaLabelFormat?,
            (),
          ),
        children,
      ),
    )},
};
