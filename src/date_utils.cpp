#include "date_utils.h"
#include <string>

bool isLeapYear(int year) {
	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

short numberOfDaysInMonthsShort(short year, short month) {
	if (month < 1 || month >12) {
		return 0;
	}
	int numberOfDays[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return month == 2 ? (isLeapYear(year) ? 29 : 28) : numberOfDays[month - 1];
}


//Day
void decreaseDateByOneDay(sDate& d) {
	if (d.day != 1) {
		d.day--;
		return;
	}
	else {
		d.month--;
		if (d.month == 0) {
			d.month = 12;
			d.year--;

		}
	}
	d.day = numberOfDaysInMonthsShort(d.year, d.month);


}

void decreaseDateByXDay(sDate& d, int daysToSubtract) {

	for (int i = 0; i < daysToSubtract; i++) {
		decreaseDateByOneDay(d);
	}
}

//Week
void decreaseDateByOneWeek(sDate& d) {
	decreaseDateByXDay(d, 7);
}

void decreaseDateByXWeek(sDate& d, int weeksToSubtract) {
	int totalDays = weeksToSubtract * 7;
	decreaseDateByXDay(d, totalDays);
}

//Month
void decreaseDateByOneMonth(sDate& d) {
	d.month--;
	if (d.month == 0) {
		d.month = 12;
		d.year--;

	}
	int maxDays = numberOfDaysInMonthsShort(d.year, d.month);
	if (d.day > maxDays) {
		d.day = maxDays;
	}

}
void decreaseDateByXMonths(sDate& d, int months) {
	for (int i = 0; i < months; i++) {
		decreaseDateByOneMonth(d);
	}
}

//year

void decreaseDateByOneYear(sDate& d) {
	d.year--;
	int maxDays = numberOfDaysInMonthsShort(d.year, d.month);
	if (d.day > maxDays) {
		d.day = maxDays;
	}
}


void decreaseDateByXYearsFaster(sDate& d, int years) {
	d.year -= years;
	int maxDays = numberOfDaysInMonthsShort(d.year, d.month);
	if (d.day > maxDays) {
		d.day = maxDays;
	}
}


// Large units
void decreaseDateByOneDecade(sDate& d) {
	decreaseDateByXYearsFaster(d, 10);
}



void decreaseDateByXDecadesFaster(sDate& d, int decadesToSub) {


	d.year = d.year - decadesToSub * 10;

	int maxDays = numberOfDaysInMonthsShort(d.year, d.month);
	if (d.day > maxDays) {
		d.day = maxDays;
	}
}
void decreaseDateByOneCentury(sDate& d) {
	decreaseDateByXDecadesFaster(d, 10);
}

void decreaseDateByOneCenturyFaster(sDate& d) {
	d.year = d.year - 100;
	int maxDays = numberOfDaysInMonthsShort(d.year, d.month);
	if (d.day > maxDays) {
		d.day = maxDays;
	}
}



void decreaseDateByOneMillennium(sDate& d) {
	decreaseDateByXYearsFaster(d, 1000);

}

// ==========================
// Date addition (increase)
// ==========================
bool isLastDayInMonth(const sDate &d) {
	return d.day == numberOfDaysInMonthsShort(d.year, d.month);
}

bool isLastMonthInYear(const sDate& d) {
	return d.month == 12;
}

void increaseDateByOneDay(sDate& d) {
	if (isLastDayInMonth(d)) {
		if (isLastMonthInYear(d)) {
			d.year++;
			d.day = 1;
			d.month = 1;
			return;
		}
		d.day = 1;
		d.month++;
		return;
	}
	d.day++;
	return;
}
void increaseDateByXDay( sDate& d,int daysToAdd) {
	for (int i = 0; i < daysToAdd; i++) {
		increaseDateByOneDay(d);
	}

}
void increaseDateByXWeek(sDate& d1, int weeksToAdd ) {
	increaseDateByXDay( d1,(7 * weeksToAdd));
}
void increaseDateByXMonths(sDate& d, int monthsToAdd ) {
	d.month = d.month + monthsToAdd;
	while (d.month > 12) {
		d.month = d.month - 12;
		d.year++;
	}
	short monthDays = numberOfDaysInMonthsShort(d.year, d.month);
	if (d.day > monthDays) {
		d.day = monthDays;
	}


}


void increaseDateByXYears(sDate& d, int yearsToAdd ) {
	d.year = d.year + yearsToAdd;
	if (d.month == 2 && d.day == 29 && !isLeapYear(d.year)) {
		d.day = 28;
	}

}

// ==========================
// Date queries & calculations
// ==========================
int calculateIndex(int day, int month, int year) {
	short a, y, m;
	a = (14 - month) / 12;
	y = year - a;
	m = month + 12 * a - 2;
	return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}


std::string dayName(short index) {
	static std::string days[7] = {
		"Sunday", "Monday", "Tuesday",
		"Wednesday", "Thursday", "Friday", "Saturday"
	};
	return days[index];
}


bool isWeekEnd(const sDate& d) {
	//weekends are sat and sun
	std::string day = dayName(calculateIndex(d.day, d.month, d.year));
	return  day == "Saturday" || day == "Sunday";
}
bool isEndOfWeek(const sDate& d) {
	return dayName(calculateIndex(d.day, d.month, d.year)) == "Friday";
}
bool isBusinessDay(const sDate& d) {
	return !isWeekEnd(d);
}
short daysUntilEndOfWeek(short dayIndex) {
	if (dayIndex >= 4) {
		return 0;
	}
	return  4 - dayIndex;
}
short calcEndWeekDays(const sDate& d) {
	return daysUntilEndOfWeek(calculateIndex(d.day, d.month, d.year));
}

short calcEndOfMonth(const sDate& d) {
	return numberOfDaysInMonthsShort(d.year, d.month) - d.day;
}

int calcEndOfYear(const sDate& d) {
	short totalDays = 0;

	for (int i = d.month; i <= 12; i++) {
		totalDays += numberOfDaysInMonthsShort(d.year, i);
	}
	return totalDays - d.day;
}


/*
===============================================================================
REFERENCE ONLY — NOT USED IN PRODUCTION
===============================================================================

The following functions were part of an earlier iterative approach and are kept
ONLY for learning and comparison purposes.

They demonstrate how date subtraction can be implemented using repeated calls
(loop-based approach), but they are intentionally NOT exposed or used because:

1) They are slower (O(n) time complexity)
2) Faster O(1) implementations exist
3) Keeping both versions public would confuse users .

Preferred approach:
- Use fast, direct calculations such as:
	decreaseDateByXYearsFaster
	decreaseDateByXDecadesFaster

These reference implementations are kept here to document the evolution of the
solution and to highlight the performance trade-offs.

-------------------------------------------------------------------------------

void decreaseDateByXYears(sDate& d, int years) {
	for (int i = 0; i < years; i++) {
		decreaseDateByOneYear(d);
	}
}

void decreaseDateByXDecades(sDate& d, int decades) {
	for (int i = 0; i < decades; i++) {
		decreaseDateByOneDecade(d);
	}
}

===============================================================================
END OF REFERENCE
===============================================================================
*/
