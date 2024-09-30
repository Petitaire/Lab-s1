#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*data of EPFU student*/

typedef enum
{
	Male;
	Female;
	Other;
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

/*check if two students information are identical*/
bool equalEntry(EPFUStud *student1, EPFUStud *student2)
{
	if(strcmp(student1->name,student2->name)==0 &&
	student1->sex == student2->sex &&
	student1->phone == student2->phone &&
	student1->id == student2->id &&
	student1->grades.scale100 == student2->grades.scale100 &&
	student1->grades.scale5 == student2->grades.scale5 &&
	student1->final_grade == student2->final_grade)
		return true;
	else return false;
}

/*compare the last name of two students, which alphabetically comes first*/ 
bool comesFirst(EPFUStud *student1, EPFUStud *student2)
{
	/*strrchr: pointer to an array right after ' '*/
	char* last_name1 = strrchr(student1->name, ' ');
	char* last_name2 = strrchr(student2->name, ' ');

	if(last_name1!= NULL && last_name2!= NULL && strcasecmp(last_name1, last_name2)!=0)
	{
		int last_name_comparison=strcasecmp(last_name1+1, last_name2+1);
		/*+1 to skip the space*/
	
	return last_name_comparison<0
	/*<0 returns true, means nam 1 comes first, >0 return false, means name2 come first*/
	}

	int first_name_comparison = strcasecmp(student1->name, student2->name);
	return first_name_comparison<0;

}


int main(int argc, char *argv[])
{
	EPFUStud student1; //define a variable of type EPFUStud

	//input information
	strcpy(student1.name, "Kuba");
	student1.sex = Male;
	student1.phone = 789524635;
	student1.id = 345762;	
	student1.grades.scale100 = 90;
	student1.grades.scale5 = 4.5;
	student1.final_grade = 80.5;


	return 0;
}
