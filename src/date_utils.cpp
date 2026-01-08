#include "date_utils.h"
#include <vector>
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
int countDateDiff(sDate d1, sDate d2) {
	int counter = 0;
	while (!isSameDate(d1, d2)) {

		if (isDate1BeforeDate2(d1, d2)) {
			counter++;


			 increaseDateByOneDay(d1);

		}
		else {
			counter++;


			increaseDateByOneDay(d2);

		}
	}
	return counter;
}

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
short calculateVacationDays(sDate dateFrom, sDate dateTo) {
	short dayCounter = 0;
	while (isDate1BeforeDate2(dateFrom, dateTo)) {
		if (isBusinessDay(dateFrom)) {
			dayCounter++;
		}
		 increaseDateByOneDay(dateFrom);
	}
	return dayCounter;
}

sDate calculateVacationEndDate(sDate d, short vacationDays) {
	while (vacationDays > 0) {
		increaseDateByOneDay(d);

		if (!isWeekEnd(d)) {
			vacationDays--;
		}
	}


	return d;
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
// ==========================
// Date comparison
// ==========================


bool isSameDate(const sDate& d1,const  sDate& d2) {
	return d2.day == d1.day && d2.month == d1.month && d1.year == d2.year;
}
bool isDate1BeforeDate2(const sDate &d1, const sDate& d2) {
	if (d2.year != d1.year) {
		return d2.year > d1.year;
	}
	if (d2.month != d1.month) {
		return d2.month > d1.month;
	}

	return d2.day > d1.day;

}

bool isDate1AfterDate2(const sDate& d1,const sDate& d2) {
	return isDate1BeforeDate2(d2, d1);
}
short compareDates(const sDate& d1,const sDate& d2) {
	if (isSameDate(d1, d2)) {
		return enDateCompare::Equal;
	}
	else if (isDate1BeforeDate2(d1, d2)) {
		return enDateCompare::Before;
	}
	else {
		return enDateCompare::After;
	}
}



// ==========================
// Period utilities
// ==========================


bool isOverlap(const sPeriod& period1, const sPeriod& period2) {

	return (compareDates(period1.periodStart, period2.periodEnd) != enDateCompare::After && compareDates(period1.periodEnd, period2.periodStart) != enDateCompare::Before);

}

int calculatePeriodLength(sPeriod period, bool includeEndDay ) {
	int days = countDateDiff(period.periodStart, period.periodEnd);
	return includeEndDay ? days + 1 : days;
	
}

int countOverlapDays(sPeriod period1, sPeriod period2) {
	sDate overLapStarts;
	sDate overlapEnds;
	if (compareDates(period1.periodStart, period2.periodStart) == enDateCompare::After) {
		overLapStarts = period1.periodStart;
	}
	else {
		overLapStarts = period2.periodStart;
	}

	if (compareDates(period1.periodEnd, period2.periodEnd) == enDateCompare::Before) {
		overlapEnds = period1.periodEnd;
	}
	else {
		overlapEnds = period2.periodEnd;
	}
	if (compareDates(overLapStarts, overlapEnds) == enDateCompare::After)
		return 0;
	sPeriod overlapPeriod;
	overlapPeriod.periodStart = overLapStarts;
	overlapPeriod.periodEnd = overlapEnds;
	return calculatePeriodLength(overlapPeriod);
}

bool checkIfDateOverlap(sDate period2Starting, sPeriod period1) {
	sPeriod period2;
	period2.periodStart = period2Starting;
	period2.periodEnd = period2Starting;

	return (isOverlap(period1, period2));
}


// ==========================
// Date validation
// ==========================
bool validateDate(const sDate& d) {
	int maxDay = 0;
	if (d.month > 12 || d.month < 1) {

		return false;
	}
	maxDay = numberOfDaysInMonthsShort(d.year, d.month);


	if (d.day > maxDay || d.day < 1) {
		return false;
	}
	return true;
}

// ==========================
// String & Date conversion 
// ==========================

std::vector <std::string> split(std::string str, std::string delim ) {

	size_t pos = 0;
	std::string word = "";
	std::vector<std::string> result;
	while ((pos = str.find(delim)) != std::string::npos) {

		result.push_back(str.substr(0, pos));
		str.erase(0, pos + delim.length());
	}
	result.push_back(str);

	return result;
}

std::string convertstructDateToString(const sDate& Date)
{
	return std::to_string(Date.day) + "/" + std::to_string(Date.month) +
		"/" + std::to_string(Date.year);
}


sDate convertStringDateToStructDate(std::string date, std::string dilim ) {
	std::vector<std::string>vString = split(date, dilim);

	sDate d;
	d.day = stoi(vString[0]);
	d.month = stoi(vString[1]);
	d.year = stoi(vString[2]);
	return d;
}

// ==========================
// Date Formatting
// ==========================
std::string replaceWordInString(std::string& s1, std::string stringToReplace, std::string sRepalceTo) {
	size_t pos = s1.find(stringToReplace);
	while (pos != std::string::npos)
	{
		s1 = s1.replace(pos, stringToReplace.length(), sRepalceTo);
		pos = s1.find(stringToReplace);
	}
	return s1;
}

std::string formatDate(const sDate& d, std::string format) {

	replaceWordInString(format, "dd", std::to_string(d.day));
	replaceWordInString(format, "mm", std::to_string(d.month));
	replaceWordInString(format, "yyyy", std::to_string(d.year));
	return format;

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
