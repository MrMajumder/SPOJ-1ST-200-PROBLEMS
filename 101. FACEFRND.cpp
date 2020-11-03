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

    int f;
    cin>>f;
    set<int> st;

    int n;
    for(int i = 0; i < f; i++)
    {
        cin>>n;
        st.insert(n);
        int t;
        cin>>t;
        while(t--)
        {
            cin>>n;
            st.insert(n);
        }
    }
    cout<<st.size() - f<<endl;

    return 0;
}


