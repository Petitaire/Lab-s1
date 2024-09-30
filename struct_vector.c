#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*struct of a n-dimension vector*/
typedef struct
{
	int dim;
	double *value;
}NVec;

/*create a vector of type NVec and allocate memeory*/ 
NVec initialization(int dim)
{
	NVec vector;
	vector.dim = dim;
	vector.value =(double*)malloc(dim*sizeof(double));
	return vector;
}

/*user input each value*/
void input_value(NVec *vector)
{
	for(int i=0; i<vector->dim; ++i)
	{
		printf("please enter the %d-th value:", i+1);
		scanf("%lf", &vector->value[i]);
	}

//length = magnitude	
double length(NVec *vector)
{
	double sum=0;
	double result;
	for(int i=0; i<vector->dim; ++i)
	{
		sum+=vector->value[i]*vector->value[i];
	}
	result = sqrt(sum);
	return result;
}
/*calculate the sum of two vector*/
Nvec add(NVec *vector1, NVec *vector2)
{
	NVec vector_sum = initialization(vector1->dim);
	for(int i=0; i<vector1->dim; ++i)
	{
		vector_sum.value[i]=vector1->value[i]+vector2->value[i];
	}
	return vector_sum;
}

/*compare the length of two vector*/
int NVecCmp(NVec *v1, NVec *v2)
{
	double length1 = length(v1);//without & because v1 is already pointer
	double length2 = length(v2);
	if(length1<length2)
		return -1;
	else if(length1==length2)
		return 0;
	else
		return 1;
}

int main(int argc, char *argv[])
{
	int dim;
	printf("please enter the dimension of vector:");
	scanf("%d", &dim);

	NVec vector1 = initialization(dim);
	printf("Input for vector 1.");
	input_value(&vector1);

	NVec vector2 = initialization(dim);
	printf("Input for vector 2.");
	input_value(&vector2);
	
	double length1=length(&vector1);
	double length2=length(&vector2);

	NVec sum = add(&vector1, &vector2);


	free(vector1.value);
	free(vector2.value);
	free(sum.value);
	
	return 0;
}
