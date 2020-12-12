#include <stdio.h>
#include <stdlib.h>

int main(void){
	unsigned long long *nums, l, s, invalid = 15353384U;
	int i, j, p_sum, n = 0, max_nums = 1000;
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

	for(i = 0; nums[i] < invalid; i++){
		l = nums[i];
		s = nums[i];

		p_sum = nums[i];

		for(j = i + 1; p_sum < invalid; j++){
			p_sum += nums[j];

			if(nums[j] < s)
				s = nums[j];

			if(nums[j] > l)
				l = nums[j];
		}

		if(p_sum == invalid){
			printf("%llu\n", l + s);
			break;
		}
	}

	free(nums);

	return 0;
}

