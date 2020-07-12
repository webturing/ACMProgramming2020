#include <iostream>
#include <cstring>
#include <cstdlib>
#include <set>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#define LL long long
#define LLU unsigned long long
using namespace std;
double log_C[50005],a[50005];
int main()
{
    int n,T;
    scanf("%d",&T);
    for (int kcase=1;kcase<=T;++kcase)
    {
        scanf("%d",&n);
        for (int i=0;i<n;++i)
            scanf("%lf",&a[i]);
        log_C[0]=log10(1);
        for (int i=1;i<n;++i)
            log_C[i]=log_C[i-1]+log10(n-i)-log10(i);//,printf("%lf %lf\n",log_C[i],pow(10,log_C[i]));
        double ans=0.0;
        for (int i=0;i<n;++i)
            if (a[i]<0)
                ans-=pow(10,log_C[i]+log10(-a[i])-log10(2)*(n-1));
            else
                ans+=pow(10,log_C[i]+log10(a[i])-log10(2)*(n-1));
        printf("Case #%d: %.3lf\n",kcase,ans);
    }
    return 0;
}