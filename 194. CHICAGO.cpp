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

vector<vector<pair<int, double>>> graph;

double dijkstra(int n)
{
    priority_queue<pair<double, int>> pq;
    vector<bool> visited(n + 1, false);
    vector<double> probab(n + 1, 0);
    pq.push(make_pair(1.0, 1));
    while(!pq.empty())
    {
        int node = pq.top().second;
        double p = pq.top().first;
        if(node == n) return p;
        pq.pop();
        if(visited[node]) continue;
        visited[node] = true;
        int len = graph[node].size();
        for(int i = 0; i < len; i++)
        {
            int xnode = graph[node][i].first;
            double xp = graph[node][i].second;
            if(!visited[xnode] && (p * xp > probab[xnode])) pq.push(make_pair(probab[xnode]= p * xp, xnode));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n;
    while(n)
    {
        cin>>m;
        graph = vector<vector<pair<int, double>>>(n + 1);
        while(m--)
        {
            int a, b, p;
            cin>>a>>b>>p;
            graph[a].push_back(make_pair(b, (p / 100.0)));
            graph[b].push_back(make_pair(a, (p / 100.0)));
        }
        cout<<setprecision(6)<<fixed<<(100.0 * dijkstra(n))<<" percent"<<endl;
        cin>>n;
    }

    return 0;
}

