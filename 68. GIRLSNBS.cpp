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

    int g, b;
    cin>>g>>b;

    while(g != -1)
    {
        if(g == 0 || b == 0) cout<<max(g, b)<<endl;
        else
        {
            cout<< (int) ceil((max(g, b)) * 1.0 / (min(g, b) + 1))<<endl;
        }
        cin>>g>>b;
    }

    return 0;
}

