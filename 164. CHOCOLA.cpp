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

    int t;
    cin>>t;
    while(t--)
    {
        int n, m; // n = col, m = row
        cin>>n>>m;
        n--; m--;
        int x[n];
        int y[m];
        for(int i = 0; i < n; i++) cin>>x[i];
        for(int i = 0; i < m; i++) cin>>y[i];
        int h = 1, v = 1;
        int i = 0, j = 0;
        int ans = 0;
        sort(x, x + n, greater<int>());
        sort(y, y + m, greater<int>());
        while(i < n && j < m)
        {
            if(x[i] > y[j])
            {
                ans += x[i++] * v;
                h++;
            }
            else
            {
                ans += y[j++] * h;
                v++;
            }
        }
        while(i < n)
        {
            ans += x[i++] * v;
        }
        while(j < m)
        {
            ans += y[j++] * h;
        }
        cout<<ans<<endl;
    }

    return 0;
}

