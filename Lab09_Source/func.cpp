#include "func.h"

// opens and read books collection file
void open_and_read_file_books(std::vector<LibraryBook> &book_info_vec, std::string filename) {
	std::string line_title;
	std::string line_author;
	std::string line_isbn;

	std::ifstream fin;
	
	// try to open books.txt
	try {
		fin.open(filename);

		if (!fin) {
			throw filename;
		}
	}
	catch (std::string filename) {
		std::cout << "ERROR: " << filename << std::endl;
	}

	// read one line at a time, and store into STR
	while (!(fin.eof())) {
		std::getline(fin, line_title);
		std::getline(fin, line_author);
		std::getline(fin, line_isbn);

		// create a vector of library book and pass in vars
		book_info_vec.push_back(LibraryBook (line_title, line_author, line_isbn));
	}
}

// opens and reads ISBN file, and also prints out to the checkedOut.txt
void open_and_read_file_isbn(std::vector<std::string> &isbn_vec, std::vector<LibraryBook> &book_info_vec, std::string filename) {
	std::string line_isbn;

	std::ifstream fin;
	std::ofstream fout;

	// try and open isbn file
	try {
		fin.open(filename);

		if (!fin) {
			throw filename;
		}
	}
	catch (std::string filename) {
		std::cout << "ERROR: " << filename << std::endl;
	}

	// read one line at a time, and store into STR
	while (!(fin.eof())) {
		std::getline(fin, line_isbn);

		// check if current isbn is checked out or not
		for (int i = 0; i < book_info_vec.size(); i++) {
			if (book_info_vec.at(i).getISBN() == line_isbn) {
				if (book_info_vec.at(i).isCheckedOut()) {
					book_info_vec.at(i).CheckIn();
					break;
				}
				else {
					book_info_vec.at(i).checkOut();
					break;
				}
			}
		}
	}

	// print out checked out books to txt
	try {
		fout.open("checkedout.txt");

		if (!fout) {
			throw - 1;
		}
	}
	catch (int a) {
		std::cout << "ERROR: " << a << std::endl;
	}

	fout << "Books checked out:" << std::endl << std::endl;
	fout << "------------------" << std::endl << std::endl;
	fout << "Title\tAuthor\tISBN" << std::endl << std::endl;

	for (int i = 0; i < book_info_vec.size(); i++) {
		if (book_info_vec.at(i).isCheckedOut()) {
			fout << book_info_vec.at(i).getTitle() << "\t" << book_info_vec.at(i).getAuthor() << "\t" << book_info_vec.at(i).getISBN() << std::endl << std::endl;
		}
	}

}