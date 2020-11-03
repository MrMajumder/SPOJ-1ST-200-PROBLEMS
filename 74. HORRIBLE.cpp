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


ll tree[4 * 100010];
ll lazy[ 4 * 100010];
ll n;

void init(ll x)
{
    x *= 4;
    for(int i = 0; i <= x; i++)
    {
        tree[i] = lazy[i] = 0;
    }
}

void lazyupdate(ll node, ll start, ll fin)
{
    if(lazy[node] != 0)
    {
        tree[node] += (fin - start + 1) * lazy[node];
        if(start != fin)
        {
            lazy[node << 1] += lazy[node];
            lazy[node << 1 | 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}


void updateRange(ll node, ll start, ll fin, ll l, ll r, ll val)
{
    lazyupdate(node, start, fin);
    //Three cases to consider
    //Case 1: If [l, r] totally outside [start, end], do nothing
    if(start > fin || start > r || fin < l) return;
    //Case 2: If [l,r] totally inside [start, end], update that node
    if(l <= start && fin <= r)
    {
        tree[node] += (fin - start + 1) * val;
        if(start != fin)
        {
            lazy[node << 1] += val;
            lazy[node << 1 | 1] += val;
        }
        return;
    }
    //Case 3: If [l, r] partially overlapping, then recur to child nodes and update their values, then update the node
    ll mid = start + ((fin - start) / 2);
    updateRange(node << 1, start, mid, l, r, val);
    updateRange(node<< 1 | 1, mid + 1, fin, l, r, val);

    tree[node] = tree[node << 1] + tree[node << 1 | 1];
}


///Start and Fin are the intervals represented by a node, e.g. for node 1, start = 0, and fin = n - 1 (where n is the size of the array)
ll queryRange(ll node, ll start, ll fin, ll l, ll r)
{
    //Three cases to consider
    //Case 1: If [l, r] totally outside [start, end], return 0
    if(start > fin || start > r || fin < l) return 0;

    lazyupdate(node,start, fin);

    //Case 2: If [l,r] totally inside [start, end], return that node
    if(l <= start && fin <= r) return tree[node];

    //Case 3: If [l, r] partially overlapping, then recur to child nodes and return their values, then return the total value
    ll mid = start + ((fin - start) / 2);
    ll q1 = queryRange(node << 1, start, mid, l, r);
    ll q2 = queryRange(node<< 1 | 1, mid + 1, fin, l, r);

    return q1 + q2;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    ll c;

    while(t--)
    {
        cin>>n>>c;
        init(n);
        ll m, p, q, v;

//        ///Tree printing start
//        cout<<"Current Tree: ";
//        for(int i = 0; i < n<<1; i++)
//        {
//            cout<<tree[i]<<" ";
//        }
//        cout<<endl;
//        cout<<"Lazy Array: ";
//        for(int i = 0; i < n; i++)
//        {
//            cout<<lazy[i]<<" ";
//        }
//        cout<<endl;
//        ///Tree printing end

        while(c--)
        {
            cin>>m>>p>>q;
            if(m)
            {
                cout<<queryRange(1, 0, n - 1, p - 1, q - 1)<<endl;
            }
            else
            {
                cin>>v;
                updateRange(1, 0, n - 1, p - 1, q - 1, v);
            }
//            cout<<"Current Tree: ";
//            for(int i = 0; i < n<<1; i++)
//            {
//                cout<<tree[i]<<" ";
//            }
//            cout<<endl;
//            cout<<"Lazy Array: ";
//            for(int i = 0; i < n; i++)
//            {
//                cout<<lazy[i]<<" ";
//            }
//            cout<<endl;
        }
    }


    return 0;
}

