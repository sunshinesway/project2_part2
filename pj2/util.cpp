// Cheyenne Swasey
// 1227888508

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "util.h"
#include "heap.h"
#include "data_structures.h"

HEAP* initArray(int cap) {
    HEAP *heap = (HEAP *)calloc(1, sizeof(HEAP));
        if (!heap) {
            fprintf(stderr, "Error: memory allocation failed for Heap\n");
            return heap;
        }
    heap->capacity = cap;
    heap->size = 0;
    heap->A = (ELEMENT **)calloc(cap, sizeof(ELEMENT *));

    return heap;
}

void printArray(HEAP *heap, int count) {
    //base case if heap is null - error message
    if(!heap) {
        fprintf(stderr, "Error: heap is NULL");
    }
    //not NULL: print heap size, then each key value in ELEMENT A array
    else {

        printf("Number of Heapify calls: %d\n%d\n",count, heap->size);
        for(int i = 1; i <= heap->size; i++) {
            printf("%lf\n",heap->A[i]->key);
        }
    }
}

void printArray(HEAP *heap) {
    //base case if heap is null - error message
    if(!heap) {
        fprintf(stderr, "Error: heap is NULL");
    }
        //not NULL: print heap size, then each key value in ELEMENT A array
    else {
        printf("%d\n", heap->size);
        for(int i = 1; i <= heap->size; i++) {
            printf("%lf\n",heap->A[i]->key);
        }
    }
}

void writeArray(HEAP *heap, FILE *outputFile) {
    //base case if heap is null - error message
    if(!heap) {
        fprintf(stderr, "Error: heap is NULL");
        return;
    }
    //not NULL: write array A to outputFile
    //error if file cannot be opened
    else if (!outputFile) {
        fprintf(stderr, "Error: cannot open file %s\n", "ofile");
        return;
    }
    //write first heap-size, then each key value in ELEMENT A array
    else {
        fprintf(outputFile, "%d\n", heap->size);
        for (int i = 1; i <= heap->size; i++) {
            fprintf(outputFile, "%lf\n", heap->A[i]->key);
        }
        //close the file DON'T FORGET IT
        fclose(outputFile);
    }
}

void readIn(HEAP *heap, FILE *inputFile) {
    //base case if heap is null - error message
    if(!heap) {
        fprintf(stderr, "Error, file cannot be opened \n");
        return;
    }
    //not NULL: write array A to outputFile
    //error if file cannot be opened
    else if (!inputFile) {
        fprintf(stderr, "Error: cannot open file %s\n", "ifile");
        return;
    }
    //read from file
    else {
        double key;
        //first, pull int: heap-size
        fscanf(inputFile, "%d", &heap->size);
        //error if heap cap<heap size
        if (heap->size > heap->capacity) {
            fprintf(stderr, "Error, heap capacity = %d, smaller than desired heap size = %d\n",
                    heap->capacity, heap->size);
            return;
        }
        else {
            //create new ELEMENT
            ELEMENT *newElem = (ELEMENT *)malloc(sizeof(ELEMENT));
            //loop through array, setting double value from file to key field
            for (int i = 1; i <= heap->size; i++) {
                heap->A[i] = newElem;
                fscanf(inputFile, "%lf", &key);
                heap->A[i]->key = key;
            }
        }
    }
    fclose(inputFile);
}

void swap(HEAP *heap, int itemInd1, int itemInd2) {

    //create temp element for swapping
    ELEMENT *item1 = heap->A[itemInd1];
    ELEMENT *item2 = heap->A[itemInd2];

    ELEMENT *temp = item1;

    *item1 = *item2;
    *item2 = *temp;
}