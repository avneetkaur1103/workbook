class Solution {
public:
    int skip[10][10] = {0};
    bool is_allowed(int prev, int next, vector<bool> visited){
        return visited[next]==false && (skip[prev][next] == 0 || visited[skip[prev][next]]);
    }
    int count_pattern(int n, vector<bool>& visited, int pos){
        if(n < 0) return 0;
        if(n == 0) return 1;
        visited[pos] = true;
        int count = 0;
        for(int i = 1; i < 10; i++){
            if(is_allowed(pos, i, visited)){
                count += count_pattern(n-1, visited, i);
            }
        }
        visited[pos] = false;
        return count;
    }
    int numberOfPatterns(int m, int n) {
        skip[1][3] = skip[3][1] = 2;
        skip[1][7] = skip[7][1] = 4;
        skip[3][9] = skip[9][3] = 6;
        skip[7][9] = skip[9][7] = 8;
        skip[1][9] = skip[9][1] = skip[2][8] = skip[8][2] = skip[3][7] = skip[7][3] = skip[4][6] = skip[6][4] = 5;
        vector<bool> visited(10, false);
        int result = 0;
        for(int i = m; i <=n; i++){
            result+= count_pattern(i-1, visited, 1)*4;
            result+= count_pattern(i-1, visited, 2)*4;
            result+= count_pattern(i-1, visited, 5);
        }
        return result;
    }
};