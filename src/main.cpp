// 8c34To46.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "date_utils.h"




int main()
{
	// Simple demo to verify date subtraction utilities

	sDate d{ 29, 2, 2024 };

	decreaseDateByOneDay(d);
	std::cout << d.day << "/" << d.month << "/" << d.year << std::endl;

	decreaseDateByOneMonth(d);
	std::cout << d.day << "/" << d.month << "/" << d.year << std::endl;

	decreaseDateByOneYear(d);
	std::cout << d.day << "/" << d.month << "/" << d.year << std::endl;

	// Addition tests
	sDate a{ 28, 2, 2023 };
	increaseDateByOneDay(a);   // non-leap year
	std::cout << a.day << "/" << a.month << "/" << a.year << std::endl; // 1/3/2023

	sDate b{ 28, 2, 2024 };
	increaseDateByOneDay(b);   // leap year
	std::cout << b.day << "/" << b.month << "/" << b.year << std::endl; // 29/2/2024

	sDate c{ 31, 12, 2024 };
	increaseDateByOneDay(c);
	std::cout << c.day << "/" << c.month << "/" << c.year << std::endl; // 1/1/2025

	// QUERYING tests
	sDate q{ 5, 1, 2026 };

	std::cout << dayName(calculateIndex(q.day, q.month, q.year)) << std::endl;
	std::cout << isWeekEnd(q) << std::endl;
	std::cout << isBusinessDay(q) << std::endl;
	std::cout << calcEndOfMonth(q) << std::endl;
	std::cout << calcEndOfYear(q) << std::endl;


	// Business / vacation tests
	sDate from{ 1, 9, 2022 };
	sDate to{ 5, 9, 2022 };   

	std::cout << calculateVacationDays(from, to) << std::endl; 

	sDate ret = calculateVacationEndDate({ 2, 9, 2022 }, 1);
	std::cout << ret.day << "/" << ret.month << "/" << ret.year << std::endl; 

	// Period overlap test
	sPeriod p1{ {1,9,2022}, {5,9,2022} };
	sPeriod p2{ {5,9,2022}, {10,9,2022} };

	std::cout << isOverlap(p1, p2) << std::endl; 


    // --------------------------
    // Test : String <-> Date
    // --------------------------
    std::cout << "[Test 1] String <-> Date conversion\n";

    sDate d1 = convertStringDateToStructDate("10/03/2024");
    std::cout << "Day   : " << d1.day << "\n";
    std::cout << "Month : " << d1.month << "\n";
    std::cout << "Year  : " << d1.year << "\n";

    std::cout << "Back to string: "
        << convertstructDateToString(d1) << "\n\n";
    
    // --------------------------
    // Test : Date validation
    // --------------------------
    std::cout << "[Test 2] Date validation\n";

    sDate validDate{ 29, 2, 2024 };
    sDate invalidDate{ 31, 2, 2023 };

    std::cout << "29/2/2024 valid?   "
        << (validateDate(validDate) ? "Yes" : "No") << "\n";

    std::cout << "31/2/2023 valid?   "
        << (validateDate(invalidDate) ? "Yes" : "No") << "\n\n";

    // --------------------------
    // Test : Period length
    // --------------------------
    std::cout << "[Test 3] Period length\n";

    sPeriod period1{
        { 1, 3, 2024 },
        { 10, 3, 2024 }
    };

    std::cout << "Days between 1/3/2024 and 10/3/2024 (exclusive): "
        << calculatePeriodLength(period1) << "\n";

    std::cout << "Days between 1/3/2024 and 10/3/2024 (inclusive): "
        << calculatePeriodLength(period1, true) << "\n\n";


    // --------------------------
    // Test : Single date overlap
    // --------------------------
    std::cout << "\n[Test 5] Single date overlap\n";

    sDate checkDate{ 7, 3, 2024 };

    std::cout << "Does 7/3/2024 overlap period 1/10 March? "  << (checkIfDateOverlap(checkDate, p1) ? "Yes" : "No") << "\n";



    // ==========================
    //  Test Date Formatting
    // ==========================

    std::string date = "13/12/2025";
    sDate dateToFormat = convertStringDateToStructDate(date, "/");

    std::cout << "\n" << formatDate(dateToFormat, "mm/dd/yyyy") << "\n";
    std::cout << "\n" << formatDate(dateToFormat, "mm-dd-yyyy") << "\n";
    std::cout << "\n" << formatDate(dateToFormat, "dd-mm-yyyy") << "\n";
    std::cout << "\n" << formatDate(dateToFormat, "Day:dd, Month:mm,Year:yyyy") << "\n";
    std::cout << "\n==== End of Tests ====\n";
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
