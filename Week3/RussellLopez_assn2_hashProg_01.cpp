//***************************************************************************
//  CODE FILENAME: RussellLopez-assn2-hashProg.cpp
//  DESCRIPTION:
//  CLASS TERM:    Fall 8wk2 2012
//  DATE:          11/11/2012
//  DESIGNERS:     Scott Russell and Jason Lopez
//  FUNCTIONS:     main - entry point for the program, calls to all secondary
//                      functions
//                 InitializeHashArrays - calls GetHash size to receive listSize of all dynamic arrays
//                      function then initializes all dynamic arrays and passes then
//                      all with reference return of listSize variable
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
//                 OutputHeader  - Outputs array size, list size, and load factor
//                 OutputChainedResult
//                 OutputLinearResult
//                 OutputDoubleResult
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

//Finished or Roughly So
void PopulateRandomArray(int[]); // OK
int GenerateNumber(); //OK
bool SearchArray(int, const int[], int); //OK : randArray made const
int GetHashSize(); //OK
void InitializeHashArrays(int*, int*, int&); // !! randArray[] initialized in main, do we need it?
chainingNode** CreateChainingHash(int); //OK: basically initializes my pointer to pointers
chainingNode* InitializeNode(int); //OK

       // **********Lets put all of our PopulateXX functions here*********
int GetPrimaryHashLocation(int, int); //OK
void PopulateChainingHash(const int[], chainingNode**, int); // !! Made array const, double check


//Search functions next
void SearchChaining(const int[], chainingNode**, int, float); // !!OK but Still unsure of double pointers


   //Yet to be touched***************************************************
//void PopulateLinearHash(int randArray[], int linearHash[]);
//void PopulateDoubleHash(int randArray[], int doubleHash[]);
//int GetSecondaryHashLocation(int key, int listSize);
   //Search Functions
//void SearchLinear(int randArray[], int linearHash[]);
//void SearchDouble(int randArray[], int doubleHash[]);

//Output and Wrap-up
float OutputHeader(int listSize);
void OutputChainedResult(float, int);
void OutputLinearResult(float, int);
void OutputDoubleResult(float, int);
//void OutputResults(string searchType, int itemsExamined);
//void DeleteArrays(int[], int*, int*);  // !!Do we need randArray? do we need to delete it?
//void DeleteNodes(int chainingHash[]);


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
    int randArray[ARRAY_SIZE];
    int *linearHash;   //hash table used for Linear
    int *doubleHash;   //hash table used for Double Hashing
    chainingNode **chainingHash;  // hash table used for Separate Chaining
    int listSize;
    float loadFactor; //ratio of array size to hash size: used to determine efficiency of hash collision

    //Fill array with random numbers from 1-30000
    PopulateRandomArray (randArray);

    //Create 3 Hash Tables: Linear, Double, Separate
    InitializeHashArrays (linearHash, doubleHash, listSize);
    chainingHash = CreateChainingHash (listSize);

    //Sequential Input and Collision Resolution on each list
    PopulateChainingHash(randArray, chainingHash, listSize);

    //Display results
    loadFactor = OutputHeader(listSize);
    SearchChaining (randArray, chainingHash, listSize, loadFactor);  // search nodes and display avg results

// //TEST1: RANDOMARRAY PRINT (first 100 elements)
//   // print first 100 array elements at 10 per line
//    int idx = 1;
//    int numPerLine = 0;
//    cout << endl << endl;
//    cout << "Test print: display 100 random numbers from main array:" << endl;
//    while (idx < 100){
//        cout << setw(7) << randArray[idx];
//        if (idx % 10 == 0)
//            cout << endl;
//        idx++;
//    }
// //END TEST1*************************************

    return 0;
} // end main

//FUNCTIONS:

