#include <stdio.h>
#include <stdlib.h>

int main(void){
	int sum = 0, n, count, *questions;
	char s[30];
	FILE *pf;

	pf = fopen("first_input.txt", "r");
		if(pf == NULL){printf("Err: No File\n"); return 1;}
	
	questions = (int*)calloc(26, sizeof(int));

	count = 0;
	while(fgets(s, 30, pf)){
		if(s[0] == '\n'){
			for(n = 0; n < 26; n++)
				if(questions[n] == count)
					sum++;
			
			count = 0;

			free(questions);
			questions = (int*)calloc(26, sizeof(int));
		}else{
			count++;
			for(n = 0; s[n] != '\n'; n++)
				questions[((int) s[n]) - 97]++;
		}
	}
	for(n = 0; n < 26; n++)
		if(questions[n] == count)
			sum++;

	printf("%d\n", sum);
	
	free(questions);
	fclose(pf);

	return 0;
}

