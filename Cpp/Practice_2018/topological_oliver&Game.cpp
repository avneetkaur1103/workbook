#include <iostream>
#include<bits/stdc++.h>
using namespace std;

static long _count = 0;
template <typename T>
std::ostream& operator<<(std::ostream& o, std::vector<T> const& data)
{
   std::copy_n(begin(data), data.size() - 1,
      std::ostream_iterator<T>{o, ", "});
   return o << data.back();
}

bool doDfs(std::vector<list<int>>& G ,std::vector<int>& inStack, int parent , int X, int Y , int dir){
	for(auto& i : G[parent]){
		if(!inStack[i]){
			inStack[i] = _count++;
			doDfs(G,inStack,i,X,Y,dir);
			cout << inStack << endl;
			if(!dir  && inStack[X]!= 0 && inStack[Y] != 0 && inStack[X] < inStack[Y])
				return true;
			else if(dir && inStack[X]!= 0 && inStack[Y] != 0 && inStack[X] > inStack[Y])
				return true;
			inStack[i] = 0;
		}
	}
	return false;
}
bool solve(std::vector<list<int>>& G, int src , int X , int Y , int dir){
	std::vector<int> inStack(G.size(),0);
	_count = 1;
	inStack[0] = _count;
	return doDfs(G, inStack,0, X , Y , dir);
}

int main(){
	int node;
	cin >> node;
	std::vector<list<int>> G(node);
	int x,y;
	for(int i = 0 ; i < node-1 ; i++){
		cin >> x >> y;
		G[x-1].push_back(y-1);
		G[y-1].push_back(x-1);
	}
	int queries, dir , X , Y;
	cin >> queries;
	while(queries--){
		cin >> dir >> X >> Y;
		solve(G,0,X-1,Y-1,dir) ?  cout << "YES\n" : cout << "N0\n";
	}
}
