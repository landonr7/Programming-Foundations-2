#ifndef RestaurantNode_H
#define RestaurantNode_H

#include <iostream>

using namespace std;

class RestaurantNode {

    public: //Public account attributes
    
    RestaurantNode(); //Constructors
    RestaurantNode(const string restNameIn, const float restRatingIn, const string mealIn, const string mealTypeIn, const float priceIn);
    RestaurantNode(const string restNameIn, const float restRatingIn, const string mealIn, const string mealTypeIn, const float priceIn, RestaurantNode* next);
    RestaurantNode(const string restNameIn, const float restRatingIn, const string mealIn, const string mealTypeIn, const float priceIn, RestaurantNode* next, RestaurantNode* prev);


    
    ~RestaurantNode(); //Destructor
    
    
    void printN() const; //Print method

    
    RestaurantNode(const RestaurantNode &copy); //Copy constructor
    
    
    string getRestName() const; //Getters
    float getRestRating() const;
    string getMeal() const;
    string getMealType() const;
    float getPrice() const;
    RestaurantNode * getNext() const;
    RestaurantNode * getPrev() const;

    
    
    void setRestName(const string restNameIn); //Setters
    void setRestRating(const float restRatingIn);
    void setMeal(const string mealIn);
    void setMealType(const string mealTypeIn);
    void setPrice(const float priceIn);
    void setNext(RestaurantNode * next);
    void setPrev(RestaurantNode * prev);

    
    private: //Private account attributes
    
    string restName;
    float restRating;
    string meal;
    string mealType;
    float price;
    RestaurantNode* Next;
    RestaurantNode* Prev;
};

#endif