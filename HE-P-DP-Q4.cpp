#include<bits/stdc++.h>
#define all(c) c.begin() , c.end()
using namespace std;


template<typename T>
ostream& operator<<(ostream& 0, std::vector<T> const& data){
	copy_n(data.begin(),data.size()-1,ostream_iterator<T>{o,", "});
	return o<<data.back();
}

void printEvens(string& s){
	std::vector<int> res(s.length());
	for(auto i = s.rbegin(); i != rend() ; i++){
		if(!(*i&1))
			res.push_back(res.back()+1);
	}
	reverse(all(res));
	cout << res;
}
int main(){
	string str;
	cin >> str;
	printEvens(str)
}