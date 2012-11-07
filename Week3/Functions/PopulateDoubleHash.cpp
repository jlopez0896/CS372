//***************************************************************************
//  FUNCTION: PopulateDoubleHash
//  DESCRIPTION: function populates array with key integers from the random array
//               by using double hashing collision technique
//  IMPLEMENTED BY: Jason Lopez
//  INPUT:
//        Parameters: randArray - reference array for random integer keys
//                    doubleHash - reference array for double hash order of keys
//                    listSize - size of double hash table
//                    overflowHashError - report error if unable to add values to
//                                        the hash table
//  OUTPUT:
//        Return Val: None
//  CALLS TO: GetPrimaryHashLocation, GetSecondaryHashLocation
//***************************************************************************


void PopulateDoubleHash(const int randArray[], int* &doubleHash, int listSize,
                        bool overflowHashError)
{
    //Declare Variables
    int randCounter = 0;
    int hashPosition = 0;
    int secondHashInterval = 0;
    bool endHashProcessing = false;
    int overflowCounter = 0;

    //Ensure the overflow hash error is set to false
    overflowHashError = false;

    //Loop through random array and input values into linear hash table
    for(randCounter = 0; randCounter < ARRAY_SIZE; randCounter++)
    {
        //Get hash position
        hashPosition = GetPrimaryHashLocation(randArray[randCounter], listSize);

        if(doubleHash[hashPosition] == 0)
        {
            doubleHash[hashPosition] = randArray[randCounter];
        }
        else
        {
            //Get the second hash position
            hashPosition = GetSecondaryHashLocation(randArray[randCounter], listSize);
            secondHashInterval = hashPosition;

            if(doubleHash[hashPosition] == 0)
            {
                doubleHash[hashPosition] = randArray[randCounter];
            }
            else
            {
                //Continue to add the second hash interval to the position until
                //a free location is found
                while(!endHashProcessing)
                {
                    //Increment hash position
                    hashPosition += secondHashInterval;
                    if(doubleHash[hashPosition] == 0)
                    {
                        doubleHash[hashPosition] = randArray[randCounter];
                        endHashProcessing = true;
                    }
                    if(overflowCounter == listSize)
                    {
                        endHashProcessing = true;
                        overflowHashError = true;
                    }
                    overflowCounter ++;
                }
            }

        }

        //Reset hash position
        hashPosition = 0;
    }
}
