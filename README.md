# Reason bindings for react-dates

[Reason](https://reasonml.github.io/) bindings for [react-dates](https://github.com/airbnb/react-dates).

## Status

🚧 Not everything is supported yet. 🚧

Feel free to create an issue or PR.

## Installation

```sh
npm install --save bs-react-dates
```

Then add `bs-react-dates` to `bs-dependencies` in your `bsconfig.json`:

```js
{
  ...
  "bs-dependencies": ["bs-react-dates"]
}
```

To include styles

```js
[%bs.raw {|require('react-dates/lib/css/_datepicker.css')|}];
```

## TODO

* [x] [DateRangePicker](https://github.com/airbnb/react-dates#daterangepicker)
* [ ] [SingleDatePicker](https://github.com/airbnb/react-dates#singledatepicker)
* [ ] [DayPickerRangeController](https://github.com/airbnb/react-dates#daypickerrangecontroller)
* [ ] can I/should I make it independable from `bs-moment`?

## Usage

Please take a look at [examples](https://github.com/ahrefs/bs-react-dates/tree/master/examples).
To run demo:

```sh
$ cd examples
$ npm install
$ npm start
```
