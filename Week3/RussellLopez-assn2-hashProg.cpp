//***************************************************************************
//  CODE FILENAME: RussellLopez-assn2-hashProg.cpp
//  DESCRIPTION:
//  CLASS TERM:    Fall 8wk2 2012
//  DATE:          11/11/2012
//  DESIGNERS:     Scott Russell and Jason Lopez
//  FUNCTIONS:     main - entry point for the program, calls to all secondary
//                      functions
//                 InitializeArrays - function initializes all dynamic arrays
//                      needed for the program
//                 DeleteArrays - function delets all dynamic arrays to free memory
//                 PopulateRandomArray - Calls GenerateNumber to get number.
//                      Runs sequential search of array to test for number if no
//                      match found, number is added to next available space.
//                      Repeats until array filled.
//                 GenerateNumber - uses cstdlib rand() and the limits of MIN_RAND
//                      and MAX_RAND to generate a random integer and return it
//                      to the calling function
//                 SearchArray - Sequential search of each member of array for
//                      matching number.  Returns false if nothing found, true
//                      if match found
//                 GetHashSize - function will prompt user for the size of the
//                      hash tables to create
//                 PopulateLinearHash - function populates array with key integers
//                      from the random array by using linear probing collision
//                      technique
//                 PopulateDoubleHash - function populates array with key integers
//                      from the random array by using double hashing collision
//                      technique
//                 PopulateChainingHash - function populates array wtih key
//                      integers from the random array by using separate chaining
//                      collision technique
//                 GetPrimryHashLocation - function uses modulo-division to
//                      determine the initial location for a key
//                 GetSecondaryHashLocation - function uses a secondary hash
//                      algorithm to deterimine an alternate position if a
//                      collision is encountered with the primary hash location
//                 InitializeNode - function initializes a node for adding to the
//                      chaining hash
//                 SearchLinear - function searches the linear hash array to find
//                      half of the integers in the random array
//                 SearchDouble - function searches the double hash array to find
//                      half of the integers in the random array
//                 SearchChaining - function searches the separate chaining hash
//                      array to find half of the integers in the random array
//                 OutputResults - function will display search results for the
//                      user
//                 DeleteNodes - function will delete chaining nodes to free up
//                      memory
//
//***************************************************************************

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

//Define Constants
const int HASH_MIN = 1;  //lower limit of random numbers
const int HASH_MAX = 30000;  // upper limit of random numbers
const int MIN_HASHSIZE = 7000;  //lowest allowed hash table size
const int ARRAY_SIZE = 5000;   //max array size

//Define Enum Types and Records
struct chainingNode{
   int key;
   chainingNode *next;
};

//Define Function Prototypes
void InitializeArrays(int randArray[], int linearHash[], int doubleHash[],
                      int chainingHash[]);

void DeleteArrays(int randArray[], int linearHash[], int doubleHash[],
                  int chainingHash[]);

void PopulateRandomArray(int randArray[]);

int GenerateNumber();

bool SearchArray(int tempNum, int randArray[], int arraySize);

int GetHashSize();

void PopulateLinearHash(int randArray[], int linearHash[]);

void PopulateDoubleHash(int randArray[], int doubleHash[]);

chainingHash** CreateChainingHash(int listSize);

void PopulateChainingHash(int randArray, int chainingHash[]);

int GetPrimaryHashLocation(int key, int listSize);

int GetSecondaryHashLocation(int key, int listSize);

chainingNode* InitializeNode(int key);

void SearchLinear(int randArray[], int linearHash[]);

void SearchDouble(int randArray[], int doubleHash[]);

void SearchChaining(int randArray[], int chainingHash[]);

void OutputResults(string searchType, int itemsExamined);

void DeleteNodes(int chainingHash[]);


//***************************************************************************
//  FUNCTION: main
//  DESCRIPTION: entry point for the program, calls to all secondary functions
//  IMPLEMENTED BY: Scott Russell
//  INPUT: None
//  OUTPUT:
//        Return Val:  0 for successful processing
//  CALLS TO:
//***************************************************************************

int main()
{
    //Define Variables
    int returnValue = 0;

    return returnValue;
}

