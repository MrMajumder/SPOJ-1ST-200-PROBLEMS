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
const int MOD = 1000000007; //9digits
const double EPS = 1e-8;
const long double EULER = 2.71828182845904523536;   //20digits
const long double PI = 3.14159265358979323846;      //20digits
//float = 7digits, double = 15digits, long double = 21 digits precision

//defined my own datatypes
typedef long long ll;
typedef unsigned long long ull;

vector<vector<pair<int, int>>> graph;

int mstcost(int n)
{
    priority_queue<pair<int, int>> pq;
    vector<int> dist(n + 1, INF);
    vector<bool> visited(n + 1, false);
    dist[1] = 0;
    pq.push(make_pair(0, 1));
    while(!pq.empty())
    {
        int node = pq.top().second;
        pq.pop();
        if(visited[node]) continue;
        visited[node] = true;
        int len = graph[node].size();
        for(int i = 0; i < len; i++)
        {
            int x = graph[node][i].first;
            int xdist = graph[node][i].second;
            if(!visited[x] && dist[x] > xdist) pq.push(make_pair(- (dist[x] = xdist), x));
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) if(dist[i] != INF) ans += dist[i];
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
        int n;
        cin>>n;
        graph = vector<vector<pair<int, int>>>(n + 1);
        for(int i = 1; i <= n; i++)
        {
            string city;
            int road;
            cin>>city>>road;
            while(road--)
            {
                int a, cost;
                cin>>a>>cost;
                graph[i].push_back(make_pair(a, cost));
            }
        }

        cout<<mstcost(n)<<endl;
    }

    return 0;
}

