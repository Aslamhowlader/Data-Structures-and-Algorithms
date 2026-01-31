#include <bits/stdc++.h>
using namespace std;

enum Color
{
    WHITE,
    GRAY,
    BLACK
};

struct vertex
{
    Color color;
    int parent;
    int d; 
    int f; 
};

vector<vertex> V;
int t = 0;

// DFS Visit
void DFS_visit(int u, vector<vector<int>> &G)
{
    t = t + 1;
    V[u].d = t;
    V[u].color = GRAY;

    for (int v : G[u])
    {
        if (V[v].color == WHITE)
        {
            V[v].parent = u;
            DFS_visit(v, G);
        }
    }

    V[u].color = BLACK;
    t = t + 1;
    V[u].f = t;
}


void DFS(vector<vector<int>> &G)
{
    int n = G.size();
    V.resize(n);

    for (int u = 0; u < n; u++)
    {
        V[u].color = WHITE;
        V[u].parent = -1;
    }

    t = 0;

    for (int u = 0; u < n; u++)
    {
        if (V[u].color == WHITE)
        {
            DFS_visit(u, G);
        }
    }
}

int main()
{

    vector<vector<int>> G = {
        {1, 2}, 
        {3},    
        {3},    
        {}     
    };

    DFS(G);

    cout << "Node | Parent | Discover | Finish\n";
    cout << "--------------------------------------\n";

    for (int i = 0; i < G.size(); i++)
    {
        cout << " " << i
             << "   |   " << V[i].parent
             << "     |    " << V[i].d
             << "      |   " << V[i].f
             << endl;
    }

    return 0;
}
