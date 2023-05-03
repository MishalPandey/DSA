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
	 
	    for (int i = n-1; i >= 0; --i)
	    {
	        
	           for(int j= m-1; j>= 0; j--)
	           {

			           	if(i+1>=n && j+1>= m)
		           		{
		           			  dp[i][j]= array[i][j];
		           		}
		           		else if(i+1>=n)
		           		{
		           			  dp[i][j]= dp[i][j+1] + array[i][j];
		           		}
		           		else if(j+1>=m)
		           		{
		           			  dp[i][j]= dp[i+1][j] + array[i][j];
		           		

		           		}
		           		else{
		           			  dp[i][j]= min(dp[i][j+1], dp[i+1][j] )+ array[i][j];
		           		
		           		}

	           }
	           
	    }

	    cout<<dp[0][0]<<nl;
	  





}
      
