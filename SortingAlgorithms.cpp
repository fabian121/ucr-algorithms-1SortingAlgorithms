/* 
 * File:   SortingAlgorithms.cpp
 * Author: this is a change from FABIAN and I write another change22
 * 
 * Created on January 11, 2014, 11:15 AM
 */

#include "SortingAlgorithms.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

SortingAlgorithms::SortingAlgorithms() {
}

SortingAlgorithms::SortingAlgorithms(const SortingAlgorithms& orig) {
}

SortingAlgorithms::~SortingAlgorithms() {
}


/*insertion sorting algorithm implementation*/
int* SortingAlgorithms::insertionSorting(int array[], int size){
    
    //variables
    int currentContent = 0, previousPosition = 0;
    
    //go over from second position to last
    for(int currentPosition = 1; currentPosition < size; currentPosition++){
        //store current and previous content from the array
        currentContent = array[currentPosition];
        previousPosition = currentPosition - 1;
        
        //backward route of subsets
        while(previousPosition > -1 && currentContent < array[previousPosition]){
            array[previousPosition + 1] = array[previousPosition];
            previousPosition--;
        }//end while
        
        //store current content
        array[previousPosition + 1] = currentContent;
    }
    
    //return sorted array
    return array;
}

/*Sorts an array through selection algorithm*/
int* SortingAlgorithms::selectionSorting(int array[], int size) {
    //variables
    int minimumPosition = 0, minimumValue;
    
    //go over first position penultimate
    for(int currentPosition = 0; currentPosition < size; currentPosition++){
        minimumPosition = currentPosition;
        minimumValue = array[currentPosition];
        
        //go over the rest (subset) of the array comparing
        for(int comparingPosition = currentPosition + 1; comparingPosition < size; comparingPosition++){
            //compare
            if(array[comparingPosition] < minimumValue){
                minimumValue = array[comparingPosition];
                minimumPosition = comparingPosition;
            }
        }//end inner for
        
        //switch minimum values
        array[minimumPosition] = array[currentPosition];
        array[currentPosition] = minimumValue;
    }//end main for
    
    //return sorted array
    return array;
}


/*method for create a new array with random numbers*/
int* SortingAlgorithms::createRandomNumbers(int array[], int size, int range) {
    
    //for make real random numbers
    srand(time(NULL));
    
    for(int i = 0; i < size; i++){
        array[i] = rand() % range;
    }//end for
    
    //return the new array
    return array;
}




