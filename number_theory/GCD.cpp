#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    return a%b==0? b:gcd(b,a%b);
}
int main(){
    int t;
    cin>>t;
    while(t>0){
        int x,y;
        cin>>x>>y;
        cout<<gcd(x,y)<<endl;
        t--;
    }
    return 0;
}
// solve(a,  b)
// {
//    if (a == 0)
//           return b;
//    if (b == 0)
//           return a;
//    if (a == b)
//           return a;
//    if (a > b)
//           return solve(a - b, b);
//    return solve(a, b - a);
//   }