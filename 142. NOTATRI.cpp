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
    while(n)
    {
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin>>a[i];
        sort(a.begin(), a.end());
        vector<int> li;
        for(int i = 0; i < n - 1; i++)
        {
            for(int j = i + 1; j < n; j++) li.push_back(a[i] + a[j]);
        }
        sort(li.begin(), li.end());
        int len = li.size();
        int ans = 0;
        for(int i = 0; i < len;)
        {
            int k = i + 1;
            while(k < len && li[i] == li[k]) k++;
            vector<int>::iterator ub = upper_bound(a.begin(), a.end(), li[i]);
            if(ub == a.end()) break;
            ans += (a.end() - ub) * (k - i);
            i = k;
        }
        cout<<ans<<endl;
        cin>>n;
    }

    return 0;
}

