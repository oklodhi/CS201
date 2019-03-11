#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <vector>

// 1 month's calendar printed to output stream, with day headers
void PrintOneMonth(int Year, int StartDayNumber, std::vector<int> DaysInMonth);

// Returns name of month 
std::string GetMonthName(int MonthNumber);

// Returns days in that month & year, allowing for leap year
int DaysPerMonth(int MonthNumber, int Year); 

// Returns day of the week as int (Sun = 0, Mon = 1, etc)
int GetStartDayNumber(); 

// Returns a 4-digit number that is the year. Valid number between 1000 - 9999
int GetYear(); 

