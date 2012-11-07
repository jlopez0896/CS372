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

int GetSecondaryHashLocation(int key, int listSize)
{
    //Define Variables
    int returnValue = 0;

    returnValue = (key % (listSize - 2)) + 1;

    return returnValue;
}

