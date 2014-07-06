#ifndef LETTERCASE

#include <stdio.h>

char *a = "aa\0";
char *b = "Bb\0";

int main(){
printf("First Character of sting a -> %c\n", a[0]);
printf("First Character of sting b -> %c\n", b[0]);


if(a[0] >= 'a' && a[0] <= 'z'){
	printf("a[0] is Lower Case\n");
}else{
	printf("a[0] is Upper Case\n");
}

if(b[0] >= 'a' && b[0] <= 'z'){
	printf("b[0] is Lower Case\n");
}else{ 
	printf("b[0] is Upper Case\n");
}

return 0;
}
#endif
