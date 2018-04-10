open ReactDates;

open MomentRe;

[@bs.obj]
external makeProps :
  (
    ~onDatesChange: datesObj => unit,
    ~onFocusChange: Js.nullable(string) => unit,
    ~startDate: Moment.t=?,
    ~startDateId: string=?,
    ~endDate: Moment.t=?,
    ~endDateId: string=?,
    ~focusedInput: [@bs.string] [ | `startDate | `endDate]=?,
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
    ~phrases: DateRangePickerPhrases.t=?,
    ~dayAriaLabelFormat: string=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "react-dates"]
external dateRangePickerAbs : ReasonReact.reactClass = "DateRangePicker";

let dateRangePicker = ReasonReact.statelessComponent("DateRangePicker");

let make =
    (
      ~onDatesChange,
      ~onFocusChange,
      ~startDate=?,
      ~startDateId=?,
      ~endDate=?,
      ~endDateId=?,
      ~focusedInput=?,
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
    ) => {
  let handleDatesChange = v =>
    onDatesChange({
      "startDate": Js.toOption(v##startDate),
      "endDate": Js.toOption(v##endDate),
    });
  let handleFocusChange = v =>
    onFocusChange(ReactDates.nullableFocusedInputToJs(v));
  {
    ...dateRangePicker,
    render: _self =>
      ReasonReact.element(
        ReasonReact.wrapJsForReason(
          ~reactClass=dateRangePickerAbs,
          ~props=
            makeProps(
              ~onDatesChange=handleDatesChange,
              ~onFocusChange=handleFocusChange,
              ~startDate?,
              ~startDateId?,
              ~endDate?,
              ~endDateId?,
              ~focusedInput?,
              ~startDatePlaceholderText?,
              ~endDatePlaceholderText?,
              ~disabled?,
              ~required=?required |> optBoolToOptBoolean,
              ~readOnly=?readOnly |> optBoolToOptBoolean,
              ~screenReaderInputMessage?,
              ~showClearDates=?showClearDates |> optBoolToOptBoolean,
              ~showDefaultInputIcon=?
                showDefaultInputIcon |> optBoolToOptBoolean,
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
              ~withFullScreenPortal=?
                withFullScreenPortal |> optBoolToOptBoolean,
              ~daySize?,
              ~isRTL=?isRTL |> optBoolToOptBoolean,
              ~initialVisibleMonth?,
              ~firstDayOfWeek?,
              ~numberOfMonths?,
              ~keepOpenOnDateSelect=?
                keepOpenOnDateSelect |> optBoolToOptBoolean,
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
        ),
      ),
  };
};