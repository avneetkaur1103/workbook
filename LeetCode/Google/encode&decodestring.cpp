// https://leetcode.com/problems/encode-and-decode-strings/
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string result = "";
        for(auto str: strs){
            int len = str.size();
            result += to_string(len) + "|" + str;
        }
        return result;
    }
    int getlen(string s, int& pos){ // ex 5|Apple4|Bear4|Home
        int right = s.find('|', pos);
        if(right == string::npos)
            return -1;
        int len = stoi(s.substr(pos,right-pos));
        pos = right+1;
        return len;
    }
        
    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int pos = 0; int n = s.length();
        
        vector<string> result;
        while(pos < n){
            int len = getlen(s, pos);
            if(len == -1)
                return result;
            string nextword = s.substr(pos, len);
            pos += len;
            result.push_back(nextword);
        }
        return result;        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));