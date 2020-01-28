// https://leetcode.com/problems/can-i-win/

class Solution {
public:
    bool canIWinUtil(int maxChoosableInteger, int desiredTotal, bitset<21> used, unordered_map<bitset<21>, bool>& iswin){
        if(iswin.find(used) != iswin.end())
            return iswin[used];
        
        bitset<21> temp = used;
        for(int i = maxChoosableInteger; i > 0; i--){
            if(!used[i]){
                temp[i] = 1;
                if(i >= desiredTotal || !canIWinUtil(maxChoosableInteger, desiredTotal-i, temp, iswin)){
                    iswin[used] = true;
                    return true;
                }
                temp[i] = 0;
            }
        }
        return iswin[used] = false;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        bitset<21> used;
        unordered_map<bitset<21>, bool> iswin;
        int sum = (maxChoosableInteger * (maxChoosableInteger+1))/2;

        if(desiredTotal > sum)
            return false;
        if(maxChoosableInteger >= desiredTotal)
            return true;
        return canIWinUtil(maxChoosableInteger, desiredTotal, used, iswin);
    }
};