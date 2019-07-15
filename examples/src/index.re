[%bs.raw {|require('./index.css')|}];
[%bs.raw {|require('react-dates/lib/css/_datepicker.css')|}];
BsReactDates.Initialize.initialize;

ReactDOMRe.renderToElementWithId(
  <div>
    <h2> (ReasonReact.string("DateRangePicker example")) </h2>
    <ExampleDateRangePicker />

    <h2> (ReasonReact.string("SingleDatePicker example")) </h2>
    <ExampleSingleDatePicker />
  </div>,
  "root",
);
