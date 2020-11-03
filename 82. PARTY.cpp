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


void knapSack(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];

   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }

//   for(int i = 0; i <= n; i++)
//    {
//        for(int j = 0; j <= W; j++)
//        {
//            cout<<K[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    int maxfun = K[n][W];
    int minval = W;

    if(maxfun == 0) minval = 0;
    else while(K[n][minval] == maxfun) minval--;

    cout<<(minval + ((minval)? 1 : 0))<<" "<<maxfun<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int money, party;

    while(1)
    {
        cin>>money;
        cin>>party;
        if(money == 0 && party == 0) break;

        int cost[party], weight[party];
        int c, w;

        for(int i = 0; i < party; i++)
        {
            cin>>c;
            cin>>w;
            cost[i] = c;
            weight[i] = w;
        }

        knapSack(money, cost, weight, party);
    }

    return 0;
}

