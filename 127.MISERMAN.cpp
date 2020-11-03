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

    int n, m;
    cin>>n>>m;

    int arr[n][m + 2];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m + 2; j++)
        {
            if(j == 0 || j == m + 1) arr[i][j] = INF;
            else cin>>arr[i][j];
        }
    }

    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < m + 1; j++)
        {
            arr[i][j] += min(arr[i - 1][j], min(arr[i - 1][j - 1], arr[i - 1][j + 1]));
        }
    }

    int mini = INF;
    for(int j = 0; j < m + 2; j++)
    {
        mini = min(mini, arr[n - 1][j]);
    }

    cout<<mini<<endl;

    return 0;
}

