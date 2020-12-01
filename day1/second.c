#include <stdio.h>
#include <stdlib.h>

int cmpfun(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}

int main(void){
	int n = 0, i, j, k, *list, aux, count = 1000;
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

	for(i = 0; i < n - 2; i++){
		for(j = i + 1; j < n - 1; j++){
			for(k = j + 1; k < n && list[i] + list[j] + list[k] <= 2020; k++){
				if(list[i] + list[j] + list[k] == 2020){
					printf("%d\n", list[i] * list[j] * list[k]);
					
					free(list);
					return 0;
				}
			}
		}
	}

	free(list);

	return 0;
}

