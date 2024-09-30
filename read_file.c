#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
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


/*array of struct to NVec: 
in parameter arr or arr[](preferably),access with arr.dim

array of pointer to NVec: 
in parameter *arr(preferably) of arr[], access with arr[]->dim or(*arr[]).dim

pointer of pointer to NVec:
in parameter (**arr or *arr[]), use arr[i][j].dim*/

void read_file(const char* filename, NVec arr[], NVec *arrPtr)
{
	FILE *file = fopen(filename, "r"); //file name will be pass to function

	if(file == NULL)
	{
		printf("Error opening the file.\n");
		return;
	}

	int num_vectors;
	fscanf(file, "%d\n", &num_vectors);

	arr = (NVec*)malloc(num_vectors*sizeof(NVec));

	//memeory allocation for simple array

	arrPtr = (NVec**)malloc(num_vectors*sizeof(NVec*));
	for (int i = 0; i < num_vectors; ++i)
   	{
        	arrPtr[i] = (NVec*)malloc(sizeof(NVec));
    	}//memeory allocation for array of pointer


       	//suppose the first line we have the number of vectors
	//we allocate memeory for the whole arr and arrPtr
	
	for(int i=0; i<num_vectors; ++i)
	{
		fscanf(file, "%d", &arr[i].dim); 
	        arr[i].value = (double*)malloc(arr[i].dim*sizeof(double));
		
		arrPtr[i]->dim = arr[i].dim;
		arrPtr[i]->value = (double*)malloc(arrPtr[i]->dim*sizeof(double));
	       	//suppose we scan one vector on each line
		//allocate memeory for value[] in each vector

		for(int j=0; j<arr[i].dim; ++j)
		{
			double temp;
		   	fscanf(file, "%lf", &temp);
			
			arr[i].value[j] = temp;
			arrPtr[i]->value[j] = temp;
		}
		fscanf(file, "\n");
	}
	
	fclose(file);
}

//read a file with complex
void read_file2(const char *filename, Complex arr[], Complex *arrPtr)
{
	FILE *file = fopen(filename, "r");
	if(file==NULL)
	{
		printf("Error Opening File\n");
	}

	//suppose there's no information about the number of complex numbers in file
	//we need to count how many complex numbers - how many new lines in file
	
	int ch;
	int num_complex=0;
	while(ch = fgetc(file)!= EOF)
	{
		if(ch== '\n') 
			num_complex++; //1 new line = 1 num_complex
	}

	fseek(file,0,SEEK_SET); //return to the beginning of file

	arr=(Complex*)malloc(num_complex*sizeof(Complex));
	arrPtr=(Complex*)malloc(num_complex*sizeof(Complex));
	
	for(int i=0; i<num_complex; ++i)
	//or use if(!feof(file)), feof check if it's the end of fileś
	{
		int tempRE, tempIM;
		fscanf(file, "%*d%d%d", &tempRE, &tempIM); //* to skip the first integer
		arr[i].RE = tempRE;
		arrPtr[i]->RE = tempRE;
		arr[i].IM = tempIM;
		arrPtr[i]->IM = tempIM;
	}

	fclose(file);
}

//read a file with EPFUStud

void read_file3(const char *filename, EPFUStud *arr, EPFUStud **arrPtr)
{
	
	FILE *file = fopen(filename, "r");
	if(file==NULL)
	{
		printf("Error Opening File\n");
		return;
	}

	char ch;
	int num_students=0;
	while(ch=getc(file)!=EOF)
	{
		if(ch=='\n')
			num_students++;
	}

	fseek(file,0,SEEK_SET);

	arr=(EPFUStud*)malloc(num_students*sizeof(EPFUStud));
	arrPtr=(EPFUStud**)malloc(num_students*sizeof(EPFUStud*));
 
	for(int i=0; i<num_students; ++i)
	{
		arrPtr[i]=(EPFUStud*)malloc(sizeof(EPFUStud));

		fscanf(file, "%s",arr[i].name) //scan to string, no &
		
		char sexStr[20];
		fscanf(file, "%s", sexStr); //scan to string no need &

		if(strcmp(sexStr, "Male")==0)
			arr[i].sex = Male;
		else if(strcmp(sexStr, "Female")==0)
			arr[i].sex = Female;
		else if(strcmp(sexStr, "Other")==0)
			arr[i].sex = Other;

		fscanf(file, "%d%d%d%f%f", &arr[i].phone, &arr[i].id, &arr[i].grades.scale100, &arr[i].grades.scale5, &arr[i].finalu_grade);

		strcpy(arrPtr[i]->name, arr[i].name);
		arrPtr[i]->sex = arr[i].sex;
		arrPtr[i]->id = arr[i].id;
		arrPtr[i]->phone = arr[i].phone;
		arrPtr[i]->grades->scale100 = arr[i].grades.scale100;
		arrPtr[i]->grades->scale5 = arr[i].grade.scale5;
		arrPtr[i]->final_grade = arr[i].final_grade;
	}
	fclose(file);
}

//count number of char in the file
int coundt_char(const char*filename)
{
	FILE *file = fopen(filename, "r");

	if(file==NULL)
	{
		printf("Error Opening File.\n");
		return;
	}

	char ch;
	int count=0;
	while((ch=fgetc(file))!= EOF)
	{
		if(ch!= ' ' && ch!='\n')
			count++;
	}
	fclose(file);
	return count;
}

//count number of strings in the file
//in other to return more than one value, we need to pass pointers to functions
void coundt_strings(const char*filename, int *count_str, int *count_line)
{
	FILE *file = fopen(filename, "r");

	if(file==NULL)
	{
		printf("Error Opening File.\n");
		return;
	}
	
	char ch;
	int string =0;
	int line =0;

	//method 1 to count string (and line
	while((ch=fgetc(file))!=EOF)
	{
		if(ch=='\n')
		{
			line++;
			string++;
		}
		else if(ch== ' ' || ch == '\t' || ch=='\r')
			string++;
	}

	*count_str = string; //use *pointer = value to assign an value to pointer
	*count_line = line;

	//method 2 to count string
	
	int count=0;
	while(fscanf(file, "%*s")==1) 
	// * means read but not store
	// ==1 means onw string is successfully read
	{
		count++;
	}
	*count_str = count;

	//count average num of chars on each line

	fclose(file);
}


