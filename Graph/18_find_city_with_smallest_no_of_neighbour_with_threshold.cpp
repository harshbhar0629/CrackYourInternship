#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

#define pi pair<int, int>
class Solution
{
    // int cntCity, city;

    // void dijkstra(int src, vector<list<pi>>& graph, const int threshold, const int n){
    //     vector<int>dis(n, 1e8);
    //     dis[src] = 0;
    //     priority_queue<pi, vector<pi>, greater<pi>>pq;
    //     pq.push({0, src});

    //     while(!pq.empty()){
    //         auto [wt, node] = pq.top(); pq.pop();
    //         for(auto [neighbour, edgeWt]: graph[node]){
    //             if(dis[neighbour] > wt + edgeWt){
    //                 dis[neighbour] = wt + edgeWt;
    //                 pq.push({dis[neighbour], neighbour});
    //             }
    //         }
    //     }

    //     int total_city_under_threshold = 0;
    //     for(int i=0; i<n; i++){
    //         if(dis[i] <= threshold){
    //             total_city_under_threshold++;
    //         }
    //     }

    //     if(cntCity >= total_city_under_threshold){
    //         cntCity = total_city_under_threshold;
    //         city = max(city, src);
    //     }
    // }

public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {

        int cost[n][n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cost[i][j] = 1e9;
            }
            cost[i][i] = 0;
        }

        for (auto edge : edges)
        {
            cost[edge[0]][edge[1]] = edge[2];
            cost[edge[1]][edge[0]] = edge[2];
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (cost[i][k] != 1e9 and cost[k][j] != 1e9)
                    {
                        cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
                    }
                }
            }
        }

        int total_city = 1e8, city = 0;
        for (int i = 0; i < n; i++)
        {
            int cntCity = 0;
            for (int j = 0; j < n; j++)
            {
                if (cost[i][j] <= distanceThreshold)
                {
                    cntCity++;
                }
            }
            if (cntCity <= total_city)
            {
                total_city = cntCity;
                city = i;
            }
        }

        return city;

        // this->city = 0;
        // this->cntCity = 1e9;
        // vector<list<pi>>graph(n, list<pi>());
        // for(auto edge: edges){
        //     graph[edge[0]].push_back({edge[1], edge[2]});
        //     graph[edge[1]].push_back({edge[0], edge[2]});
        // }

        // for(int i=0; i<n; i++){
        //     dijkstra(i, graph, distanceThreshold, n);
        // }

        // return city;
    }
};

int main(){
    

    return 0;
}