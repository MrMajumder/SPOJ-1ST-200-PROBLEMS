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
        int n, top;
        cin>>n>>top;
        int arr[n];
        int cum[n + 1];
        for(int i = 0; i < n; i++)
        {
            cin>>arr[i];
            cum[i + 1] = cum[i] + arr[i];
        }
        int maxstation = 0;
        int maxpeople = 0;
        int stpassed = 1;
        int pa, pb;
        pb = 1 + (pa = 0);
        while(pb <= n)
        {
            //cout<<pa<<SPACE<<pb<<endl;
            if(cum[pb] - cum[pa] <= top)
            {
                if(stpassed > maxstation)
                {
                    maxstation = stpassed;
                    maxpeople = cum[pb] - cum[pa];
                }
                else if(stpassed == maxstation)
                {
                    maxpeople = min(maxpeople, cum[pb] - cum[pa]);
                }
                pb++;
                stpassed++;
            }
            else
            {
                stpassed--;
                pa++;
                if(pa == pb)
                {
                    pb++;
                    stpassed++;
                }
            }
        }
        cout<<maxpeople<<SPACE<<maxstation<<endl;
    }

    return 0;
}

