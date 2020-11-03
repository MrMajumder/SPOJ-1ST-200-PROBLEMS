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

vector<int> magic;
void precalc(int n = 2700)
{
    vector<bool> isPrime(n, true);
    vector<int> factorCount(n, 0);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i < n; i++) if(isPrime[i]) for(int j = i * 2; j < n; j += i)
    {
        factorCount[j]++;
        isPrime[j] = false;
    }

    for(int i = 2; i < n; i++) if(factorCount[i] >= 3) magic.push_back(i);
    //cout<<magic.size()<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precalc();
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<magic[n - 1]<<endl;
    }

    return 0;
}

