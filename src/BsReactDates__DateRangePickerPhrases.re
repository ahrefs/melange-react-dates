type t;

[@bs.obj]
external make :
  (
    ~closeDatePicker: string,
    ~clearDates: string,
    ~focusStartDate: string,
    ~jumpToPrevMonth: string,
    ~jumpToNextMonth: string,
    ~keyboardShortcuts: string,
    ~showKeyboardShortcutsPanel: string,
    ~hideKeyboardShortcutsPanel: string,
    ~openThisPanel: string,
    ~enterKey: string,
    ~leftArrowRightArrow: string,
    ~upArrowDownArrow: string,
    ~pageUpPageDown: string,
    ~homeEnd: string,
    ~escape: string,
    ~questionMark: string,
    ~selectFocusedDate: string,
    ~moveFocusByOneDay: string,
    ~moveFocusByOneWeek: string,
    ~moveFocusByOneMonth: string,
    ~moveFocustoStartAndEndOfWeek: string,
    ~returnFocusToInput: string,
    ~keyboardNavigationInstructions: string,
    ~chooseAvailableStartDate: string => string,
    ~chooseAvailableEndDate: string => string,
    ~dateIsUnavailable: string => string
  ) =>
  t =
  "";