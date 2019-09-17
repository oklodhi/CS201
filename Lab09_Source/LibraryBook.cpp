#include "LibraryBook.h"

LibraryBook::LibraryBook() {
	title = ""; 
	author = ""; 
	ISBN = "";
	is_checked_out = false; 
}

LibraryBook::LibraryBook(std::string _title, std::string _author, std::string _ISBN) {
	title = _title;
	author = _author; 
	ISBN = _ISBN;
	is_checked_out = false;
}

LibraryBook::~LibraryBook() {

}

std::string LibraryBook::getTitle() {
	return title;
}

std::string LibraryBook::getAuthor() {
	return author;
}

std::string LibraryBook::getISBN() {
	return ISBN;
}

void LibraryBook::checkOut() {
	is_checked_out = true;
}

void LibraryBook::CheckIn() {
	is_checked_out = false;
}

bool LibraryBook::isCheckedOut() {
	return is_checked_out;
}