#include "RestaurantNode.h"

class RestaurantList {
    
    public:
    
    RestaurantList(); //Default constructor
    RestaurantList(const RestaurantList & copy); //Copy constructor
    ~RestaurantList(); //Destructor
    
    void addMeal(); //Add meal function
    void highestPrice(); //Expensive meal function
    void changePrice(); //Change price function
    void printL(); //Print function
    
    
    
    private:
    
    RestaurantNode * head; //Declaring head pointer for restaurant node
    RestaurantNode * tail; //Declaring tail pointer for restaurant node
    void insertHead(const string restNameIn, const float restRatingIn, const string mealIn, const string mealTypeIn, const float priceIn); //Insert head function
    
};