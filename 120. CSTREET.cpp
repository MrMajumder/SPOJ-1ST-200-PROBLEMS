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

vector<vector<pair<int, int>>> graph;

int primMST(int v)
{
    vector<bool> visited(v + 1, false);
    vector<int> key(v + 1, INF);
    vector<int> parent(v + 1, -1);
    priority_queue<pair<int, int>> pq; //key, node

    key[1] = 0;
    pq.push(make_pair(0, 1));

    //for(int i = 1; i <= v - 1; i++)
    while(!pq.empty())
    {
        int node = pq.top().second;
//        if(visited[node])
//        {
//            i--;
//            continue;
//        }
        pq.pop();
        visited[node] = true;
        int len = graph[node].size();
        for(int i = 0; i < len; i++)
        {
            int tempnode = graph[node][i].first;
            int tempkey = graph[node][i].second;
            if(!visited[tempnode] && key[tempnode] > tempkey)
            {
                parent[tempnode] = node;
                pq.push(make_pair(-(key[tempnode] = tempkey), tempnode));
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= v; i++) if(key[i] != INF) ans += key[i];
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int p, v, e;
        cin>>p>>v>>e;
        graph = vector<vector<pair<int, int>>> (v + 1);
        while(e--)
        {
            int src, dest, cost;
            cin>>src>>dest>>cost;
            graph[src].push_back(make_pair(dest, cost));
            graph[dest].push_back(make_pair(src, cost));
        }
        cout<<(p * primMST(v))<<endl;
    }

    return 0;
}

