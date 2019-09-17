// Omer Khan
// mokddp@mail.umkc.edu	
// March 21
// CS201L Lab 09

#include "func.h"


int main() {
	const std::string BOOKS_FILE = "books.txt";
	const std::string ISBN_FILE = "isbns.txt";

	std::vector<LibraryBook> book_info_vec;
	std::vector<std::string> isbn_vec;

	open_and_read_file_books(book_info_vec, BOOKS_FILE);
	open_and_read_file_isbn(isbn_vec, book_info_vec ,ISBN_FILE);
}