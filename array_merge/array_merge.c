#include "array_merge.h"
#include <../mergesort/mergesort.c>

int* array_merge(int num_arrays, int* sizes, int** values) {
  
  int totalSize=0;
  int index =1;

  for(int i=0; i < num_arrays; ++i){
	  totalSize = totalSize + sizes[i];
  }	  
  totalSize += 1;
  int* tempArray = (int*)malloc(sizeof(int)*totalSize); 

  for(int i=0; i < num_arrays; ++i){
	  for(int j=0; j < sizes[i]; ++j){
		  tempArray[index]= values[i][j];
		  ++index;
		 }
  }
  // need to check if num_arrays = 0
  mergesort(totalSize, tempArray);

  int place = 2;
  for(int i=2, i< totalSize; ++i)
	  if (temp[i] != temp[i-1]){
		temp[place]=temp[i];
		++place;
	  }
  }


	  
  return sizes;
}
