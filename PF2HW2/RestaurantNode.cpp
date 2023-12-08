#include "RestaurantNode.h"
// #include <iostream>
// #include <iomanip>
// #include <cmath>
// #include <fstream>
// #include <cstdlib>
// #include <string>

//Default Constructor
RestaurantNode::RestaurantNode() {
    restName = "";
    restRating = 0.0;
    meal = "";
    mealType = "";
    price = 0.0;
    Next = NULL; 
    Prev = NULL;
    
}

//Constructor
RestaurantNode::RestaurantNode(const string restNameIn, const float restRatingIn, const string mealIn, const string mealTypeIn, const float priceIn) {
    restName = restNameIn;
    restRating = restRatingIn;
    meal = mealIn;
    mealType = mealTypeIn;
    price = priceIn;
    Next = NULL;
    Prev = NULL;
    
}

RestaurantNode::RestaurantNode(const string restNameIn, const float restRatingIn, const string mealIn, const string mealTypeIn, const float priceIn, RestaurantNode* next) {
    restName = restNameIn;
    restRating = restRatingIn;
    meal = mealIn;
    mealType = mealTypeIn;
    price = priceIn;
    Next = next;
    Prev = NULL;
}

RestaurantNode::RestaurantNode(const string restNameIn, const float restRatingIn, const string mealIn, const string mealTypeIn, const float priceIn, RestaurantNode* next, RestaurantNode* prev) {
    restName = restNameIn;
    restRating = restRatingIn;
    meal = mealIn;
    mealType = mealTypeIn;
    price = priceIn;
    Next = next;
    Prev = prev;
}

//Destructor
RestaurantNode::~RestaurantNode() {
    
}

//Print method
void RestaurantNode::printN() const {
    
    cout << "Restaurant name: " << restName << endl;
    cout << "Restaurant rating: " << restRating << endl;
    cout << "Meal: " << meal << endl;
    cout << "Meal type: " << mealType << endl;
    cout << "Price: $" << price << endl << endl;
    
}

//Copy constructor
RestaurantNode::RestaurantNode(const RestaurantNode & copy) {
    restName = copy.restName;
    restRating = copy.restRating;
    meal = copy.meal;
    mealType = copy.mealType;
    price = copy.price;
    Next = copy.Next;
    Prev = copy.Prev;
}

//Getters
string RestaurantNode::getRestName() const {
    
    return restName;
}

float RestaurantNode::getRestRating() const {
    
    return restRating;
}

string RestaurantNode::getMeal() const {
    
    return meal;
}

string RestaurantNode::getMealType() const {
    
    return mealType;
}

float RestaurantNode::getPrice() const {
    
    return price;
}

RestaurantNode* RestaurantNode::getNext() const {
    
    return Next;
}

RestaurantNode* RestaurantNode::getPrev() const {
    
    return Prev;
}


//Setters
void RestaurantNode::setRestName(const string restNameIn) {
    restName = restNameIn;
}

void RestaurantNode::setRestRating(const float restRatingIn) {
    restRating = restRatingIn;
}

void RestaurantNode::setMeal(const string mealIn) {
    meal = mealIn;
}

void RestaurantNode::setMealType(const string mealTypeIn) {
    mealType = mealTypeIn;
}

void RestaurantNode::setPrice(const float priceIn) {
    price = priceIn;
}

void RestaurantNode::setNext(RestaurantNode* next) {
    Next = next;
}

void RestaurantNode::setPrev(RestaurantNode* prev) {
    Prev = prev;
}
