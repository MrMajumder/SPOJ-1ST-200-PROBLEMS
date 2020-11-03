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

    int t;
    cin>>t;
    while(t--)
    {
        vector<int> aa;
        int n;
        cin>>n;
        while(n)
        {
            aa.push_back(n);
            cin>>n;
        }
        int maxi = -1;
        cin>>n;
        while(n)
        {
            vector<int> ab;
            while(n)
            {
                ab.push_back(n);
                cin>>n;
            }
            int lena = aa.size();
            int lenb = ab.size();
            //cout<<lena<<" "<<lenb<<endl;
            int dp[lena + 1][lenb + 1];
            for(int i = 0; i <= lena; i++)
            {
                for(int j = 0; j <= lenb; j++)
                {
                    if(i== 0 || j == 0) dp[i][j] = 0;
                    else if(aa[i - 1] == ab[j  - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                    else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
//            cout<<endl;
//            for(int i = 0; i <= lena; i++)
//            {
//                for(int j = 0; j <= lenb; j++)
//                {
//                    cout<<dp[i][j]<<SPACE;
//                }
//                cout<<endl;
//            }
            maxi = max(maxi, dp[lena][lenb]);
            cin>>n;
        }
        cout<<maxi<<endl;
    }

    return 0;
}

