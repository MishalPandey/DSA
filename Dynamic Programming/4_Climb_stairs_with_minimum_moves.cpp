#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define ll long long
const int M= 998244353;
 


int main()
{

	  ios_base::sync_with_stdio(false);
	  cin.tie(NULL); cout.tie(NULL);

	  int n; cin>>n;
	  int jumps[n];

	  for (int i = 0; i < n; ++i)
	  {

	  		cin>>jumps[i];
	  }

	  int dp[n + 1];
	  memset(dp , -1 , sizeof(dp)); //for initialisize 0 and -1 value to all array element
	  dp[n] = 0;


		  
	    for (int i = n-1; i >= 0; --i)
	    {
	        
	           if(jumps[i] > 0)
	           {
	           		int min_steps = INT_MAX;
	           		for (int j = 1; j <= jumps[i] && i + j < n + 1; ++j)
	           		{
	           			if(dp[i+j] != -1)
	           			{
	           				min_steps= min(min_steps, dp[i+j]);
	           			}
	           		}

	           		if(min_steps != INT_MAX)
	           		{
	           			dp[i] = min_steps + 1;

	           		}

	           }
	           
	    }

	    cout<<dp[0]<<nl;
	  





}
      
