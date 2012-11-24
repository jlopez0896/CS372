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
//  CALLS TO: GetPrimaryHashLocation, GetSecondaryHashLocation
//***************************************************************************
int SearchDouble(const int randArray[], int doubleHash[], int listSize, bool &overflowHashError)
{
    //Define Variables
    int randCounter = 0;
	int doubleCounter = 0;
	int hashPosition = 0;
	int secondHashInterval = 0;
	int overflowCounter = 0;
	bool searchItemFound = false;  //calls to doubleHash stop when found
	overflowHashError = false; //calls to doubleHash stop when hash size limit reached


	while(randCounter < ARRAY_SIZE && !overflowHashError){
        //Get hash position
        hashPosition = GetPrimaryHashLocation(randArray[randCounter], listSize);
        //if position is open: put in array number
        if(doubleHash[hashPosition] == randArray[randCounter])
            doubleCounter++;
        //otherwise continue to search for a secondary position until: 1. open found, 2. overflow detected

        else{

            while(!searchItemFound && !overflowHashError)
            {
                //Get the second hash position
                secondHashInterval = GetSecondaryHashLocation(randArray[randCounter], listSize);
                hashPosition += secondHashInterval;
                doubleCounter++;

                if(doubleHash[hashPosition] == randArray[randCounter]){ //if unfilled: put in key
                    searchItemFound = true;
                }
                else if(hashPosition > listSize){
                    //We have reached the end of the list.  Set hashPosition
                    //back to the beginning of the list while maintaining the
                    //hash interval
                    hashPosition = hashPosition - listSize;
                    doubleCounter++;
                    if(doubleHash[hashPosition] == randArray[randCounter]){
                        searchItemFound = true;
                    }
                }
                else if(overflowCounter > listSize){
                    overflowHashError = true;
                } // end if overflow

                overflowCounter ++;
            }
            //Reset overflow counter and search item found bool
            overflowCounter = 0;
            searchItemFound = false;
        }

        randCounter+=2;
    } // end For: length of hash
	return doubleCounter;
}
