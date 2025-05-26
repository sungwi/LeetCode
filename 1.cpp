#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
    public:

        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> mp; // value -> idx
            for (int i = 0; i < nums.size(); i++) {
                int compliment = target - nums[i];
                if (mp.count(compliment)) {
                    return {mp[compliment], i};
                }
                mp[nums[i]] = i;
            }
            return {};
        }

        vector<int> twoSum_2(vector<int>& nums, int target) {
            // unordered_map <value, index-vector>: same values case possible
            unordered_map<int, vector<int>> mp;
            for (int i = 0; i < nums.size(); i++) {
                mp[nums[i]].push_back(i);
            }

            // solution
            int curr_idx = -1;
            for (const auto& pair: mp) {
                int curr_val = pair.first;
                int curr_idx = pair.second[0];

                int another_val = target - curr_val;
                if (mp.count(another_val)) {
                    int another_idx;
                    if (another_val == curr_val) {
                        for (const auto& n: mp[another_val]) {
                            if (curr_idx != n) another_idx = n;
                        }
                    }
                    else {
                        another_idx = mp[another_val][0];
                    }
                    vector<int> rs;
                    rs.push_back(another_idx);
                    rs.push_back(curr_idx);
                    return rs;
                }
            }
            return {};
        }
    };