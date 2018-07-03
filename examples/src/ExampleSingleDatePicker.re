open MomentRe;

open BsReactDates;

type action =
  | DateChange(Moment.t)
  | FocusChange(bool);

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
    | FocusChange(v) =>
      ReasonReact.Update({...state, focused: v})
    },
  render: self =>
    <SingleDatePicker
      date=?self.state.date
      id="dateId"
      focused=self.state.focused
      onDateChange=(date => self.send(DateChange(date)))
      onFocusChange=(v => {
        self.send(FocusChange(v##focused));
      })
    />,
};
