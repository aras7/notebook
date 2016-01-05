int max_sum_less_than_p(int arr[], int N, int P) {

    int last = 0, x = 0,answer = 0;

    for(int i = 0;i < N;i++) {

        x += arr[i];

        while(x > P && last < i)
        	x -= arr[last++];

        if(x > P)
        	x = 0,last++;

        if(x > answer)
        	answer = x;
    }

    return answer;
}
