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

    int n, k;
    cin>>n;
    int arr[n];

    for(int i = 0; i < n; i++) cin>>arr[i];
    cin>>k;

    deque <int> q;
    for(int i = 0; i < k; i++)
    {
        while(!q.empty() && arr[q.back()] <= arr[i]) q.pop_back();
        q.push_back(i);
    }
    cout<<arr[q.front()]<<SPACE;
    for(int i = k; i < n; i++)
    {
        while(!q.empty() && q.front() <= (i - k)) q.pop_front();
        while(!q.empty() && arr[q.back()] <= arr[i]) q.pop_back();
        q.push_back(i);
        cout<<arr[q.front()]<<SPACE;
    }
    cout<<endl;

    return 0;
}

