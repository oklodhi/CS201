#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

double GetMiles();

double GetGallons(); 

double GetMPG(std::vector<double> miles, std::vector<double> gallons); 