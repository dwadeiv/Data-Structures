/*
---------------------------------------------------------------------------------------------------
Purpose: This is the driver class that implements all the data strucutres of Linked list, BST, and Hashtables of linear, quadtratic, and chaining techniques. This driver function tests each functions search and insertion by seeing how long it takes for the each data structure to search for a random integer and to insert an element into the data sturcutre. 
Authors: David and Kartik
Date: April 28 2020
---------------------------------------------------------------------------------------------------
*/

#include "Driver.hpp"

using namespace std;


int main(){

    // For code timing
    using namespace std::chrono;

    srand((unsigned) time(0));

    int test_data[SIZE_OF_DATA];

    float LL_insert[NUMBER_OF_INSERTS];
    float LL_search[NUMBER_OF_SEARCHES];

    float BST_insert[NUMBER_OF_INSERTS];
    float BST_search[NUMBER_OF_SEARCHES];

    float HTC_insert[NUMBER_OF_INSERTS];
    float HTC_search[NUMBER_OF_SEARCHES];
    float HTC_collisions[NUMBER_OF_SEARCHES];

    float HTL_insert[NUMBER_OF_INSERTS];
    float HTL_search[NUMBER_OF_SEARCHES];
    float HTL_collisions[NUMBER_OF_SEARCHES];

    float HTQ_insert[NUMBER_OF_INSERTS];
    float HTQ_search[NUMBER_OF_SEARCHES];
    float HTQ_collisions[NUMBER_OF_SEARCHES];


    string input_filename;
    #ifdef FILENAME_A
        input_filename = FILENAME_A;
    #endif
    #ifdef FILENAME_B
        input_filename = FILENAME_B;
    #endif

    ifstream in_file;
    in_file.open(input_filename);

    string line;
    int index = 0;

    while(getline(in_file, line)){
        stringstream in_file(line);
        string number;
        while(getline(in_file, number, ',')){
            // Converting to int
            int number_cast = (int)atoi(number.c_str());
            test_data[index] = number_cast;
            index ++;
        }
    }
    in_file.close();

//--------------------LL:-----------------------------

    LinkedList LL;
    int LL_random_indexes[NUMBER_OF_INDEXES];

    ofstream LL_outfile;
    #ifdef FILENAME_A
        LL_outfile.open(LL_O_A_FILE);
    #endif
    #ifdef FILENAME_B
        LL_outfile.open(LL_O_B_FILE);
    #endif

    string LL_output;
    int LL_index = 0;

    for(int i = 0; i < NUMBER_OF_INSERTS; i++){

        for(int j = 0; j < NUMBER_OF_INDEXES; j++){
            // Create array with random numbered index (First loop 0-99, second loop 0-199, etc)
            int random_index = (rand() % (NUMBER_OF_INDEXES*(i+1)));
            LL_random_indexes[j] = random_index; 
        }

        // Starting time
        auto ll_insert_start = steady_clock::now();

        for(int j = LL_index; j < (LL_index + NUMBER_OF_INDEXES); j++){
            LL.insert(test_data[j]);
        }

        // Ending time
        auto ll_insert_end = steady_clock::now();
        // Calculating insert time in microseconds
        LL_insert[i] = (duration_cast<microseconds>(ll_insert_end - ll_insert_start).count())/100;

        // Starting time
        auto ll_search_start = steady_clock::now();
        for(int j = 0; j < NUMBER_OF_INDEXES; j ++){
            LL.search(test_data[LL_random_indexes[j]]);
        }
        // Ending time
        auto ll_search_end = steady_clock::now();
        
        // Calculating search time in microseconds
        LL_search[i] = (duration_cast<microseconds>(ll_search_end - ll_search_start).count())/100;

        LL_output += to_string(LL_insert[i]) + "," + to_string(LL_search[i]) + "\n";
        LL_index += NUMBER_OF_INDEXES;
    }

    LL_outfile << LL_output << endl;
    LL_outfile.close();

//--------------------BST:-----------------------------

    BST Tree;
    int BST_random_indexes[NUMBER_OF_INDEXES];

    ofstream BST_outfile;
    #ifdef FILENAME_A
        BST_outfile.open(BST_O_A_FILE);
    #endif
    #ifdef FILENAME_B
        BST_outfile.open(BST_O_B_FILE);
    #endif

    string BST_output;
    int BST_Index = 0;

    for(int i = 0; i < NUMBER_OF_INSERTS; i++){

        for(int j = 0; j < NUMBER_OF_INDEXES; j++){
            // Create array with random numbered index (First loop 0-99, second loop 0-199, etc)
            int random_index = (rand() % (NUMBER_OF_INDEXES*(i+1)));
            BST_random_indexes[j] = random_index; 
        }

        // Starting time
        auto bst_insert_start = steady_clock::now();

        for(int j = BST_Index; j < (BST_Index + NUMBER_OF_INDEXES); j++){
            Tree.insert(test_data[j]);
        }

        // Ending time
        auto bst_insert_end = steady_clock::now();
        // Calculating insert time in microseconds
        BST_insert[i] = (duration_cast<nanoseconds>(bst_insert_end - bst_insert_start).count())/100;

        // Starting time
        auto bst_search_start = steady_clock::now();
        for(int j = 0; j < NUMBER_OF_INDEXES; j ++){
            Tree.search(test_data[BST_random_indexes[j]]);
        }
        // Ending time
        auto bst_search_end = steady_clock::now();
        
        // Calculating search time in microseconds
        BST_search[i] = (duration_cast<nanoseconds>(bst_search_end - bst_search_start).count())/100;

        BST_output += to_string(BST_insert[i]) + "," + to_string(BST_search[i]) + "\n";
        BST_Index += NUMBER_OF_INDEXES;
    }

    BST_outfile << BST_output << endl;
    BST_outfile.close();

//--------------------Hash_Table_Chaining:-----------------------------

    HashTable HTC(SIZE_OF_DATA);
    int HTC_random_indexes[NUMBER_OF_INDEXES];

    ofstream HTC_outfile;
    #ifdef FILENAME_A
        HTC_outfile.open(HTC_O_A_FILE);
    #endif
    #ifdef FILENAME_B
        HTC_outfile.open(HTC_O_B_FILE);
    #endif

    string HTC_output;
    int HTC_index = 0;

    for(int i = 0; i < NUMBER_OF_INSERTS; i++){
        int total_collisions = HTC.getNumOfCollision();

        for(int j = 0; j < NUMBER_OF_INDEXES; j++){
            // Create array with random numbered index (First loop 0-99, second loop 0-199, etc)
            int random_index = (rand() % (NUMBER_OF_INDEXES*(i+1)));
            HTC_random_indexes[j] = random_index; 
        }

        // Starting time
        auto htc_insert_start = steady_clock::now();

        for(int j = HTC_index; j < (HTC_index + NUMBER_OF_INDEXES); j++){
            HTC.insertItem(test_data[j]);
        }

        // Ending time
        auto htc_insert_end = steady_clock::now();
        // Calculating insert time in microseconds
        HTC_insert[i] = (duration_cast<nanoseconds>(htc_insert_end - htc_insert_start).count())/100;

        // Starting time
        auto htc_search_start = steady_clock::now();
        for(int j = 0; j < NUMBER_OF_INDEXES; j ++){
            HTC.searchItem(test_data[HTC_random_indexes[j]]);
        }
        // Ending time
        auto htc_search_end = steady_clock::now();
        
        // Calculating search time in microseconds
        HTC_search[i] = (duration_cast<nanoseconds>(htc_search_end - htc_search_start).count())/100;

        // Collisions every 100 iterations
        int collisions = HTC.getNumOfCollision() - total_collisions;
        HTC_collisions[i] = collisions;

        // For output to csv file
        HTC_output += to_string(HTC_insert[i]) + "," + to_string(HTC_search[i]) + "," + to_string(HTC_collisions[i]) + "\n";

        HTC_index += NUMBER_OF_INDEXES;
    }


    HTC_outfile << HTC_output << endl;
    HTC_outfile.close();
    // cout << "=======================================" << endl;

//--------------------Hash_Table_Linear_Probing:-----------------------------

    hashTableLinearProbing HTL(SIZE_OF_DATA);
    int HTL_random_indexes[NUMBER_OF_INDEXES];

    ofstream HTL_outfile;
    #ifdef FILENAME_A
        HTL_outfile.open(HTL_O_A_FILE);
    #endif
    #ifdef FILENAME_B
        HTL_outfile.open(HTL_O_B_FILE);
    #endif

    string HTL_output;
    int HTL_index = 0;

    for(int i = 0; i < NUMBER_OF_INSERTS; i++){
        int total_collisions = HTL.getNumOfCollision();

        for(int j = 0; j < NUMBER_OF_INDEXES; j++){
            // Create array with random numbered index (First loop 0-99, second loop 0-199, etc)
            int random_index = (rand() % (NUMBER_OF_INDEXES*(i+1)));
            HTL_random_indexes[j] = random_index; 
        }

        // Starting time
        auto htl_insert_start = steady_clock::now();

        for(int j = HTL_index; j < (HTL_index + NUMBER_OF_INDEXES); j++){
            HTL.insertItem(test_data[j]);
        }

        // Ending time
        auto htl_insert_end = steady_clock::now();
        // Calculating insert time in microseconds
        HTL_insert[i] = (duration_cast<nanoseconds>(htl_insert_end - htl_insert_start).count())/100;

        // Starting time
        auto htl_search_start = steady_clock::now();
        for(int j = 0; j < NUMBER_OF_INDEXES; j ++){
            HTL.searchItem(test_data[HTL_random_indexes[j]]);
        }
        // Ending time
        auto htl_search_end = steady_clock::now();
        
        // Calculating search time in microseconds
        HTL_search[i] = (duration_cast<nanoseconds>(htl_search_end - htl_search_start).count())/100;

        // Collisions every 100 iterations
        int collisions = HTL.getNumOfCollision() - total_collisions;
        HTL_collisions[i] = collisions;

        // For output to csv file
        HTL_output += to_string(HTL_insert[i]) + "," + to_string(HTL_search[i]) + "," + to_string(HTL_collisions[i]) + "\n";

        HTL_index += NUMBER_OF_INDEXES;
    }

    HTL_outfile << HTL_output << endl;
    HTL_outfile.close();

//--------------------Hash_Table_Quadratic_Probing:-----------------------------

    hashTableQuadraticProbing HTQ(SIZE_OF_DATA);
    int HTQ_random_indexes[NUMBER_OF_INDEXES];

    ofstream HTQ_outfile;
    #ifdef FILENAME_A
        HTQ_outfile.open(HTQ_O_A_FILE);
    #endif
    #ifdef FILENAME_B
        HTQ_outfile.open(HTQ_O_B_FILE);
    #endif

    string HTQ_output;
    int HTQ_index = 0;

    for(int i = 0; i < NUMBER_OF_INSERTS; i++){
        int total_collisions = HTQ.getNumOfCollision();

        for(int j = 0; j < NUMBER_OF_INDEXES; j++){
            // Create array with random numbered index (First loop 0-99, second loop 0-199, etc)
            int random_index = (rand() % (NUMBER_OF_INDEXES*(i+1)));
            HTQ_random_indexes[j] = random_index; 
        }

        // Starting time
        auto htq_insert_start = steady_clock::now();

        for(int j = HTQ_index; j < (HTQ_index + NUMBER_OF_INDEXES); j++){
            HTQ.insertItem(test_data[j]);
        }

        // Ending time
        auto htq_insert_end = steady_clock::now();
        // Calculating insert time in microseconds
        HTQ_insert[i] = (duration_cast<nanoseconds>(htq_insert_end - htq_insert_start).count())/100;

        // Starting time
        auto htq_search_start = steady_clock::now();
        for(int j = 0; j < NUMBER_OF_INDEXES; j ++){
            HTQ.searchItem(test_data[HTQ_random_indexes[j]]);
        }
        // Ending time
        auto htq_search_end = steady_clock::now();
        
        // Calculating search time in microseconds
        HTQ_search[i] = (duration_cast<nanoseconds>(htq_search_end - htq_search_start).count())/100;

        // Collisions every 100 iterations
        int collisions = HTQ.getNumOfCollision() - total_collisions;
        HTQ_collisions[i] = collisions;

        // For output to csv file
        HTQ_output += to_string(HTQ_insert[i]) + "," + to_string(HTQ_search[i]) + "," + to_string(HTQ_collisions[i]) + "\n";

        HTQ_index += NUMBER_OF_INDEXES;
    }

    HTQ_outfile << HTQ_output << endl;
    HTQ_outfile.close();



    return 0;
}