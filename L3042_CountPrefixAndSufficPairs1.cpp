#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    int countPrefixSuffixPairs(std::vector<std::string>& words) {
        int count = 0;
        std::unordered_map<std::string, int> suffixCount;

        for (const std::string& word : words) {
            int wordSize = word.size();
            for (int i = 1; i < wordSize; ++i) {
                std::string prefix = word.substr(0, i);
                std::string suffix = word.substr(wordSize - i); // Corrected substring extraction
                if (suffixCount.find(prefix) != suffixCount.end()) {
                    count += suffixCount[prefix];
                }
            }
            suffixCount[word]++;
        }

        return count;
    }
};
