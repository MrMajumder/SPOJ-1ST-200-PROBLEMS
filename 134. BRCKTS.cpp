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

struct Node{
    int pairs, left, right;
    Node()
    {
        pairs = left = right = 0;
    }
}sgt[60000];

string s;

Node mergeNode(Node l, Node r)
{
    Node parentNode;
    int minpair = min(l.left, r.right);
    parentNode.pairs = l.pairs + r.pairs + minpair;
    parentNode.left = l.left + r.left - minpair;
    parentNode.right = l.right + r.right - minpair;
    return parentNode;
}

void build(int node, int start, int fin)
{
    if(start == fin)
    {
        //sgt[node] = getnode();
        sgt[node].pairs = 0;
        sgt[node].left = (s[start] == '(') ? 1 : 0;
        sgt[node].right = (s[start] == ')') ? 1 : 0;
    }
    else
    {
        int mid = start + ((fin - start) / 2);
        build(node << 1, start, mid);
        build(node << 1 | 1, mid + 1, fin);
        sgt[node] = mergeNode(sgt[node << 1], sgt[node << 1 | 1]);
    }
}

void update(int node, int start, int fin, int pos)
{
    if(start == fin)
    {
        if(sgt[node].left)
        {
            sgt[node].left = 0;
            sgt[node].right = 1;
            s[pos] = ')';
        }
        else
        {
            sgt[node].left = 1;
            sgt[node].right = 0;
            s[pos] = '(';
        }
    }
    else
    {
        int mid = start + ((fin - start) / 2);
        if(pos <= mid) update(node << 1, start, mid, pos);
        else update(node << 1 | 1, mid + 1, fin, pos);
        sgt[node] = mergeNode(sgt[node << 1], sgt[node << 1 | 1]);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 10;
    while(t--)
    {
        int n;
        cin>>n;
        cin>>s;
        build(1, 0, n - 1);
        int q;
        cin>>q;
        cout<<"Test "<<10 - t<<":"<<endl;
        while(q--)
        {
            int mode;
            cin>>mode;
            for(int i = 0; i < 2 * n; i++)
            {
                cout<<sgt[i].pairs<<" "<<sgt[i].left<<" "<<sgt[i].right<<endl;
            }
            if(mode == 0)
            {
                if(sgt[1].left == 0 && sgt[1].right == 0) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
            else
            {
                update(1, 0, n - 1, mode);
            }
        }
    }

    return 0;
}

