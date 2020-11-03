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

int LCS(string s1, string s2, int n)
{
    int arr[n + 1][n + 1];

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0) arr[i][j] = 0;
            else
            {
                if(s1[i - 1] == s2[j - 1]) arr[i][j] = arr[i - 1][j - 1] + 1;
                else
                {
                    arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
                }
            }
        }
    }

    return arr[n][n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        string s, r;
        cin>>r;
        s = r;
        int len = s.length();
        reverse(r.begin(), r.end());
        cout<< len - LCS(s, r, len)<<endl;
    }


    return 0;
}

