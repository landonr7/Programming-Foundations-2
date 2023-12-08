#include "Stack.h"

//Constructor
Stack::Stack() {
   
   count = 0;
}

//Copy constructor
Stack::Stack(const Stack& copy) {

   count = copy.count;
}

//Destructor
Stack::~Stack() {
   
}

//Push method
void Stack::push(const int number) {

   data.push_back(number);
   count++;
}

//Pop method
void Stack::pop() {
   
   if(isEmpty()) {
   
      cout << "Stack is empty or something I think" << endl;
      return;
   }
   
   data.erase(data.begin());
   count--;
}

//Top method
void Stack::top() const {
  cout << data[0] << " is the top... or something" << endl;
  
}

//Full method
bool Stack::isFull() const {
   
   return false;
}

//Empty method
bool Stack::isEmpty() const {
   
   return count == 0;
}

//Count method
int Stack::getCount() const {
   
   return count;
}

//Print method
void Stack::print() const {
   
   if (isEmpty()) {
      
      cout << "Stack is empty I'm pretty sure" << endl;
      return;
   }
   
   cout << "Printing the stack... I guess..." << endl;
   
   for(int i = 0; i < count; i++) {
      
      cout << i << ". " << data[i] << "\n";
   }

   cout << endl;
}
