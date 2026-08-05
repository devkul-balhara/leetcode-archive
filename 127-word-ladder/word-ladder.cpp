class Solution {
public:
    // Function to calculate the shortest transformation sequence length
    int ladderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Queue for BFS storing current word
        queue<string> q;
        q.push(startWord);
        // Set for quick lookup and deletion
        unordered_set<string> dict(wordList.begin(), wordList.end());
        dict.erase(startWord);
        int steps = 1;
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                string curr = q.front();
                q.pop();
                if(curr == targetWord) return steps;
                for(int j = 0; j < curr.size(); j++) {
                    char originalChar = curr[j];
                    for(char c = 'a'; c <= 'z'; c++) {
                        curr[j] = c;
                        if(dict.count(curr)){
                            q.push(curr);
                            dict.erase(curr);
                        }
                    }
                    curr[j] = originalChar; // backtrack the character
                }
            }
            steps++;
        }
        // If no sequence exists
        return 0;
    }
};

// Note:
// In Word Ladder I (minimum length), we can remove a word from the dictionary
// as soon as it is discovered because we only care about the shortest distance.

// In Word Ladder II (all shortest sequences), we cannot remove it immediately.
// Another node in the same BFS level may also reach this word, forming another
// shortest path. Therefore, we collect all words visited in the current level
// and remove them only after the entire level is processed.

// We do not keep them for future levels because any path reaching the same word
// from a deeper level would be longer and cannot be part of a shortest sequence.