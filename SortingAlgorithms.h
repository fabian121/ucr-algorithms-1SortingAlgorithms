/* 
 * File:   SortingAlgorithms.h
 * Author: user
 *
 * Created on January 11, 2014, 11:14 AM
 */

#ifndef SORTINGALGORITHMS_H
#define	SORTINGALGORITHMS_H

class SortingAlgorithms {
public:
    SortingAlgorithms();
    SortingAlgorithms(const SortingAlgorithms& orig);
    virtual ~SortingAlgorithms();
    
    int* insertionSorting(int arr[], int size);
    int* selectionSorting(int arr[], int size);
    int* createRandomNumbers(int array[], int size, int range);
private:

};

#endif	/* SORTINGALGORITHMS_H */

