#include "date_utils.h"

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


void decreaseDateByXYearsFaster(sDate& d, int yearsToSub) {
	d.year -= yearsToSub;
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
