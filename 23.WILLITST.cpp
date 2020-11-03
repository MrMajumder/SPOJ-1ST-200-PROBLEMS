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
    ll num;
    cin>>num;
    while(num != 3 && num != 1)
    {
        if(num % 2) num = (num * 3) + 3;
        else num /= 2;
    }

    if(num == 3) cout<<"NIE"<<endl;
    if(num == 1) cout<<"TAK"<<endl;

    return 0;
}

