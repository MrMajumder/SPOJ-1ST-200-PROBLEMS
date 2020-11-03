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
        double u, v, w, U, V, W;
        cin>>W>>V>>u>>U>>v>>w;
        double ux = (v * v) + (w * w) - (U * U);
        double vx = (w * w) + (u * u) - (V * V);
        double wx = (u * u) + (v * v) - (W * W);

        double vol = (1.0 / 12) * sqrt((4 * u * u * v * v * w * w) - (u * u * ux * ux) - (v * v * vx * vx) - (w * w * wx * wx) + (ux * vx * wx));
        cout<<setprecision(4)<<fixed<<vol<<endl;
    }

    return 0;
}

