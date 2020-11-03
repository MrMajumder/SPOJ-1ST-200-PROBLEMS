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
    while(t)
    {
        int arr[t];
        int next[t];
        for(int i = 0; i < t; i++) cin>>arr[i];
        for(int i = 0; i < t; i++) next[arr[i] - 1] = i + 1;

        bool isAmbi = true;
        for(int i = 0; i < t; i++)
            if(arr[i] != next[i])
            {
                isAmbi = false;
                break;
            }

        if(isAmbi) cout<<"ambiguous"<<endl;
        else cout<<"not ambiguous"<<endl;

        cin>>t;
    }

    return 0;
}

