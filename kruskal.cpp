// MST -- Minimum Spanning Tree ( 1. Kruskal algorithm )
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
const int MAX = 1e4 + 5;
int id[MAX], nodes, edges;
pair< long long, pair<int, int> > p[MAX];    // array of "< weight, (vertex, vertex) >"

void initialize()
{
    for (int i = 0; i < MAX; ++i)
        id[i] = i;
}

// for making the id's of all the nodes of a disjoint set identical
int root(int x)
{
    while (id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

// to make the id's of the roots of two disjoint sets connected by an edge identical
void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}

long long kruskal()
{
    int x, y;
    long long cost, minimumCost = 0;
    for (int i = 0; i < edges; ++i)
    {
        // Selecting edges one by one in increasing order from the beginning
        x = p[i].second.first;      // i'th edge, first vertex
        y = p[i].second.second;     // i'th edge, second vertex
        cost = p[i].first;          // i'th edge's weight
        
        // Check if the selected edge is creating a cycle or not
        if (root(x) != root(y))
        {
            cout << "\n" << x << "--" << y << "\n";
            minimumCost += cost;
            union1(x, y);
        }
    }
    return minimumCost;
}

int main()
{
    int x, y;
    long long weight, cost, minimumCost;
    initialize();

    cout << "Enter the number of nodes and edges : ";
    cin >> nodes >> edges;
    cout << "Enter the vertices and the corresponding weight : \n";
    for (int i = 0; i < edges; ++i)
    {
        cin >> x >> y >> weight;
        p[i] = make_pair(weight, make_pair(x, y));  // < weight, (vertex, vertex) >
    }

    // Sort the edges in the ascending order
    sort(p, p + edges);
    cout << "\nConnected edges are as follows : \n";
    minimumCost = kruskal();
    cout << "\nMinimum cost = " << minimumCost << endl;

    return 0;
}