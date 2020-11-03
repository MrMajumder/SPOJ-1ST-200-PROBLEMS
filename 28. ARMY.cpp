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
        int m, g;
        cin>>g>>m;
        bool gwin = true;

        int garr[g], marr[m];

        for(int i = 0; i < g; i++)
        {
            cin>>garr[i];
        }
        for(int i = 0; i < m; i++)
        {
            cin>>marr[i];
        }

        sort(garr, garr + g, greater<int>());
        sort(marr, marr + m, greater<int>());

        int mcheck = 0;
        for(; mcheck < m; mcheck++)
        {
            if(garr[0] > marr[mcheck])
            {
                gwin = true;
                break;
            }
            else if(garr[0] < marr[mcheck])
            {
                gwin = false;
                break;
            }
        }

        if(gwin) cout<<"Godzilla"<<endl;
        else cout<<"MechaGodzilla"<<endl;

    }

    return 0;
}

