#include<bits/stdc++.h>
using namespace std;

//defined my macro functions
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

//defined my macro strings
#define ENDL "\n"
#define SPACE " "

//defined my constants
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
const double EPS = 1e-8;
const double PI = 3.14159265358979323846;

//defined my own datatypes
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, diff;
    cin>>n>>diff;
    int arr[n];
    for(int i = 0; i < n; i++) cin>>arr[i];
    sort(arr, arr + n);

    int ans = 0;
    int i = 0, j = 1;
    while(i < n && j < n)
    {
        int hold = arr[j] - arr[i];
        if(hold == diff)
        {
            ans++;
            i++;
            j++;
        }
        else if(hold > diff)
        {
            i++;
            if(i == j) j++;
        }
        else if(hold < diff)
        {
            j++;
        }
    }
    cout<<ans<<endl;

    return 0;
}
