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

vector <bool> isPrime(10000);
vector<bool> visited(10000);
vector<int> dist(10000);

void rangePrime(int a, int b)
{
    fill(isPrime.begin(), isPrime.end(), true);
    isPrime[0] = isPrime[1] = false;
    for(int p = 2; p * p <= b; p++)
    {
        int l = a / p;
        l *= p;
        for(int i = l; i <= b; i += p)
        {
           if(i >= a && i != p) isPrime[i] = false;
        }
    }
}

int bfs(int a, int b)
{
    fill(visited.begin(), visited.end(), false);
    fill(dist.begin(), dist.end(), -1);
    queue<int> q;
    q.push(a);
    dist[a] = 0;
    visited[a] = true;

    char num[8];
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        sprintf(num, "%d", u);
        for(int i = 0; i < 4; i++)
        {
            for(int j =  0; j <= 9; j++)
            {
                if(i == 0 && j == 0) continue;
                num[i] = j + '0';
                int temp = atoi(num);
                if(!visited[temp] && isPrime[temp] && temp != u)
                {
                    q.push(temp);
                    visited[temp] = true;
                    dist[temp] = dist[u] + 1;
                    if(temp == b) return dist[b];
                }
            }
            sprintf(num, "%d", u);
        }
    }
    return dist[b];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    rangePrime(1000, 10000);
    int t;
    cin>>t;
    while(t--)
    {
        int a, b;
        cin>>a>>b;
        if(a == b)
        {
            cout<<0<<endl;
            continue;
        }
        int ans = bfs(a, b);
        if(ans == -1) cout<<"Impossible"<<endl;
        else cout<<ans<<endl;
    }

    return 0;
}


