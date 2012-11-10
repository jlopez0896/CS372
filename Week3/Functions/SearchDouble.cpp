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

int SearchDouble(const int randArray[], int* &doubleHash, int listSize, bool &overflowHashError)
{
    //Define Variables
	int returnValue = 0;
	int doubleCounter = 0;
	int hashPosition = 0;
	int hashIncrement = 0;
	bool searchItemFound = false;

	overflowHashError = false;

	for(int i = 0; i < ARRAY_SIZE; i += 2){
		//Get the initial hash location for the search
		hashPosition = GetPrimaryHashLocation(randArray[i], listSize);

		//Compare values
		if(randArray[i] == doubleHash[hashPosition]){
			doubleCounter++;
		}
		else{
		    //Call second hash position
		    hashIncrement = GetSecondaryHashLocation(randArray[i], listSize);

		    hashPosition += hashIncrement;

		    if(randArray[i] == doubleHash[hashPosition]){
		        doubleCounter++;
		    }
		    else{
                //Loop until the value is found
                do{
                    if(doubleCounter < ARRAY_SIZE)
                    {
                        doubleCounter++;
                        hashPosition += hashIncrement;
                        if(randArray[i] == doubleHash[hashPosition]){
                            doubleCounter++;
                            searchItemFound = true;
                        }
                    }
                    else{
                        overflowHashError = true;
                    }
                }
                while(!searchItemFound || !overflowHashError);

		    }

		}

		//Reset hash position
		hashPosition = 0;
	}

	returnValue = doubleCounter;
	return returnValue;
}
