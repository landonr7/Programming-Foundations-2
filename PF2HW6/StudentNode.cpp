#include "StudentNode.h"
#include <iomanip>

using namespace std;
   
// Default constructor
StudentNode::StudentNode() {
   key = "";
   country = "";
   city = "";
   gender = "";
   gpa = 0.0;
   Next = NULL;
}

// Overloaded setter constructor
StudentNode::StudentNode(string const keyIn, string const countryIn, string const cityIn, string const genderIn, float const gpaIn) {
   key = keyIn;
   country = countryIn;
   city = cityIn;
   gender = genderIn;
   gpa = gpaIn;
   Next = NULL;
}

// Overloaded steer constructor w pointer
StudentNode::StudentNode(string const keyIn, string const countryIn, string const cityIn, string const genderIn, float const gpaIn, StudentNode* const next) {
   key = keyIn;
   country = countryIn;
   city = cityIn;
   gender = genderIn;
   gpa = gpaIn;
   Next = next;
}

// Copy constructor
StudentNode::StudentNode(const StudentNode& copy) {
   key = copy.key;
   country =copy.country;
   city = copy.city;
   gender = copy.gender;
   gpa = copy.gpa;
   Next = copy.Next;
}

// Print method
void StudentNode::printN() const {
   cout << "Full Name: " << key << endl;
   cout << "Country: " << country << endl;
   cout << "City: " << city << endl;
   cout << "Gender: " << gender << endl;
   cout << "GPA: " << gpa << endl << endl;
}

// Destructor
StudentNode::~StudentNode() {}

// Setter methods
void StudentNode::setKey(string keyIn) {
   key = keyIn; 
   
}      
void StudentNode::setCountry(string countryIn) {
   country = countryIn; 
   
}
void StudentNode::setCity(string cityIn) {
   city = cityIn; 
   
}
void StudentNode::setGender(string genderIn) {
   gender = genderIn; 
   
}
void StudentNode::setGpa(float gpaIn) {
   gpa = gpaIn; 
   
}
void StudentNode::setNext(StudentNode* next) {
   Next = next; 
   
}

// Getter methods
string StudentNode::getKey() const {
   return key; 
   
}      
string StudentNode::getCountry() const {
   return country; 
   
}
string StudentNode::getCity() const {
   return city; 
   
}
string StudentNode::getGender() const {
   return gender; 
   
}
float StudentNode::getGpa() const {
   return gpa; 
   
}
StudentNode* StudentNode::getNext() const {
   return Next; 
   
}
