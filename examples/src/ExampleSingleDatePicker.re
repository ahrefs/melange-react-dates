open MomentRe;
open BsReactDates;

[@react.component]
let make = () => {
  /* State variables:
    - date: option(Moment.t)
    - focused: bool
  */
  let (date, setDate) = React.useState(() => Some(momentNow()));
  let (focused, setFocused) = React.useState(() => false);

  <SingleDatePicker
      date=?{date}
      id="dateId"
      focused
      onDateChange=(d => setDate(_ => Some(d)))
      onFocusChange={f => setFocused(_ => f##focused)}
  />
}