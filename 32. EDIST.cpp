#include<bits/stdc++.h>
using namespace std;

#define max2(a, b) (((a) > (b)) ? (a) : (b))
#define min2(a, b) (((a) > (b)) ? (b) : (a))
#define abs(a) (((a) > 0) ? (a) : (-(a)))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

const int INF = 0x3f3f3f3f;

typedef long long ll;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string a, b;
        cin>>a>>b;

        int alen = a.length();
        int blen = b.length();

        int dp[alen + 1][blen + 1];

        for(int i = 0; i <= alen; i++)
        {
            for(int j = 0; j <= blen; j++)
            {
                if(i == 0 || j == 0)
                {
                    dp[i][j] = max(i, j);
                    continue;
                }

                if(a[i - 1] == b[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = min3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
                }
            }
        }

        cout<<dp[alen][blen]<<endl;

    }

    return 0;
}

