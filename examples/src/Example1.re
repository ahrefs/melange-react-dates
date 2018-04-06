open MomentRe;

type action =
  | DatesChange(Moment.t, Moment.t)
  | FocusChange(RD.FocusedInput.t);

type state = {
  focusedInput: RD.FocusedInput.t,
  startDate: Moment.t,
  endDate: Moment.t,
};

let component = ReasonReact.reducerComponent("Example1");

let make = _children => {
  ...component,
  initialState: () => {
    focusedInput: StartDate,
    startDate: moment("2018-01-01"),
    endDate: moment("2018-10-01"),
  },
  reducer: (action, state) =>
    switch (action) {
    | DatesChange(startDate, endDate) =>
      ReasonReact.Update({...state, startDate, endDate})
    | FocusChange(focusedInput) =>
      ReasonReact.Update({...state, focusedInput})
    },
  render: self =>
    <RD
      startDate=self.state.startDate
      startDateId="startDateId"
      endDate=self.state.endDate
      endDateId="endDateId"
      focusedInput=self.state.focusedInput
      onDatesChange=(v => self.send(DatesChange(v##startDate, v##endDate)))
      onFocusChange=(v => self.send(FocusChange(RD.FocusedInput.fromJS(v))))
    />,
};