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
    ll t;
    cin>>t;

    while(t--)
    {
        int stall, cow;
        cin>>stall>>cow;

        ll barn[stall];

        for(int i = 0; i < stall; i++)
        {
            cin>>barn[i];
        }
        sort(barn, barn + stall);
        ll lo = 0, hi = barn[stall - 1] - barn[0], mid;
        int ans = 0;

        while(lo < hi)
        {
            mid = (lo + hi) / 2;
            int cows = 1, below = barn[0];
            for(int i = 1; i < stall; i++)
            {
                if(barn[i] - below >= mid)
                {
                    cows++;
                    below = barn[i];
                }
            }

            if(cows >= cow)
            {
                lo = mid + 1;
                ans = mid;
            }
            else
            {
                hi = mid;
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}

