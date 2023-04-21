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

	  int arr[n];
	  for (int i = 0; i < n; ++i)
	  {
	  		cin>>arr[i];
	  }

	  int dp[n + 1];
	  memset(dp ,0 , sizeof(dp)); //for initialisize 0 and -1 value to all array element
	  dp[n] = 1;

	  for (int i = n - 1; i >= 0; --i)
	  {
	  		for (int j = 1; j <= arr[i]  && i + j <= n; ++j)
	  		{
	  			dp[i] += dp[i + j];
	  		}
	  }

	  cout<<dp[0]<<nl;
	  





}
      
