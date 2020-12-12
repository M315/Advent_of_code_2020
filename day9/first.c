#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
	unsigned long long *nums;
	int i, j, k, n = 0, max_nums = 1000;
	bool check;
	FILE *pf;

	pf = fopen("first_input.txt", "r");
		if(pf == NULL){printf("Err: No File\n"); return 1;}
	
	nums = (unsigned long long*) malloc(max_nums * sizeof(unsigned long long));
	while(fscanf(pf, "%llu", &nums[n]) != EOF){
		n++;
		if(n == max_nums){
			max_nums += 1000;
			nums = (unsigned long long*)realloc(nums, max_nums * sizeof(unsigned long long));
		}
	}
	
	fclose(pf);

	for(i = 25; i < n; i++){
		check = false;
		for(j = i - 25; j < i - 1 && !check; j++)
			for(k = j + 1; k < i && !check; k++)
				if(nums[i] == nums[j] + nums[k])
					check = true;
		if(!check){
			printf("%llu\n", nums[i]);
			break;
		}
	}

	free(nums);

	return 0;
}

