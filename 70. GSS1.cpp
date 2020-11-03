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

ll mini = -INF;

struct node{
    ll prefix;
    ll suffix;
    ll totalSum;
    ll totalSubSum;
};

void buildSegmentTree(node arr[], int n)
{
    ll x;
    for(int i = 0; i < n; i++)
    {
        cin>>x;
        mini = min(mini, x);

        arr[n + i].prefix = arr[n + i].suffix = arr[n + i].totalSum = arr[n + i].totalSubSum = x;
    }

    for(int i = n-1; i > 0; i--)
    {
        arr[i].prefix = max(arr[i << 1].prefix, arr[i << 1].totalSum + arr[i << 1 | 1].prefix);
        arr[i].suffix = max(arr[i << 1 | 1].suffix, arr[i << 1 | 1].totalSum + arr[i << 1].suffix);
        arr[i].totalSum = arr[i << 1].totalSum + arr[i << 1 | 1].totalSum;
        arr[i].totalSubSum = max(max(arr[i << 1].totalSubSum, arr[i << 1 | 1].totalSubSum), arr[i << 1].suffix + arr[i << 1 | 1].prefix);
    }
}

ll query(node arr[], int l, int r, int n)
{
    node lans, rans;
    lans.prefix = lans.suffix = lans.totalSubSum = lans.totalSum = rans.prefix = rans.suffix = rans.totalSubSum = rans.totalSum = mini;
    l -= 1;
    node templ, tempr;

    for(l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if(l & 1)
        {
            templ.prefix = max(lans.prefix, lans.totalSum + arr[l].prefix);
            templ.suffix = max(arr[l].suffix, arr[l].totalSum + lans.suffix);
            templ.totalSum = lans.totalSum + arr[l].totalSum;
            templ.totalSubSum = max(max(lans.totalSubSum, arr[l].totalSubSum), lans.suffix + arr[l].prefix);
            lans = templ;

            l++;
        }

        if(r & 1)
        {
            r--;

            tempr.prefix = max(arr[r].prefix, arr[r].totalSum + rans.prefix);
            tempr.suffix = max(rans.suffix, rans.totalSum + arr[r].suffix);
            tempr.totalSum = rans.totalSum + arr[r].totalSum;
            tempr.totalSubSum = max(max(arr[r].totalSubSum, rans.totalSubSum), arr[r].suffix + rans.prefix);
            rans = tempr;
        }
    }

    return max(max(lans.totalSubSum, rans.totalSubSum), lans.suffix + rans.prefix);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    node sgt[2 * n];

    buildSegmentTree(sgt, n);

    int q;
    cin>>q;
    int l, r;

    while(q--)
    {
        cin>>l>>r;
        cout<<(ll) query(sgt, l, r, n)<<endl;
    }

    return 0;
}

