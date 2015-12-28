#define INF (1 << 30)
#define MAX_NODES (3000 +7)
#define MAX_EDGES (3000 * 3000 + 7)

int edges[MAX_EDGES][3]; // from, to, weight

pair<vector<int>, vector<int> > BellmanFord(int source, int N, int M, bool *cycle) {
  /*
  input:
  N -> nodes,
  M -> edges

  output:
  pair<vector<int>, vector<int>> -> min distances from source, predecesor in path
  cycle -> negative cycle?
  */

  vector<int> min_distance(N, INF);
  vector<int> predecessor(N, -1);

  min_distance[source] = 0;
  predecessor[source] = source;

  for(int i = 1;i < N;i++)
    for(int j = 0;j < M;j++)
      if(min_distance[edges[j][0]] != INF && min_distance[edges[j][0]] + edges[j][2] < min_distance[edges[j][1]]) {
        min_distance[edges[j][1]] = min_distance[edges[j][0]] + edges[j][2];
        predecessor[edges[j][1]] = edges[j][0];
      }

  *cycle = false;

  for(int j = 0;j < M;j++)
    if(min_distance[edges[j][0]] != INF && min_distance[edges[j][0]] + edges[j][2] < min_distance[edges[j][1]]) {
       *cycle = true;
    }

  return pair<vector<int>, vector<int> >(min_distance, predecessor);
}
