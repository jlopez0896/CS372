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
void PopulateDoubleHash(const int randArray[], int doubleHash[], int listSize,
                        bool &overflowHashError)
{
    //Declare Variables
    int randCounter = 0;
    int hashPosition = 0;
    int secondHashPosition = 0;
    int secondHashInterval = 0;
    bool endHashProcessing = false;
    int overflowCounter = 0;

    //Ensure the overflow hash error is set to false
    overflowHashError = false;

    //Loop through random array and input values into linear hash table
    while(randCounter < ARRAY_SIZE && !overflowHashError){
        //Get hash position
        hashPosition = GetPrimaryHashLocation(randArray[randCounter], listSize);
        //if position is open: put in array number
        if(doubleHash[hashPosition] == NULL)
            doubleHash[hashPosition] = randArray[randCounter];
        //otherwise continue to search for a secondary position until: 1. open found, 2. overflow detected
        else{

            while(!endHashProcessing && !overflowHashError)
            {
                //Get the second hash position
                secondHashInterval = GetSecondaryHashLocation(randArray[randCounter], listSize);
                hashPosition += secondHashInterval;

                if(doubleHash[hashPosition] == NULL){ //if unfilled: put in key
                    doubleHash[hashPosition] = randArray[randCounter];
                    endHashProcessing = true;
                }
                else if(hashPosition > listSize){
                    //We have reached the end of the list.  Set hashPosition
                    //back to the beginning of the list while maintaining the
                    //hash interval
                    hashPosition = hashPosition - listSize;
                    if(doubleHash[hashPosition] == NULL){
                        doubleHash[hashPosition] = randArray[randCounter];
                        endHashProcessing = true;
                    }
                }
                else if(overflowCounter > listSize){
                    endHashProcessing = true;
                    overflowHashError = true;
                } // end if overflow

                overflowCounter ++;
            }
            //Reset overflow counter and end hash processing bool
            overflowCounter = 0;
            endHashProcessing = false;
        }
        //Increase counter to the next item
        randCounter++;

    } // end While: length of hash

} // end PopulateDoubleHash
