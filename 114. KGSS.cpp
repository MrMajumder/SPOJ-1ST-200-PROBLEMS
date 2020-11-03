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

pair<int, int> tree[2 * (100000 + 1)];

void updateNode(int node)
{
    int arr[4];
    arr[0] = tree[node << 1].first;
    arr[1] = tree[node << 1].second;
    arr[2] = tree[node << 1 + 1].first;
    arr[3] = tree[node << 1 + 1].second;
    sort(arr, arr + 4);
    tree[node] = make_pair(arr[3], arr[2]);
}

void build(int node, int start, int fin)
{
    if(start == fin) return;
    int mid = start + ((fin - start) / 2);
    build(node << 1, start, mid);
    build(node << 1 + 1, mid + 1, fin);
    updateNode(node);
}

void buildTree(int n)
{
    int x;
    for(int i = 0; i < n; i++)
    {
        cin>>x;
        tree[n + i].first = x;
        tree[n + i].second = -INF;
    }
    build(1, 1, n);
}

void updateTree(int node, int start, int fin, int idx, int val)
{
    if(start == fin)
    {
        tree[node].first = val;
        return;
    }
    int mid = start + ((fin - start) / 2);
    if(idx <= mid)  updateTree(node << 1,       start,      mid, idx, val);
    else            updateTree(node << 1 + 1,   mid + 1,    fin, idx, val);
    updateNode(node);
}

pair<int, int> queryTree(int node, int start, int fin, int l, int r)
{
    if(r < start || l > fin) return make_pair(-INF, -INF);
    if(l <= start && fin <= r) return tree[node];
    int mid = start + ((fin - start) / 2);
    pair<int, int> p1 = queryTree(node << 1, start, mid, l, r);
    pair<int, int> p2 = queryTree(node << 1 + 1, mid + 1, fin, l, r);
    int arr[4];
    arr[0] = p1.first;
    arr[1] = p1.second;
    arr[2] = p2.first;
    arr[3] = p2.second;
    sort(arr, arr + 4);
    return make_pair(arr[3], arr[2]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    buildTree(n);
    int op;
    cin>>op;
    while(op--)
    {
        char x;
        for(int i = 0; i < 2 * n; i++) cout<<"("<<tree[i].first<<", "<<tree[i].second<<")"<<SPACE;
        cout<<endl;
        int a, b;
        cin>>x>>a>>b;
        if(x == 'U') updateTree(0, 1, n - 1, a - 1, b);
        else if(x == 'Q')
        {
            pair<int, int> p = queryTree(0, 1, n - 1, a - 1, b - 1);
            cout<<p.first + p.second<<endl;
        }
    }

    return 0;
}

