// https://www.geeksforgeeks.org/minimum-positive-points-to-reach-destination/
#include <bits/stdc++.h>
using namespace std;

int minInitialPoints(vector<vector<int>>& points){
	int nR = points.size();
	int nC = points[0].size();
	vector<vector<int>> dp(nR, vector<int>(nC));
	dp[nR-1][nC-1] = max(1-points[nR-1][nC-1], 1);
	for(int i = nR-1; i >= 0; i--){
		for(int j = nC-1; j >= 0; j--){
			if(i == nR-1 && j == nC-1)
				continue;
			else if(i == nR-1)
				dp[i][j] = max(points[i][j] - dp[i][j+1], 1);
			else if(j == nC-1)
				dp[i][j] = max(points[i][j] - dp[i+1][j], 1);
			else{
				int _min_next = min(dp[i+1][j], dp[i][j+1]);
				dp[i][j] = max(_min_next - points[i][j], 1);
			}
		}
	}
	return dp[0][0];
}

// Driver Program
int main()
{

    vector<vector<int>> points = { {-2,-3,3},
                      {-5,-10,1},
                      {10,30,-5}
                    };
    cout << "Minimum Initial Points Required: "
         << minInitialPoints(points);
    return 0;
}
