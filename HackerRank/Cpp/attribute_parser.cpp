#include <bits/stdc++.h>
using namespace std;

/* Sample Input
    <tag1 value = "HelloWorld">
    <tag2 name = "Name1">
    </tag2>
    </tag1>
*/

int main(){
    int n, m;
    cin >> n >> m; cin.ignore(); // cin leavs \n
    map<string, string> attributes;
    string line, word, attribute, value;
    string path = "";
    while(n--){
        getline(cin, line);
        stringstream ss(line);

        while(getline(ss, word, ' ')){
            if(word[0] == '<'){
                if(word[1] == '/'){     //terminating tag
                    string tag = word.substr(2);
                    tag.erase(remove_if(tag.begin(), tag.end(), [](char ch){ return ch == '>';}), tag.end());
                    path = path.substr(0, path.length()-tag.length()-1);        // 1 for '.'
                }
                else{    //openinng tag
                    string tag = word.substr(1);
                    tag.erase(remove_if(tag.begin(), tag.end(), [](char ch){ return ch == '>';}), tag.end());
                    if(path == "")
                        path = tag;
                    else
                        path = path + "." + tag;
                }
            }
            else{
                attribute = word;
                getline(ss, value, ' ');
                getline(ss, value, ' ');
                value.erase(remove_if(value.begin(), value.end(), [](char ch){ return (ch == '"' || ch == '>');}), value.end());
                attributes[path + "~" + word] = value;
            }
        }
    }
    string query;
    while(m--){
        cin >> query;
        if(attributes.find(query) != attributes.end())
            cout << attributes[query] <<endl;
        else
            cout << "Not Found!" << endl;
    }

}
