open ReactDates;

open MomentRe;

module Phrases = {
  type t;
  [@bs.obj]
  external make :
    (
      ~closeDatePicker: string,
      ~clearDates: string,
      ~focusStartDate: string,
      ~jumpToPrevMonth: string,
      ~jumpToNextMonth: string,
      ~keyboardShortcuts: string,
      ~showKeyboardShortcutsPanel: string,
      ~hideKeyboardShortcutsPanel: string,
      ~openThisPanel: string,
      ~enterKey: string,
      ~leftArrowRightArrow: string,
      ~upArrowDownArrow: string,
      ~pageUpPageDown: string,
      ~homeEnd: string,
      ~escape: string,
      ~questionMark: string,
      ~selectFocusedDate: string,
      ~moveFocusByOneDay: string,
      ~moveFocusByOneWeek: string,
      ~moveFocusByOneMonth: string,
      ~moveFocustoStartAndEndOfWeek: string,
      ~returnFocusToInput: string,
      ~keyboardNavigationInstructions: string,
      ~chooseAvailableStartDate: string => string,
      ~chooseAvailableEndDate: string => string,
      ~dateIsUnavailable: string => string
    ) =>
    t =
    "";
};

[@bs.module "react-dates"]
external dateRangePicker : ReasonReact.reactClass = "DateRangePicker";

