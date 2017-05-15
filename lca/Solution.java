import java.util.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

/* READER */
class FastReader
{
    BufferedReader br;
    StringTokenizer st;

    public FastReader()
    {
        br = new BufferedReader(new
                 InputStreamReader(System.in));
    }

    String next()
    {
        while (st == null || !st.hasMoreElements())
        {
            try
            {
                st = new StringTokenizer(br.readLine());
            }
            catch (IOException  e)
            {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    int nextInt()
    {
        return Integer.parseInt(next());
    }

    long nextLong()
    {
        return Long.parseLong(next());
    }

    double nextDouble()
    {
        return Double.parseDouble(next());
    }

    String nextLine()
    {
        String str = "";
        try
        {
            str = br.readLine();
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
        return str;
    }
}

/* END READER */
class Pair<A, B> {
    public A first;
    public B second;

  public Pair(A a, B b) {
    this.first = a;
    this.second = b;
  }
}

class Node {
    private int id;
    private int level = -1;
    private int parent = -1; // parent id
    private List<Integer> children = new ArrayList<Integer>(); // childen ids

    // Parent of the group which it belongs
    private int parentGroup = -1;

    public Node() {}
    public Node(int n) { this.id = n; }
    public Node(int n, int parent) {
        this.id = n;
        this.parent = parent;
    }
    public Node(int n, int level, int parent) {
        this.id = n;
        this.level = level;
        this.parent = parent;
    }

    public void setLevel(int l) { this.level = l; }
    public int getLevel() { return this.level; }

    public void setId(int i) { this.id = i; }
    public int getId() { return this.id; }

    public void setParent(int p) { this.parent = p; }
    public int getParent() { return this.parent; }

    public void setParentGroup(int p) { this.parentGroup = p; }
    public int getParentGroup() { return this.parentGroup; }

    public void addChild(int child) {
        // returns the level of the new node
        children.add(child);
    }
    public List<Integer> getChildren() { return this.children; }
}

class LCATree {
    /*
    Docs: https://www.topcoder.com/community/data-science/data-science-tutorials/range-minimum-query-and-lowest-common-ancestor/#Lowest%20Common%20Ancestor%20(LCA)
    Tree is 0-index
    */
    private int nodesCount;
    private Node[] nodes;
    private int root = -1;

    public LCATree(int n, ArrayList<Pair<Integer, Integer> > edges) {
        this.nodesCount = n;

        if(edges.size() != this.nodesCount - 1)
            System.out.println("This should not happen");

        this.nodes = new Node[this.nodesCount];

        for(int i = 0; i < this.nodesCount; i++) {
            this.nodes[i] = new Node(i); // set Id
        }

        this.fillEdges(edges);

        int treeDepth = findTreeDepth();

        int H = (int)Math.floor(Math.sqrt(treeDepth));
        DFSSetParentGroup(this.root, this.root, 1, H);
    }
    public LCATree(int n) {
        this.nodesCount = n;

        this.nodes = new Node[this.nodesCount];

        for(int i = 0; i < this.nodesCount; i++) {
            this.nodes[i] = new Node(i); // set Id
        }
    }

    public void addEdge(int from, int to) {
        this.nodes[to].setParent(from);
        this.nodes[from].addChild(to);
    }

    public void calculateLCA() {
        int treeDepth = findTreeDepth();

        int H = (int)Math.floor(Math.sqrt(treeDepth));
        DFSSetParentGroup(this.root, this.root, 1, H);
    }



    private void fillEdges(ArrayList<Pair<Integer, Integer> > edges) {

        for(Object item: edges) {
            Pair<Integer, Integer> edge = (Pair<Integer, Integer>)item;

            this.nodes[edge.second].setParent(edge.first);
            this.nodes[edge.first].addChild(edge.second);
        }
    }

    private int findTreeDepth() {
        int maxDepth = 0;

        boolean[] visited = new boolean[this.nodesCount];
        Arrays.fill(visited, false);

        for(int i = 0; i < this.nodesCount; i++) {
            // look for parent
            if(this.nodes[i].getParent() == -1) {
                this.root = i;
                break;
            }
        }

        Queue<Integer> queue = new LinkedList<Integer>();

        // BFS to fill leves and find max depth
        int currentNode;
        queue.add(this.root);
        visited[this.root] = true;
        this.nodes[this.root].setLevel(0);

        while(!queue.isEmpty()) {
            currentNode = queue.element();
            queue.remove();

            for(int nextNode: this.nodes[currentNode].getChildren()) {
                if(!visited[nextNode]) {

                    this.nodes[nextNode].setLevel(this.nodes[this.nodes[nextNode].getParent()].getLevel() + 1);
                    maxDepth = Math.max(maxDepth, this.nodes[nextNode].getLevel());

                    queue.add(nextNode);
                    visited[nextNode] = true;
                }
            }
        }

        return maxDepth;
    }

    private void DFSSetParentGroup(int node, int parent, int depth, int H) {
        this.nodes[node].setParentGroup(parent);

        for(int nextNode: this.nodes[node].getChildren()) {

            if(depth == H) {
                depth = 0;
                parent = node;
            }

            DFSSetParentGroup(nextNode, parent, depth + 1, H);
        }
    }

    public int lca(int a, int b) {
        while(this.nodes[a].getParentGroup() != this.nodes[a].getParentGroup()) {
            if(this.nodes[a].getLevel() > this.nodes[b].getLevel())
                a = this.nodes[a].getParentGroup();
            else
                b = this.nodes[b].getParentGroup();
        }

        while(a != b) {
          //System.out.printf("%d %d\n", a, b);
          if(this.nodes[a].getLevel() > this.nodes[b].getLevel())
              a = this.nodes[a].getParent();
          else
              b = this.nodes[b].getParent();
        }

        return a;
    }
}

class Solution{
    public static void main(String[] args) {

        /*ArrayList<Pair<Integer, Integer> > edges = new ArrayList<Pair<Integer, Integer> >();
        edges.add(new Pair<Integer, Integer>(0, 1));
        edges.add(new Pair<Integer, Integer>(0, 2));
        edges.add(new Pair<Integer, Integer>(0, 3));
        edges.add(new Pair<Integer, Integer>(2, 4));
        edges.add(new Pair<Integer, Integer>(2, 5));
        edges.add(new Pair<Integer, Integer>(2, 6));
        edges.add(new Pair<Integer, Integer>(5, 7));
        edges.add(new Pair<Integer, Integer>(5, 8));
        edges.add(new Pair<Integer, Integer>(6, 9));
        edges.add(new Pair<Integer, Integer>(6, 10));
        edges.add(new Pair<Integer, Integer>(9, 11));
        edges.add(new Pair<Integer, Integer>(9, 12));

        LCATree lca = new LCATree(13, edges);

        System.out.println(lca.lca(4, 10));
        */
        FastReader sc = new FastReader();

        int tests = sc.nextInt();
        for(int test = 1; test <= tests; test++) {
            int n = sc.nextInt();
            LCATree lca = new LCATree(n);

            for(int i = 0; i < n; i++) {
                int x;
                int m = sc.nextInt();

                for(int j = 0; j < m; j++) {
                    x = sc.nextInt();

                    lca.addEdge(i, x - 1);
                }
            }

            lca.calculateLCA();
            System.out.printf("Case %d:\n", test);

            int q = sc.nextInt();

            for(int i = 0; i < q; i++) {
                int a = sc.nextInt() - 1;
                int b = sc.nextInt() - 1;

                System.out.println(lca.lca(a, b) + 1);
            }
        }

    }
}
