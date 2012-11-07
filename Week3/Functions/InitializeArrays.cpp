//***************************************************************************
//  FUNCTION: InitializeArrays
//  DESCRIPTION: function initializes all dynamic arrays needed for the program
//  IMPLEMENTED BY: Scott Russell and Jason Lopez
//  INPUT:
//        Parameters: linearHash - reference array for linear hash order of keys
//                    doubleHash - reference array for double hash order of keys
//                    listSize - ref return of integer variable of size of hash table
//  OUTPUT:
//        Return Val: linearHash - initialized dynamic int array of listSize
//                    doubleHash - initialized dyanimc int array of listSize
//                    listSize - ref return of integer variable of size of hash table
//  CALLS TO: None
//***************************************************************************

void InitializeHashArrays (int* &linearHash, int* &doubleHash, int &listSize)
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
    else
    {
        for(int i = 0; i < listSize; i++)
        {
            linearHash[i] = 0;
            doubleHash[1] = 0;
        }

    }

} // end InitializeHashArrays
