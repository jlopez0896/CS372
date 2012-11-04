//***************************************************************************
//  FUNCTION: main
//  DESCRIPTION: entry point for the program, calls to all secondary functions
//  IMPLEMENTED BY: Scott Russell
//  INPUT: None
//  OUTPUT:
//        Return Val:  0 for successful processing
//  CALLS TO:
//***************************************************************************


//***************************************************************************
//  FUNCTION: InitializeArrays
//  DESCRIPTION: function initializes all dynamic arrays needed for the program
//  IMPLEMENTED BY:
//  INPUT:
//        Parameters: randArray - reference array for random integer keys
//                    linearHash - reference array for linear hash order of keys
//                    doubleHash - reference array for double hash order of keys
//                    chainingHash - reference array for separate chaining hash
//                                   order of keys
//  OUTPUT:
//        Return Val: None
//  CALLS TO: None
//***************************************************************************


//***************************************************************************
//  FUNCTION: DeleteArrays
//  DESCRIPTION: function delets all dynamic arrays to free memory
//  IMPLEMENTED BY:
//  INPUT:
//        Parameters: randArray - reference array for random integer keys
//                    linearHash - reference array for linear hash order of keys
//                    doubleHash - reference array for double hash order of keys
//                    chainingHash - reference array for separate chaining hash
//                                   order of keys
//  OUTPUT:
//        Return Val: None
//  CALLS TO: None
//***************************************************************************


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


//***************************************************************************
//  FUNCTION: GenerateNumber
//  DESCRIPTION: uses cstdlib rand() and the limits of MIN_RAND and MAX_RAND to
//               generate a random integer and return it to the calling function
//  IMPLEMENTED BY: Jason Lopez
//  INPUT:
//        Parameters: None
//  OUTPUT:
//        Return Val: random integer
//  CALLS TO: None
//***************************************************************************


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
//***************************************************************************


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


//***************************************************************************
//  FUNCTION: PopulateLinearHash
//  DESCRIPTION: function populates array with key integers from the random array
//               by using linear probing collision technique
//  IMPLEMENTED BY: Jason Lopez
//  INPUT:
//        Parameters: randArray - reference array for random integer keys
//                    linearHash - reference array for linear hash order of keys
//  OUTPUT:
//        Return Val: None
//  CALLS TO: GetPrimaryHashLocation
//***************************************************************************


//***************************************************************************
//  FUNCTION: PopulateDoubleHash
//  DESCRIPTION: function populates array with key integers from the random array
//               by using double hashing collision technique
//  IMPLEMENTED BY: Jason Lopez
//  INPUT:
//        Parameters: randArray - reference array for random integer keys
//                    doubleHash - reference array for double hash order of keys
//  OUTPUT:
//        Return Val: None
//  CALLS TO: GetPrimaryHashLocation, GetSecondaryHashLocation
//***************************************************************************

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


//***************************************************************************
//  FUNCTION: GetPrimryHashLocation
//  DESCRIPTION: function uses modulo-division to determine the initial location
//               for a key
//  IMPLEMENTED BY: Jason Lopez
//  INPUT:
//        Parameters: key - integer to be added to a hash table
//                    listSize - integer size of the hash table
//  OUTPUT:
//        Return Val: int - initial position to place the key in the hash table
//  CALLS TO: None
//***************************************************************************


//***************************************************************************
//  FUNCTION: GetSecondaryHashLocation
//  DESCRIPTION: function uses a secondary hash algorithm to deterimine an
//               alternate position if a collision is encountered with the primary
//               hash location
//  IMPLEMENTED BY: Jason Lopez
//  INPUT:
//        Parameters: key - integer to be added to a hash table
//                    listSize - integer size of the hash table
//  OUTPUT:
//        Return Val: int - second position to place the key in the hash table
//  CALLS TO: None
//***************************************************************************


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


//***************************************************************************
//  FUNCTION: SearchLinear
//  DESCRIPTION: function searches the linear hash array to find half of the
//               integers in the random array
//  IMPLEMENTED BY: Jason Lopez
//  INPUT:
//        Parameters: randArray - reference array for random integer keys
//                    linearHash - reference array for linear hash order of keys
//  OUTPUT:
//        Return Val: None
//  CALLS TO: GetPrimaryHashLocation, OutputResults
//***************************************************************************


//***************************************************************************
//  FUNCTION: SearchDouble
//  DESCRIPTION: function searches the double hash array to find half of the
//               integers in the random array
//  IMPLEMENTED BY: Jason Lopez
//  INPUT:
//        Parameters: randArray - reference array for random integer keys
//                    doubleHash - reference array for double hash order of keys
//  OUTPUT:
//        Return Val: None
//  CALLS TO: GetPrimaryHashLocation, GetSecondaryHashLocation, OutputResults
//***************************************************************************


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


//***************************************************************************
//  FUNCTION: OutputResults
//  DESCRIPTION: function will display search results for the user
//  IMPLEMENTED BY:
//  INPUT:
//        Parameters: searchType - type of search executed (linear, double, or
//                    chaining)
//                    itemsExamined - integer of the items that were examined by
//                    the search
//  OUTPUT:
//        Return Val: None
//  CALLS TO: None
//***************************************************************************


//***************************************************************************
//  FUNCTION: DeleteNodes
//  DESCRIPTION: function will delete chaining nodes to free up memory
//  IMPLEMENTED BY: Scott Russell
//  INPUT:
//        Parameters: chainingHash - reference array for separate chaining hash
//                                   order of keys
//  OUTPUT:
//        Return Val: None
//  CALLS TO: None
//***************************************************************************

