//CECS 424 ASSIGNMENT 1
//mergesort.c
//Dominique Oyco - 014605758

#include <stdio.h>
#include <stdlib.h>

//mergesort steps
//1. Divide the array into 2 parts of length n/2. If the length is an odd number, we round it off.
//2. Sort the right half and the left half of the array recursively
//3. Merge the sorted left half and the sorted right half of the array until the whole array is sorted

//this function allows the user to obtain a new array from an index of one specific element to another
int* split(int *a, int first, int last){
	int* newArray = (int*) malloc((last - first) * sizeof(int));  //need to dynamically allocate the new array because the array size might change

	for(int i = first; i < last; i++){							  //iterate through the original array from the first element until it reaches the element before the last
		newArray[i - first] = a[i];								  //store the elements iterated on the new array
	}

	return newArray;											  //this function returns the new array
	//free(newArray); 											  //free the memory space allocated by the new array
}

//This function combines two arrays into one. Msort function will call this to combine the sorted array
//param: *a - pointer to the array containing the integers to be sorted
//param: *leftArray - pointer to the left side array of the original array a
//param: leftSize - the length of the left array
//param: *rightArray - pointer to the right side array of the original array a
//paramL rightSize - the right size of the right array
void merge(int *a, int *leftArray, int leftSize, int *rightArray, int rightSize){ //if error, change a to slicedarray
	int i = 0; 									//index for the left array
	int j = 0; 									//index for the right array

	//this loop determines which element in the left or right side is greater and inserts it back to the original array
	while(i < leftSize && j < rightSize){		
        if (leftArray[i] < rightArray[j])		//if leftarray < rightarray, insert the element on the left side first
        {
            a[i+j] = leftArray[i];				//go to the left array and and insert the current element on the current index back to a
            i++;								//increment i
        }
        else 									//if leftarray < rightarray, insert the element on the right side
        {
            a[i+j] = rightArray[j];				//go to the right array and insert the current element on the current index back to a
            j++;								//increment j
        }
	}

	//this loop merges the left array into the original array a
	for(; i<leftSize; i++){ 					//since i = 0 is already declared above. I did not include on the for loop 
		a[i+j] = leftArray[i];					//merge the left array into the original array a
	}

	//this loop merges the right array into the original array a
	for(; j<rightSize; j++){ 					//since j = 0 is already declared above. I did not include on the for loop 
		a[i+j] = rightArray[j];					//merge the right array into the original array a
	}

	free(leftArray);							//free the left array from the memory
	free(rightArray);							//free the right array from the memory
}

//required msort function
//param: *a - pointer to the array containing the integers to be sorted
//param: n - the length of the array
void msort(int *a, int n){
	if(n <= 1){											//if the array length is 0 or less then just return nothing
		return;
	}

	int mid = n/2;										//The middle point in the array. If it's odd, we round it up
	int midLast = n-mid;								//length of array - middle = length of the right array

	int *leftArray = split(a, 0, mid+1);				//Split the original array into two. 
														//The left side are elements from index 0 to the element right after the middle element
	int *rightArray = split(a, mid, n);					//Split the original array into two. 
														//The right side are elements from the middle element all the way to the last element

	msort(leftArray, mid);								//Use recursion to sort the array on the left side.
	msort(rightArray, midLast);							//Use recursion to sort the array on the right side. 

	merge(a, leftArray, mid, rightArray, midLast);		//merge the two sorted arrays together
}

//use to print the array of integers
//param: *a - pointer to the array containing the integers to be sorted
//param: n - the length of the array
void arrayPrinter(int *a, int n){
	printf("The sorted array using mergesort: ");
	for (int i = 0; i < n; i++)		//print the array element by element by iterating through it
	{
		printf("%d ", a[i]);   		//print the current element in the array that the index is pointing to. 
									//%d is the format specifier to print an integer and \t is tab
	}
	printf("\n"); 					//Just to put the runtime on the newline
}

int main(){
    int *numArray = NULL; 											//the array that will store the elements to be sorted
    int i; 															//a counter
    int arrSize;													//the size of the array

    printf("\nPlease Enter Number of elements in an array  :  "); 	//ask the user for the size of the array
    scanf("%d", &arrSize);											//store the user input in the address of the arraySize 
    numArray = (int*) malloc(arrSize * sizeof(int)); 				//need to dynamically allocate the new array because the array size might change

    printf("\nPlease Enter %d elements in the Array \n", arrSize);	//ask the user for the elements to be inserted inside the array
    for (i = 0; i < arrSize; i++)									//continue getting the user input until the pointer reaches the max size of the array
    {
        scanf("%d", &numArray[i]);									//get the elements and store it on the address of the numarray on each index
    }  

	printf("Sorting the array using mergesort...\n");	
	msort(numArray, arrSize);										//pass in the array and the arraysize to the msort function so the mergesort operation can be performed
	arrayPrinter(numArray, arrSize);								//print the new sorted array
	free(numArray);
    return 0;														//return 0 if process went without problems
}