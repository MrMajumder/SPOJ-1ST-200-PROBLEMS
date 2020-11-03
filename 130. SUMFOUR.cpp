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

    int n;
    cin>>n;
    int arr[4][n];
    for(int i = 0; i < n; i++) cin>>arr[0][i]>>arr[1][i]>>arr[2][i]>>arr[3][i];
    vector<int> sum1, sum2;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            sum1.push_back(arr[0][i] + arr[1][j]);
            sum2.push_back(-(arr[2][i] + arr[3][j]));
        }
    }
    sort(sum1.begin(), sum1.end());
    sort(sum2.begin(), sum2.end());
    int ans = 0;
    for(int i = 0; i < sum1.size();)
    {
        int j = i + 1;
        while(j < sum1.size() && sum1[i] == sum1[j]) j++;
        vector<int>::iterator hi = upper_bound(sum2.begin(), sum2.end(), sum1[i]);
        vector<int>::iterator lo = lower_bound(sum2.begin(), sum2.end(), sum1[i]);
        ans += (j - i) * (hi - lo);
        i = j;
    }
    cout<<ans<<endl;

    return 0;
}

