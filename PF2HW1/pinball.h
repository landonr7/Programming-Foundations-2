#ifndef PINBALL_H
#define PINBALL_H

#include <fstream>

using namespace std;

class Pinball {

    public:
    //Public account attributes
    
    //Constructors
    Pinball();
    Pinball(const string nameIn, const int yearIn, const string manufacturerIn, const float ratingIn, const string themeIn);
    
    //Destructor
    ~Pinball();
    
    //Print method
    void print() const;

    //Copy constructor
    Pinball(const Pinball &copy);
    
    //Getters
    string getMachineName() const;
    int getYearProduced() const;
    string getManufacturer() const;
    float getFunRating() const;
    string getTheme() const;
    
    //Setters
    void setMachineName(const string nameIn);
    void setYearProduced(const int yearIn);
    void setManufacturer(const string manufacturerIn);
    void setFunRating(const float ratingIn);
    void setTheme(const string themeIn);
    
    private:
    string machineName;
    int yearProduced;
    string manufacturer;
    float funRating;
    string theme;
};

#endif