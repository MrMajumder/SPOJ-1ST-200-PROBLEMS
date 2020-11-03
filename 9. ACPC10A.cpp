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
    int x, y, z;
    cin>>x>>y>>z;

    while(!(x == 0 && y == 0 && z == 0))
    {
        if((y - x) == (z - y)) cout<<"AP "<< z + z - y<<endl;
        else cout<<"GP "<<z * (z / y)<<endl;
        cin>>x>>y>>z;
    }

    return 0;
}

