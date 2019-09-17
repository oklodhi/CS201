#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <array>

// main menu loop
void main_menu(); 

// opens and reads from file 
void file_read_open(std::ifstream& fin, std::string finname, std::vector<double>& vec);

// opens and writes to a file
void file_write_open(std::ofstream& fout, std::string foutname, std::vector<double>& vec);

void file_sorted_write_open(std::ofstream& fout, std::string foutname, std::vector<double>& vec);

// calculate distance between (x1, y1, z1) to (x2, y2, z2)
double calcDistance(double x1, double y1, double z1, double x2, double y2, double z2);