#include<bits/stdc++.h>
#include<fstream>
using namespace std;

#define max2(a, b) (((a) > (b)) ? (a) : (b))
#define min2(a, b) (((a) > (b)) ? (b) : (a))
#define abs(a) (((a) > 0) ? (a) : (-(a)))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n = 1e8;
    int nsqrt = sqrt(n);

    vector<int> pos(n + 1, 0);
    vector<bool>isPrime(n + 1, true);

    isPrime[0] = isPrime[1] = false;
    pos[2] = 1;

    for(int i = 4; i <= n; i+=2)
    {
        isPrime[i] = false;
    }
    int counter = 1;

    for(int i = 3; i <= nsqrt; i+= 2)
    {
        if(isPrime[i])
        {
            pos[i] = ++counter;
            for(int j = i * i; j <= n; j += (i * 2))
            {
                isPrime[j] = 0;
            }
        }
    }
    for(int i = nsqrt + 1; i <= n; i++)
    {
        if(isPrime[i])
            pos[i] = ++counter;
    }

    fstream myfile;
    myfile.open("PosVal.txt");

    for(int i = 0; i <= n; i++)
    {
        cout<<i<<endl;
        myfile <<pos[i]<<", ";
    }
    myfile.close();



//    int t, num, place;
//    int row, col;
//    cin>>t;
//    while(t--)
//    {
//        cin>>num;
//
//        if(!isPrime[num])
//        {
//            cout<<"-1"<<endl;
//            continue;
//        }
//        place = pos[num];
//        row = (floor( sqrt( (8 * place) + 1 ) ) - 1) / 2;
//        col = place - ((row * (row + 1)) / 2);
//        if(col)
//        {
//            row++;
//        }
//        else
//        {
//            col = place - (((row - 1) * row) / 2);
//        }
//        cout<<row<<" "<<col<<endl;
//    }


    return 0;
}


