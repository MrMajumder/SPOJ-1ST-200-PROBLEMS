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

vector<vector<int>> graph;
int n;
int dp[100000 + 1][2];

int calc(int node, int parent, bool ispcovered)
{
    if(dp[node][ispcovered] != -1) return dp[node][ispcovered];
    int l = 1, r = 0;
    if(ispcovered)
    {
        for(int i = 0; i < graph[node].size(); i++) if(graph[node][i] != parent) l += calc(graph[node][i], node, true);
        for(int i = 0; i < graph[node].size(); i++) if(graph[node][i] != parent) r += calc(graph[node][i], node, false);
        dp[node][ispcovered] = min(l, r);
    }
    else
    {
        for(int i = 0; i < graph[node].size(); i++) if(graph[node][i] != parent) l += calc(graph[node][i], node, true);
        dp[node][ispcovered] = l;
    }
    return dp[node][ispcovered];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin>>n;
    graph = vector<vector<int>>(n + 1);
    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    memset(dp, -1, sizeof dp);
    int l = 1, r = 0;
    for(int i = 0; i < graph[1].size(); i++) l += calc(graph[1][i], 1, true);
    for(int i = 0; i < graph[1].size(); i++) r += calc(graph[1][i], 1, false);
    cout<<min(l, r)<<endl;
    return 0;
}

