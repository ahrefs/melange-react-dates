open MomentRe;

open BsReactDates;

[@react.component]
let make = () => {
  /* State variables:
    - focusedInput: option(Utils.focusedInput),
    - startDate: option(Moment.t),
    - endDate: option(Moment.t),
  */
  let (focusedInput, setFocusedInput) = React.useState(() => None);
  let (startDate, setStartDate) = React.useState(() => Some(momentNow()));
  let (endDate, setEndDate) = React.useState(() => Some(Moment.add(~duration=duration(5, `days), momentNow())));

  <DateRangePicker
    startDate=?{startDate}
    startDateId="startDateId"
    endDate=?{endDate}
    endDateId="endDateId"
    focusedInput=?{focusedInput}
    onDatesChange={v => {
      let d = DateRangePicker.handleDatesChange(v);
      setStartDate(_ => d.startDate);
      setEndDate(_ => d.endDate);
    }}
    onFocusChange={v => setFocusedInput(_ => DateRangePicker.handleFocusChange(v))}
    isOutsideRange={_ => false}
  />
}