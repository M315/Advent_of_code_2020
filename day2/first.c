#include <stdio.h>
#include <stdlib.h>

int main(void){
	int lower, upper, count, valid = 0;
	char ctrl, pass;
	FILE *pf;

	pf = fopen("first_input.txt", "r");
		if(pf == NULL){printf("Err: No File\n"); return 1;}
	
	while(fscanf(pf, "%d-%d", &lower, &upper) != EOF){
		fscanf(pf, " %c: ", &ctrl);

		count = 0;

		do{
			fscanf(pf, "%c", &pass);
			if(pass == ctrl)
				count++;
		}while(pass != '\n');

		if(count >= lower && count <= upper)
			valid++;
	}

	printf("%d\n", valid);
	
	return 0;
}

