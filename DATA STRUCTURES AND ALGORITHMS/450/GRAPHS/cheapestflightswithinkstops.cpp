class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector <vector<pair<int,int>>> graph(n);
        int m = flights.size();
        for(auto i=0;i<m;i++){
            graph[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        priority_queue <tuple<int,int,int> ,vector <tuple<int,int,int>>,greater<tuple<int,int,int>> > pq;
        pq.push(make_tuple(0,src,-1));
        vector <int> dist(n,INT_MAX);
        while(!pq.empty()){
            auto [cost,u,stops] = pq.top();
            pq.pop();
            if(stops>k)
                continue;
            if(dist[u]<stops)
                continue;
            dist[u] = stops;
            if(u==dst){
                return cost;
            }
            int z = graph[u].size();
            for(auto i=0;i<z;i++){
                auto [v,w] = graph[u][i];
                pq.push(make_tuple(cost+w,v,stops+1));
            }
        }
        return -1;
    }
};