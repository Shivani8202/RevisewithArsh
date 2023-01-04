#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<int> adj[n];
        //making adjacency matrix
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int> par(n), dist(n);
        queue<int> q;
        q.push(0);
        par[0] = -1;
        dist[0] = 0;
        //making parent array and computing distance of every node from 0 
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int node = q.front();q.pop();
                for(int child:adj[node]){
                    if(child == par[node]) continue;
                    q.push(child);
                    par[child] = node;
                    dist[child] = dist[node] + 1;
                }
            }
        }
        //bob's run toward node 0
        int ptr = bob;
        int d = 0;
        while(ptr){
            if(dist[ptr] > d) amount[ptr] = 0;
            else if(dist[ptr] == d) amount[ptr] /= 2;
            ptr = par[ptr];
            ++d;
        } 
        //now calculating maximum cost obtained by reaching any leaf node
        q.push(0);
        int res = -1e8;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int node = q.front();q.pop();
                bool f=false;
                for(int nbr:adj[node]){
                    if(nbr == par[node]) continue;
                    f=true;
                    amount[nbr] += amount[node];
                    q.push(nbr);
                }
                if(f==false) res=max(res,amount[node]);
            } 
        }
        return res;
    }
};
