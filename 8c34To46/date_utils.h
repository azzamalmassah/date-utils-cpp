#pragma once

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
void decreaseDateByOneMillennium(sDate& d);
