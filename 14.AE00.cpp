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
    int n;
    cin>>n;

    int upto = floor(sqrt(n));
    int sum = 0;

    for(int i = 1; i <= upto; i++)
    {
        sum += (n / i) - (i - 1);
    }
    cout<<sum<<endl;

    return 0;
}

