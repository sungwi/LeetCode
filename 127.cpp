#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
    public:
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
            // edge case
            auto it = find(wordList.begin(), wordList.end(), wordList[wordList.size()-1]);
            if (it == wordList.end()) return 0;
    
            int len = beginWord.length();
            // Create combination map: d*g:dog, dig, dug...
            unordered_map<string, vector<string>> combo;
            for (string word: wordList) {
                for (int i = 0; i < len; i++) {
                    // form a generic form from the current word
                    string newWord = word.substr(0, i) + "*" + word.substr(i+1, len);
                    combo[newWord].push_back(word);
                }
            }

            // BFS prep
            // pair<word, level of search>
            queue<pair<string, int>> Q;
            Q.push(make_pair(beginWord, 1)); // initial componenet for BFS

            // visited map for each wor
            unordered_map<string, bool> visited;
            for (int i = 0; i < len; i++) visited[wordList[i]] = false;
            visited[beginWord] = true; // inital state for BFS

            // BFS in combo map
            while (!Q.empty()) {
                pair<string, int> node = Q.front();
                string currWord = node.first;
                int level = node.second;
                Q.pop();
                // iterate for all possible generic form
                for (int i = 0; i < len; i++) {
                    string generic = currWord.substr(0, i) + "*" + currWord.substr(i+1, len);
                    for (string word: combo[generic]) {
                        if (word == endWord) return level+1;
                        if (!visited[word]) {
                            visited[word] = true;
                            Q.push(make_pair(word, level+1));
                        }
                    }
                }
                
            }
            return 0;
        }
    };