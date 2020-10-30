#ifndef DRIVER_HPP
#define DRIVER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <time.h>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <unistd.h>
#include "LinkedList.hpp"
#include "BST.hpp"
#include "hashTableChaining.hpp"
#include "hashTableLinearProbing.hpp"
#include "hashTableQuadraticProbing.hpp"

// Macros
// #define FILENAME_A          "dataSetA.csv"
#define FILENAME_B          "dataSetB.csv"
#define SIZE_OF_DATA        40000
#define NUMBER_OF_INSERTS   400
#define NUMBER_OF_SEARCHES  400
#define NUMBER_OF_INDEXES   100
// DatasetA
#define LL_O_A_FILE           "LL_DataA.csv"
#define BST_O_A_FILE          "BST_DataA.csv"
#define HTC_O_A_FILE          "HTC_DataA.csv"
#define HTL_O_A_FILE          "HTL_DataA.csv"
#define HTQ_O_A_FILE          "HTQ_DataA.csv"
#define LL_O_B_FILE           "LL_DataB.csv"
#define BST_O_B_FILE          "BST_DataB.csv"
#define HTC_O_B_FILE          "HTC_DataB.csv"
#define HTL_O_B_FILE          "HTL_DataB.csv"
#define HTQ_O_B_FILE          "HTQ_DataB.csv"

#endif