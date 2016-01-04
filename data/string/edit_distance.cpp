#define TAM (2007)

int min_of_3(int a, int b, int c) {
	return min(min(a, b), c);
}

int edit_distance[TAM][TAM];

int Wagner_Fischer_algorithm(string A, string B)
{
	memset(edit_distance, 0, sizeof edit_distance);

	for(int i = 1; i <= A.size(); edit_distance[i][0] = i++);
	for(int i = 1; i <= B.size(); edit_distance[0][i] = i++);

	for(int j,i = 1;i <= A.size();i++)
		for(j = 1;j <= B.size();j++)
			if(A[i-1] == B[j-1])
				edit_distance[i][j] = edit_distance[i-1][j-1];
			else
				edit_distance[i][j] = min_of_3(
					edit_distance[i-1][j],  // a deletion
					edit_distance[i][j-1],  // an insertion
					edit_distance[i-1][j-1] // a substitution
				) + 1;

	return edit_distance[A.size()][B.size()];
}