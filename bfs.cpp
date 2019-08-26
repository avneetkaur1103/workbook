#include <iostream>
#include<bits/stdc++.h>
using namespace std;
std::vector<pair<int,int> > _index = {{-1,0},{1,0},{0,-1},{0,1}};
void doBfs(std::vector<std::vector<char>> &v , queue<pair<int,int>>& q){
	int r,c;
	while(!q.empty()){
		pair<int , int> p = q.front();
		r = p.first;
		c = p.second;
		q.pop();
		for(int i = 0 ; i < _index.size() ; i++){
			int targetX = r + _index[i].first;
			int targetY = c + _index[i].second;
			if( targetX >= 0 && targetX < v.size() && targetY >= 0 && targetY < v[0].size() && v[targetX][targetY] == 'X'){
				v[targetX][targetY] = 'O';
				q.push({targetX,targetY});
				//cout << "(" << targetX << " , " << targetY << ")" <<endl;

			}
		}
	}

}

int countGroup(std::vector<std::vector<char> >& v)
{
	int count  = 0 ;
	std::queue<pair<int,int>> q;
	for(int i  = 0 ; i < v.size() ; i++){
		for(int j  = 0 ; j < v[i].size() ; j++){
			if(v[i][j] == 'X'){
			    //cout << "-----------------------------------------------" <<endl;
                //cout << "(" << i << " , " << j << ")" <<endl;
			    v[i][j] = 'O';
				q.push({i,j});
				doBfs(v , q);
				count++ ;
			}
		}
	}
	return  count;
}
int main(){
	int n_tc;
	cin >> n_tc;
	while(n_tc--){
		int n , m ;
		cin >> n >> m ;
		std::vector<std::vector<char>> input(n);
		for (int i = 0; i < n; ++i)
		{
			/* code */
			string s;
			cin >> s;
			copy(s.begin(),s.end(),back_inserter(input[i]));
			//cout << input[i].size() << " " << s << endl;
		}
		cout << countGroup(input) << endl;

	}
}
