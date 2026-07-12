class Solution {
    unordered_map<string, vector<string>> adjList;
    vector<vector<string>> ans;
    vector<string> currentPath;
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return ans;

        dict.erase(beginWord);
        queue<string> q;
        q.push(beginWord);
        bool found = false;

        // Phase 1: BFS to build the adjacency list BACKWARDS
        while(!q.empty()) {
            int sz = q.size();
            unordered_set<string> visitedThisLevel;

            for(int i = 0; i < sz; i++) {
                string curr = q.front();
                q.pop();
                if(curr == endWord) {
                    found = true; // Stop immediately upon finding it
                    break;
                }
                string parent = curr;
                for(int j = 0; j < curr.size(); j++) {
                    char originalChar = curr[j];
                    for(char c = 'a'; c <= 'z'; c++) {
                        curr[j] = c;
                        if(dict.count(curr)){
                            visitedThisLevel.insert(curr);
                            // OPTIMIZATION: Build the graph mapping CHILD -> PARENT
                            adjList[curr].push_back(parent); 
                        }
                    }
                    curr[j] = originalChar; // backtrack the character
                }
            }
            
            // Erase visited words and push into the queue
            for(const string& word : visitedThisLevel) {
                dict.erase(word);
                q.push(word);
            }
            if(found) break; // Exit BFS safely without processing extra levels
        }

        // Phase 2: DFS backwards from endWord to beginWord
        if(found){
            currentPath.push_back(endWord); // Start at the end
            dfs(endWord, beginWord);
        }

        return ans;
    }

private:
    void dfs(const string& currWord, const string& beginWord) {
        if (currWord == beginWord) {
            // Because we built the path backwards, we must reverse it before saving
            vector<string> validPath = currentPath;
            reverse(validPath.begin(), validPath.end());
            ans.push_back(validPath);
            return;
        }

        // We only traverse valid parents, completely avoiding dead ends
        for (const string& prevWord : adjList[currWord]) {
            currentPath.push_back(prevWord);
            dfs(prevWord, beginWord);
            currentPath.pop_back(); // Backtrack
        }
    }
};