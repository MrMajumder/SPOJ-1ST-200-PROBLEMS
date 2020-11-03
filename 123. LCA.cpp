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

struct LCA
{
    vector<int> first, height, euler, segmentTree;
    vector<bool> visited;
    int n;

    LCA(vector<vector<int>> &adj, int root = 1)
    {
        n = adj.size();
        height.resize(n + 2);
        first.resize(n + 2);
        euler.reserve(2 * n);
        visited.assign(n + 2, false);
        dfs(adj, root);
        int m = euler.size();
        segmentTree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vector<vector<int>> &adj, int node, int h = 0)
    {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for(auto it : adj[node])
        {
            if(!visited[it])
            {
                dfs(adj, it, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(int node, int start, int fin)
    {
        if(start == fin) segmentTree[node] = euler[start];
        else
        {
            int mid = start + ((fin - start) / 2);
            build(node << 1, start, mid);
            build(node << 1 | 1, mid + 1, fin);
            int l = segmentTree[node << 1];
            int r = segmentTree[node << 1 | 1];
            segmentTree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    int query(int node, int start, int fin, int l, int r)
    {
        if(start > r || fin < l) return -1;
        if(l <= start && fin <= r) return segmentTree[node];
        int mid = start + ((fin - start) / 2);
        int left = query(node << 1, start, mid, l, r);
        int right = query(node << 1 | 1, mid + 1, fin, l, r);
        if(left == -1) return right;
        if(right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    int lca(int u, int v)
    {
        int l = first[u], r = first[v];
        if(l > r) swap(l, r);
        return query(1, 0, euler.size() - 1, l, r);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    int cases = 1;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> adjlist(n + 1);
        for(int i = 1; i <= n; i++)
        {
            int countadj;
            cin>>countadj;
            while(countadj--)
            {
                int v;
                cin>>v;
                adjlist[i].push_back(v);
                adjlist[v].push_back(i);
            }
        }
        LCA solu(adjlist);
        int q;
        cin>>q;
        cout<<"Case "<<cases++<<":"<<endl;
        while(q--)
        {
            int x, y;
            cin>>x>>y;
            cout<<solu.lca(x, y)<<endl;
        }
    }

    return 0;
}

