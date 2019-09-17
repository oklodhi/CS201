#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

// opens and reads from file
void file_open_read(std::ifstream& fin, std::string finname, std::vector<std::string>& CategVec, std::vector<double>& AmtVec);

// calculates the total 
double calcTotal(std::vector<std::string>& CategVec, std::vector<double>& AmtVec, std::string str);

// calculates the mean
double calcMean(std::vector<std::string>& CategVec, std::vector<double>& AmtVec, std::string str);

// calculates the median
double calcMedian(std::vector<double>& tempVec, std::vector<std::string>& CategVec, std::vector<double>& AmtVec, std::string str);

// sorts the vectors
void SelectionSort(std::vector<double>& tempVec, std::vector<std::string>& CategVec, std::vector<double>& AmtVec, std::string str);

// opens and write to file
void file_open_write (std::ofstream& fout, std::string foutname, std::vector<std::string>& CategVec, std::vector<double>& AmtVec, std::vector<double>& tempVec);


