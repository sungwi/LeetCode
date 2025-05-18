#include <vector>

using namespace std;
using Graph = vector<vector<int>>;

class Solution {
    public:
        void dfs(const Graph &G, int i, vector<bool> &seen) {
            seen[i] = true;
            for (int j: G[i]) {
                if (!seen[j]) {
                    seen[j] = true;
                    dfs(G, j, seen);
                }
            }
        }

        int countComponents(int n, vector<vector<int>>& edges) {
            // create graph based on the given edges
            Graph G(n);
            for (auto edge: edges) {
                int a = edge[0];
                int b = edge[1];
                G[a].push_back(b);
                G[b].push_back(a);
            }
            
            vector<bool> seen(n, false);
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (!seen[i]) {
                    dfs(G, i, seen);
                    count++;
                }
            }
            return count;
        }
    };