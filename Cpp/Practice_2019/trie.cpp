// implement trie with insert, search & delete

#include <bits/stdc++.h>
using namespace std;

class Trie{
    class Trie_Node{
        public:
            bool is_end_of_word;
            Trie_Node* children[26];
    };
    public:
        Trie_Node* root;

        Trie(): root{new Trie_Node()}{}

        void insert(string& str){
            Trie_Node* temp = root;
            for(auto s: str){
                if(!temp->children[s - 'a'])
                    temp->children[s - 'a'] = new Trie_Node();
                temp = temp->children[s - 'a'];
            }
            temp->is_end_of_word = true;
        }

        bool search(string& str){
            Trie_Node* temp = root;
            for(auto s: str){
                if(!temp->children[s - 'a'])
                    return false;
                temp = temp->children[s - 'a'];
            }
            return temp && temp->is_end_of_word;
        }

        Trie_Node* get_prefix_end(Trie_Node* root, string str){
            Trie_Node* temp = root;
                for(auto s: str){
                    if(!temp->children[s - 'a'])
                        return nullptr;
                    temp = temp->children[s - 'a'];
                }
                return temp;
        }

        void prefixes(string str){
            Trie_Node* end = get_prefix_end(root, str);
            print(end, str, "");
        }

        void remove(string& str){
            root = remove(root, str, 0);
        }

        void print(){
            print(root, "", "");
        }

    protected:
        void print(Trie_Node* root, string prefix, string str){
            if(root && root-> is_end_of_word)
                cout << prefix << str << endl;
            for(int i = 0; i < 26; i++){
                if(root->children[i])
                    print(root->children[i], prefix, str+(char)(i+'a'));
            }
        }
        
        Trie_Node* remove(Trie_Node* root, string& str, int index){
            if(!root)
                return root;
            if(index == str.size()){
                if(root->is_end_of_word)
                    root-> is_end_of_word = false;
                if (all_of(&root->children[0], &root->children[0]+26, [](auto x){return !x;})){
                    delete root;
                    root = nullptr;
                }
                return root;
            }
            root->children[str[index]-'a'] = remove(root->children[str[index]-'a'], str, index+1);

            if( !root->is_end_of_word && all_of(&root->children[0], &root->children[0]+26, [](auto x){return !x;})){
                delete root;
                root = nullptr;
            }
            return root;
        }
};

int main(){
    string words[] = { "the", "a", "there",
                      "answer", "any", "by",
                      "bye", "their", "hero", "heroplane" };
    Trie trie;
    for(auto word: words)
        trie.insert(word);

    cout << "All Keys in the Trie " << endl;
    trie.print();
    cout << "Words for prefix: th " << endl;
    trie.prefixes("th");

    cout << "Is key: " << words[0] << " in trie " << trie.search(words[0]) << endl;
    trie.remove(words[0]);
    cout << "Is key: " << words[0] << " in trie " << trie.search(words[0]);
    cout << "Keys after deletion" << endl;
    trie.print();


}
