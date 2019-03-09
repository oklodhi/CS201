#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>

// 1 month's calendar printed to output stream, with day headers
void PrintOneMonth(int MonthNumber, int Year, int StartDayNumber); 

// Returns days in that month & year, allowing for leap year
int DaysPerMonth(int MonthNumber, int Year); 

// Returns day of the week as int (Sun = 0, Mon = 1, etc)
int GetStartDayNumber(); 

// Returns a 4-digit number that is the year
int GetYear(); 

