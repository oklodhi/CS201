#pragma once

#include "Employee.h"

// opens and read the input files
void open_and_read_file(vector<Employee> &EmpVec, string filename);

// opens and writes to output files
void open_and_write_file(vector<Employee> &EmpVec, string filename);