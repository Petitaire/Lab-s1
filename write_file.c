#include<stdio.h>
#include<math.h>

typedef struct
{
	int dim;
	double *value;
}NVec;

typedef struct
{
	int RE;
	int IM;
}Complex

typedef enum
{
	Male,
	Female,
	Other,
}SEX;

typedef struct
{
	int scale100;
	float scale5;
}TESTgrades;

typedef struct
{
	char name[20];
	SEX sex;
	int phone;
	int id;
	TESTgrades grades;
	float final_grade;
}EPFUStud;


//stroe an array of 100 NVec in the file named vector.txt
void write_file1(NVec arr[])
{
	FILE *file = fopen("vector.txt", "w"); 
	//open in writing mode, if file doesn't exist, it will be created
	
	if(file!=NULL)
	{
		for(int i=0; i<100; ++i)
		{
		   fprintf(file, "%d-th vector. dim: %d, ", i+1, arr[i].dim);
		
		   for(int j=0; j<arr[i].dim; ++j)
		   {
			fprintf(file, "value: %lf", arr[i].value[j]);
	       	   }

		   fprintf(file, "\n");
	        }
	fclose(file);
}

//write in file vectorCmp.txt : each pair of vectors from the array, result of their comparison
void write_file2(NVec arr[])
{
	FILE *file=fopen("vectorCmp.txt", "w");

	if(file!=NULL)
	{
		for(int i=0; i<50; ++i)
		{	
			double length1, length2;

			fprintf(file, "%d-th pair of vectors.\n", i+1);

//write vector 1 and calculate its length
//
			length1 = print_vector_calcul_length(file,arr,i);

//write vector 2 and calculate its length
//we assume the first pair is:  arr[0] and arr[99]  
		
			length2 = print_vector_calcul_length(file,arr,99-i);

			if(length1>length2)
			fprintf(file, "vector 1 > vector 2.\n");

			else if(length1==length2)
			fprintf(file, "vector 1 = vector 2.\n");

			else
			fprintf(file, "vector 1 < vector 2.\n");
		}

	}

}

double print_vector_calcul_length(FILE *file, NVec arr[], int index)
{
	double sum=0.0;
	double length;

	fprintf(file, "vector %d dim: %d, ", index+1, arr[index].dim);
	for(int j=0; j<arr[indexi].dim; ++j)
	{
		fprintf(file, "value: %lf, ",arr[index].value[j]);
		sum + = (arr[index].value[j]*arr[index].value[j]);

	}
	length = sqrt(sum);
	return length;

}

//stroe an array of 50 Complex in the file named complex.txt

void write_file3(Complex arr[])
{

	FILE *file = fopen("complex.txt", "w");

	if(file==NULL)
	{
		printf("Error Creating File.\n");
		return;
	}

	for(int i=0; i<50; ++i)
	{
		fprintf(file, "%-th complex number: ", i+1);
		fprintf(file, "real part: %d, imaginary part: %d\n", arr[i].RE, arr[i].IM);
	}

	fclose(file);
}

//result of comparison and addition of complex

void write_File4(Complex arr[])
{

	FILE *file = fopen("complexCmp_Oper.txt", "w");

	if(file==NULL)
	{
		printf("Error Creating File.\n");
		return;
	}

	for(int i=0; i<25; ++i)
	{
		fprintf(file,"%d-th pair: ", i+1);
		fprintf(file, "complex 1: real: %d, imaginary: %d\n", arr[i].RE, arr[i].IM);
		fprintf(file, "complex 2: real: %d, imaginary: %d\n", arr[49-i].RE, arr[49-i].IM);

		double mag1 = sqrt(arr[i].RE*arr[i].RE + arr[i].IM*arr[i].IM);
		double mag2 =  sqrt(arr[49-i].RE*arr[49-i].RE + arr[49-i].IM*arr[49-i].IM);

		if(mag1>mag2)
			fprintf(file, "complex1>complex2\n");
		else if(mag1==mag2)
			fprintf(file, "complex1=complex2\n");
		else
			fprintf(file, "complex1=complex2\n");

		fprintf(file,"the sum is: ");
		fprintf(file, "real: %d, imaginary: %d\n", arr[i].RE+arr[49-i].RE, arr[i].IM+arr[49-i].IM);
	}
	fclose(file);
}

//store an array of 42 EPFUStud to a file students.txt

void write_file5(EPFUStud arr[])
{

	FILE *file = fopen("students.txt", "w");
	if(file==NULL)
	{
		printf("Error Opening File.\n");
	}

	const char sex[]={"Male", "Female", "Other"}; 
	//in enum, the first element is represented by 0, second by 1...
	//so we need a string array that corresponds to it
	//str[0] will be first element in enum but type string...


	for(int i=0; i<42; ++i)
	{
		fprintf(file, "%s %s %d %d %d %f %f\n", arr[i].name, sex[arr[i].sex], arr[i].phone, arr[i].id, arr[i].grades.scale100, arr[i].grades.scale5, arr[i].final_grade);
	}

	fclose(file);

}

int main()
{
	NVec arr[100];
	
	int dim=3; //suppose the dimension is the same for all vectors NVec
	//initialization
	for(int i=0; i<100; ++i)
	{
	
		arr[i].dim=dim;
		arr[i].value=(double*)malloc(arr[i].dim*sizeof(double));

		for(int j=0; j<arr[i].dim; ++j)
		{
			printf("The value of the %d-th vector:", j+1);
			scanf("%lf", &arr[i].value[j]);
		}
	}

	return 0;
}
