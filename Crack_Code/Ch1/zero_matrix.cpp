// Cracking the coding interview Q - 1.8

#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;

void print(vector<vector<int>>& matrix){
	for(auto v: matrix){
		for(auto i: v){
			cout << i << " ";
		}
		cout << endl;
	}
	cout << string(10, '-') << endl;
}

void fill_zeros(vvi& matrix){
	int n = matrix.size();
	int m = n? matrix[0].size(): 0;
	if(!n || !m){
		cout << "Debug: Empty";
		return;
	}
	bool first_row_has_zero = false;
	first_row_has_zero = find(matrix[0].begin(), matrix[0].end(), 0) != matrix[0].end();
	for(int i = 1; i < n; i++){
        bool clear_row = false;
		for(int j = 0; j < m; j++){
			if(!matrix[i][j]){
				matrix[0][j] = 0;
				clear_row = true;
			}
		}
		if(clear_row)
			fill(matrix[i].begin(), matrix[i].end(), 0);
	}
	print(matrix);

	for(int j = 0; j < m; j++){
		if(!matrix[0][j])
			for(int i = 0; i < n; i++){
				matrix[i][j] = 0;
			}
	}
	if(first_row_has_zero)
        fill(matrix[0].begin(), matrix[0].end(), 0);
}


int main(){
	vvi matrix = {{1,2,0,4}, {2, 0, 1, 3}, {1, 3, 5, 7}};
	cout << "Before" << endl;
	print(matrix);
	fill_zeros(matrix);
	cout << "After" << endl;
	print(matrix);
}
