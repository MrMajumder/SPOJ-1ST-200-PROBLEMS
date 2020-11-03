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
int n;

int dijkstra(int src, int dest)
{
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, src));
    vector<int> cost(n + 1, 200010);
    cost[src] = 0;

    while(!pq.empty())
    {
        int d, c;
        c = - pq.top().first;   //cost
        d = pq.top().second;    //node
        if(d == dest) return c;
        pq.pop();
        if(cost[d] < c) continue;
        int len = graph[d].size();
        for(int i = 0; i < len; i++)
        {
            int a, b;
            a = graph[d][i].first;  //node
            b = graph[d][i].second; //cost
            if(c + b < cost[a]) pq.push(make_pair(-(cost[a] = c + b), a));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        map<string, int> name;
        cin>>n;
        graph = vector<vector<pair<int, int>>> (n + 1);

        for(int i = 1; i <= n; i++)
        {
            string s;
            cin>>s;
            name[s] = i;
            int m;
            cin>>m;
            while(m--)
            {
                int loc, c;
                cin>>loc>>c;
                graph[i].push_back(make_pair(loc, c));
            }
        }
        int cases;
        cin>>cases;
        while(cases--)
        {
            string s1, s2;
            cin>>s1>>s2;
            cout<<dijkstra(name[s1], name[s2])<<endl;
        }
    }

    return 0;
}

