open MomentRe;

open BsReactDates;

type action =
  | DatesChange(Moment.t, Moment.t)
  | FocusChange(ReactDates.FocusedInput.t);

type state = {
  focusedInput: ReactDates.FocusedInput.t,
  startDate: Moment.t,
  endDate: Moment.t,
};

let component = ReasonReact.reducerComponent("Example1");

let make = _children => {
  ...component,
  initialState: () => {
    focusedInput: StartDate,
    startDate: momentNow(),
    endDate: Moment.add(~duration=duration(5, `days), momentNow()),
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
      startDate=self.state.startDate
      startDateId="startDateId"
      endDate=self.state.endDate
      endDateId="endDateId"
      focusedInput=self.state.focusedInput
      onDatesChange=(v => self.send(DatesChange(v##startDate, v##endDate)))
      onFocusChange=(
        v => self.send(FocusChange(ReactDates.FocusedInput.fromJS(v)))
      )
    />,
};