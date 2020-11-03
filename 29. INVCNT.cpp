#include<bits/stdc++.h>
using namespace std;

#define max2(a, b) (((a) > (b)) ? (a) : (b))
#define min2(a, b) (((a) > (b)) ? (b) : (a))
#define abs(a) (((a) > 0) ? (a) : (-(a)))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

const int INF = 0x3f3f3f3f;

typedef long long ll;

void convert(int arr[], int len)
{
    int temp[len];
    for(int i = 0; i < len; i++) temp[i] = arr[i];
    sort(temp, temp + len);
    for(int i = 0; i < len; i++) arr[i] = lower_bound(temp, temp + len, arr[i]) - temp + 1;
}

ll read(ll arr[], int len)
{
    ll ans = 0;
    while(len > 0)
    {
        ans += arr[len];
        len -= len & -len;
    }
    return ans;
}

void update(ll arr[], int pos, int val, int len)
{
    while(pos <= len)
    {
        arr[pos] += val;
        pos += pos & -pos;
    }
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        ll tree[n + 1]=;
        memset(tree, 0, sizeof(tree));
        for(int i = 0; i < n; i++) cin>>arr[i];
        convert(arr, n);

        ll ans = 0;

        for(int i = n - 1; i >= 0; i--)
        {
            ans += read(tree, arr[i] - 1);
            update(tree, arr[i], 1, n);
        }
        cout<<ans<<endl;

    }

    return 0;
}

