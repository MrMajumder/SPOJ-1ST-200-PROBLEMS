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

int mincyclicstring(string s)
{
    s += s;
    int n = s.size();
    int i = 0, ans = 0;
    while(i < n / 2)
    {
        ans = i;
        int j = i + 1, k = i;
        while(j < n && s[k] <= s[j])
        {
            if(s[k] < s[j]) k = i;
            else k++;
            j++;
        }
        while(i <= k) i += j - k;
    }
    return ans + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<mincyclicstring(s)<<endl;
    }

    return 0;
}

