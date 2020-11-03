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

struct node
{
    int prefix;
    int suffix;
    int totalSum;
    int totalSubSum;
};

node t[50000 + 5];

void build(int idx, int l, int r)
{
    if(l == r) return;
    int mid = l + ((r - l) / 2);
    build(idx<<1, l, mid);
    build(idx<<1|1, mid + 1, r);
    t[idx].prefix = max(t[idx << 1].prefix, t[idx << 1].totalSum + t[idx << 1 | 1].prefix);
    t[idx].suffix = max(t[idx << 1 | 1].suffix, t[idx << 1 | 1].totalSum + t[idx << 1].suffix);
    t[idx].totalSum = t[idx << 1].totalSum + t[idx << 1 | 1].totalSum;
    t[idx].totalSubSum = max3(t[idx << 1].totalSubSum, t[idx << 1 | 1].totalSubSum, t[idx << 1].suffix + t[idx << 1 | 1].prefix);
}

void buildsegmenttree(int n)
{
    int x;
    for(int i = 0; i < n; i++)
    {
        cin>>x;
        t[n + i].prefix = t[n + i].suffix = t[n + i].totalSum = t[n + i].totalSubSum = x;
    }
    build(1, 0, n - 1);
}

node * query(int idx, int start, int fin, int l, int r)
{
    if(r < start || fin < l)
    {
        node * temp = new node;
        temp->prefix = temp->suffix = temp->totalSubSum = temp->totalSum = -INF;
        return temp;
    }
    if(l <= start && fin <= r) return (t + idx);

    int mid = start + ((fin - start) / 2);
    node * n1 = query(idx << 1, start, mid, l, r);
    node * n2 = query(idx << 1 | 1, mid + 1, fin, l, r);

    node * ans = new node;
    ans->prefix = max(n1->prefix, n1->totalSum + n2->prefix);
    ans->suffix = max(n2->suffix, n2->totalSum + n1->suffix);
    ans->totalSum = n1->totalSum + n2->totalSum;
    ans->totalSubSum = max3(n1->totalSubSum, n2->totalSubSum, max3(ans->prefix, ans->suffix, n1->suffix + n2->prefix));

    return ans;
}

void update(int idx, int l, int r, int pos, int val)
{
    if(l == r)
    {
        t[idx].prefix = t[idx].suffix = t[idx].totalSum = t[idx].totalSubSum = val;
        return;
    }

    int mid = l + ((r - l) / 2);
    if(l <= pos && pos <= mid) update(idx << 1, l, mid, pos, val);
    else update(idx << 1 | 1, mid + 1, r, pos, val);

    t[idx].prefix = max(t[idx << 1].prefix, t[idx << 1].totalSum + t[idx << 1 | 1].prefix);
    t[idx].suffix = max(t[idx << 1 | 1].suffix, t[idx << 1 | 1].totalSum + t[idx << 1].suffix);
    t[idx].totalSum = t[idx << 1].totalSum + t[idx << 1 | 1].totalSum;
    t[idx].totalSubSum = max(t[idx << 1].totalSubSum,
                             max(t[idx << 1 | 1].totalSubSum,
                                 max(t[idx].prefix,
                                     max(t[idx].suffix, t[idx << 1].suffix + t[idx << 1 | 1].prefix))));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    buildsegmenttree(n);
    int q;
    cin>>q;

    int m, l, r;
    while(q--)
    {
        cin>>m>>l>>r;
        if(m == 1)
        {
            node * ans = query(1, 0, n - 1, l - 1, r - 1);
            cout<<ans->totalSubSum<<endl;
        }
        else if (m == 0)
        {
            update(1, 0, n - 1, l - 1, r);
        }
        else
        {
            for(int i = 0; i <= 2 * n; i++) cout<<t[i].totalSubSum<<SPACE;
            cout<<endl;
        }
    }

    return 0;
}

