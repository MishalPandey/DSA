//Using Recursion

#include <iostream>
using namespace std;

int qb[10000000];

int FibMemoized(int n){
    if(n==0 || n==1){
        return n;
    }
    if(qb[n]!=0){
        return qb[n];
    }

    int fibnm1= FibMemoized(n-1);
    int fibnm2= FibMemoized(n-2);
    int fibn= fibnm1+ fibnm2;
    qb[n]= fibn;
    return fibn;

}

int main(){
    int n;
    cin>>n;
    cout<<FibMemoized(n)<<endl;
    return 0;
}

//Using Tabulation

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

int main()
{

	  ios_base::sync_with_stdio(false);
	  cin.tie(NULL); cout.tie(NULL);

	  int n; cin>>n;

	  int dp[n + 1];
	  dp[0] = 0, dp[1]= 1;

		  
        for (int i = 2; i <= n; ++i)
        {

                dp[i]= dp[i-1]+ dp[i-2];
            
        }
	  cout<<dp[n]<<nl;
	  





}
