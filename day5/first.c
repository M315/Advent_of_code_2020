#include <stdio.h>
#include <stdlib.h>

int main(void){
	int n, pow, row, col, id, max_id = 0;
	char s[12];
	FILE *pf;

	pf = fopen("first_input.txt", "r");
		if(pf == NULL){printf("Err: No File\n"); return 1;}
	
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
		
		id = (row * 8) + col;
		if(max_id < id)
			max_id = id;
	}

	printf("%d\n", max_id);

	fclose(pf);

	return 0;
}

