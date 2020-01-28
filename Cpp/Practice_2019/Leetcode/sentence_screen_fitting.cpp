// https://leetcode.com/problems/sentence-screen-fitting/
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n = sentence.size();
        vector<int> next(n, -1);
        vector<int> total(n, 0);
        int start = 0, totalcount = 0;
        for(int i = 0; i < rows; i++){
            if(next[start] == -1){
                int j = start, count = 0, col = cols;
                while(col > 0 && col >= sentence[j].size()){
                    //cout << "word: " << sentence[j] << " row " << i << " col " << col << endl; 
                    col -= sentence[j].size()+1;
                    j = (j+1)%n;
                    if(j == 0) count++;
                }
                next[start] = j;
                total[start] = count;
                start = j;
                totalcount += count;
            }
            else{
                totalcount += total[start];
                start = next[start];
            }
        }
        return totalcount;
    }
};
