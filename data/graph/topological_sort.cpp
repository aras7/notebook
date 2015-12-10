struct Edge;
struct Node
{
    int ind;
    bool visited;
    int count_edges;
    
    list<Edge>TO;
    
    Node():visited(false),ind(0),count_edges(0){}
    Node(int i):ind(i),visited(false),count_edges(0){}
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
class CMP_Topological_Sort
{
      public: bool operator()(int &a,int  b)
      {
          return a > b;
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

      void Ini(int N)
      {
          for(size_t i = 0;i < N;i++)
          {
              vect_nodes[i].ind = i;
              vect_nodes[i].visited = false;
              vect_nodes[i].TO.clear();
          }
      }

      void AddEdge(int f,int t)
      {
          Edge e(&vect_nodes[f],&vect_nodes[t]);
          
          vect_nodes[f].TO.push_back(e);
          vect_nodes[t].count_edges++;
      }

      // Every node has to have number of edges(count_edges) which finish at that node
      vector<int> Topological_Sort(int size,bool *hasloop)
      {
          *hasloop = false;
          
          vector<int>answer;
          priority_queue<int , vector<int>, CMP_Topological_Sort>_queue;
          
          for(int i = 0;i < size;i++)
              if(!vect_nodes[i].count_edges)
                  _queue.push(i);
                  
          
          while(!_queue.empty())
          {
              int x = _queue.top();
              _queue.pop();
              
              answer.push_back(x);
              
              for(list<Edge>::iterator it = vect_nodes[x].TO.begin();it != vect_nodes[x].TO.end();it++)
              {
                    it->to->count_edges--;
                    
                    if(!it->to->count_edges)
                        _queue.push(it->to->ind);
              }
          }
          
          for(int i = 0;i < size;i++)
              if(vect_nodes[i].count_edges)
              {
                   *hasloop = true;
                   break;
              }
                  
          return answer;
      }
};