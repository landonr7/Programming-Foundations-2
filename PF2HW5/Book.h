#ifndef Book_H
#define Book_H

#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

class Book {
   
public:
   
   Book(); //Constructors
	Book(const int yearIn, const string titleIn, const string firstIn, const string lastIn, const string genreIn, const float ratingIn);

	~Book(); //Destructor

	void print() const; //Print method

	Book(const Book& copy); //Copy constructor

	int getYear() const; //Getters
   string getTitle() const;
	string getFirstName() const;
	string getLastName() const;
	string getGenre() const;
	float getRating() const;


   void setCopy(const Book & copy);//Setters
   void setBook(const int yearIn, const string titleIn, const string lastNameIn, const string firstNameIn, const string genreIn, const float ratingIn);
	void setYear(const int yearIn); 
	void setTitle(const string titleIn);
	void setFirstName(const string firstNameIn);
	void setLastName(const string lastNameIn);	
	void setGenre(const string genreIn);	
	void setRating(const float ratingIn);
   
private:
   int year;
   string title;
   string lastName;
   string firstName;
   string genre;
   float rating;
};

#endif