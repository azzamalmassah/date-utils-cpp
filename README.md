


# date-utils-cpp

A small, dependency-free C++ library for working with calendar dates.

This library provides simple and safe utilities for date subtraction, date addition, and common date queries, with correct handling of leap years and month/year boundaries.

---

## Why This Project?

Working with dates is deceptively complex. This project was created to:

- Practice real-world C++ problem solving
- Implement robust date-handling logic
- Build a reusable utility library
- Follow professional GitHub and Visual Studio standards

---

## Key Features

- Simple and clear `sDate` structure
- Add days to any date
- Calculate days from the beginning of the year
- Date subtraction (days → millennia)
- Date addition (days → years)
- Day-of-week calculation
- Weekend and business-day checks
- Remaining days in week, month, and year
- Leap-year–safe logic

---

## Project Structure

```text
date-utils-cpp/
├── src/
│   ├── date_utils.h     # Date structures & declarations
│   ├── date_utils.cpp  # Date utility implementations
│   └── main.cpp        # Usage examples / testing
├── date-utils-cpp.sln
├── .gitignore
└── README.md
````

---

## Tech Stack

* **Language:** C++
* **Standard:** C++17 (recommended)
* **IDE:** Visual Studio
* **Version Control:** Git & GitHub

---

## Usage Example

```cpp
#include <iostream>
#include "date_utils.h"

int main() {
    sDate d{29, 2, 2024};

    decreaseDateByOneDay(d);
    increaseDateByOneDay(d);

    std::cout << dayName(calculateIndex(d.day, d.month, d.year)) << std::endl;
    std::cout << "Weekend: " << isWeekEnd(d) << std::endl;
    std::cout << "Days till end of month: " << calcEndOfMonth(d) << std::endl;
}
```

---

## Supported Operations

### Date Subtraction

* `decreaseDateByOneDay`
* `decreaseDateByXDay`
* `decreaseDateByOneWeek`
* `decreaseDateByXWeek`
* `decreaseDateByOneMonth`
* `decreaseDateByXMonths`
* `decreaseDateByOneYear`
* `decreaseDateByXYearsFaster`
* `decreaseDateByOneDecade`
* `decreaseDateByXDecadesFaster`
* `decreaseDateByOneCentury`
* `decreaseDateByOneMillennium`

### Date Addition

* `increaseDateByOneDay`
* `increaseDateByXDay`
* `increaseDateByXWeek`
* `increaseDateByXMonths`
* `increaseDateByXYears`

### Date Querying

* `isWeekEnd`
* `isBusinessDay`
* `isEndOfWeek`
* `calcEndWeekDays`
* `calcEndOfMonth`
* `calcEndOfYear`
* `dayName`
* `calculateIndex`

---

## Testing

All functionality is demonstrated in `main.cpp` and covers:

* Leap years
* Month and year boundaries
* Date addition and subtraction
* Query correctness

---

## Requirements

* C++17 or later
* No third-party dependencies
* Works with Visual Studio, GCC, and Clang

---

## License

MIT License — free to use, modify, and distribute.

````

---

