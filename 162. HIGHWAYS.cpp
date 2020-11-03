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

int n, m;
vector<vector<pair<int, int>>> graph;

int dijkstra(int src, int dest)
{
    priority_queue<pair<int, int>> pq;
    vector<int> dist(n + 1, INF);
    vector<bool> visited(n + 1, false);
    pq.push(make_pair(0, src));
    dist[src] = 0;
    while(!pq.empty())
    {
        int sv = pq.top().second;
        int st =  - pq.top().first;
        if(sv == dest) return st;
        pq.pop();
        if(visited[sv]) continue;
        visited[sv] = true;
        int len = graph[sv].size();
        for(int i = 0; i < len; i++)
        {
            int xv = graph[sv][i].first;
            int xt = graph[sv][i].second;
            if(!visited[xv] && dist[xv] > st + xt) pq.push(make_pair(-(dist[xv] = st + xt), xv));
        }
    }
    return INF;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int st, dest;
        cin>>n>>m>>st>>dest;
        graph = vector<vector<pair<int, int>>>(n + 1);
        while(m--)
        {
            int a, b, time;
            cin>>a>>b>>time;
            graph[a].push_back(make_pair(b, time));
            graph[b].push_back(make_pair(a, time));
        }
        int ans = dijkstra(st, dest);
        if(ans == INF) cout<<"NONE"<<endl;
        else cout<<ans<<endl;
    }

    return 0;
}

