// https://leetcode.com/problems/rle-iterator/
#define all(c) c.begin() , c.end()
class RLEIterator {
public:
    vector<long> prefix;
    long flushed = 0;
    vector<int> nums;
    RLEIterator(vector<int>& A) {
        int n = A.size();
        prefix.resize(n/2);
        nums = A;
        for(int i = 0; i < n; i++){
            if(!(i&1)){    
                int j = i/2;
                prefix[j] = j > 0 ? prefix[j-1] + nums[i] : nums[i]+1;
            }
        }
    }
    
    int next(int n) {
       
        auto itr = upper_bound(all(prefix), n+flushed);
        flushed += n;
        if(itr == prefix.end())
            return -1;
        else{
            int index = itr - prefix.begin();
            return nums[index*2+1];
        }
        
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */