//CECS 424 ASSIGNMENT 1
//quicksort.c
//Dominique Oyco - 014605758

#include <stdio.h>
#include <stdlib.h>

//quicksort steps
//1. create a median of three function to determine the pivot to be used
//2. create a swap function
//3. create a partition function 
//4. create a quicksort function featuring the required quicksort function on the requirements
//5. create another quicksort function to call the quicksort function on #4. 

//This function returns the pivot by using the median of three method
//param: *a - pointer to the array containing the integers to be sorted
//param: first - the first element in the array
//param: last - the last element in the array
//RETURN: first, last, or mid - the median of the first element, last element, and the middle element in an array to be used as a pivot on other methods
int medianOfThree(int *a, int first, int last){
	int mid = (first + last)/2; //determines the middle element in the array

	//(first < mid < last) OR (first > mid > last)
	if((&a[first] < &a[mid] && &a[mid] < &a[last]) || (&a[first] > &a[mid] && &a[mid] > &a[last]))
	{
		return mid; //pivot is the middle of the array
	}
	
	//(mid < first < last OR last > first > mid) OR (mid > first > last OR last < first < mid)
	else if((&a[first] > &a[mid] && &a[first] < &a[last]) || (&a[first] < &a[mid] && &a[first] > &a[last]))
	{
		return first; //pivot is the first element in the array
	}
	
	//(first < last < mid OR mid > last > first) OR (first > last > mid OR mid < last < first)
	else if((&a[first] < &a[last] && &a[mid] > &a[last]) || (&a[first] > &a[last] || &a[mid] < &a[last]))
	{
		return last; //pivot is the last element in the array
	}
	
	else
	{
		return -1; //an error
	}
}

//This function is made to swap value inside an array
//param: *k - original element that needs to be swapped
//param: *l - element that is replacing the original element k
void swap(int *k, int *l){
	int temp = *k; //a temporary variable that is initialized to be the original value to be swapped
	*k = *l; 	  //swapping the old value to the new value
	*l = temp; 	  //setting the temp variable to the new value
}

//This function partitions the array based on the pivot calculated on the Median of Three Function
//param: *a - pointer to the array containing the integers to be sorted
//param: first - the first element in the array
//param: last - the last element in the array
//RETURN: (i+1) - The index of the last element of the first partition
int partition(int *a, int first, int last){
	int median = medianOfThree(a, first, last); //Use Median of Three to get the median of the first, last, and middle elements in the array
	int pivot = a[median]; 						//Get the pivot of the array using Median of Three
	swap(&a[median], &a[last]);					//swap the median and the last element in the array

    int i = (first - 1);  						//index where the left marker of the array begins

   	//This loop determines the elements that goes to the left of the pivot
    for (int j = first; j < last; j++) 			//j is the index inside the marker. Starts at b[0]
    {
        if (a[j] <= pivot)						
        {
            i++;    							// the left marker increments to the next element if b[j] <= pivot
            swap(&a[i], &a[j]); 
            //swap the current position of the marker with the current position of the element inside
            //to determine which elements are in the left side of the pivot. Once the pivot is reached, 
            //the remaining elements are in the right half of the array
        }
    }	    
    
    //needs to swap the last element with the index of the marker + 1 b/c marker + 1 is the index of the 
    //last element of the first partition
    swap(&a[i + 1], &a[last]); 										
    return (i + 1);													//return the index of the last element of the first partition 
}

//This function sorts the array using quicksort
//param: *a - pointer to the array containing the integers to be sorted
//param: first - the first element in the array
//param: last - the last element in the array
void qsort1(int *a, int first, int last){//i is first and j is last
	//if first = last, there is only one element and thus no sorting is needed
	//if first > last, it is not valid since last is the length of the array
	if(first < last) 
	{
		int p = partition(a, first, last);  						//call the partioning to partition the array
		qsort1(a, first, p - 1); 		   							//sorts the element on the left side of the pivot
		qsort1(a, p + 1, last); 		  							//sorts the elements on the right side of the pivot
	}
}

//required function
//param: *a - pointer to the array containing the integers to be sorted
//param: n - the length of the array
void qsort2(int *a, int n){ 										//quick sort array a with n elements in place in C
	qsort1(a, 0, n-1);												//call the other quicksort 
}

//use to print the array of integers
//param: *a - pointer to the array containing the integers to be sorted
//param: n - the length of the array
void arrayPrinter(int *a, int n){
	printf("The sorted array using quicksort: ");
	for (int i = 0; i < n; i++) 									//print the array element by element by iterating through it
	{
		printf("%d ", a[i]);   										//print the current element in the array that the index is pointing to. 
																	//%d is the format specifier to print an integer and \t is tab
	}
	printf("\n"); 													//Just to put the runtime on the newline
}

int main(){
    int *numArray = NULL; 											//the array that will store the elements to be sorted
    int i; 															//a counter
    int arrSize;													//the size of the array

    printf("\nPlease Enter the Number of elements in an array:  "); //ask the user for the size of the array
    scanf("%d", &arrSize);											//store the user input in the address of the arraySize 
    numArray = (int*) malloc(arrSize * sizeof(int)); 				//need to use malloc to manually allocate the memory since I'm using a pointer

    printf("\nPlease Enter %d elements of an Array \n", arrSize);	//ask the user for the elements to be inserted inside the array
    for (i = 0; i < arrSize; i++)									//continue getting the user input until the pointer reaches the max size of the array
    {
        scanf("%d", &numArray[i]);									//get the elements and store it on the address of the numarray on each index
    }  

	printf("Sorting the array using quicksort\n");	
	qsort2(numArray, arrSize);										//call the quicksort function to sort the elements using quicksort
	arrayPrinter(numArray, arrSize);								//print the new sorted array
    return 0;														//return 0 if process went without problems
}
