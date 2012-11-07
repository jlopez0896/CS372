//***************************************************************************
//  FUNCTION: PopulateLinearHash
//  DESCRIPTION: function populates array with key integers from the random array
//               by using linear probing collision technique
//  IMPLEMENTED BY: Jason Lopez
//  INPUT:
//        Parameters: randArray - reference array for random integer keys
//                    linearHash - reference array for linear hash order of keys
//                    listSize - size of the hash array
//  OUTPUT:
//        Return Val: None
//  CALLS TO: GetPrimaryHashLocation
//***************************************************************************

void PopulateLinearHash(const int randArray[], int* &linearHash, int listSize)
{
    //Define Variables
    int randCounter = 0;
    int hashPosition = 0;


    //Loop through random array and input values into linear hash table
    for(randCounter = 0; randCounter < ARRAY_SIZE; randCounter++)
    {
        //Get hash position
        hashPosition = GetPrimaryHashLocation(randArray[randCounter], listSize);

        if(linearHash[hashPosition] == 0)
        {
            linearHash[hashPosition] = randArray[randCounter];
        }
        else
        {
            hashPosition ++;
            //Loop until a free position is found in the linear hash
            //since the hash table is larger than the random array we won't have
            //to worry about an infinite loop
            while(linearHash[hashPosition] != 0)
            {
                //Continue to the end of the list to find an open position
                if(hashPosition < listSize)
                {
                    hashPosition ++;
                }
                //Start at the beginning of the list
                else
                {
                    hashPosition = 0;
                }

            }
            linearHash[hashPosition] = randArray[randCounter];
        }

        //Reset hash position
        hashPosition = 0;
    }
