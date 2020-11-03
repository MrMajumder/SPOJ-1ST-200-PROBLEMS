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

    string s;
    getline(cin, s);
    while(s != "*")
    {
        stringstream line(s);
        string word;
        line>>word;
        int start = (word[0] >= 'a') ? (word[0] - 'a') : (word[0] - 'A');
        bool oui = true;
        while(line)
        {
            line>>word;
            int now = (word[0] >= 'a') ? (word[0] - 'a') : (word[0] - 'A');
            if(now != start)
            {
                oui = false;
                break;
            }
        }
        if(oui) cout<<"Y"<<endl;
        else cout<<"N"<<endl;
        getline(cin, s);
    }

    return 0;
}

