#ifndef REPLACEWHITESPACE

#include <stdio.h>
#include <string.h>

char* replaceWS(char *oldstring, char *newString){

	int i = 0;
	int j = i;
	while(oldstring[i] != '\0'){
	
		if(oldstring[i] != ' '){
			newString[j] = oldstring[i];
		}else{
			newString[j] = '%';
			j++;
			newString[j] = '2';
			j++;
			newString[j] = '0';
		}
		j++;
		i++;
	}
	newString[j] = '\0';

	return newString;
}

int main(){

	char *st = "Hello Brave New World";
	char *np;

	printf("%s\n", st);
	np = replaceWS(st,np);


	printf("Replacing whitespaces in \"%s\" \n\t =>\"%s\"\n", st, np);
}
#endif

