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

    int x, y;
    for(int i = 0; i < n; i++)
    {
        cin>>x>>y;
        if(x == y || x == y + 2)
        {
            if(x%2)
            {
                cout<<x + y - 1<<endl;
            }
            else
            {
                cout<<x + y<<endl;
            }
        }
        else
        {
            cout<<"No Number"<<endl;
        }
    }

    return 0;
}

