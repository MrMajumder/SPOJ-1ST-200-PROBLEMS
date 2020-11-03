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

ll operate(ll a, string op, ll b)
{
    if(op == "+") return a + b;
    else if(op == "-") return a - b;
    else if(op == "*") return a * b;
    else if(op == "/") return a / b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        ll ans, second;
        string op;
        cin>>ans;
        cin>>op;

        while(op != "=")
        {
            cin>>second;
            ans = operate(ans, op, second);
            cin>>op;
        }
        cout<<ans<<ENDL;
    }

    return 0;
}

