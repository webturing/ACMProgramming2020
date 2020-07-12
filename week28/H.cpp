#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>
using namespace std;
int main(){
    double a,b;
    while(cin>>a>>b){
        double y1,y2,y;
        y1=pow(b+1,1.5);
        y2=pow(a+1,1.5);
        y=y1-y2;
        y=y*2/3;
        printf("%.3lf\n",y);
    }
}