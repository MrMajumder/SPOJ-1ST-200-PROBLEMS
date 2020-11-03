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

int digit[30];
int len;

int compute(int pos, int prevsum)
{
    if(pos == len) return 1;
    int sum = 0, ans = 0;
    for(int i = pos; i < len; i++)
    {
        sum += digit[i];
        ans += ((prevsum <= sum) ? compute(i + 1, sum): 0);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;
    int testcase = 1;
    while(s != "bye")
    {
        len = s.length();
        memset(digit, 0, sizeof digit);
        for(int i = 0; i < len; i++) digit[i] = (int) s[i] - '0';
        cout<<(testcase++)<<". "<<compute(0, 0)<<endl;
        cin>>s;
    }

    return 0;
}

