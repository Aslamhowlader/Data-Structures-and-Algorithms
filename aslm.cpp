#include <iostream>
using namespace std;

#define MAX 8
#define INF 9999


char nodes[MAX] = {'s','w','r','t','x','v','u','y'};


int nodeIndex(char c) {
    for(int i = 0; i < MAX; i++) {
        if(nodes[i] == c) return i;
    }
    return -1;
}

void BFS(int adj[MAX][MAX], int source) {
    int color[MAX];
    int distance[MAX];
    int parent[MAX];
    int Q[MAX];
    int front = 0, rear = 0;

    for(int i=0; i<MAX; i++){
        color[i] = 0;
        distance[i] = INF;
        parent[i] = -1;
    }

    color[source] = 1;
    distance[source] = 0;
    parent[source] = -1;

    Q[rear++] = source;

    while(front < rear){
        int u = Q[front++];
        for(int v=0; v<MAX; v++){
            if(adj[u][v] != 0 && color[v]==0){
                color[v] = 1;
                distance[v] = distance[u] + 1;
                parent[v] = u;
                Q[rear++] = v;
            }
        }
        color[u] = 2;
    }


    cout << "Node\tDistance\tParent\n";
    for(int i=0; i<MAX; i++){
        cout << nodes[i] << "\t"
             << (distance[i]==INF ? -1 : distance[i]) << "\t\t";
        if(parent[i]==-1) cout << "NIL\n";
        else cout << nodes[parent[i]] << "\n";
    }
}

int main() {
    int adj[MAX][MAX] = {0};


    adj[nodeIndex('s')][nodeIndex('t')] = 1;
    adj[nodeIndex('t')][nodeIndex('s')] = 1;

    adj[nodeIndex('s')][nodeIndex('w')] = 1;
    adj[nodeIndex('w')][nodeIndex('s')] = 1;

    adj[nodeIndex('t')][nodeIndex('x')] = 1;
    adj[nodeIndex('x')][nodeIndex('t')] = 1;

    adj[nodeIndex('w')][nodeIndex('v')] = 1;
    adj[nodeIndex('v')][nodeIndex('w')] = 1;

    adj[nodeIndex('x')][nodeIndex('u')] = 1;
    adj[nodeIndex('u')][nodeIndex('x')] = 1;

    adj[nodeIndex('v')][nodeIndex('y')] = 1;
    adj[nodeIndex('y')][nodeIndex('v')] = 1;

    int source = nodeIndex('s');
    BFS(adj, source);

    return 0;
}
