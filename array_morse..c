
/*1 char * morse [26] = { " . - " , " -... " , " -. -. " ,
2 " -.. " , " . " , " .. -. " , " -.. " , " .... " , " .. " ,
3 " . - - -" , " -. -" , " . -.. " , " --" , " -. " ,
4 " ---" , " . - -. " , " . -. " , " ... " ,
5 " -" , " .. - " , " . - - " , " ... - " ,
6 " -.. - " , " -. -" , " - -.. " };
here defined morse codees. each one char corresponds to letter a to z*/

/*eng[] is an array of strings={apple,banana,orange}*/

#include <stdio.h>
#include <ctype.h>

void eng_to_morse(char *morse[], char *eng[], char *result[])
{
//NULL indicates the end of an array
//'\0' indicates the end of a string(word)

	for(int i=0; eng[i] != NULL ; ++i}
	{	
		for(int j=0; eng[i][j] != '\0'; ++j)
		{
			if(isupper(eng[i][j])
			eng[i][j]=tolower(eng[i][j]);
			

			//find the index of current letter in alphabet order
			int index = eng[i][j]-'a';

			if(index>0 && index<26)

			//locates to the correspond index in morse
			result[i][j] = morse[index];
		}
	}	
}
