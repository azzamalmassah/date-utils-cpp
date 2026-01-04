#  date-utils-cpp

**A clean, lightweight C++ date utility library**

`date-utils-cpp` is a reusable C++ utility library that provides **reliable date calculations** such as adding days, handling month/year rollovers, and leap year logic.
The project is built with a **clean Visual Studio structure** and focuses on **correctness, readability, and extensibility**.

---

##  Why This Project?

Working with dates is deceptively complex.
This project was created to:

* Practice **real-world C++ problem solving**
* Implement **robust date-handling logic**
* Build a **reusable utility library**
* Follow **professional GitHub & Visual Studio standards**

---

##  Key Features

*  Simple and clear `sDate` structure
*  Add days to any date
*  Calculate days from the beginning of the year
*  Correct handling of:

  * Month boundaries
  * Year changes
  * Leap years
*  Modular utility functions
*  Easy to test and extend

---

## 🗂️ Project Structure

```
date-utils-cpp/
│
├── src/
│   ├── date_utils.h      # Date structures & declarations
│   ├── date_utils.cpp    # Date utility implementations
│   └── main.cpp          # Usage examples / testing
│
├── date-utils-cpp.sln
├── .gitignore
└── README.md
```

## 🛠️ Tech Stack

* **Language:** C++
* **Standard:** C++17 (recommended)
* **IDE:** Visual Studio
* **Version Control:** Git & GitHub

---

##  Example Usage

```cpp
sDate today = { 1, 1, 2026 };
sDate futureDate = addingDaysToDate(40, today);
```

The function correctly:

* Moves across months
* Updates the year if required
* Accounts for leap years









