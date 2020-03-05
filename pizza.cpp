#include <bits/stdc++.h>
#include<fstream>
using namespace std;

vector<int> sum_p(int m,int n,vector<int> s){
    vector<int> curr;
    vector<int> sol;
    int sum=-1;
    int c=0;
   
    for(int i=n-1;i>=0;i--){
        curr.clear();
        c=s[i];
        curr.push_back(i);
        if(c>m) continue;
        if(c==m) {
            sol=curr;
            curr.clear();
            return sol;
                 }
       
        for(int j=n-1;j>=0 && i!=j;j--){
            c+=s[j];
           
            if(c>m){
                c-=s[j];
                continue;
                   }
            curr.push_back(j);
            if(c==m){
                sol=curr;
                curr.clear();
                return sol;
                   }
        }
     if(c>sum){
         sum=c;
         sol=curr;
         curr.clear();
        }
       
    }
   
    return sol;
}


void printsol(vector<int> sol){
    sort(sol.begin(),sol.end());
   ofstream ans;
   ans.open("E_also_big.out");
    ans<<sol.size()<<endl;
    for(int i=0;i<sol.size();i++){
        ans<<sol[i]<<" ";
    }
    ans<<endl;
    ans.close();
    return;
}


int main()
{
 ifstream ex;
    int m,n;
    ex.open("e_also_big.in");
	ex>>m>>n;
       vector<int> sl;
	for(int i=0;i<n;i++)
	{
	int a;
	ex>>a;
	sl.push_back(a);
	}
	
    ex.close();
   vector<int> sol;
    sol= sum_p(m,n,sl);
    printsol(sol);
    
   return 0;
}

