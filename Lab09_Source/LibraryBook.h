#include <string>

class LibraryBook {
private: 
	std::string title; 
	std::string author; 
	std::string ISBN; 
	bool is_checked_out; 

public:
	LibraryBook();
	LibraryBook(std::string _title, std::string _author, std::string _ISBN);
	~LibraryBook(); 

	std::string getTitle(); 
	std::string getAuthor(); 
	std::string getISBN(); 

	void checkOut(); 
	void CheckIn();
	bool isCheckedOut(); 
};