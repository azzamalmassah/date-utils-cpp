#pragma once
#include <string>
struct sDate {
    int day;
    int month;
    int year;
};

// Common helpers
bool isLeapYear(int year);
short numberOfDaysInMonthsShort(short year, short month);

// Day
void decreaseDateByOneDay(sDate& d);
void decreaseDateByXDay(sDate& d, int days);

// Week
void decreaseDateByOneWeek(sDate& d);
void decreaseDateByXWeek(sDate& d, int weeks);

// Month
void decreaseDateByOneMonth(sDate& d);
void decreaseDateByXMonths(sDate& d, int months);


// Year
void decreaseDateByOneYear(sDate& d);
void decreaseDateByXYearsFaster(sDate& d, int years);

// Large units
void decreaseDateByOneDecade(sDate& d);
void decreaseDateByXDecadesFaster(sDate& d, int decades);

void decreaseDateByOneCentury(sDate& d);
void decreaseDateByOneCenturyFaster(sDate& d);
void decreaseDateByOneMillennium(sDate& d);
// ==========================
// Date addition (increase)
// ==========================

bool isLastDayInMonth(const sDate& d);
bool isLastMonthInYear(const sDate& d);

// Day
void increaseDateByOneDay(sDate& d);
void increaseDateByXDay(sDate& d, int daysToAdd);

// Week
void increaseDateByXWeek(sDate& d, int weeksToAdd = 1);

// Month
void increaseDateByXMonths(sDate& d, int monthsToAdd = 1);

// Year
void increaseDateByXYears(sDate& d, int yearsToAdd = 1);


// ==========================
// Date queries & calculations
// ==========================

int calculateIndex(int day, int month, int year);
std::string dayName(short index);

bool isWeekEnd(const sDate& d);
bool isEndOfWeek(const sDate& d);
bool isBusinessDay(const sDate& d);
sDate calculateVacationEndDate(sDate d, short vacationDays);
short calculateVacationDays(sDate dateFrom, sDate dateTo);
short daysUntilEndOfWeek(short dayIndex);
short calcEndWeekDays(const sDate& d);
short calcEndOfMonth(const sDate& d);
int   calcEndOfYear(const sDate& d);

enum enDateCompare { Before = -1, Equal = 0, After = 1 };
bool isSameDate(const sDate& d1, const  sDate& d2);
bool isDate1BeforeDate2(const sDate &d1, const sDate& d2);
short compareDates(const sDate& d1, const sDate& d2);
bool isDate1AfterDate2(const sDate& d1, const sDate& d2);

// ==========================
// Period utilities
// ==========================

struct sPeriod {
    sDate periodStart;
    sDate periodEnd;
};

bool isOverlap(const sPeriod& period1, const sPeriod& period2);

