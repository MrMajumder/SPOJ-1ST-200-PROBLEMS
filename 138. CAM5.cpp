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

void bfs(int src, vector<bool> & visited)
{
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int a = q.front();
        q.pop();
        visited[a] = true;
        int len = graph[a].size();
        for(int i = 0; i < len; i++)
        {
            if(!visited[graph[a][i]])
            {
                q.push(graph[a][i]);
            }
        }
    }
}

int countbfs(int v)
{
    vector<bool> visited(v, false);
    int ans = 0;
    for(int i = 0; i < v; i++)
    {
        if(!visited[i])
        {
            ans++;
            bfs(i, visited);
        }
    }
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
        int v, e;
        cin>>v>>e;
        graph = vector<vector<int>>(v);
        for(int i = 0; i < e; i++)
        {
            int a, b;
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        cout<<countbfs(v)<<endl;
    }

    return 0;
}
