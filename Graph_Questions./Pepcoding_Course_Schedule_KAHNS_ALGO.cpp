#include<bits/stdc++.h>
using namespace std;
#define nl '\n'


// Kahn's Algorithms


int main(){
    int n;
  cin >> n;
  vector<int>graph[n+1];

  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int x ;
    int y ;
    cin >> x >> y;
    graph[x].push_back( y);
  }
   vector<int> ordering;

   vector<int>indegree(n+1, 0);
   for (int i = 0; i < n; ++i)
   {
       for(auto child: graph[i])
            indegree[child]++;
   }

   queue<int>q;

   for (int i = 0; i < n; ++i)
   {
       if(indegree[i]== 0){
            q.push(i);
       }
   }

   int ct=0;
   while(q.size())
   {
        int ver = q.front();
        q.pop();

        ordering.push_back(ver);
        ct++;

        for(auto child : graph[ver])
        {
            indegree[child]--;

            if(indegree[child]==0)
                q.push(child);
        }
   }

   if(ct== n)
   {
        for(auto it: ordering)
            cout<<it<<" ";
        cout<<nl;

   }
   else{
    cout<<"-1"<<nl;
   }


    

}
