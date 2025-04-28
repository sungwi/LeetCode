#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    private:
        int M, N;
        vector<vector<bool>> seen;
        static constexpr int dx[4] = {0, 1, 0, -1};
        static constexpr int dy[4] = {1, 0, -1, 0};

    public:
        int dfs(const vector<vector<int>>& grid, int x, int y) {
            seen[x][y] = true;
            int area = 1;
            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (newX < 0 || newX >= M || newY < 0 || newY >= N) continue;
                if (grid[newX][newY] == 0) continue;
                if (seen[newX][newY]) continue;
                area += dfs(grid, newX, newY);
            }
            return area;
        }
        
        int maxAreaOfIsland(vector<vector<int>>& grid) {
            M = grid.size();
            N = grid[0].size();
            seen = vector<vector<bool>>(M, vector<bool>(N, false));

            int maxArea = 0;
            for (int x = 0; x < M; x++) {
                for (int y = 0; y < N; y++) {
                    if (grid[x][y] == 1 && !seen[x][y]) {
                        maxArea = max(dfs(grid, x, y), maxArea);
                    }
                }
            }
            return maxArea;
        }
    };