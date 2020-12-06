#include <stdio.h>
#include <stdlib.h>

int main(void){
	int n, pow, row, col, *id;
	char s[12];
	FILE *pf;

	pf = fopen("first_input.txt", "r");
		if(pf == NULL){printf("Err: No File\n"); return 1;}

	id = (int*)calloc(911, sizeof(int));
	
	while(fgets(s, 12, pf)){
		row = 0;
		pow = 1;
		for(n = 6; n >= 0; n--){
			if(s[n] == 'B')
				row += pow;
			pow *= 2;
		}

		col = 0;
		pow = 1;
		for(n = 9; n >= 7; n--){
			if(s[n] == 'R')
				col += pow;
			pow *= 2;
		}
		
		id[(row * 8) + col] = 1;
	}

	for(n = 1; n < 910; n++)
		if(id[n - 1] && !id[n] && id[n + 1])
			printf("%d\n", n);

	fclose(pf);
	free(id);

	return 0;
}

