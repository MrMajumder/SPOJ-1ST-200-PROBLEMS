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
int maxi, targetnode;

void dfs(int node, vector<int> &dist, vector<bool> & visited)
{
    visited[node] = true;
    if(dist[node] > maxi)
    {
        maxi = dist[node];
        targetnode = node;
    }
    int len = graph[node].size();
    for(int i = 0; i < len; i++)
    {
        pair<int, int> p = graph[node][i];
        if(!visited[p.first])
        {
            dist[p.first] = dist[node] + p.second;
            dfs(p.first, dist, visited);
        }
    }
    visited[node] = false;
    dist[node] = 0;
}

void findlongest(int n)
{
    maxi = 0;
    vector<int> dist(n + 1, 0);
    vector<bool> visited(n + 1, false);
    dfs(1, dist, visited);
    maxi = 0;
    dfs(targetnode, dist, visited);
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
        for(int i = 0; i < n - 1; i++)
        {
            int a, b, c;
            cin>>a>>b>>c;
            graph[a].push_back(make_pair(b, c));
            graph[b].push_back(make_pair(a, c));
        }
        findlongest(n);
        cout<<maxi<<endl;
    }

    return 0;
}

