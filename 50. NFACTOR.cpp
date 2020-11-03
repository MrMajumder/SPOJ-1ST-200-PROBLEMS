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

typedef long long ll;
int n = 1e6;
int counter[11][1000001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int nsqrt = sqrt(n);

    vector<int> factor(n + 1, 0);

    for(int i= 2; i <= n; i++)
    {
        if(factor[i] == 0)
        {
            for(int j = i; j <= n; j+= (i))
            {
                factor[j]++;
            }
        }
    }


    for(int i = 0; i <= 10; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            counter[i][j] = counter[i][j - 1] + (bool)(factor[j] == i);

        }
    }

    int t;
    int a, b, f;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>f;

        cout<<counter[f][b] - counter[f][a - 1]<<ENDL;

    }


    return 0;
}

