//***************************************************************************
//  FUNCTION: OutputDoubleResult
//  DESCRIPTION: function uses Knuth's formula for searching with double hashing
//               and displays search result output for user
//  IMPLEMENTED BY: Jason Lopez
//  INPUT:
//        Parameters: loadFactor - ratio of array to possible hash locations
//                    itemsExamined - count of each node accessed to find key
//                    doublePopulateError - bool to note if there was an error
//                                          loading the double hash table
//  OUTPUT:
//        Return Val: None
//  CALLS TO: None
//***************************************************************************

void OutputDoubleResult(float loadFactor, int totalExamined, bool doublePopulateError)
{
    //Define Variables
    float localAvg = 0.00;
    float knuthAverage = 0.00;

    if(!doublePopulateError){
        //Calculate Knuth average
        knuthAverage = 0.5(1 + (1 / (1 - loadFactor)));

        //Calculate Program's avg items examined: itemsExamined / number of items sought
        localAvg = static_cast<float>(totalExamined) / (ARRAY_SIZE / 2);

        //Display output for user
        cout << setw(4) << "" << "Double Hashing" << endl;
        cout << setw(12) << totalExamined << " items examined" << " (avg = "
             << localAvg << " items examined per search)" << endl;
        cout << setw(12) << " vs" << " predicted Knuth avg = " << knuthAverage
             << " items per search";

        cout << endl << endl << endl;
    }
    else{
        cout << setw(4) << "" << "Double Hashing" << endl;
        cout << setw(12) << "There was an error encountered in populating the "
             << "double hash table." << endl;
        cout << setw(12) << "No results will be displayed for the double hashing"
             << "results." << endl;
        cout << endl << endl;
    }
}
