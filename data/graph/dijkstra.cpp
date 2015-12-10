struct Edge;
struct Node
{
    int ind;
    bool visited;
    
    list<Edge>TO;
    
    Node():visited(false),ind(0){}
    Node(int i):ind(i),visited(false){}
};

struct Edge
{
     Node *from,*to;
     int weight;
     
     Edge(){}
     Edge(Node *f,Node *t):from(f),to(t),weight(0){}
     Edge(Node *f,Node *t,int w):from(f),to(t),weight(w){}
};
struct Path
{
     Node *to;
     int time;
     
     Path(){}
     Path(Node *t,int x):to(t),time(x){}
};
class CMP
{
      public: bool operator()(Path &a,Path b)
      {
          return a.time > b.time;
      }
};

class Graph
{
      vector<Node>vect_nodes;
      
      public :
             
      Graph(){}
      Graph(int n)
      {
          vect_nodes.clear();
          vect_nodes = vector<Node>(n);
          for(size_t i = 0;i < vect_nodes.size();vect_nodes[i].ind = i++);
      }

      void Init()
      {
          for(size_t i = 0;i < vect_nodes.size();i++)
          {
              vect_nodes[i].ind = i;
              vect_nodes[i].visited = false;
              vect_nodes[i].TO.clear();
          }
      }

      void AddEdge(int f,int t,int w)
      {
          Edge e(&vect_nodes[f],&vect_nodes[t],w);
          
          vect_nodes[f].TO.push_back(e);
      }

      // Dijkstra
      int Shortest_Path_with_Dijkstra(int from,int to)
      {
          Path p;
          priority_queue<Path,vector<Path> ,CMP> p_queue;
          
          p = Path(&vect_nodes[from],0);
          p_queue.push(p);
          
          while(!p_queue.empty())
          {
              p = p_queue.top();
              p_queue.pop();
              
              if(p.to->visited) continue;
              if(p.to->ind == to)return p.time;
              
              p.to->visited = true;

              for(list<Edge>::iterator it = p.to->TO.begin();it != p.to->TO.end();it++)
                   if(!it->to->visited)
                   {
                       Path _p(it->to , p.time + it->weight);
                       p_queue.push(_p);
                   }
          }
          
          return -1;
      }

};
int n;//no. nodos
Graph G(n+1);

scanf("%d%d%d",&f,&t,&p);
G.AddEdge(f,t,p);

k = G.Shortest_Path_with_Dijkstra(F,T); 
        
if(k == -1)
  puts("NONE");
else
  printf("%d\n",k);