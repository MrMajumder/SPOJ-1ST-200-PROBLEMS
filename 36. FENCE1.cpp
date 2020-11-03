#include<bits/stdc++.h>
using namespace std;

#define max2(a, b) (((a) > (b)) ? (a) : (b))
#define min2(a, b) (((a) > (b)) ? (b) : (a))
#define abs(a) (((a) > 0) ? (a) : (-(a)))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

const int INF = 0x3f3f3f3f;
const double PI = 2 * acos(0.0);

typedef long long ll;

int main()
{
    int p;
    cin>>p;

    while(p)
    {
        double ans = p * p * (1 / 2.0) * (1 / 3.1415926);
        cout<<fixed<<setprecision(2)<<ans<<endl;

        cin>>p;
    }

    return 0;
}
