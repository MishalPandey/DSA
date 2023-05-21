#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define ll long long
const int M= 998244353;
 


int main()
{

	  ios_base::sync_with_stdio(false);
	  cin.tie(NULL); cout.tie(NULL);

	  int n, m; cin>>n>>m;
	  int array[n][m];

	  for (int i = 0; i < n; ++i)
	  {

		  	for(int j=0; j < m; j++)
		  	{
		  		cin>>array[i][j];

		  	}

	  		
	  }

	  int dp[n][m];
	  memset(dp , 0 , sizeof(dp)); //for initialisize 0 and -1 value to all array element

		  
	    
	    for(int j= m-1; j>= 0; j--)
	    {
	    	for (int i = 0; i < n; ++i)
	    	{
	    
			           	if(j== m-1)
		           		{
		           			dp[i][j]= array[i][j];
		           		}
		           		else if(i==0 && i+1<n)
		           		{
		           			dp[i][j]= max(dp[i][j+1], dp[i+1][j+1]) + array[i][j];
		           		}
		           		else if(i==n-1 && i>0)
		           		{
		           			dp[i][j]= max(dp[i][j+1], dp[i-1][j+1]) + array[i][j];
		           		

		           		}
		           		else{
		           			dp[i][j]= max(max(dp[i][j+1], dp[i-1][j+1]), dp[i+1][j+1]) + array[i][j];
		           		
		           		}

	           }
	           
	    }
	    int ans =INT_MIN;
	    for(int i= n-1; i>= 0; i--)
	    {
	    	ans = max(ans, dp[i][0]);
	    }



	    cout<<ans<<nl;
	  





}
      
