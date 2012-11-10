//***************************************************************************
//  FUNCTION: OutputLinearResult
//  DESCRIPTION: function uses Knuth's formula for searching with linear probing
//               and displays search result output for user
//  IMPLEMENTED BY: Jason Lopez
//  INPUT:
//        Parameters: loadFactor - ratio of array to possible hash locations
//                    itemsExamined - count of each node accessed to find key
//  OUTPUT:
//        Return Val: None
//  CALLS TO: None
//***************************************************************************

void OutputLinearResult(float loadFactor, int totalExamined)
{
    //Define Variables
    float localAvg = 0.00;
    float knuthAvg = 0.00;

    //Calculate Knuth average
    knuthAvg = ((1 + (1 / (1 - loadFactor))) / 2);

    //Calculate Program's avg items examined: itemsExamined / number of items sought
    localAvg = static_cast<float>(totalExamined) / (ARRAY_SIZE / 2);

    //Display output for user
    cout << setw(4) << "" << "Linear Probing" << endl;
    cout << setw(12) << totalExamined << " items examined" << " (avg = "
         << localAvg << " items examined per search)" << endl;
    cout << setw(12) << " vs" << " predicted Knuth avg = " << knuthAvg
         << " items per search";

    cout << endl << endl << endl;

}
