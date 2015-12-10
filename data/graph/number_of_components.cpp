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

Node *_queue[10000000];
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

      void Ini()
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

      // Number of components
      int Number_Of_Components(int N)
      {
          int answer = 0;
          
          for(int i = 1;i <= N;i++)
              if(!vect_nodes[i].visited)
              {
                  BFS(i,-1);
                  answer++;
              }
              
          return answer;
      }
      bool BFS(int f, int t)
      {
           Node *node;
           
           int front = 0,last = 0;
           
           _queue[0] = &vect_nodes[f];
              vect_nodes[f].visited = true;
           
           do
           { 
                node = _queue[front++];
                
                if(node->ind == t)
                    return true;
                
                for(list<Edge>::iterator it = node->TO.begin(); it != node->TO.end();it++)
                    if(!it->to->visited)
                    {
                        _queue[++last] = it->to;
                        it->to->visited = true;
                    }
           }
           while(front <= last);
           
           return false;
      }
};