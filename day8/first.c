#include <stdio.h>
#include <stdlib.h>

typedef struct instruction{
	char name[4];
	int val;
} ins;

int main(void){
	int i, n, *used, accumulator = 0, list_max = 1000;
	ins *list = (ins*)malloc(list_max * sizeof(ins));
	FILE *pf;

	pf = fopen("first_input.txt", "r");
		if(pf == NULL){printf("Err: No File\n"); return 1;}
	
	n = 0;
	while(fscanf(pf, "%s %d\n", list[n].name, &list[n].val) != EOF){
		n++;
		if(n == list_max){
			list_max += 1000;
			list = (ins*)realloc(list, list_max * sizeof(ins));
		}
	}

	used = (int*)calloc(n, sizeof(int));
	i = 0;
	while(!used[i]){
		used[i] = 1;
		
		if(list[i].name[0] == 'a'){
			accumulator += list[i].val;
			i++;
		}else if(list[i].name[0] == 'j'){
			i += list[i].val;
		}else{
			i++;
		}
	}

	printf("%d\n", accumulator);

	free(used);
	free(list);
	fclose(pf);

	return 0;
}

