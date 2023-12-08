#include "Password.h"

Password::Password() //Constructor
{
	password = '\0';
	rank = 0;
	hash = '\0';

}

Password::Password(const string passwordIn, const int rankIn, const string hashIn) //Default constructor
{
	password = passwordIn;
	rank = rankIn;
	hash = hashIn;

}

Password::~Password() //Destructor
{


}

void Password::print() const //Print method
{
	cout << password << "," << rank << "," << hash << endl;

}

Password::Password(const Password& copy)  //Copy constructor
{
	password = copy.password;
	rank = copy.rank;
	hash = copy.hash;

}

string Password::getPassword()const  //Getters
{
	return password;

}
int Password::getRank() const
{
	return rank;

}
string Password::getHash() const
{
	return hash;

}

void Password::setPassword(const string passwordIn)  //Setters
{
	password = passwordIn;

}
void Password::setRank(const int rankIn)
{
	rank = rankIn;

}
void Password::setHash(const string hashIn)
{
	hash = hashIn;

}