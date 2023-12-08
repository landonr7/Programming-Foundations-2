#include "pinball.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <string>

//Deafult constructor
Pinball::Pinball() {
    // machineName = "";
    // yearProduced = 0;
    // manufacturer = "";
    // funRating = 0.0;
    // theme = "'\0'";
}

//Constructor
Pinball::Pinball(const string nameIn, const int yearIn, const string manufacturerIn, const float ratingIn, const string themeIn) {
    machineName = nameIn;
    yearProduced = yearIn;
    manufacturer = manufacturerIn;
    funRating = ratingIn;
    theme = themeIn;
}

//Copy constructor
Pinball::Pinball(const Pinball & copy) {
    machineName = copy.machineName;
    yearProduced= copy.yearProduced;
    manufacturer = copy.manufacturer;
    funRating = copy.funRating;
    theme = copy.theme;
    
}

//Destructor
Pinball::~Pinball() {
    
}

//Print method
void Pinball::print() const {
    cout << "Machine name: " << getMachineName() << endl;
    cout << "Year produced: " << getYearProduced() << endl;
    cout << "Manufacturer: " << getManufacturer() << endl;
    cout << "Fun rating: " << fixed << setprecision(2) << getFunRating() << endl;
    cout << "Theme:" << getTheme() << endl << endl;
}

//Getters
string Pinball::getMachineName() const {
    
    return machineName;
}

int Pinball::getYearProduced() const {
    
    return yearProduced;
}

string Pinball::getManufacturer() const {
    
    return manufacturer;
}

float Pinball::getFunRating() const {
    
    return funRating;
}

string Pinball::getTheme() const {
    
    return theme;
}

//Setters
void Pinball::setMachineName(const string nameIn) {
    
    machineName = nameIn;
}

void Pinball::setYearProduced(const int yearIn) {
    
    yearProduced = yearIn;
}

void Pinball::setManufacturer(const string manufacturerIn) {
    
    manufacturer = manufacturerIn;
}

void Pinball::setFunRating(const float ratingIn) {
    
    funRating = ratingIn;
}

void Pinball::setTheme(const string themeIn) {
    
    theme = themeIn;
}