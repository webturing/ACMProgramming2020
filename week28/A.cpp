#include<cstdio>

int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    int n,m,k,f;
    while(scanf("%d%d%d",&n,&k,&m)==3&&n)
    {
        f=0;
        for(int i=2;i<=n;i++)f=(f+k)%i;
        f=(m-k+1+f)%n;
        if(f<=0)f+=n;
        printf("%d\n",f);
    }
}