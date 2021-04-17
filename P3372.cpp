#if 0
#include <iostream>
using namespace std;

using namespace std;
long long n,m,tree[100005],tree1[100005];//题目要求longlong
inline void add(long long*z,long long x,long long num)
{
    while(x<=n)
    {
        z[x]+=num;
        x+=x&(-x);
    }
}
inline long long getsum(long long*z,long long x)
{
    long long sum=0;
    while(x>0)
    {
        sum+=z[x];
        x-=x&(-x);
    }
    return sum;
}
int main()
{
    cin.sync_with_stdio(false);
    cin>>n>>m;
    long long a,b=0;
    for(long long i=1;i<=n;i++)
    {
        cin>>a;
        b=a-b;
        add(tree,i,b);
        add(tree1,i,(i-1)*b);
        b=a;
    }
    for(long long i=1;i<=m;i++)
    {
        int t,x,y,z;
        cin>>t;
        if (t==1)
        {
            cin>>x>>y>>z;
            add(tree,x,z);
            add(tree,y+1,-z);
            add(tree1,x,z*(x-1));
            add(tree1,y+1,-z*y);//此处为核心，联系上方的公式，想一想为什么这么修改。
        }
        else
        {
            cin>>x>>y;
            cout<<(y*getsum(tree,y)-(x-1)*getsum(tree,x-1))-(getsum(tree1,y)-getsum(tree1,x-1))<<endl;
        }
    }
    return 0;
} 

#endif