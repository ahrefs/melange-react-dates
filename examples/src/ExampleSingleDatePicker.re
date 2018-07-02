open MomentRe;

open BsReactDates;

type action =
  | DateChange(Moment.t)
  | FocusChange;

type state = {
  date: option(Moment.t),
  focused: bool
};

let component = ReasonReact.reducerComponent("ExampleSingleDatePicker");

let make = _children => {
  ...component,
  initialState: () => {
    date: Some(momentNow()),
    focused: false,
  },
  reducer: (action, state) =>
    switch (action) {
    | DateChange(date) =>
      ReasonReact.Update({date: Some(date), focused: false})
    | FocusChange =>
      ReasonReact.Update({...state, focused: true})
    },
  render: self =>
    <SingleDatePicker
      date=?self.state.date
      id="dateId"
      focused=self.state.focused
      onDateChange=(date => self.send(DateChange(date)))
      onFocusChange=(_v => self.send(FocusChange))
    />,
};
