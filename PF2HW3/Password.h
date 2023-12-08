#ifndef Password_H
#define Password_H

#include <iostream>

using namespace std;

class Password {

public:

	Password(); //Constructors
	Password(const string passIn, const int rankIn, const string hashIn);

	~Password(); //Destructor

	void print() const; //Print method

	Password(const Password& copy); //Copy constructor

	string getPassword() const; //Getters
	int getRank() const;
	string getHash() const;

	void setPassword(const string passIn); //Setters
	void setRank(const int rankIn);
	void setHash(const string hashIn);

private:
	string password;
	int rank;
	string hash;
};

#endif