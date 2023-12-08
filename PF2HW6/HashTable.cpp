#include "HashTable.h"

//Default Constructor
HashTable::HashTable(int tableSizeIn) {
    
   tableSize = tableSizeIn;   
   collisionHash = 0;
   countHash = 0;
   hashTable = new StudentList[tableSize];
}

//Destructor (empty)
HashTable::~HashTable() {

}

//Insert function
void HashTable::insertHT(string key, string country, string city, string gender, float gpa) {
   countHash++;
   int hashIndex = hashFunction(key);
   if(hashTable[hashIndex].isEmpty() == 0) {
      collisionHash++;
   }
   hashTable[hashIndex].insertL(key, country, city, gender, gpa);
}

//Delete function
void HashTable::removeHT(string key) {
   countHash--;
   int hashIndex = hashFunction(key);
   hashTable[hashIndex].removeL(key);
}

//Update function 
void HashTable::updateHT(string key, string country, string city, string gender, float gpa) {
    
   int hashIndex = hashFunction(key);
   hashTable[hashIndex].updateL(key, country, city, gender, gpa);
}

//Search Function
StudentNode* HashTable::searchHT(string key) {
   
   int hashIndex = hashFunction(key);
   cout << "Index is: " << hashIndex << endl;
   
   return hashTable[hashIndex].searchL(key);
}

//Getters
int HashTable::getCount() {
   return countHash; 
   
}
int HashTable::getColl() {
   return collisionHash; 
}
int HashTable::getSize() {
   return tableSize; 
}

//Print function
void HashTable::printHT() const {
    
   for (int i = 0; i < tableSize; i++) {
        
      if (!hashTable[i].isEmpty()) {
    
         cout << "Hash Index: " << i << endl;
         hashTable[i].printL();
      }
   }
}

//Hash function
int HashTable::hashFunction(string key) {
    
   int num = 887;
    
   for (int i = 0; i < key.length(); i++) {
        
      num += (19 * key[i] + 7);
   }
    
   return num % tableSize;
}