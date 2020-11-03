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
    int turn = 0;
    cin>>t;

    while(turn++ < t)
    {
        int stamp, fren;
        cin>>stamp>>fren;
        int arr[fren];

        for(int i = 0; i < fren; i++)
        {
            cin>>arr[i];
        }

        sort(arr, arr + fren, greater<int>());

        int sum = 0, required = 0;
        while(sum < stamp && required < fren)
        {
            sum += arr[required++];
        }
        cout<<"Scenario #"<<turn<<":"<<endl;
        if(sum >= stamp && required <= fren) cout<<required<<endl<<endl;
        else cout<<"impossible"<<endl<<endl;
    }

    return 0;
}

