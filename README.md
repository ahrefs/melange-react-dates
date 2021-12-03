# Reason bindings for react-dates

[Reason](https://reasonml.github.io/) bindings for [react-dates](https://github.com/airbnb/react-dates).

## Status 🚧 🏗

It is not completed, we are adding bindings as we go. Doesn't follow semver.

## Installation, [npm](https://www.npmjs.com/package/@ahrefs/bs-react-dates)

```sh
yarn add @ahrefs/bs-react-dates
```
```sh
npm install --save @ahrefs/bs-react-dates
```

Then add `@ahrefs/bs-react-dates` to `bs-dependencies` in your `bsconfig.json`:

```js
{
  ...
  "bs-dependencies": ["@ahrefs/bs-react-dates"]
}
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

```

## TODO

* [x] [DateRangePicker](https://github.com/airbnb/react-dates#daterangepicker)
* [x] [SingleDatePicker](https://github.com/airbnb/react-dates#singledatepicker)
* [x] [DayPickerRangeController](https://github.com/airbnb/react-dates#daypickerrangecontroller)
* [ ] can/should I remove dep on `bs-moment`?

