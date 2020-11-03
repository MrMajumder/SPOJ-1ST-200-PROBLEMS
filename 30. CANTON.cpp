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
        int n;
        cin>>n;
        bool leftpull = true;
        int l = 1, r = 1;
        for(int i = 1; i < n; i++)
        {
            if(leftpull)
            {
                l--;
                r++;
            }
            else
            {
                r--;
                l++;
            }

            if(l == 0 || r == 0)
            {
                if(leftpull)
                {
                    l++;
                    leftpull = false;
                }
                else
                {
                    r++;
                    leftpull = true;
                }
            }
        }
        cout<<"TERM "<<n<<" IS "<<l<<"/"<<r<<endl;
    }
    return 0;
}

