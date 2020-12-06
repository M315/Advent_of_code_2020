#include <stdio.h>
#include <stdlib.h>

int main(void){
	int sum = 0, n, *questions;
	char s[30];
	FILE *pf;

	pf = fopen("first_input.txt", "r");
		if(pf == NULL){printf("Err: No File\n"); return 1;}
	
	questions = (int*)calloc(26, sizeof(int));

	while(fgets(s, 30, pf)){
		if(s[0] == '\n'){
			for(n = 0; n < 26; n++)
				sum += questions[n];
			
			free(questions);
			questions = (int*)calloc(26, sizeof(int));
		}else{
			for(n = 0; s[n] != '\n'; n++)
				questions[((int) s[n]) - 97] = 1;
		}
	}
	for(n = 0; n < 26; n++)
		sum += questions[n];

	printf("%d\n", sum);
	
	fclose(pf);

	return 0;
}

