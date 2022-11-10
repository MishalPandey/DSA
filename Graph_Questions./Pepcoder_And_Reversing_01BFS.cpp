#include<bits/stdc++.h>
using namespace std;
#define nl '\n'

class Edge {
public:
  int src;
  int nbr;
  int wt;

  Edge(int src, int nbr, int wt) {
    this->src = src;
    this->nbr = nbr;
    this->wt = wt;
  }
};

// 0-1 BFS


int main(){
    int n;
  cin >> n;
  vector<Edge>graph[n+1];

  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int v1 ;
    int v2 ;
    cin >> v1 >> v2;
    graph[v1].push_back( Edge(v1, v2, 0));
    graph[v2].push_back( Edge(v2, v1, 1));
  }
   vector<bool>vis(n+1, false);



   deque<pair<int, int>> q;

   q.push_back({1, 0});

    while(q.size())
    {
            pair<int, int>p= q.front();
            q.pop_front();

            vis[p.first] = true;

            if(p.first == n)
            {
                    cout<<p.second<<nl;
                    return 0;

            }

            for(Edge edge: graph[p.first])
            {
                    if(vis[edge.nbr]==false)
                    {
                        if(edge.wt == 0)
                            q.push_front({edge.nbr, p.second+ 0});
                        else
                            q.push_back({edge.nbr, p.second + 1});

                    }
            }
    }

    cout<<"-1"<<nl;


    

}
