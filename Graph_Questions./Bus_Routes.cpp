#include<bits/stdc++.h>
using namespace std;
#define nl '\n'
#define fs  first
#define sc  second


int main(){

    int buses, stops;
    cin>>buses>>stops;

        vector<vector<int>>v(buses+1, vector<int>(stops + 1, 0));
        // buses se stops ka pata
        for(int i = 1; i <= buses; ++i)
            for(int j = 1; j <= stops; ++j)
                cin >> v[i][j];
        

    int src, dest;
    cin >> src >> dest;// stops enter

    // stops se busses ka pata, jo jo bus us stop se pass ho rhi hai
    map<int, vector<int>>m;

    for(auto i = 1; i <= buses; ++i)
    {
        for(int j = 1; j <= stops; ++j)
        {
            m[v[i][j]].push_back(i);
        }
    }

    set <int> bus_stops, buses_taken;

    queue <int> q;
    q.push(src);

    bus_stops.insert(src);

    int min_buses = 0;


    function <void()> bfs;  
    bfs = [&]()
    {
        while(q.size())
        {
            int size = q.size();

            while(size--)
            {
                int front = q.front();
                q.pop();

                if(front == dest)
                {
                    bus_stops.insert(dest);
                    return;
                }

                vector <int> busess = m[front];

                for(auto bus : busess)
                {
                    if(buses_taken.count(bus))
                        continue;

                    for(int i = 1; i <= stops; ++i)
                    {
                        if(bus_stops.count(v[bus][i]))
                            continue;

                        q.push(v[bus][i]);
                        bus_stops.insert(v[bus][i]);
                    }

                    buses_taken.insert(bus);
                }
            }
            
            min_buses++;
        }
    };

    bfs();

    if(bus_stops.count(dest))
        cout << min_buses << nl;

    else
        cout << -1 << nl;

}
