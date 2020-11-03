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

    while(n != -1)
    {
        int arr[n];
        float add = 0.0;
        for(int i = 0; i < n; i++)
        {
            cin>>arr[i];
            add += arr[i];
        }
        add = (add * 1.0) / n;

        if(add != floor(add))
        {
            cout<<-1<<endl;
        }
        else
        {
            int ans = 0;
            for(int i = 0; i < n; i++)
            {
                if(arr[i] < add)
                {
                    ans += add - arr[i];
                }
            }
            cout<<ans<<endl;
        }
        cin>>n;
    }

    return 0;
}

