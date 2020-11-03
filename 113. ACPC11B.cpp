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
        int n, m;
        cin>>n;
        int a[n];
        for(int i = 0; i < n; i++) cin>>a[i];
        cin>>m;
        int b[m];
        for(int i = 0; i < m; i++) cin>>b[i];

        sort(a, a + n);
        sort(b, b + m);

        int i, j;
        i = j = 0;
        int mini = INF;
        while(i < n && j < m)
        {
            mini = min(mini, abs(a[i] - b[j]));
            if(a[i] > b[j]) j++;
            else if(a[i] < b[j]) i++;
            else i++, j++;
        }

        while(i < n) mini = min(mini, abs(a[i++] - b[j - 1]));
        while(j < m) mini = min(mini, abs(a[i - 1] - b[j++]));

        cout<<mini<<endl;
    }

    return 0;
}

