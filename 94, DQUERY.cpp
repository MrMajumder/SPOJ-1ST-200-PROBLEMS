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

int coun[1000000 + 5];
int arr[30000 + 5];
int block;
int curans;
struct Query
{
    int l, r, idx;
};

bool compare(Query a, Query b)
{
    if(a.l / block != b.l / block) return (a.l / block) < (b.l / block);
    return a.r < b.r;
}

void add(int pos)
{
    coun[arr[pos]]++;
    if(coun[arr[pos]] == 1) curans++;
}

void remov(int pos)
{
    coun[arr[pos]]--;
    if(coun[arr[pos]] == 0) curans--;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    block = (int)sqrt(n);
    for(int i = 1; i <= n; i++) cin>>arr[i];

    int m;
    cin>>m;
    Query q[m];
    int ans[m];
    for(int i = 0; i < m; i++)
    {
        cin>>q[i].l>>q[i].r;
        q[i].idx = i;
    }
    sort(q, q + m, compare);

    int curl, curr;
    curl = curr = 1;

    for(int i = 0; i < m; i++)
    {
        while(curl < q[i].l)
        {
            remov(curl++);
        }
        while(curl > q[i].l)
        {
            add(--curl);
        }
        while(curr <= q[i].r)
        {
            add(curr++);
        }
        while(curr > q[i].r + 1)
        {
            remov(--curr);
        }
        ans[q[i].idx] = curans;
    }

    for(int i = 0; i < m; i++) cout<<ans[i]<<endl;

    return 0;
}

