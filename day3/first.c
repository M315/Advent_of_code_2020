#include <stdio.h>
#include <stdlib.h>

int main(void){
	int n, m = 1, m_max = 1000, i, j, trees = 0;
	char **map, aux[100];
	FILE *pf;

	pf = fopen("first_input.txt", "r");
		if(pf == NULL){printf("Err: No File\n"); return 1;}
	
	map = (char**)malloc(m_max * sizeof(char*));

	fgets(aux, 100, pf);

	i = 0;
	while(aux[i] != '\n')
		i++;

	n = i;
	map[0] = (char*)malloc(n * sizeof(char));
	for(i = 0; i < n; i++)
		map[0][i] = aux[i];

	while(fgets(aux, 100, pf) != NULL){
		map[m] = (char*)malloc(n * sizeof(char));
		for(i = 0; i < n; i++)
			map[m][i] = aux[i];

		m++;

		if(m == m_max){
			m_max += 1000;
			map = (char**)realloc(map, m_max * sizeof(char*));
		}

	}

	for(i = 0, j = 0; i < m; i++, j = (j + 3) % n)
		if(map[i][j] == '#')
			trees++;

	printf("%d\n", trees);

	for(i = 0; i < m; i++)
		free(map[i]);
	free(map);
	
	return 0;
}

