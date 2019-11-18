#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>>& matrix);
void rotate_matrix(vector<vector<int>>& m){
	int n = m.size();
	for(int r = 0; r < n/2; r++){
		for(int c = r; c < n-r-1; c++){
			pair<int, int> curr = {r, c};
			pair<int, int> next;
			int last = m[r][c];
			for(int i = 0; i < 4; i++){
				next = {curr.second, n - curr.first -1};
				int temp = m[next.first][next.second];
				m[next.first][next.second] = last;
				last = temp;
				curr = next;
			}
			print(m);
			cout << endl;
		}
	}
}

void print(vector<vector<int>>& matrix){
	for(auto v: matrix){
		for(auto i: v){
			cout << i << " ";
		}
		cout << endl;
	}
	cout << string(10, '-') << endl;
}

int main(){
	vector<vector<int>> matrix = {{0,1,2,10},
							{3,4,5,11},
							{6,7,8,12},
							{13,14,15,16}};
	rotate_matrix(matrix);
	rotate_matrix(matrix);
	rotate_matrix(matrix);
	rotate_matrix(matrix);
	print(matrix);

}
