int aux[SIZE];

int kadane(int n) {
	int local_max = 0, max_sum = 0;

    for(int i = 0; i < n; i++) {

    	local_max = max(0, local_max + aux[i]);

    	max_sum = max(max_sum, local_max);
    }

    return max_sum;
}