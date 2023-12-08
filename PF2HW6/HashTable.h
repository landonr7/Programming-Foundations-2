#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "StudentList.h"

class HashTable {
   public:
   
      //Constructor
      HashTable(int tableSizeIn);
      
      //Destructor
      ~HashTable();
      
      //Insert function
      void insertHT(string key, string country, string city, string gender, float gpa);
      
      //Remove function
      void removeHT(string key);
      
      //Update function
      void updateHT(string key, string country, string city, string gender, float gpa);
      
      //Search function
      StudentNode* searchHT(string key);
      
      //Getters
      int getCount();
      int getColl();
      int getSize();
      
      //Print function
      void printHT() const;
   
   private:
   
      int tableSize;
      StudentList* hashTable;
      int countHash;
      int collisionHash;

      
      //Hash Function
      int hashFunction(string key);
    
};

#endif