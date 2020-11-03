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
const int MOD = 1000000007; //9digits
const double EPS = 1e-8;
const long double EULER = 2.71828182845904523536;   //20digits
const long double PI = 3.14159265358979323846;      //20digits
//float = 7digits, double = 15digits, long double = 21 digits precision

//defined my own datatypes
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int row, col;
    cin>>row>>col;
    int t;
    cin>>t;
    while(t--)
    {
        int mx, my, cax, cay, cbx, cby;
        cin>>mx>>my>>cax>>cay>>cbx>>cby;
        bool oui = false;
        for(int i = 1; i <= row; i++)
        {
            for(int j = 1; j <= col; j++)
            {
                if((i != 1 && i != row)) if(j != 1 && j != col) continue;
                int md = abs(i - mx) + abs(j - my);
                int cad = abs(i - cax) + abs(j - cay);
                int cbd = abs(i - cbx) + abs(j - cby);
                if(md < cad && md < cbd)
                {
                    oui = true;
                    i = row + 1;
                    break;
                }
            }
        }
        if(oui) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}

