#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>

using namespace std;
const int MAX = 1e4 + 5;
typedef pair<long long, int> PII;
bool marked[MAX];
vector<PII> adj[MAX];

long long prim(int x)
{
    /* This declares a std::priority_queue containing std::pair<long long, int> instances 
    where a std::vector<std::pair<long long, int>> is the underlying container of the 
    priority queue (as it is a container adaptor).
    The std::greater<std::pair<long long, int>> is used as the Comparator function object 
    for the queue, checking whether the LHS pair is greater than the RHS pair. */
    // analogous to MIN_HEAP ( i.e., ascending ordered elements )
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    int y;
    long long minimumCost = 0;
    PII p;
    Q.push(make_pair(0, x));
    while (!Q.empty())
    {
        // Select the edge with minimum weight
        p = Q.top();    // i.e., the first element
        Q.pop();
        x = p.second;
        // Checking for cycle
        if (marked[x] == true)
            continue;
        minimumCost += p.first;
        marked[x] = true;
        for (int i = 0; i < adj[x].size(); ++i)
        {
            y = adj[x][i].second;
            if (marked[y] == false)
                Q.push(adj[x][i]);
        }
    }
    return minimumCost;
}

int main()
{
    int nodes, edges, x, y;
    long long weight, minimumCost;
    cin >> nodes >> edges;
    for (int i = 0; i < edges; ++i)
    {
        cin >> x >> y >> weight;
        adj[x].push_back(make_pair(weight, y));
        adj[y].push_back(make_pair(weight, x));
    }
    // Selecting 1 as the starting node
    minimumCost = prim(1);
    cout << minimumCost << endl;
    return 0;
}