[%bs.raw {|require('./index.css')|}];

[%bs.raw {|require('react-dates/lib/css/_datepicker.css')|}];

ReactDOMRe.renderToElementWithId(
  <div>
    <h2> (ReasonReact.string("DateRangePicker example")) </h2>
    <ExampleDateRangePicker />
  </div>,
  "root",
);
