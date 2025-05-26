#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string, vector<string>> mp;

            for (const auto& str: strs) {
                // string -> as char vector to be sorted
                string sorted_str = str;
                sort(sorted_str.begin(), sorted_str.end());

                // sorted string is the key of map
                // value is original str in strs
                mp[sorted_str].push_back(str);
            }

            // convert mp to 2D vector
            vector<vector<string>> rs;
            for (const auto& pair: mp) {
                rs.push_back(pair.second);
            }
            return rs;
        }
    };