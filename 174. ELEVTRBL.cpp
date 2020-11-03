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

int floorno, up, down;

int bfs(int src, int dest)
{
    vector<int> dist(floorno + 1, INF);
    vector<bool> visited(floorno + 1, false);
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        if(node == dest) return dist[node];
        if(visited[node]) continue;
        visited[node] = true;
        if((node + up <= floorno) && !visited[node + up] && dist[node + up] > dist[node] + 1)
        {
            dist[node + up] = dist[node] + 1;
            q.push(node + up);
        }
        if((node - down >= 1) && !visited[node - down] && dist[node - down] > dist[node] + 1)
        {
            dist[node - down] = dist[node] + 1;
            q.push(node - down);
        }
    }
    return INF;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int start, goal;
    cin>>floorno>>start>>goal>>up>>down;
    int ans = bfs(start, goal);
    if(ans == INF) cout<<"use the stairs"<<endl;
    else cout<<ans<<endl;
    return 0;
}

