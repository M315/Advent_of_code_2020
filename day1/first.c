#include <stdio.h>
#include <stdlib.h>

int cmpfun(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}

int main(void){
	int n = 0, i, j, *list, aux, count = 1000;
	FILE *pf;

	pf = fopen("first_input.txt", "r");
		if(pf == NULL){printf("Err: No File\n"); return 1;}
	
	list = (int*)malloc(1000 * sizeof(int));
	while(fscanf(pf, "%d", &aux) != EOF){
		list[n] = aux;
		n++;
		
		if(n == count){
			count += 1000;
			list = (int*)realloc(list, count * sizeof(int));
		}
	}

	qsort(list, n, sizeof(int), cmpfun);

	for(i = 0; i < n - 1; i++){
		for(j = i + 1; j < n && list[i] + list[j] <= 2020; j++){
			if(list[i] + list[j] == 2020){
				printf("%d\n", list[i] * list[j]);
				
				free(list);
				return 0;
			}
		}
	}

	free(list);

	return 0;
}

