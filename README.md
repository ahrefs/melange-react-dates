# Melange bindings for react-dates

[Melange](https://melange.re/) bindings for [react-dates](https://github.com/airbnb/react-dates).

## Status 🚧 🏗

It is not completed, we are adding bindings as we go. Doesn't follow semver.

## Installation

Install [opam](https://opam.ocaml.org/) package manager.

Then:

```
opam pin add melange-react-dates.dev git+https://github.com/ahrefs/melange-react-dates.git#master
```

The bindings support the following versions of the `react-dates`
npm package, which should be installed separately:

```json
  "dependencies": {
    "react-dates": "^21.8.0"
  }
```

## Setup

Add `melange-react-dates` to the `libraries` field in your `dune` file:

```dune
; ...
  (libraries melange-react-dates)
; ...
```

To include styles

```js
[%bs.raw {|require('react-dates/lib/css/_datepicker.css')|}];
```

`react-dates` [assumes](https://github.com/airbnb/react-dates/issues/798) that `box-sizing: border-box` is set globally in your page's CSS. At least do this, to make it display properly.

```css
.DateRangePicker *,
.SingleDatePicker *,
.DayPickerRangeController * {
  box-sizing: border-box;
}
```

## Examples

```js
[%bs.raw {|require('react-dates/lib/css/_datepicker.css')|}];

[@react.component]
let make = () => {
  let (dates, setDates) = React.useState(_ => DateRangePicker.Dates.{startDate: None, endDate: None});
  let (focusedInput, setFocusedInput) = React.useState(_ => None);

  <DateRangePicker
    startDate=?{dates.startDate}
    startDateId="startDateId"
    endDate=?{dates.endDate}
    endDateId="endDateId"
    ?focusedInput
    onDatesChange={v => setDates(_ => v)}
    onFocusChange={v => setFocusedInput(_ => v)}
    isOutsideRange={_day => false}
  />;
};
```

## TODO

* [x] [DateRangePicker](https://github.com/airbnb/react-dates#daterangepicker)
* [x] [SingleDatePicker](https://github.com/airbnb/react-dates#singledatepicker)
* [x] [DayPickerRangeController](https://github.com/airbnb/react-dates#daypickerrangecontroller)
* [ ] can/should I remove dep on `bs-moment`?