[@bs.obj]
external makeProps :
  (
    ~startDate: Moment.t,
    ~startDateId: string,
    ~endDate: Moment.t,
    ~endDateId: string,
    ~onDatesChange: datesObj => unit,
    ~focusedInput: Js.Nullable.t(string),
    ~onFocusChange: Js.nullable(string) => unit,
    /* input related props */
    ~startDatePlaceholderText: string=?,
    ~endDatePlaceholderText: string=?,
    ~disabled: [@bs.string] [ | `startDate | `endDate]=?,
    ~required: Js.boolean=?,
    ~readOnly: Js.boolean=?,
    ~screenReaderInputMessage: string=?,
    ~showClearDates: Js.boolean=?,
    ~showDefaultInputIcon: Js.boolean=?,
    ~customInputIcon: ReasonReact.reactElement=?,
    ~customArrowIcon: ReasonReact.reactElement=?,
    ~customCloseIcon: ReasonReact.reactElement=?,
    ~inputIconPosition: [@bs.string] [ | `before | `after]=?,
    ~noBorder: Js.boolean=?,
    ~block: Js.boolean=?,
    ~small: Js.boolean=?,
    ~regular: Js.boolean=?,
    /* calendar presentation and interaction related props */
    ~renderMonth: Moment.t => StrOrNode.t=?,
    ~orientation: [@bs.string] [ | `horizontal | `vertical]=?,
    ~anchorDirection: [@bs.string] [ | `left | `right]=?,
    ~horizontalMargin: int=?,
    ~withPortal: Js.boolean=?,
    ~withFullScreenPortal: Js.boolean=?,
    ~daySize: int=?, /* todo: not negative */
    ~isRTL: Js.boolean=?,
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
    ~keepOpenOnDateSelect: Js.boolean=?,
    ~reopenPickerOnClearDates: Js.boolean=?,
    ~renderCalendarInfo: unit => StrOrNode.t=?,
    ~hideKeyboardShortcutsPanel: Js.boolean=?,
    /* navigation related props */
    ~navPrev: ReasonReact.reactElement=?,
    ~navNext: ReasonReact.reactElement=?,
    ~onPrevMonthClick: Moment.t => unit=?,
    ~onNextMonthClick: Moment.t => unit=?,
    ~onClose: datesObj => unit=?,
    ~transitionDuration: int=?, /* todo: not negative */
    /* day presentation and interaction related props */
    ~renderCalendarDay: Moment.t => StrOrNode.t=?,
    ~renderDayContents: Moment.t => StrOrNode.t=?,
    ~minimumNights: int=?,
    ~enableOutsideDays: Js.boolean=?,
    ~isDayBlocked: day => Js.boolean=?,
    ~isOutsideRange: day => Js.boolean=?,
    ~isDayHighlighted: day => Js.boolean=?,
    /* internationalization props */
    ~displayFormat: DisplayFormat.t=?,
    ~monthFormat: string=?,
    ~weekDayFormat: string=?,
    ~phrases: Phrases.t=?,
    ~dayAriaLabelFormat: string=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~startDate,
      ~startDateId,
      ~endDate,
      ~endDateId,
      ~onDatesChange,
      ~focusedInput,
      ~onFocusChange,
      ~startDatePlaceholderText=?,
      ~endDatePlaceholderText=?,
      ~disabled=?,
      ~required=?,
      ~readOnly=?,
      ~screenReaderInputMessage=?,
      ~showClearDates=?,
      ~showDefaultInputIcon=?,
      ~customInputIcon=?,
      ~customArrowIcon=?,
      ~customCloseIcon=?,
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
      ~daySize=?,
      ~isRTL=?,
      ~initialVisibleMonth=?,
      ~firstDayOfWeek=?,
      ~numberOfMonths=?,
      ~keepOpenOnDateSelect=?,
      ~reopenPickerOnClearDates=?,
      ~renderCalendarInfo=?,
      ~hideKeyboardShortcutsPanel=?,
      ~navPrev=?,
      ~navNext=?,
      ~onPrevMonthClick=?,
      ~onNextMonthClick=?,
      ~onClose=?,
      ~transitionDuration=?,
      ~renderCalendarDay=?,
      ~renderDayContents=?,
      ~minimumNights=?,
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
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=dateRangePicker,
    ~props=
      makeProps(
        ~startDate,
        ~startDateId,
        ~endDate,
        ~endDateId,
        ~onDatesChange,
        ~focusedInput=focusedInput |> FocusedInput.toJS,
        ~onFocusChange,
        ~startDatePlaceholderText?,
        ~endDatePlaceholderText?,
        ~disabled?,
        ~required=?required |> optBoolToOptBoolean,
        ~readOnly=?readOnly |> optBoolToOptBoolean,
        ~screenReaderInputMessage?,
        ~showClearDates=?showClearDates |> optBoolToOptBoolean,
        ~showDefaultInputIcon=?showDefaultInputIcon |> optBoolToOptBoolean,
        ~customInputIcon?,
        ~customArrowIcon?,
        ~customCloseIcon?,
        ~inputIconPosition?,
        ~noBorder=?noBorder |> optBoolToOptBoolean,
        ~block=?block |> optBoolToOptBoolean,
        ~small=?small |> optBoolToOptBoolean,
        ~regular=?regular |> optBoolToOptBoolean,
        ~renderMonth?,
        ~orientation?,
        ~anchorDirection?,
        ~horizontalMargin?,
        ~withPortal=?withPortal |> optBoolToOptBoolean,
        ~withFullScreenPortal=?withFullScreenPortal |> optBoolToOptBoolean,
        ~daySize?,
        ~isRTL=?isRTL |> optBoolToOptBoolean,
        ~initialVisibleMonth?,
        ~firstDayOfWeek?,
        ~numberOfMonths?,
        ~keepOpenOnDateSelect=?keepOpenOnDateSelect |> optBoolToOptBoolean,
        ~reopenPickerOnClearDates=?
          reopenPickerOnClearDates |> optBoolToOptBoolean,
        ~renderCalendarInfo?,
        ~hideKeyboardShortcutsPanel=?
          hideKeyboardShortcutsPanel |> optBoolToOptBoolean,
        ~navPrev?,
        ~navNext?,
        ~onPrevMonthClick?,
        ~onNextMonthClick?,
        ~onClose?,
        ~transitionDuration?,
        ~renderCalendarDay?,
        ~renderDayContents?,
        ~minimumNights?,
        ~enableOutsideDays=?enableOutsideDays |> optBoolToOptBoolean,
        ~isDayBlocked?,
        ~isOutsideRange?,
        ~isDayHighlighted?,
        ~displayFormat=?displayFormat |> DisplayFormat.encodeOpt,
        ~monthFormat?,
        ~weekDayFormat?,
        ~phrases?,
        ~dayAriaLabelFormat?,
        (),
      ),
    children,
  );