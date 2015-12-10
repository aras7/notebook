struct Edge;
struct Node
{
    int ind;
    bool visited;

    int mark;
    
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

      //n -> columns
      int POS(int i,int j,int n)
      {
           return (i-1) * n + j - 1;
      }
      BFS

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

      // Bipartite
      // Every node has to have 'mark' as an attribute which value can be // 0(none), 1(type 1) , -1(type 2)
      bool isBipartiete()
      {
           bool bipartiete = true;
           
           for(int i = 1,size = vect_nodes.size();bipartiete && i < size;i++)
               if(!vect_nodes[i].visited)                     
                   bipartiete &= BFS_To_Bipartite(i,1); 
           
           return bipartiete;
      }

      bool BFS_To_Bipartite(int p,int val_mark)
      {
           if(!vect_nodes[p].visited)
           {
               bool bipartite = true;
           
               vect_nodes[p].mark = val_mark;
               vect_nodes[p].visited = true;
               
               for(list<Edge>::iterator it = vect_nodes[p].TO.begin();bipartite && it != vect_nodes[p].TO.end();it++)
                    bipartite &= BFS_To_Bipartite(it->to->ind , (val_mark == 1 ? -1 : 1));

               return bipartite;
           }
           else
               return vect_nodes[p].mark == val_mark;
      }

};