#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
	int lower, upper, count, valid = 0;
	char ctrl, pass;
	bool l, u;
	FILE *pf;

	pf = fopen("first_input.txt", "r");
		if(pf == NULL){printf("Err: No File\n"); return 1;}
	
	while(fscanf(pf, "%d-%d", &lower, &upper) != EOF){
		fscanf(pf, " %c: ", &ctrl);
		l = false;
		u = false;

		count = 1;

		do{
			fscanf(pf, "%c", &pass);
			if(count == lower && pass == ctrl)
				l = true;
			if(count == upper && pass == ctrl)
				u = true;
			count++;
		}while(pass != '\n');

		if(l ^ u)
			valid++;
	}

	printf("%d\n", valid);
	
	return 0;
}

