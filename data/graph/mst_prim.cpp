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

class CMP
{
      public: bool operator()(Edge &a,Edge b)
      {
          return a.weight > b.weight;
      }
};

class Graph_To_Get_Minimum_Spanning_Tree
{
      vector<Node>vect_nodes;
      
      public :
             
      Graph_To_Get_Minimum_Spanning_Tree(){}
      Graph_To_Get_Minimum_Spanning_Tree(int n)
      {
          vect_nodes.clear();
          vect_nodes = vector<Node>(n);
          for(size_t i = 0;i < vect_nodes.size();vect_nodes[i].ind = i++);
      }

      void Ini(int _max)
      {
          for(size_t i = 0;i < _max;i++)
          {
              vect_nodes[i].ind = i;
              vect_nodes[i].visited = false;
              vect_nodes[i].TO.clear();
          }
      }

      void AddEdge(int f,int t,int w)
      {
          Edge e[] = { Edge(&vect_nodes[f],&vect_nodes[t],w) , 
                       Edge(&vect_nodes[t],&vect_nodes[f],w) };
          
          vect_nodes[f].TO.push_back(e[0]);
          vect_nodes[t].TO.push_back(e[1]);
      }

      
      bool Prim_Algorithm(int *answer)
      {
          *answer = 0;
          
          Edge e(&vect_nodes[0],&vect_nodes[0],0);
          
          priority_queue<Edge,vector<Edge> ,CMP> p_queue;
          
          p_queue.push(e);
          
          do
          {
              e = p_queue.top();
              p_queue.pop();
              
              if(!e.to->visited)
              {
                   e.to->visited = true;
                   
                   *answer += e.weight;
                   
                   for(list<Edge>::iterator it = e.to->TO.begin();it != e.to->TO.end();it++)
                       p_queue.push(*it);
              }    

          }
          while(!p_queue.empty());
          
          for(int i = 0,size = vect_nodes.size();i < size;i++)
              if(!vect_nodes[i].visited)
                  return false;
          
          return true;
          
      }
};