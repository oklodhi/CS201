#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "LibraryBook.h"


// opens and read books collection file
void open_and_read_file_books(std::vector<LibraryBook> &book_info_vec, std::string filename);

// opens and reads ISBN file, and also prints out to the checkedOut.txt
void open_and_read_file_isbn(std::vector<std::string> &isbn_vec, std::vector<LibraryBook> &book_info_vec, std::string filename);