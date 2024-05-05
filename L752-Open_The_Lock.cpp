#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<string> Q;
        Q.push("0000");
        visited.insert("0000");
        int moves = 0;
        
        while (!Q.empty()) {
            int size = Q.size();
            for (int i = 0; i < size; i++) {
                string current = Q.front();
                Q.pop();
                
                if (dead.count(current)) continue;
                if (current == target) return moves;
                
            for (int j = 0; j < 4; j++) {
                for (int k = -1; k <= 1; k += 2) {
                    char digit = current[j];
                    digit = (digit - '0' + k + 10) % 10 + '0';
                    string next = current;
                    next[j] = digit;
                        
                    if (!visited.count(next)) {
                            Q.push(next);
                            visited.insert(next);
                        }
                    }
                }
            }
        moves++;
        }
        return -1;
    }
};
