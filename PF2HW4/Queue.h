#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <iostream>
#include <vector>

using namespace std;

class Queue
{
public:
   Queue();
	Queue(const Queue& copy);
   ~Queue();
   
   void insert(const int number);
   void remove();
   
	bool isFull() const;
   bool isEmpty() const;
   int getCount() const;
   int getFront() const;

   void print() const;
   
private:
   int count;
   int front;
   vector <int> data;
};
#endif