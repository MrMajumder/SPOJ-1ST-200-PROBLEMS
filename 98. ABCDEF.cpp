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

    int n;
    cin>>n;
    int numset[n];
    for(int i = 0; i <n; i++) cin>>numset[i];

    int n3 = n * n * n;
    int a[n3], b[n3];
    int coun1 = 0, coun2 = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++)
            {
                a[coun1++] = (numset[i] * numset[j]) + numset[k];
                if(numset[k] != 0) b[coun2++] = (numset[i] + numset[j]) * numset[k];
            }
        }
    }

    sort(a, a + (coun1));
    sort(b, b + (coun2));


    int i, j, c1, c2, ans;
    i = j = ans = 0;

    while(i < coun1 && j < coun2)
    {
        if(a[i] != b[j])
        {
            if(a[i] <  b[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        else if(a[i] == b[j])
        {
            c1 = c2 = 1;
            while(a[i++] == a[i])
            {
                 c1++;
                 if(i == coun1 - 1)
                 {
                     i++;
                     break;
                 }
            }
            while(b[j++] == b[j])
            {
                 c2++;
                 if(j == coun2 - 1)
                 {
                     j++;
                     break;
                 }
            }
            ans += c1 * c2;
        }
    }
    cout<<ans<<endl;

    return 0;
}