//***************************************************************************
//  FUNCTION: PopulateRandomArray
//  DESCRIPTION: Calls GenerateNumber to get number. Runs sequential search of
//               array to test for number if no match found, number is added to
//               next available space. Repeats until array filled.
//  IMPLEMENTED BY: Scott Russell
//  INPUT:
//        Parameters: randArray - reference array to contain all random numbers
//                    to be used as the key values for the program
//  OUTPUT:
//        Parameters: randArray - reference return of populated array
//  CALLS TO: GenerateNumber, SearchArray
//***************************************************************************
void PopulateRandomArray(int randArray[])
{
    int idx = 0;   //count of array spaces filled
    int tempNum;    // number returned from GenerateNumber and tested in array

    //populate first array space
    tempNum = GenerateNumber();  //add one number to array (no need to search for match)
    randArray[idx] = tempNum;
    idx = 1;

    // Now loop to 5000 generating numbers and searching array for them ...
       // add if unique
    while (idx < ARRAY_SIZE)
    {
        tempNum = GenerateNumber();  //get a random number
        if(!SearchArray(tempNum, randArray, idx)){   // if there is no match
            randArray[idx] = tempNum;      //place it in the array
            idx++;  //increment to next space in array
        } // end if: new unique random number
    } // end while: fill all array spaces

    return;
} // end PopulateRandomArray

//***************************************************************************
//  FUNCTION: GenerateNumber
//  DESCRIPTION: uses cstdlib rand() and the limits of MIN_RAND and MAX_RAND to
//               generate a random integer and return it to the calling function
//  IMPLEMENTED BY: Scott Russell
//  INPUT:
//        Parameters: None
//  OUTPUT:
//        Return Val: random integer
//  CALLS TO: None
//***************************************************************************
int GenerateNumber()
{
	int num; //number will randomly be generated and returned

	num = rand() % ((HASH_MAX + HASH_MIN) - HASH_MIN) + HASH_MIN;

    return num;
} // end GenerateNumber

//***************************************************************************
//  FUNCTION: SearchArray
//  DESCRIPTION: Sequential search of each member of array for matching number.
//               Returns false if nothing found, true if match found
//  IMPLEMENTED BY: Scott Russell
//  INPUT:
//        Parameters: tempNum - integer to search for
//                    randArray - reference array to be searched
//                    arraySize - size of the array to be searched
//  OUTPUT:
//        Return Val: bool - true if integer is found, false if integer is not
//                           found in the array
//  CALLS TO: None
//****************************************************************************
bool SearchArray(int tempNum, const int randArray[], int lastPosition)
{
    bool found = false;
    int loc = 0;   // location in randomArray to check for duplicate

    //search each member of array for matching number
    while (loc < lastPosition && (!found)) //last position is the last filled place of array
        if (randArray[loc] == tempNum)
            found = true;
        else
            loc++;

    return found;
} // end SearchArray

//***************************************************************************
//  FUNCTION: GetHashSize
//  DESCRIPTION: function will prompt user for the size of the hash tables to create
//  IMPLEMENTED BY: Scott Russell
//  INPUT:
//        Parameters: None
//  OUTPUT:
//        Return Val: int - size of the hash tables
//  CALLS TO: None
//***************************************************************************
int GetHashSize ()
{
    int listSize;   //size of hash table
    //Prompt for number: read number and loop until valid
    cout << "Enter size of hash table (at least 7000): ";
    do{
        cin >> listSize;
        if (listSize < MIN_HASHSIZE){ //NOTE* int limit is: 2147483647, TEST THIS???
            cout << "Invalid input:" << endl;
            cout << "   Number must be above 7000. Try again: ";
        } // end if hashize invalid
    } while (listSize < MIN_HASHSIZE);// end do:while validate hashize input

    return listSize;

} // end CreateHashTable

//***************************************************************************
//  FUNCTION: InitializeHashArrays
//  DESCRIPTION: function initializes all dynamic arrays needed for the program
//  IMPLEMENTED BY: Scott Russell
//  INPUT:
//        Parameters: linearHash - int pointer to be initialized dynamic hash table array
//                    doubleHash - int pointer to be initialized to dynamic hash table array
//                    listSize  - integer size of hash tables for each array
//
//  OUTPUT:
//        Return Val: linearHash - initialized dynamic int array of listSize
//                    doubleHash - initialized dyanimc int array of listSize
//                    listSize - ref return of integer variable of size of hash table
//  CALLS TO: GetHashSize
//***************************************************************************
void InitializeHashArrays (int *linearHash, int *doubleHash, int &listSize)
{
    //Call GetHashSize to set the size of hash tables and allocate dynamic arrays accordingly
    listSize = GetHashSize();

    char ch;  //wait char for user to acknowledge heap error
    //Pointers used to create dynamic arrays of size = listSize
    linearHash = new int[listSize];
    doubleHash = new int[listSize];

    //verify memory allocation
    if (linearHash == NULL || doubleHash == NULL){
        cout << "Error: memory not allocated. Press C to continue: ";
        cin >> ch;
    } // end linearHash allocation check;

    return;

} // end InitializeHashArrays

