// https://leetcode.com/explore/interview/card/google/62/recursion-4/370/

class Solution {
    class TrieNode{
        public:
        TrieNode* children[26];
        set<int> words;
    };
    class Trie{
        public:
        TrieNode *root;
        Trie(): root{new TrieNode()}{}
        void add(string& s, int index){
            TrieNode* temp = root;
            for(auto ch: s){
                if(temp->children[ch-'a'])
                    temp = temp->children[ch-'a'];
                else{
                    temp->children[ch-'a'] = new TrieNode();
                    temp = temp->children[ch-'a'];
                }
                temp->words.insert(index);
            }
        }
        set<int> get_word_for_prefix(string& prefix){
            TrieNode *temp = root;
            for(auto ch: prefix){
                if(temp->children[ch-'a'])
                    temp = temp->children[ch-'a'];
                else
                    return set<int>();
            }
            return temp->words;
        }
    };

public:
    void all_square(vector<string>&words, vector<int>& visited, int size, int index, int len, vector<string>& square, vector<vector<string>>& result, Trie& trie){
        if(index == len){
            result.push_back(square);
            return;
        }
        stringstream ss;
        for(int i = 0; i < index; i++){
            ss << square[i][index];
        }
        string prefix = ss.str();
        set<int> iwords = trie.get_word_for_prefix(prefix);
        for(int i : iwords){
            if(!visited[i]){
                //visited[i] = true;
                square[index] = words[i];
                all_square(words, visited, size, index+1, len, square, result, trie);
                //visited[i] = false;
            }
        }
    }

    vector<vector<string>> wordSquares(vector<string>& words) {
        if(!words.size())
            return vector<vector<string>>();

        int len = words[0].size();
        int n = words.size();

        Trie trie;
        for(int i = 0; i < n; i++){
            trie.add(words[i], i);
        }

        vector<string> square(len);
        vector<int> visited(n, false);
        vector<vector<string>> result;
        for(int i = 0; i<n; i++){
            //visited[i] = true;
            square[0] = words[i];
            all_square(words, visited, n, 1, len, square, result, trie);
            //visited[i] = false;
        }
        return result;
    }
};
int main(){
    vector<string> words = {"abat","baba","atan","atal"};
    Solution sol;
    auto result = sol.wordSquares(words);

    for(auto iresult: result){
        for(auto words: iresult)
            cout << words << endl;
        cout << "-------" << endl;
    }
}