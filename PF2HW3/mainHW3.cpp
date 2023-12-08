#include "Password.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <time.h>

using namespace std;

void printMenu() { //Print menu function

    cout << "Pick an option:" << endl << "----------------------------------------------------------------------------" << endl
        << "1.) Search recursively two passwords and pull all the passwords between them" << endl
        << "2.) Search recursively for password" << endl
        << "3.) Search recursively of given file by hash" << endl
        << "4.) Compare linear and binary search" << endl
        << "5.) Iterative search for password" << endl
        << "6.) Exit the program" << endl << "----------------------------------------------------------------------------" << endl;
}

char getChoice() {
    char c = ' ';
    while (cout << "Enter menu selection:\n" && cin >> c && (c < '1' || c > '6'))
        cout << "Error: invalid input. Please try again.\n";
    return c;
}

// PROVIDED
bool readFile(string filename, vector<Password>& list)
{
    string password;
    string rank;
    string hash;

    ifstream din;
    din.open(filename);
    if (din.fail()) {
        cout << "Error in opening file.\n";
        return 0;
    }
    while (getline(din, password, ','))
    {
        getline(din, rank, ',');
        getline(din, hash);
        Password temp(password, stoi(rank), hash);
        list.push_back(temp);
    }
    din.close();
    return 1;
}
// PROVIDED
bool readFile_given_hashes(string filename, vector<string>& list)
{
    string hash;

    ifstream din;
    din.open(filename);
    if (din.fail()) {
        cout << "Error in opening file.\n";
        return 0;
    }
    while (getline(din, hash)) {
        list.push_back(hash);
    }
    return 1;
}

int binarySearch(vector<Password> password, string& userPassword, int high, int low, int& counterB) //Binary search function
{
    int mid = (high + low) / 2;

    // check termination condition
    if (high < low)
    {
        return -1; //not found
    }
    else if (userPassword == password[mid].getPassword())
    {
        counterB = counterB + 1;
        return mid; //found
    }
    // handle recursive case
    else if (userPassword > password[mid].getPassword())
    {
        counterB = counterB + 1;
        int temp1 = mid + 1;
        return binarySearch(password, userPassword, high, temp1, counterB);
    }
    else
    {
        counterB = counterB + 1;
        int temp2 = mid - 1;
        return binarySearch(password, userPassword, temp2, low, counterB);
    }

}

int hashSearch(int userHash, int low, int high, vector<Password> hash)
{
    int mid3 = (high + low) / 2;
    int temp3 = stoi(hash[mid3].getHash(), 0, 16);
    
    if (low > high)
    {
        return -1;
    }
    if (userHash == temp3)
    {
        return mid3;
    }
    else if (userHash > temp3)
    {
        int temph = mid3 + 1;
        return hashSearch(userHash, temph, high, hash);
    }
    else
    {
        int tempg = mid3 - 1;
        return hashSearch(userHash, low, tempg, hash);
    }

}

int linearSearch(vector<Password>& password, string userPassword) //Linear search function
{
    int size = password.size();

    for (int i = 0; i < size; i++)
    {

        if (password[i].getPassword() == userPassword)
        {
            return i;
        }


    }
    return -1;
}

int iterativeSearch(vector<Password>& password, const string userPassword, int high, int low)
{
    while (low <= high) {
        int mid2 = (high + low) / 2;
        if (userPassword == password[mid2].getPassword())
        {
            return mid2;
        }
        else if (userPassword < password[mid2].getPassword()) {
            high = mid2 - 1;
        }
        else {
            low = mid2 + 1;
        }
    }
    cout << "Password is not found.";
    return -1;
}

//----------------------------------------------
int main()
{
    //vector for hash sorted file
    vector<Password> hash;
    //vector for password sorted file
    vector<Password> password;
    //vector for hashes to search for
    vector<string> given_hashes;
    //vector for plaintext passwords
    vector<Password> plaintext;
    //vector for hash values
    vector<Password> hash_values;
    //vector for hashes
    vector<string> recieved_hashes;

    int passIndex;
    int passIndex1;
    int passIndex2;

    int counterB = 0;

    string userPassword = "\0";

    readFile("sorted_hash_indexed_list.txt", hash);
    readFile("sorted_password_indexed_list.txt", password);
    readFile_given_hashes("hashes_to_search.txt", given_hashes);

    int low = 0;
    int high = password.size() - 1;

    int hashSize = given_hashes.size();
 
    char c = '0';
    do { //Do while function for input

        printMenu();

        c = getChoice();

        switch (c)
        {

        case '1': //Search for a range of passwords

            cout << "Enter the first password:" << endl;
            cin >> userPassword;

            passIndex1 = binarySearch(password, userPassword, high, low, counterB);

            if (passIndex1 == -1)
            {
                cout << "Password not found." << endl;
                break;
            }

            cout << "Enter second password:" << endl;
            cin >> userPassword;

            passIndex2 = binarySearch(password, userPassword, high, low, counterB);

            if (passIndex2 == -1)
            {
                cout << "Password not found" << endl;
                break;
            }

            int start;
            int end;

            if (passIndex1 < passIndex2)
            {
                start = passIndex1;
                end = passIndex2;
            }
            else 
            {
                start = passIndex2;
                end = passIndex1;
            }

            for (int i = start; i <= end; i++)
            {
                password[i].print();
            }

            break;

        case '2': //Binary search for a password

            cout << "Enter the password you like to search:" << endl;
            cin >> userPassword;

            passIndex = binarySearch(password, userPassword, high, low, counterB);

            if (passIndex == -1)
            {
                cout << "Password not found." << endl;
                break;
            }

            cout << "Found at index: " << passIndex << endl;
            password[passIndex].print();
            cout << "Indexes visited: " << counterB << endl;

            break;

        case '3': //Binary search for hashes

            for (int i = 0; i < hashSize; i++)
            {

                int conv = stoi(given_hashes[i], 0, 16);
                int hashIndex = hashSearch(conv, 0, hash.size() - 1, hash);

                if (hashIndex != -1)
                {
                    cout << given_hashes[i] << " was found." << endl;
                }
                else
                {
                    cout << given_hashes[i] << " was not found." << endl;
                }
            }

            break;

        case '4': //
            cout << "Enter the password you like to search:" << endl;
            cin >> userPassword;

            passIndex1 = linearSearch(password, userPassword);

            if (passIndex1 == -1)
            {
                cout << "Password not found." << endl;
                break;
            }

            password[passIndex1].print();
            cout << "Took this many linear iterations to find: " << passIndex1 + 1 << endl;

            passIndex2 = binarySearch(password, userPassword, high, low, counterB);

            if (passIndex2 == -1)
            {
                cout << "Password not found." << endl;
                break;
            }

            password[passIndex2].print();
            cout << "Took this many binary iterations to find: " << counterB << endl;

            break;

        case '5':

            cout << "Enter the password you like to search:" << endl;
            cin >> userPassword;

            passIndex = iterativeSearch(password, userPassword, high, low);
            if (passIndex == -1)
            {
                cout << "Password not found." << endl;
                break;
            }

            password[passIndex].print();

            break;

        case '6': //Exits program
            
            cout << "The program ran successfully, have a nice night." << endl;

            return 0;

        default:

            cout << "Enter a valid input." << endl;
        }

    } while (c != 6);


    return 0;
}
