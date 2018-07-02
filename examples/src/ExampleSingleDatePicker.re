open MomentRe;

open BsReactDates;

type action =
  | DateChange(option(Moment.t));

type state = {
  startDate: option(Moment.t)
};

let component = ReasonReact.reducerComponent("ExampleSingleDatePicker");

let make = _children => {
  ...component,
  initialState: () => {
    startDate: Some(momentNow()),
  },
  reducer: (action, state) =>
    switch (action) {
    | DateChange(startDate) =>
      ReasonReact.Update({...state, startDate})
    },
  render: self =>
    <SingleDatePicker
      date=?self.state.startDate
      id="startDateId"
      focused=false
      onDateChange=(v => self.send(DateChange(v.startDate)))
      onFocusChange=(_v => ())
    />,
};
