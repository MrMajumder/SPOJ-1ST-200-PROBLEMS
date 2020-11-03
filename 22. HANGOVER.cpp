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
    double x;
    cin>>x;

    while(x)
    {
        double sum = 0.0;
        int cards = 1;

        while(sum <  x)
        {
            sum += 1.0 / (cards + 1);
            cards++;
        }
        cout<<cards - 1<<" card(s)"<<endl;

        cin>>x;
    }

    return 0;
}

