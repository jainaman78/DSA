#include<bits/stdc++.h>
using namespace std;

vector<int> primeNumbersTillN(int N) 
{ 
	vector<int>ans;
	vector<bool>bol(N+1,true);
	bol[0]=false;
	bol[1]=false;
 	for(int i=2;i*i<=N;i++){
		 for(int j=2*i;j<=N;j+=i){
			 bol[j]=false;
		 }
	 }
	 for(int i=2;i<=N;i++){
		 if(bol[i]==true){
			 ans.push_back(i);
		 }
	 }
	 return ans;
}