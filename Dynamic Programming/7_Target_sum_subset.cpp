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
	  int array[n];

	  for (int i = 0; i < n; ++i)
	  {

		  	
		  		cin>>array[i];
	  		
	  }

	  int dp[n+1][tar+1];
	  memset(dp , 0 , sizeof(dp)); //for initialisize 0 and -1 value to all array element

		  
	    
	    for(int i= 0; i< n+1; i++)
	    {
	    	for (int j = 0; j < tar + 1; ++j)
	    	{
	    
			           	if(i==0 && j== 0)
		           		{
		           			dp[i][j]= true;
		           		}
		           		else if(i==0 )
		           		{
		           			dp[i][j]= false;
		           		}
		           		else if(j==0 )
		           		{
		           			dp[i][j]= true;
		           		}
		           		
		           		else{
		           			if(dp[i-1][j]== true) dp[i][j]= true;
			           		
			           		else 
			           		{
			           			int val = array[i-1];
			           			if(j>=val)
			           			{
			           				if(dp[i-1][j- val]== true) dp[i][j]= true;

			           			}

			           			
			           		}
		           		}

	           }
	           
	    }
	    

	    cout<<dp[n][tar]<<nl;
	  





}
      

