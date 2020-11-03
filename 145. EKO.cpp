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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, wood;
    cin>>n>>wood;
    ll prefixsum[n] = {0};
    ll tree[n];
    for(int i = 0; i < n; i++) cin>>tree[i];
    sort(tree, tree + n);
    prefixsum[0] = tree[0];
    for(int i = 1; i < n; i++) prefixsum[i] = prefixsum[i - 1] + tree[i];
    double maxtree = tree[n - 1];
    double mintree = 0;
    double ans;

    while(mintree < maxtree)
    {
        ans = mintree + ((maxtree - mintree) / 2.0);
        int pos = upper_bound(tree, tree + n, ans) - tree;
        double woodget = (prefixsum[n - 1] - prefixsum[pos - 1]) - ((n - pos) * ans);
        if(woodget == wood) break;
        else if(woodget < wood) maxtree = ans;
        else mintree = ans;
    }
    cout<<(int)floor(ans)<<endl;

    return 0;
}

