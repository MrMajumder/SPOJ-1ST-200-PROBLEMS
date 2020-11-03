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
        ll arr[n + 2];
        arr[0] = arr[n + 1] = 0;
        for(int i = 1; i <= n; i++) cin>>arr[i];
        stack<int> st;
        int i = 0;
        ll ans = 0;
        while(i < n + 2)
        {
            if(st.empty() || arr[i] >= arr[st.top()]) st.push(i++);
            else
            {
                int temp = st.top();
                st.pop();
                ans = max(ans, arr[temp] * (st.empty() ? i : (i - st.top() - 1)));
            }
        }
        cout<<ans<<endl;
        cin>>n;
    }

    return 0;
}


