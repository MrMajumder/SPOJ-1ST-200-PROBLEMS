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
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);

    int n;
    cin>>n;
    int m = (int)floor(log2(n)) + 1;
    int precomp[n][m];
    int x;
    for(int i = 0; i < n; i++)
    {
        cin>>x;
        precomp[i][0] = x;
    }

    //fill the array with dp (still not sure how this is done :))
    for(int j = 1; (1 << j) <= n; j++)
    {
        for(int i = 0; (i + (1 << j) - 1) < n; i++)
        {
            precomp[i][j] = min(precomp[i][j - 1], precomp[i + (1 << (j - 1))][j - 1]);
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout<<precomp[i][j]<<SPACE;
        }
        cout<<ENDL;
    }

    int q;
    cin>>q;
    while(q--)
    {
        int l, r;
        cin>>l>>r;

        int j = (int)log2(r - l + 1);
        int ans = min(precomp[l][j], precomp[r - (1 << j) + 1][j]);
        cout<<ans<<ENDL;
    }


    return 0;
}

