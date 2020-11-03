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

    int t;
    cin>>t;
    int d;

    while(t--)
    {
        string s;
        cin>>d;
        cin>>s;

        int arr[8] = {0};

        for(int i = 0; i < 38; i++)
        {
            if(s[i] == 'T' && s[i + 1] == 'T' && s[i + 2] == 'T') arr[0]++;
            else if(s[i] == 'T' && s[i + 1] == 'T' && s[i + 2] == 'H') arr[1]++;
            else if(s[i] == 'T' && s[i + 1] == 'H' && s[i + 2] == 'T') arr[2]++;
            else if(s[i] == 'T' && s[i + 1] == 'H' && s[i + 2] == 'H') arr[3]++;
            else if(s[i] == 'H' && s[i + 1] == 'T' && s[i + 2] == 'T') arr[4]++;
            else if(s[i] == 'H' && s[i + 1] == 'T' && s[i + 2] == 'H') arr[5]++;
            else if(s[i] == 'H' && s[i + 1] == 'H' && s[i + 2] == 'T') arr[6]++;
            else if(s[i] == 'H' && s[i + 1] == 'H' && s[i + 2] == 'H') arr[7]++;
        }

        cout<<d<<SPACE;
        for(int i = 0; i < 8; i++)
        {
            cout<<arr[i]<<SPACE;
        }
        cout<<endl;
    }


    return 0;
}