//*****************************************************************************
//  FUNCTION:    CreateChainingHash
//  DESCRIPTION: function creates array of pointers to nodes. Array is of listSize
//               and every index of array is initialized to NULL.
//               (To be used as master array in Separate Chaining method)
//  IMPLEMENTED BY: Scott Russell
//  INPUT:
//        Parameters: listSize - integer size of hash table
//  OUTPUT:
//        Return Val: chainingHash - array of pointers [listSize] large
//******************************************************************************
chainingNode** CreateChainingHash (int listSize)
{
    chainingNode **chainingHash;
    chainingHash = new (nothrow) chainingNode* [listSize]; // all nodes null default

    int idx;
    //set each array pointer to null
    for (idx = 0; idx < listSize; idx++)
        chainingHash[idx] = NULL; // all nodes created are head nodes

    //allocation unsuccessful?
    if (chainingHash == 0) {
        cout << "ERROR: Memory could not be allocated.";
    } // end if memory allocation unsuccessful

    return chainingHash;
} // end CreateHashList

//***************************************************************************
//  FUNCTION: InitializeNode
//  DESCRIPTION: function initializes a node for adding to the chaining hash
//  IMPLEMENTED BY: Scott Russell
//  INPUT:
//        Parameters: key - integer to populate node with
//  OUTPUT:
//        Return Val: newNode
//  CALLS TO: None
//***************************************************************************
chainingNode* InitializeNode(int key)
{
    chainingNode *newNode;
    char ch;  // wait char for no memory

    //make new node
    newNode = new (nothrow) chainingNode;

    // if memory not allocated properly
    if (newNode == NULL){
        cout << "Error: Memory could not be allocated";
        cin >> ch;
    } // end memory failure

    //allocation: success == assign key to node->key and next-> NULL
    else{
        newNode->key = key;
        newNode->next = NULL;
    } // setup new node

    return newNode;
} // end CreateNode

//***************************************************************************
//  FUNCTION: GetPrimaryHashLocation
//  DESCRIPTION: function uses modulo-division to determine the initial location
//               for a key
//  IMPLEMENTED BY: Scott Russell
//  INPUT:
//        Parameters: key - integer to be added to a hash table
//                    listSize - integer size of the hash table
//  OUTPUT:
//        Return Val: int - initial position to place the key in the hash table
//  CALLS TO: None
//***************************************************************************
int GetPrimaryHashLocation (int key, int listSize)
{
    int location; // address of the key to return

    location = key % listSize;

    return location;

} // end GetPrimaryHashLocation


//***************************************************************************
//  FUNCTION: PopulateChainingHash
//  DESCRIPTION: function populates array wtih key integers from the random array
//               by using separate chaining collision technique
//  IMPLEMENTED BY: Scott Russell
//  INPUT:
//        Parameters: randArray - reference array for random integer keys
//                    chainingHash - reference array for separate chaining hash
//                                   order of keys
//  OUTPUT:
//        Return Val: None
//  CALLS TO: GetPrimaryHashLocation, InitializeNode
//***************************************************************************
void PopulateChainingHash(const int randArray[], chainingNode **chainingHash, int listSize)
{
    int address;   // address in hashList of key
    int idx = 0;  // index for each step (key) in array
    chainingNode *tempNode; //pointer to temporary location in address list
    chainingNode *newNode; //node to be created and added to end of nodes at address head
    char ch;
    //for entire randArray[]
    while (idx < ARRAY_SIZE){

        //use modulo method to determine if address is filled
        address = GetPrimaryHashLocation (randArray[idx], listSize);

        //the temporary node pointed to is the head node at address
        tempNode = chainingHash[address];
        //if address pointer is null, add first node (no collision)
        if (tempNode == NULL){
            newNode = InitializeNode (randArray[idx]);
            chainingHash[address] = newNode;
        } // end add first node in address (no collision)


        //if there is already data in array location (collision)
        else{
            //move to end of nodes at address head node
            while (tempNode->next != NULL)
                tempNode = tempNode->next;
            //get new node with key from randArray location
            newNode = InitializeNode (randArray[idx]);
            tempNode->next = newNode;   // assign newNode at end
        }
        idx++;

    } // end while

} // end SequentialResoluction

