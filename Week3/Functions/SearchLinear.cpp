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
int SearchLinear(const int randArray[], int linearHash[], int listSize)
{
	//Define Variables
	//int returnValue = 0;
	int linearCounter = 0;  //count of locations checked in hash before key located
	int hashPosition = 0;   //assumed position of key within linearHash array
	bool searchItemFound = false;

	for(int i = 0; i < ARRAY_SIZE; i += 2){
		//Get the initial hash location for the search
		hashPosition = GetPrimaryHashLocation(randArray[i], listSize);

		//Compare values
		if(randArray[i] == linearHash[hashPosition])
			linearCounter++;

		//values not matched
		else{
			//Loop until the value is found
			do{
			    //move to next value in array and maintain searched location counts
			    linearCounter++;
			    hashPosition++;
			    if(randArray[i] == linearHash[hashPosition]){
			        linearCounter++;
			        searchItemFound = true;
			    } // end if: hash key found
			} while(!searchItemFound);
		} // end else: hash key not found at first location

		//Reset hash position
		hashPosition = 0;
	} // end for: traverse array (increments of 2)

	//returnValue = linearCounter;
	return linearCounter;
}
