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

    int n, t;
    cin>>n>>t;
    int m = (int) floor(log2(n)) + 1;
    int lookup[n + 1][m];

    for(int i = 0; i < n; i++)
    {
        cin>>lookup[i][0];
    }
    lookup[n][0] = 0;

    for(int j = 1; (1 << j) <= n; j++)
    {
        for(int i = 0; (i + (1 << j) - 1) < n; i++)
        {
            lookup[i][j] = max(lookup[i][j - 1], lookup[i + (1 << (j - 1))][j - 1]);
        }
    }

//    for(int i = 0; i < n; i++)
//    {
//        for(int j = 0; j < m; j++)
//        {
//            cout<<lookup[i][j]<<SPACE;
//        }
//        cout<<ENDL;
//    }
    int l, r, ans = 0;
    while(t--)
    {
        cin>>l>>r;
        int ahill = lookup[l - 1][0];
        if(l > r)
        {
            swap(l, r);

        }

        if((r - l) <= 1)
        {
            ans++;
            //cout<<"hehe"<<endl;
            continue;
        }
        int j = (int)log2(r - l - 1);
        int high = max(lookup[l + 1][j], lookup[r - (1 << j)][j]);
        if(ahill >= high)
        {
            ans++;
            //cout<<"hehe"<<endl;
        }
    }
    cout<<ans<<ENDL;

    return 0;
}