//***************************************************************************
//  FUNCTION: SearchChaining
//  DESCRIPTION: function searches the separate chaining hash array to find half
//               of the integers in the random array
//  IMPLEMENTED BY: Scott Russell
//  INPUT:
//        Parameters: randArray - reference array for random integer keys
//                    chainingHash - reference array for separate chaining hash
//                                   order of keys
//  OUTPUT:
//        Return Val: None
//  CALLS TO: GetPrimaryHashLocation, OutputResults
//***************************************************************************
void SearchChaining (const int randArray[], chainingNode** chainingHash,
                     int listSize, float loadFactor)
{
    int itemsExamined = 0; //number of items checked for one key
    int totalExamined = 0;  // sum total of all items examined for all keys searched
    int searchKeys = ARRAY_SIZE / 2;  //percent of randArray to search for
    chainingNode *tempNode;
    int address;  //key location in array returned from GetPrimaryHashLocation

    int keyIndex = 0;  // the space in randArray being searched (key)
    for (int i = 0; i < searchKeys; i++)
    {
        address = GetPrimaryHashLocation (randArray[keyIndex], listSize);
        tempNode = chainingHash[address];
        if (tempNode->key == randArray[keyIndex])
            itemsExamined = 1;
        else{
            itemsExamined = 1;
            while (tempNode->key != randArray[keyIndex]){
                tempNode = tempNode->next;
                itemsExamined++;
            } // look at next node and increase step
        }
        totalExamined += itemsExamined; //track number of nodes to find key
        keyIndex +=2; //search EVERY OTHER array index
    } //end while half of randArray is being searched

    OutputChainedResult(loadFactor, totalExamined);

    return;
}

//****************************************************************************
// FUNCTION:    OutputHeader
// DESCRIPTION: clears screen and outputs following values for user:
//                  ARRAY_SIZE, listSize, and loadFactor
//              Used to preface each call to OutputResults from main
// IMPLEMENTED BY: Scott Russell
// INPUT:
//      Parameters: listSize - size of hash table
// OUTPUT:
//      Return Val: loadFactor - ratio of array and hash sizes: used in other output functions
//****************************************************************************
float OutputHeader(int listSize)
{
    float loadFactor = ARRAY_SIZE / static_cast<double>(listSize);  //ratio of array size to hash size

    system("cls"); // clear screen

    //Array and list data output
    cout << ARRAY_SIZE << " items loaded into a " << listSize
         << " element hash table" << endl;
    cout << fixed << setprecision(2);
    cout << "Load factor = " << loadFactor << endl << endl;

    //search tests require searching for half of the items in the array (ARRAY_SIZE / 2)
    cout << "Results of searching for " << ARRAY_SIZE / 2 << " items:" << endl << endl;

    return loadFactor;
} // end OutputHeader


//****************************************************************************
// FUNCTION:    OutputChainedResult
// DESCRIPTION: function displays the number of items examined while searching for
//      set number of keys. Uses formula do determine avg items examined and displays
//      also displays Knuth's predicted avg number for chained hashing:
//          1 + (LoadFactor / 2);
// IMPLEMENTED BY: Scott Russell
// INPUT:
//      Parameteres: loadFactor - ratio of array to possible hash locations
//                   itemsExamined - count of each node accessed to find key
// OUTPUT: NONE
//*****************************************************************************
void OutputChainedResult(float loadFactor, int totalExamined)
{
    float localAvg;
    float knuthAvg;
    //Calculate Program's avg items examined: itemsExamined / number of items sought
    localAvg = static_cast<float>(totalExamined) / (ARRAY_SIZE / 2);
    //Calculate Knuth's estimated avg items examined:
    knuthAvg = 1 + (loadFactor / 2);
    cout << setw(4) << "" << "Chained Hashing" << endl;
    cout << setw(12) << totalExamined << " items examined" << " (avg = "
         << localAvg << " items examined per search)" << endl;
    cout << setw(12) << " vs" << " predicted Knuth avg = " << knuthAvg
         << " items per search";

    cout << endl << endl << endl;

    return;
}
//****************************************************************************
