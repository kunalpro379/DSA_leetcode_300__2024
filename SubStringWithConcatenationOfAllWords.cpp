#include<iostream>
#include<vector>

using namespace std;
// class Solution {
// public:

//     // vector<int> findSubstring(string s, vector<string>& words) {
//     //    //Input: s = "barfoothefoobarman", words = ["foo","bar"]
//     //    int len = words[0].length();
//     //    int noOfWords = words.size();
//     //    vector<int> result;
//     //    unordered_map<string, int> wordMap;

//     //    if (len * noOfWords > s.length())
//     //        return result;

//     //    for (string word : words) {
//     //        wordMap[word]++;
//     //    }

//     //    for (int i = 0; i <= s.length() - (noOfWords * len); i++) {
//     //        unordered_map<string, int> map2;

//     //        for (int innerWindow = 0; innerWindow < noOfWords * len; innerWindow += len) {
//     //            string curr = s.substr(i + innerWindow, len);
//     //            if (wordMap.find(curr) == wordMap.end())
//     //                break;
//     //            map2[curr]++;    

//     //            if (map2[curr] > wordMap[curr])   
//     //                break;                                                                             
//     //        }
//     //        if (map2 == wordMap) {
//     //            result.push_back(i);
//     //        }
//     //    }
//     //    return result;
//     // }





//     vector<int> findSubstring(string s, vector<string>& words) {
//         vector<int> result;
//         if (words.empty() || s.empty()) return result;

//         int len = words[0].length();
//         int noOfWords = words.size();
//         int totalLen = len * noOfWords;

//         unordered_map<string, int> wordFreqMap;
//         for (const string& word : words) {
//             wordFreqMap[word]++;
//         }

//         for (int i = 0; i <= s.length() - totalLen; ++i) {
//             unordered_map<string, int> wordSeenMap;
//             int j = 0;
//             for (; j < noOfWords; ++j) {
//                 int startPos = i + j * len;
//                 string curr = s.substr(startPos, len);
//                 if (wordFreqMap.find(curr) == wordFreqMap.end()) break;
//                 wordSeenMap[curr]++;
//                 if (wordSeenMap[curr] > wordFreqMap[curr]) break;
//             }
//             if (j == noOfWords) result.push_back(i);
//         }

//         return result;
//     }
// };
class Solution {
public:
vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> result;
    unordered_map<string, int> wordFreq;

    // Count the frequency of each word
    for (const string& word : words)
        wordFreq[word]++;

    int wordLength = words[0].length();
    int totalLength = wordLength * words.size();

    if (totalLength > s.length())
        return result;

    for (int i = 0; i <= s.length() - totalLength; i++) {
        unordered_map<string, int> currentWordFreq = wordFreq;
        int count = 0;

        for (int j = i; j < i + totalLength; j += wordLength) {
            string word = s.substr(j, wordLength);

            if (currentWordFreq.find(word) == wordFreq.end() && currentWordFreq[word] > 0) {
                count++;
                currentWordFreq[word]--;
            } else {
                break;
            }
        }

        if (count == words.size()) {
            result.push_back(i);
        }
    }

    return result;
}


//    vector<int> findSubstring(string s, vector<string>& words) {
//     vector<int> result;
//     if (words.empty() || s.empty()) return result;

//     int len = words[0].length();
//     int noOfWords = words.size();
//     int totalLen = len * noOfWords;
//     if (totalLen > s.length()) // Check if total length of all words exceeds length of s
//         return result;

//     unordered_map<string, int> wordFreqMap;
//     for (const string& word : words) {
//         wordFreqMap[word]++;
//     }

//     for (int i = 0; i <= s.length() - totalLen; ++i) {
//         unordered_map<string, int> currWordFreqMap;
//         int j = 0;
//         for (; j < totalLen; j += len) {
//             string word = s.substr(i + j, len);
//             if (wordFreqMap.find(word) == wordFreqMap.end()) break;
//             currWordFreqMap[word]++;
//             if (currWordFreqMap[word] > wordFreqMap[word]) break;
//         }
//         if (j == totalLen && currWordFreqMap == wordFreqMap) result.push_back(i);
//     }

//     return result;
// }



};