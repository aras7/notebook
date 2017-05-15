import java.util.*;


class Pair<X, Y> {
  public final X first;
  public final Y second;

  public Pair(X x, Y y) {
    this.first = x;
    this.second = y;
  }
}

class Edge {
    private int from;
    private int to;
    private int value;
    private Edge reverseEdge;

    public Edge(int to, int value) {
        this.from = -1;
        this.to = to;
        this.value = value;
        this.reverseEdge = null;
    }
    public Edge(int from, int to, int value) {
        this.from = from;
        this.to = to;
        this.value = value;
        this.reverseEdge = null;
    }
    public Edge(int from, int to, int value, Edge reverse) {
        this.from = from;
        this.to = to;
        this.value = value;
        this.reverseEdge = reverse;
    }

    public void setReverseEdge(Edge edge) { this.reverseEdge = edge; }
    public Edge getReverseEdge() { return this.reverseEdge; }

    public int getFrom() { return this.from; }
    public int getTo() { return this.to; }

    public void setValue(int value) { this.value = value; }
    public int getValue() { return this.value; }
}

class Graph{
    private int nodes_count;
    private ArrayList<Edge>[] nodes;

    public Graph(int n) {
        this.nodes_count = n;
        this.nodes = new ArrayList[n];

        for(int i = 0; i < this.nodes_count; i++)
            this.nodes[i] = new ArrayList<Edge>();
    }

    public void addEdge(int from, int to, int value) {
        Edge e1 = new Edge(from, to, value);
        Edge e2 = new Edge(to, from, value, e1);
        e1.setReverseEdge(e2);

        this.nodes[from].add(e1);
        this.nodes[to].add(e2);
    }

    public int findMaxFlow(int source, int sink) {
        int totalFlow = 0;

        Pair<ArrayList<Edge> , Integer> path = dfsFindAugmentingPath(source, sink);

        while(path != null) {
            int flow = path.second;

            for(Object item: path.first) {
                Edge edge = (Edge)item;
                edge.setValue(edge.getValue() - flow);

                Edge reverse = edge.getReverseEdge();
                reverse.setValue(reverse.getValue() + flow);
            }

            totalFlow += flow;
            path = dfsFindAugmentingPath(source, sink);
        }

        return totalFlow;
    }

    public Pair<ArrayList<Edge> , Integer> dfsFindAugmentingPath(int source, int sink) {
        int currentNode, nextNode;

        /* Edge used to reach this node. null means no visited */
        Edge[] lastEdge = new Edge[this.nodes_count];

        Stack stack = new Stack<Integer>();
        stack.add(source);
        lastEdge[source] = new Edge(source, source, Integer.MAX_VALUE);

        while(!stack.isEmpty()) {
            currentNode = (int)stack.pop();

            for(Object edge: this.nodes[currentNode]) {
                nextNode = ((Edge)edge).getTo();

                if(lastEdge[nextNode] == null && ((Edge)edge).getValue() > 0) {

                    stack.add(nextNode);
                    lastEdge[nextNode] = (Edge)edge;

                    // Found!
                    if(nextNode == sink) {
                        int flow = Integer.MAX_VALUE;
                        ArrayList<Edge> path = new ArrayList<Edge>();

                        do {
                            path.add(lastEdge[sink]);
                            flow = Math.min(flow, lastEdge[sink].getValue());

                            // Go back until source
                            sink = lastEdge[sink].getFrom();
                        }while(lastEdge[sink].getTo() != source);

                        return new Pair<ArrayList<Edge> , Integer>(path, flow);
                    }
                }
            }
        }

        // Not found :(
        return null;
    }

    public void bfs(int from) {
        int currentNode, nextNode;

        boolean[] visited = new boolean[this.nodes_count];
        Arrays.fill(visited, false);

        Queue<Integer> queue = new LinkedList<Integer>();
        queue.add(from);
        visited[from] = true;

        while(!queue.isEmpty()) {
            currentNode = queue.element();
            queue.remove();

            /* Play here ;) */
            System.out.println(currentNode + " found!");
            /* end play */

            for(Object edge: this.nodes[currentNode]) {
                nextNode = ((Edge)edge).getTo();

                if(!visited[nextNode]) {
                    queue.add(nextNode);
                    visited[nextNode] = true;
                }
            }
        }
    }
}

class MaxFlow {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int adjacencyMatrix[][] = new int[26 * 2][26 * 2];

        int n = sc.nextInt();

        for (int[] row: adjacencyMatrix)
            Arrays.fill(row, 0);

        Graph graph = new Graph(26 * 2);

        for(int i = 0; i < n; i++) {
            char cf = sc.next().charAt(0);
            int f = cf < 'a' ? (int)cf - (int)'A': (int)cf - (int)'a' + 26;

            char ct = sc.next().charAt(0);
            int t = ct < 'a' ? (int)ct - (int)'A': (int)ct - (int)'a' + 26;

            int v = sc.nextInt();
            adjacencyMatrix[f][t] += v;
        }

        for(int i = 0; i < 26 * 2; i++)
            for(int j = 0; j < 26 * 2; j++)
                graph.addEdge(i, j, adjacencyMatrix[i][j]);

        System.out.println(graph.findMaxFlow(0, 25));
    }
}
