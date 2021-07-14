void permute(int *array, int i, int length) { 
  if (length == i){
	  
     printArray(array, length);
     return;
  }
  
  int j = i;
  for (j = i; j < length; j++) { 
  
     swap(array+i,array+j);
     permute(array,i+1,length);
     swap(array+i,array+j);
	 
  }
  return;
}