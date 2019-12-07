// https://leetcode.com/explore/interview/card/google/59/array-and-strings/436/
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    bool eof;
    int start;
    int end;
    char *buf;
    Solution(): eof{false}, start{0}, end{0}{
        buf = new char[4];
    }
    bool read_external(char* buf, int& i, int n){
        end = read4(this->buf);
        start = 0;
        copyto(buf, i, n);
        if(end < 4) eof = true;
        return eof;
    }

    void copyto(char* buf, int& i, int n){
        while(i < n && start < end){
            buf[i++] = this->buf[start++]; 
        }
    }

    int read(char *buf, int n) {
        int i = 0;
        if(end-start >= n){
            copyto(buf, i, n);
            return i;
        }
        
        int total_bytes = 0;
        copyto(buf, i, n);
        while(i < n){
            if(read_external(buf, i, n))
                break;
        }
        return i;
    }
};