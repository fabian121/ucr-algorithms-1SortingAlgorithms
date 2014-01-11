/* 
 * File:   main.cpp
 * Author: user
 *
 * Created on January 9, 2014, 2:49 PM
 */

#include <cstdlib>
#include "SortingAlgorithms.h"
#include <stdio.h>
#include <sys/time.h>

using namespace std;

//prototype declarations
void randomTest();
void sortingAlgorithms(int myArray[], int size, int range);
void printArray(int myArray[], int size);

/*
 * 
 */
int main(int argc, char** argv) {

    //variables
    int size = 3, range = 1000;
    int myArray[size], mySecondArray[size];

    //sorting reference
    SortingAlgorithms algos;

    //fill out the array 
    int *newArray = algos.createRandomNumbers(myArray, size, range);

    
    //duplicate array
    for(int i = 0; i < size; i++){
        mySecondArray[i] = newArray[i];
    }

    /**************************************************************************/
    /******************        measure time       *****************************/
    //variables
    timeval initialTimeInsertion, finishTimeInsertion, initialTimeSelection, finishTimeSelection;
    double elapsedTimeInsertion, elapsedTimeSelection;

    //-----------------INSERTION-----------------------
    // start timer  
    gettimeofday(&initialTimeInsertion, NULL);
    //get my sorted array with insertion
    int *sortedArrayInsertion = algos.insertionSorting(newArray, size);
    // stop timer
    gettimeofday(&finishTimeInsertion, NULL);
    // compute and print the elapsed time in milliseconds
    elapsedTimeInsertion = (finishTimeInsertion.tv_sec - initialTimeInsertion.tv_sec) * 1000.0; // sec to ms
    elapsedTimeInsertion += (finishTimeInsertion.tv_usec - initialTimeInsertion.tv_usec) / 1000.0; // us to ms
    
    //-----------------SELECTION-----------------------
    // start timer  
    gettimeofday(&initialTimeSelection, NULL);
    //get my sorted array with selection
    int *sortedArraySelection = algos.selectionSorting(mySecondArray, size);
    // stop timer
    gettimeofday(&finishTimeSelection, NULL);
    // compute and print the elapsed time in milliseconds
    elapsedTimeSelection = (finishTimeSelection.tv_sec - initialTimeSelection.tv_sec) * 1000.0; // sec to ms
    elapsedTimeSelection += (finishTimeSelection.tv_usec - initialTimeSelection.tv_usec) / 1000.0; // us to ms
    
    
    printf("Algorithm's duration (Insertion): %lf  ms.\n", elapsedTimeInsertion);
    printf("Algorithm's duration (Selection): %lf  ms.\n", elapsedTimeSelection);

    /**************************************************************************/
    /**************************************************************************/

    //print the resulting array
    //printArray(sortedArrayInsertion,size);

    return 0;
}

/*test the random generator*/
void randomTest() {
    //variables
    int size = 1000000, range = 1000;
    int myArray[size];

    //test array generator
    SortingAlgorithms algos;
    int *newArray = algos.createRandomNumbers(myArray, size, range);
    //    for(int i = 0; i < size; i++){
    //        printf("NewArray[%d]\n", newArray[i]);
    //    }
    printf("done!\n\n");
}

/*print the entire array*/
void printArray(int myArray[], int size) {
    //print my current array
    for (int i = 0; i < size; i++) {
        printf("Array[%d]\n", myArray[i]);
    }//end for
    printf("\n\n");
}