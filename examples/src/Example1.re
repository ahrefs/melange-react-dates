open MomentRe;

open BsReactDates;

type action =
  | DatesChange(option(Moment.t), option(Moment.t))
  | FocusChange(option(ReactDates.focusedInput));

type state = {
  focusedInput: option(ReactDates.focusedInput),
  startDate: option(Moment.t),
  endDate: option(Moment.t),
};

let component = ReasonReact.reducerComponent("Example1");

let make = _children => {
  ...component,
  initialState: () => {
    focusedInput: None,
    startDate: Some(momentNow()),
    endDate: Some(Moment.add(~duration=duration(5, `days), momentNow())),
  },
  reducer: (action, state) =>
    switch (action) {
    | DatesChange(startDate, endDate) =>
      ReasonReact.Update({...state, startDate, endDate})
    | FocusChange(focusedInput) =>
      ReasonReact.Update({...state, focusedInput})
    },
  render: self =>
    <DateRangePicker
      startDate=?self.state.startDate
      startDateId="startDateId"
      endDate=?self.state.endDate
      endDateId="endDateId"
      focusedInput=?self.state.focusedInput
      onDatesChange=(v => self.send(DatesChange(v.startDate, v.endDate)))
      onFocusChange=(v => self.send(FocusChange(v)))
      isOutsideRange=((_) => false)
    />,
};