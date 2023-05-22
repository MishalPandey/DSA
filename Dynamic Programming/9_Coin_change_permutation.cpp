
#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define ll long long
const int M= 998244353;
 


int main()
{

	  ios_base::sync_with_stdio(false);
	  cin.tie(NULL); cout.tie(NULL);

	  int n, tar; cin>>n>>tar;
	  int coins[n];

	  for (int i = 0; i < n; ++i)
	  {

		  	
		  		cin>>coins[i];
	  		
	  }

	  int dp[tar+1];
	  memset(dp , 0 , sizeof(dp)); //for initialisize 0 and -1 value to all array element
	  dp[0] = 1;

		  
	    
	    for(int amt= 1; amt<= tar; amt++)
	    {
	    	for (int coin: coins )
	    	{
	    		if(coin <= amt)
	    		{
	    			int r_amt = amt - coin;
	    			dp[amt ] +=dp[r_amt];

	    		}
	    
			           	
			    
			           			
	        }
	           
	    }
	    

	    cout<<dp[tar]<<nl;
	  





}
      
