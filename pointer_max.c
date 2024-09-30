#include<stdio.h>

int *find_max(int *arrPtr, int length)
{
	int *max = arrPtr; //or int *max; max=arrPtr
	//equal to max=array[0] or max=&arrPtr[0], but these are direct value and not pointer
	//when copy address from one pointer to another pointer, dereference * is not needed
	//but when declare a pointer, * is always needed
	

	for(int i=0; i<length; ++i)
	{
		if (*(arrPtr+i) > *max)
			max = (arrPtr+i);
	}
	return max;
}

int main(int argc, char* argv[])
{
	char c; //simple variable char
	char *p; //pointer to char	
	p=&c; //p points to char c
	/*or char *p=&c*/

	*p='a'; //assign 'a' to pointer p then to variable c
		//we need to use * when it comes to value
	
	printf("the value of c: %c\n",c);
	printf("the value of p: %c\n",*p); //use * to dereference p and access to the value
	printf("the address of c: %p\n",p); // use p directly to acess to the address
	
	char arr[3];
	p=&arr[0]; //p points the begining of array
	*p ='a'; //assign 'a' to arr[0]
	*(p+1) = 'b';//a[1]
	*(p+2) = 'c';//a[2]

	printf("arr[0]: %c\n", *p);
	printf("arr[1]: %c\n", *(p+1));
	printf("arr[2]: %c\n", *(p+2));
		
	//ask user to define an array of integer
	int length;
	printf("number of element in array: ");
	scanf("%d", &length); // user input value to length

	int array[length];

	for(int i=0; i<length; ++i)
	{
		printf("enter the %d-th value:",i+1);
		scanf("%d", &array[i]);
		//user input value to array

	}

	int *arrPtr = &array[0];
	//arrPtr is a pointer points to array
	
	int *max = find_max(arrPtr, length); 
	//pass arrPtr without & because arrPtr is single pointer, and function requires a single pointer, in the same type we don't need &)
	
	printf("the max is: %d\n", *max);

	return 0;
}
