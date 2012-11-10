//***************************************************************************
//  FUNCTION: DeleteArrays
//  DESCRIPTION: function delets all dynamic arrays to free memory
//  IMPLEMENTED BY:
//  INPUT:
//        Parameters: randArray - reference array for random integer keys
//                    linearHash - reference array for linear hash order of keys
//                    doubleHash - reference array for double hash order of keys
//  OUTPUT:
//        Return Val: None
//  CALLS TO: None
//***************************************************************************

void DeleteArrays(int *randArray, int *linearHash, int *doubleHash)
{
	//Delete the dynamic arrays
	delete[] randArray;
	delete[] linearHash;
	delete[] doubleHash;
}
