#include "Book.h"

//Constructors
   Book::Book() {
      year = 0;
      title = '\0';
      firstName = '\0';
      lastName = '\0';
      genre = '\0';
      rating = 0.0;
      
   } 

//Overloaded constructor
	Book::Book(const int yearIn, const string titleIn, const string lastNameIn, const string firstNameIn, const string genreIn, const float ratingIn) {
   	year = yearIn;
   	title = titleIn;
   	firstName = firstNameIn;
   	lastName = lastNameIn;
   	genre = genreIn;
   	rating = ratingIn;
	
	}

//Destructor
	Book::~Book() {
	   
	} 

//Print method
	void Book::print() const {
	   
	   	cout << "Year released is " << year << endl << "Title is " << title << endl << "Name is " 
	   	<< firstName << lastName << endl << "Genre is " << genre << endl << "Rating is " << rating << endl;
	} 

//Copy constructor
	Book::Book(const Book& copy) {
	year = copy.year;
	title = copy.title;
	firstName = copy.firstName;    
	lastName = copy.lastName;      
	genre = copy.genre;         
	rating = copy.rating;             
	                  
	} 

//Getters
	int Book::getYear() const {
	   return year;
	} 
   string Book::getTitle() const {
      return title;
   }
	string Book::getFirstName() const {
	   return firstName;
	}
	string Book::getLastName() const {
	   return lastName;
	}
	string Book::getGenre() const {
	   return genre;
	}
	float Book::getRating() const {
	   return rating;
	}

//Setters

   void Book::setCopy(const Book& copy) {
      year = copy.year;
   	title = copy.title;
   	firstName = copy.firstName;    
   	lastName = copy.lastName;      
   	genre = copy.genre;         
   	rating = copy.rating; 
   }
   void Book::setBook(const int yearIn, const string titleIn, const string lastNameIn, const string firstNameIn, const string genreIn, const float ratingIn) {
      year = yearIn;
   	title = titleIn;
   	firstName = firstNameIn;
   	lastName = lastNameIn;
   	genre = genreIn;
   	rating = ratingIn;
   }
	void Book::setYear(const int yearIn) {
	   year = yearIn;
	} 
	void Book::setTitle(const string titleIn) {
	   title = titleIn;
	}
	void Book::setFirstName(const string firstNameIn) {
	   firstName = firstNameIn;
	}
	void Book::setLastName(const string lastNameIn) {
	   lastName = lastNameIn;
	}	
	void Book::setGenre(const string genreIn) {
	   genre = genreIn;
	}	
	void Book::setRating(const float ratingIn) {
	   rating = ratingIn;
	}