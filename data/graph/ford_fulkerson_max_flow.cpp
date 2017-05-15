#define PI(double(2.0 * acos(0.0)))
#define EPS(double(1.0e-8))
#define INF(1 << 30)
#define INF_LONG(1 LL << 62)

#define TAM(26 * 2 + 1)

using namespace std;

struct Edge;

struct Node {
   int ind;
   bool visited;

   list < Edge > TO;

   Node(): visited(false), ind(0) {}
   Node(int i): ind(i), visited(false) {}
};

struct Edge {
   Node * from, * to;
   int weight;
   int flow;

   Edge * couple;

   Edge() {}
   Edge(Node * f, Node * t): from(f), to(t), weight(0), flow(0) {}
   Edge(Node * f, Node * t, int w): from(f), to(t), weight(w), flow(0) {}
};

const int max_nodes = 500;
Node * cola[10000000];
int cola_ind = 0, cola_size = 0;

class Graph {
   int nodes_size;
   int _flows[max_nodes];
   bool visited[max_nodes];
   Node vect_nodes[max_nodes];

   list<Edge>::iterator previous[max_nodes];

   public:
      Graph(): nodes_size(0) {}
      Graph(int n): nodes_size(n) {
        for (size_t i = 0; i < nodes_size; vect_nodes[i].ind = i++);
     }

   void Ini() {
      for (size_t i = 0; i < nodes_size; i++) {
         vect_nodes[i].ind = i;
         vect_nodes[i].visited = false;
         vect_nodes[i].TO.clear();
      }
   }

   void PRINTF() {
      for (int i = 0; i < nodes_size; i++)
         for (list < Edge > ::iterator it = vect_nodes[i].TO.begin(); it != vect_nodes[i].TO.end(); it++)
            printf("%d -> %d (%d)\n", it - > from - > ind, it - > to - > ind, it - > weight - it - > flow);

   }

   void AddEdge(int f, int t, int w) {
      Edge e[] = {
         Edge( & vect_nodes[f], & vect_nodes[t], w),
         Edge( & vect_nodes[t], & vect_nodes[f], w)
      };

      e[0].couple = & e[1];
      e[1].couple = & e[0];

      vect_nodes[f].TO.push_back(e[0]);
      vect_nodes[t].TO.push_back(e[1]);
   }

   int max_flow(int from, int to) {
      if (from == to) return -7;

      int f, max_flow = 0;

      f = find_max_flow(from, to);

      while (f > 0) {
         max_flow += f;

         int x = to;

         while (x != from) {
            previous[x]->flow += f;

            if (previous[x]-> couple != NULL) previous[x]->couple->flow += f;

            x = previous[x]-> from - > ind;
         }

         f = find_max_flow(from, to);
      }

      return max_flow;
   }

   int find_max_flow(int sourse, int destination) {
      memset(_flows, 0, sizeof _flows);
      memset(visited, false, sizeof visited);

      cola_ind = cola_size = 0;
      cola[cola_size++] = & vect_nodes[sourse];

      _flows[sourse] = INF;

      bool found = false;

      for (; cola_ind < cola_size && !found; cola_ind++) {
         for (list < Edge > ::iterator it = cola[cola_ind] - > TO.begin(); it != cola[cola_ind] - > TO.end() && !found; it++)
            if ((it - > weight - it - > flow) > 0 && !visited[it - > to - > ind]) {
               _flows[it - > to - > ind] = min(_flows[cola[cola_ind] - > ind], it - > weight - it - > flow);

               previous[it - > to - > ind] = it;

               cola[cola_size++] = it - > to;

               visited[it - > to - > ind] = true;

               if (it - > to - > ind == destination)
                  found = true;
            }
      }

      if (!found) return 0;

      return _flows[destination];
   }

};

class Graph {
   vector<vector<int> >nodes;

   Graph() {}
   Graph(int n){
      nodes = vector<map<int, int> >nodes(n);
   }

   void AddEdge(int f, int t, int flow) {
       nodes[f][t] = flow;
       nodes[t][f] = 0;
   }

   int MaxFlow(int f, int t) {
       int flow = 0;

       vector<int> aumenting_path;

       aumenting_path = bfs_find_aumenting_path();

       while(aumenting_path.size() > 0) {
           aumenting_path = bfs_find_aumenting_path();
       }

       return flow;
   }
}

int Pos(char c) {
   return c <= 'Z' ? c - 'A' + 1 : c - 'a' + 27;
}

int main(int argc, char * * argv) {
   Graph G(TAM + 1);
   int m, x, y, z, MATRIX[TAM][TAM];
   char a, b;

   cin >> m;

   memset(MATRIX, 0, sizeof MATRIX);

   while (m--) {
      cin >> a >> b >> z;

      x = Pos(a), y = Pos(b);

      MATRIX[min(x, y)][max(x, y)] += z;
   }

   for (int i = 1; i <= TAM; i++)
      for (int j = i + 1; j <= TAM; j++)
         if (MATRIX[i][j] > 0)
            G.AddEdge(i, j, MATRIX[i][j]);

   printf("%d\n", G.MaxFlow(1, 26));

   return 0;
}
