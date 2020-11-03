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
        ll a, b, sum;
        cin>>a>>b>>sum;

        ll n = (2 * sum) / (a + b);
        ll d = (b - a) / (n - 5);

        ll one = a - (2 * d);

        cout<<n<<endl;
        for(int i = 0; i < n; i++)
        {
            cout<<one + (i * d)<<" ";
        }
        cout<<endl;
    }

    return 0;
}

