#define MAX (100000 + 7)

using namespace std;

char text[MAX];
int suffix_array[MAX];
int position[MAX];
int lcp_array[MAX];

int gap;
int size;

bool suffix_compare(int i, int j) {
	if (position[i] != position[j])
    	return position[i] < position[j];

    i += gap;
    j += gap;	

    if (i < size and j < size)
    	return position[i] < position[j];
        
    return i > j;
}

class StringHandler{
	public:
	StringHandler() {}

	int dict_value(char c) {
		if ('0' <= c && c <= '9')
            return c - '0';

        if ('A' <= c && c <= 'Z')
            return 20 + c - 'A';

        if ('a' <= c && c <= 'z')
            return 50 + c - 'a';

        return 0;
	}

	void build_suffix_array() {
		int tmp[size];
		
		memset(tmp, 0, sizeof tmp);

		for(int i = 0;i < size; i++) {
			position[i] = dict_value(text[i]);
            suffix_array[i] = i;
		}

		gap = 1;

		while( (gap >> 1) < size) {
			
			sort(suffix_array, suffix_array + size, suffix_compare);

			for(int i = 1; i < size; i++) {
				tmp[i] = tmp[i-1];

				if (suffix_compare(suffix_array[i-1], suffix_array[i]))
                    tmp[i] += 1;
            }

            for(int i = 0; i < size; i++)
            	position[suffix_array[i]] = tmp[i];

            gap *= 2;
		}
	}

	void build_lcp() {
		memset(lcp_array, 0, sizeof lcp_array);
		int sum_lcp = 0;

		text[size+1] = text[size];
		text[size] = '@';

		for(int c = 0, j = 0, k = 0, i = 0, __length = size; i <  __length; i++) {
			c = 0;
			
			if(i) {
	            j = suffix_array[i-1];
	            k = suffix_array[i];				
			}
			else {
	            j = size;
	            k = suffix_array[i];				
			}

			for(; ; j++,k++,c++)
			 	if(text[j] != text[k])
					break;

			lcp_array[i] = c;
	        sum_lcp += c;
		}

		text[size] = text[size+1];
	}
};