//***************************************************************************
//  FUNCTION: SearchLinear
//  DESCRIPTION: function searches the linear hash array to find half of the
//               integers in the random array
//  IMPLEMENTED BY: Jason Lopez
//  INPUT:
//        Parameters: randArray - reference array for random integer keys
//                    linearHash - reference array for linear hash order of keys
//                    listSize - size of the hash table
//  OUTPUT:
//        Return Val: integer - number of items touched when executing the linear
//                              search
//  CALLS TO: GetPrimaryHashLocation, OutputResults
//***************************************************************************

int SearchLinear(int randArray[], int* &linearHash, int listSize)
{
	//Define Variables
	int returnValue = 0;
	int linearCounter = 0;
	int hashPosition = 0;
	bool searchItemFound = false;

	for(int i = 0; i < listSize; i += 2){
		//Get the initial hash location for the search
		hashPosition = GetPrimaryHashLocation(randArray[i], listSize);

		//Compare values
		if(randArray[i] == linearHash[hashPosition]){
			linearCounter++;
		}
		else{
			//Loop until the value is found
			do{
			    linearCounter++;
			    hashPosition++;
			    if(randArray[i] == linearHash[hashPosition]){
			        linearCounter++;
			        searchItemFound = true;
			    }
			}
			while(!searchItemFound);
		}

		//Reset hash position
		hashPosition = 0;
	}

	returnValue = linearCounter;
}
