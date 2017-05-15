#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <limits>

#define INF (std::numeric_limits<int>::max())
#define INF_LONG (std::numeric_limits<long>::max())

using namespace std;

class Node {
    private:
        int id;
        int level;
        int parent;
        int parentGroup;
        vector<int> children;

    public:
        Node():parentGroup(-1), level(-1), parent(-1), id(-1){}
        Node(int i):parentGroup(-1), level(-1), parent(-1) {
            id = i;
        }

        void setLevel(int l) { level = l; }
        int getLevel() { return level; }

        void setId(int i) { id = i; }
        int getId() { return id; }

        void setParent(int p) { parent = p; }
        int getParent() { return parent; }

        void setParentGroup(int p) { parentGroup = p; }
        int getParentGroup() { return parentGroup; }

        void addChild(int child) {
            children.push_back(child);
        }
        vector<int> * getChildren() {
            return &children;
        }
};

class LCATree {
    /*
    Docs: https://www.topcoder.com/community/data-science/data-science-tutorials/range-minimum-query-and-lowest-common-ancestor/#Lowest%20Common%20Ancestor%20(LCA)
    Tree is 0-index
    */
    private:
        int nodesCount;
        Node *nodes;
        int root;

        int findTreeDepth() {
            int maxDepth = 0;

            // bool visited[nodesCount]; It is a tree so it isn't necesary to mark nodes as visited
            for(int i = 0; i < nodesCount; i++) {
                // nodes[i].setId(i); set id. not needed
                // look for parent
                if(nodes[i].getParent() == -1) {
                    root = i;
                    break;
                }
            }

            queue<int> queue;

            // BFS to fill levels and find max depth
            int currentNode;
            queue.push(root);

            nodes[root].setLevel(0);

            while(!queue.empty()) {
                currentNode = queue.front();
                queue.pop();

                vector<int> *childen = nodes[currentNode].getChildren();

                for(int i = 0, _size = childen->size(); i < _size; i++) {
                    int nextNode = (*childen)[i];

                    nodes[nextNode].setLevel(nodes[nodes[nextNode].getParent()].getLevel() + 1);
                    maxDepth = max(maxDepth, nodes[nextNode].getLevel());

                    queue.push(nextNode);
                }
            }

            return maxDepth;
        }

        void DFSSetParentGroup(int node, int parent, int depth, int H) {
            nodes[node].setParentGroup(parent);

            vector<int> *children = nodes[node].getChildren();
            for(int nextNode, i = 0, _size = children->size(); i < _size; i++) {
                nextNode = (*children)[i];

                if(depth == H) {
                    depth = 0;
                    parent = node;
                }

                DFSSetParentGroup(nextNode, parent, depth + 1, H);
            }
        }

    public:
        LCATree(int n) {
            root = -1;
            nodesCount = n;

            nodes = new Node[n];
        }
        ~LCATree() { }

        void addEdge(int from, int to) {
            nodes[to].setParent(from);
            nodes[from].addChild(to);
        }

        void calculateLCA() {
            int treeDepth = findTreeDepth();

            int H = static_cast<int>(floor(sqrt(treeDepth)));
            DFSSetParentGroup(root, root, 1, H);

        }

        int lca(int a, int b) {

            while(nodes[a].getParentGroup() != nodes[a].getParentGroup()) {
                if(nodes[a].getLevel() > nodes[b].getLevel())
                    a = nodes[a].getParentGroup();
                else
                    b = nodes[b].getParentGroup();
            }

            while(a != b) {
              if(nodes[a].getLevel() > nodes[b].getLevel())
                  a = nodes[a].getParent();
              else
                  b = nodes[b].getParent();
            }

            return a;
        }
};

int main(int argc, char const *argv[]) {
    /*
    LCATree lca_tree = LCATree(13);

    lca_tree.addEdge(0, 1);
    lca_tree.addEdge(0, 2);
    lca_tree.addEdge(0, 3);
    lca_tree.addEdge(2, 4);
    lca_tree.addEdge(2, 5);
    lca_tree.addEdge(2, 6);
    lca_tree.addEdge(5, 7);
    lca_tree.addEdge(5, 8);
    lca_tree.addEdge(6, 9);
    lca_tree.addEdge(6, 10);
    lca_tree.addEdge(9, 11);
    lca_tree.addEdge(9, 12);

    lca_tree.calculateLCA();

    printf("%d\n", lca_tree.lca(4, 10));
    printf("%d\n", lca_tree.lca(1, 11));
    printf("%d\n", lca_tree.lca(1, 3));
    printf("%d\n", lca_tree.lca(0, 3));
    printf("%d\n", lca_tree.lca(7, 10));
    */
    int tests = 0;
    scanf("%d", &tests);

    int n, m, q, x, y;
    for(int test = 1; test <= tests; test++) {
        scanf("%d", &n);

        LCATree lca_tree = LCATree(n);

        for(int i = 0; i < n; i++) {
            scanf("%d", &m);

            for(int j = 0; j < m; j++) {
                scanf("%d", &x);
                lca_tree.addEdge(i, x - 1);
            }
        }
        lca_tree.calculateLCA();

        scanf("%d", &q);
        printf("Case %d:\n", test);
        while(q--) {
            scanf("%d%d", &x, &y);

            printf("%d\n", lca_tree.lca(x - 1, y - 1) + 1);
        }

    }

    return 0;
}
