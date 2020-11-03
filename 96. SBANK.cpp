
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

bool customcompare(string a, string b)
{
    int x = a.compare(b);
    if(x <= 0) return true;
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    int n;
    while(t--)
    {
        cin>>n;
        cin.ignore();
        string arr[n];
        for(int i = 0; i < n; i++)
        {
            getline(cin, arr[i]);
        }

        sort(arr, arr + n);
        int counter = 1;
        cout<<endl;
        for(int i = 1; i < n; i++)
        {
            if(arr[i - 1] == arr[i]) counter++;
            else
            {
                cout<<arr[i - 1]<<SPACE<<counter<<endl;
                counter = 1;
            }
        }
        cout<<arr[n - 1]<<SPACE<<counter<<endl;
    }

    return 0;
}

