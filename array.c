#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//*arr = arr[] = array of integer(treated as pointer in function
//**arr = *arr[] = array of pointers(treated as pointer to pointer in function)

void sort_array_of_integer(int arr[], int length)
{
	int temp;
	
	for(int i=0; i<length-1; ++i)
	{
		for(int j=i+1; j<length; ++j)
		{
			if(arr[i]>arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;	
			}	
		}
	}
}

void sort_array_of_pointer(int *arr[], int length)
{
//here using * to compare value is necessary because it's an array to INTEGER, so we need to dereference the pointer.
	int *temp;
	
	for(int i=0; i<length-1; ++i)
	{
		for(int j=i+1; j<length; ++j)
		{
			if(*arr[i]>*arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;				
			}	
		}
	}
}

void sort_array_of_pointers_alphabetically(char* lineptr[], int length)
{
//when we pass an array of pointers to char, it means we are solving with an array of strings like lineptr={"apple", "banana", "orrange")
//so we should use strcmp to compare

	char *temp;

	for(int i=0; i<length-1; ++i)
	{
		for(int j=i+1; j<length; ++j)
		{
			if(strcmp(lineptr[i],lineptr[j])>0)
			{
				temp=lineptr[i];
				lineptr[i]=lineptr[j];
				lineptr[j]=temp;
			}
		}
	}
}

//if str1="apple", str2="orange", str1<str2 alphabetically, the result of strcmp<0


int compare_arrays_of_char(char str1[], char str2[], int length1; int length2)
{
	int difference;
	int max = length1;

	if(length1!=length2)
	{
		difference = abs(length1-length2);	
		max = (length1 > length2) ? length1 : length2;
	}


	for(int i=0; i<max; ++i)
	{
		if(str1[i] != str2[i] || str2[i] == NULL)
		difference++;
	}

	return difference;
}

//for example, difference number of "flower" and "fly" is 4: 'o','w','e','r'



void concatenat_arrays_of_integer(int arr1[], int arr2[], int length1, int length2)
{
	int new_arr[length1+length2];

	for(int i=0; i<length1+length2; ++i)
	{
		if(i<length1)
		new_arr[i]=arr1[i];
		else
		new_arr[i]=arr2[i-length1];
	}

	/*or*/

	for(int i=0; i<length1; ++i)
	{
		new_arr[i]=arr1[i];
	}
	
	for(int i=0; i<length2; ++i)
	{
		new_arr[length1+i]=arr2[i];
	}

}	

void swap_elements_array_of_pointer(int *arr[], int length, int i, int j)
{
	int *temp;
	temp = arr[i];
	arr[i]= arr[j];
	arr[j] = temp;	
}



void copy_arr(int arr1[], int length, int arr2[])
{
	for(int i=0; i<length; ++i)
	{
		arr2[i]=arr1[i];
	}
}
