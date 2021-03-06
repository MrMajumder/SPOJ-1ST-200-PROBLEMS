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
        cin>>x;
        int first[x];
        int second[x];

        for(int j = 0; j < x; j++)
        {
            cin>>first[j];
        }
        for(int j = 0; j < x; j++)
        {
            cin>>second[j];
        }

        sort(first, first + x);
        sort(second, second + x);

        ll sum = 0;
        for(int j = 0; j < x; j++)
        {
            sum += (first[j] * second[j]);
        }
        cout<<sum<<endl;
    }

    return 0;
}

