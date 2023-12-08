#include "RestaurantList.h"


RestaurantList::RestaurantList() { //Default constructor methods
    
    head = NULL;
}

RestaurantList::RestaurantList(const RestaurantList & copy) { //Copy constructor methods
    
    RestaurantNode * temp = copy.head;
    while(temp != NULL) {
        
        temp = temp->getNext();
    }
    
}
RestaurantList::~RestaurantList() { //Destructor methods
    
    RestaurantNode * temp = head;
    while(temp != NULL) {
        
        head = head->getNext();
        delete temp;
        temp = NULL;
        temp = head;
    }
    
}

void RestaurantList::insertHead(string restNameIn, float restRatingIn, string mealIn, string mealTypeIn, float priceIn) { //Insert head function methods
    
    RestaurantNode * temp = new RestaurantNode(restNameIn, restRatingIn, mealIn, mealTypeIn, priceIn, head);
    if(head == NULL) {
        
        tail = temp;        
    }
    else {
        
        head->setPrev(temp);        
    }
    head = temp;
}

void RestaurantList::addMeal() { //Add meal function methods
    
    string restNameIn = "";
    float restRatingIn = 0.0;
    string mealIn = "";
    string mealTypeIn = "";
    float priceIn = 0.0;
    
    string temp = "";
    
    cout << "What is the Restaurant's name?" << endl;
    cin >> restNameIn;
    getline(cin, temp);
    restNameIn += temp;
    
    cout << "What is the Restaurant's rating?" << endl;
    cin >> restRatingIn;
    
    cout << "What is the meal's name?" << endl;
    cin >> mealIn;
    getline(cin, temp);
    mealIn += temp;    
    
    cout << "What is the type of the meal?" << endl;
    cin >> mealTypeIn;
    getline(cin, temp);
    mealTypeIn += temp;
    
    cout << "What is the meal's price?" << endl;
    cin >> priceIn;
    
    insertHead(restNameIn, restRatingIn, mealIn, mealTypeIn, priceIn);
    
}

void RestaurantList::highestPrice() { //Expensive meal function methods
    
    RestaurantNode * temp = head;
    float num = temp->getPrice();
    
    while (temp != NULL) {
        
        if (temp->getPrice() > num) {
            
            num = temp->getPrice();
        }
        
        temp = temp->getNext();
    }
    
    cout << "Most expensive meal: $" << num << endl << endl;
}

void RestaurantList::changePrice() { //Change price function methods
    
    string pmet = "";
    string food = "";
    
    cout << "What meal would you like to change the price of?" << endl;
    cin >> food;
    getline(cin, pmet);
    food += pmet;
    
    float price = 0.0;
    RestaurantNode * temp = head;
    
    while (temp != NULL) {
        
        if (temp->getMeal() == food) {
            
            cout << "Insert a new price for the meal:" << endl;
            cin >> price;
            temp->setPrice(price);
            break;    
        }
        temp = temp->getNext();
    }

}

void RestaurantList::printL() { //Print function methods
    
    RestaurantNode * temp = head;
    
    while (temp != NULL) {
        
        temp->printN();
        temp = temp->getNext();
    }
}

