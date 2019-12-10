class Solution {
    class TrieNode{
        vector<TrieNode*> children(26, nullptr);
        set<int> words;
    };
    class Trie{
        TrieNode *root;
        Trie(): root{new TrieNode}{}
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
                    return set<int>()
            }
            return temp->words;
        }
    };

public:
    void all_square(vector<string>&words, int size, int index, int len, vector<string>& square, vector<vector<string>>& result){       
        if(index == len){
            result.push_back(square);
        }

        stringstream ss;
        for(auto& s: square){
            ss << s[index];
        }
        string prefix = ss.str();
        set<int> iwords = get_word_for_prefix(prefix);
        for(int i : iwords){
            if(!visited[i]){
                visited[i] = true;
                copy(words[i].begin(), words[i].end(), square[index]);
                all_square(words, size, index+1, len, square, result);
                visited[i] = false;
            }
        }
    }

    vector<vector<string>> wordSquares(vector<string>& words) {
        if(!words.size())
            return vector<vector<string>>();
        
        int word_len = words[0].size();
        int dict_size = words.size();

        Trie trie;
        for(auto& word: words){
            trie.add(word);
        }
        vector<vector<char>> square(words_len, vector<char>(word_len));
        vector<int> visited(dict_size, false);
        vector<vector<string>> result;
        all_square(words, size, 0, word_len, square, result);
        return result;        
    }
};