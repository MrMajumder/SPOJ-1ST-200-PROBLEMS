#include<bits/stdc++.h>
using namespace std;

#define max2(a, b) (((a) > (b)) ? (a) : (b))
#define min2(a, b) (((a) > (b)) ? (b) : (a))
#define abs(a) (((a) > 0) ? (a) : (-(a)))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

const int INF = 0x3f3f3f3f;

typedef long long ll;

int gcd(int a, int b)
{
    return b? (gcd(b, a % b)) : a;
}

int main()
{
    int t;
    cin>>t;

    for(int i = 1; i <= t; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        if(a < b) swap(a, b);
        int g = gcd(a, b);

        if(c % g) cout<<"Case "<<i<<": No"<<endl;
        else cout<<"Case "<<i<<": Yes"<<endl;
    }

    return 0;
}

