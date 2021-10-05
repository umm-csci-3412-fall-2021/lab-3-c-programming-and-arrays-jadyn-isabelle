#include "array_merge.h"
#include "../mergesort/mergesort.c"
#include "../mergesort/mergesort.h"
#include <stdlib.h>
#include <cstdio>
#include <cstring>

// num_arrays is the number of arrays
// sizes is an array of the size of each corresponding array
// values is an array with the values of each array
int* array_merge(int num_arrays, int* sizes, int** values) {
  
  int totalSize=0; // the total size of the end array
  int index =0;

  for(int i=0; i < num_arrays; ++i){
	  totalSize = totalSize + sizes[i]; // adds the numbers of each array together
  }	  
  
  int* tempArray = (int*) calloc(totalSize, sizeof(int)); // array of all the values in values

  for(int i=0; i < num_arrays; ++i){ 
	  for(int j=0; j < sizes[i]; ++j){
		  tempArray[index]= values[i][j]; //adding the values of values into the array
		  ++index;
		 }
  }

  mergesort(totalSize, tempArray); // call our mergesort function to sort the array

  int number;

  if (num_arrays != 0){
 	  number = 1;
  } else {
	  number =0;
  }

  for(int i=1; i < totalSize; i++){ 
	if(tempArray[i] != tempArray[i-1]){ // checking if there are any duplicate numbers
	  ++number;
	}
  }

  index =2;
  int* result= (int*) calloc(number+1, sizeof(int));

  result[0]= number; //number of unique elements
  
  if(number != 0) {
	  result[1] = tempArray[0];
  }

  for(int i=1; i< totalSize; ++i){
	  if(tempArray[i] != tempArray[i-1]){ //if its not a duplicate number 
		  result[index]= tempArray[i]; // add it to tempArray
	          ++index;
	  }
  }

  free(tempArray);
  return result;
}
