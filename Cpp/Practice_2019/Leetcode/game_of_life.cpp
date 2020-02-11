// https://leetcode.com/problems/game-of-life/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int nR = board.size();
        if(!nR)
        	return;
        int nC = board[0].size();
        vector<int> d = {0, 1, -1};
        for(int r = 0; r < nR; r++){
        	for(int c = 0; c < nC; c++){
        		int neighbors = 0;
        		for(auto dr: d){
        			for(auto dc: d){
        				if(!(dr == 0 && dc == 0) && r+dr >= 0 && r+dr < nR && c+dc >= 0 && c+dc < nC){
        					if(board[r+dr][c+dc] == -1 || board[r+dr][c+dc] == 1)
        						neighbors++;
        				}
        			}
        		}
        		if(board[r][c] == 1 && (neighbors > 3 || neighbors < 2))
        			board[r][c] = -1;
        		else if(board[r][c] == 0 && neighbors == 3)
        			board[r][c] = 2;
        	}
        }

        for(int r = 0; r < nR; r++){
        	for(int c = 0; c < nC; c++){
        		if(board[r][c] <= 0)
        			board[r][c] = 0;
        		else
        			board[r][c] = 1;
        	}
        }
    }
};