//Using Recursion
#include <iostream>
using namespace std;
int qb[10000000];


int CountPaths(int n){
    if(n==0 )
    {
        return 1;
    }
    else if(n<0 )
    {
        return 0;
    }
    if(qb[n]!=0)
    {
        return qb[n];
    }

    int nm1= CountPaths(n-1);
    int nm2= CountPaths(n-2);
    int nm3= CountPaths(n-3);
    int cp= nm1+ nm2+ nm3;
    qb[n]= cp;
    return cp;

}
int main(){
    int n;
    cin>>n;
    cout<<CountPaths(n)<<endl;
}



//Using Tabulation
#include <iostream>
using namespace std;

int CountPathsTab(int n){
    int dp[n+1];
    dp[0]=1;

    for (int i = 1; i <= n; ++i)
    {
        if(i==1){
            dp[i]= dp[i-1];
        }
        else if(i==2){
            dp[i]= dp[i-1]+ dp[i-2];
        }
        else{
            dp[i]= dp[i-1]+ dp[i-2]+ dp[i-3];
        }
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    cout<<CountPathsTab(n)<<endl;
}
