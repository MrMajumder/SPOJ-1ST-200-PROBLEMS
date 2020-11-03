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

vector<bool> oui(101 * 101 * 101, true);
vector<int> pos(101 * 101 * 101);

void precalc(int n)
{
    for(int i = 2; i <= n; i++)
    {
        int mul = 1;
        int cube = i * i * i;
        while(cube * mul < 1000010) oui[cube * (mul++)] = false;
    }
    int counter = 0;
    for(int i = 1; i < 1000010; i++)
    {
        if(oui[i]) counter++;
        pos[i] = counter;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precalc(101);
    int t;
    cin>>t;
    int total = t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<"Case "<<total - t<<": ";
        if(oui[n]) cout<<pos[n]<<endl;
        else cout<<"Not Cube Free"<<endl;
    }

    return 0;
}

