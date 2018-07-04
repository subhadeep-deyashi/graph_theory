/* Dijkstra algorithm for Undirected Graph, time complexity : O(|E|.log|V|)  */
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector< pii > vii;
#define INF 0x3f3f3f3f
vii *G;    // Graph
vi D;      // distance vector for storing min distance from the source.
/*=======================================*/
void dijkstra(int source, int N) {
    D.assign(N,INF);
    D[source] = 0;
    set<pii> Q;
    Q.insert({0,source});
    while(!Q.empty()) {
        auto top = Q.begin();
        int u = top->second;
        Q.erase(top);
        for(auto next: G[u])    {
            int v = next.first, weight = next.second;
            if( D[v] > D[u] + weight) {
                if(Q.find( {D[v], v} ) != Q.end())
                Q.erase(Q.find( {D[v], v} ));
                D[v] = D[u] + weight;
                Q.insert( {D[v], v} );
            }
        }
    }
}
/*==========================================*/
int main(){
    int N,M,source,u,v,w;
    cin >> N >> M >> source; 
//Input the number of nodes(0 based), number of edges and the source vertex.
    G = new vii[N];
    for(int i=0;i<M;i++){
        cin >> u >> v >> w; 
//Input the starting vertex of the edge, the ending vertex and the cost of the edge.
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    dijkstra(source, N); 
 
    for(int i=0;i<N;i++)
        cout<<D[i]<<" ";
    cout<<endl;
}