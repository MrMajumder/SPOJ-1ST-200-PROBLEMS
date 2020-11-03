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
    while(n != 0)
    {
        int a[n];
        for(int i = 0; i < n; i++) cin>>a[i];
        int m;
        cin>>m;
        int b[m];
        for(int i = 0; i < m; i++) cin>>b[i];

        int i, j;
        i = j = 0;
        int ans, tempa, tempb;
        ans = tempa = tempb = 0;
        while(i < n && j < m)
        {
            if(a[i] == b[j])
            {
                tempa += a[i++];
                tempb += b[j++];
                ans += (tempa > tempb) ? tempa : tempb;
                tempa = 0;
                tempb = 0;
            }
            else
            {
                if(a[i] > b[j])
                {
                    tempb += b[j++];
                }
                else if(a[i] < b[j])
                {
                    tempa += a[i++];
                }
            }
        }
        while(i < n) tempa += a[i++];
        while(j < m) tempb += b[j++];

        ans += (tempa > tempb) ? tempa : tempb;
        cout<<ans<<endl;
        cin>>n;
    }

    return 0;
}


