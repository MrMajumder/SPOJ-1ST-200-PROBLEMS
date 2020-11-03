
#include<bits/stdc++.h>
using namespace std;

//defined my macro functions
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

//defined my macro strings
#define ENDL "\n"
#define SPACE " "

//defined my constants
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
const double EPS = 1e-8;
const double PI = 3.14159265358979323846;

//defined my own datatypes
typedef long long ll;
typedef unsigned long long ull;

vector<vector<pair<int, int>>> adjList;

int dijkstra(int src, int c, int time)
{
    priority_queue<pair<int, int>> pq;
    vector<bool> visited(c + 1, false);
    vector<int> dist(c + 1, INF);
    dist[src] = 0;
    pq.push(make_pair(0, src));

    while(!pq.empty())
    {
        int d = - pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(visited[node]) continue;
        visited[node] = true;
        int len = adjList[node].size();
        for(int i = 0; i < len; i++)
        {
            int tempnode = adjList[node][i].first;
            int weight = adjList[node][i].second;
            if(!visited[tempnode] && dist[tempnode] > d + weight)
            {
                pq.push(make_pair(-(dist[tempnode] = d + weight), tempnode));
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= c; i++) if(dist[i] <= time) ans++;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, dest, time, e;
    cin>>n>>dest>>time>>e;

    adjList = vector<vector<pair<int, int>>>(n + 1);
    for(int i = 0; i < e; i++)
    {
        int a, b, cost;
        cin>>a>>b>>cost;
        adjList[b].push_back(make_pair(a, cost));
    }

    cout<<dijkstra(dest, n, time)<<endl;

    return 0;
}
