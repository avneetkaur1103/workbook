#include<bits/stdc++.h>
#define MOD 10000000007
using namespace std;

template <typename T>
std::ostream& operator<<(std::ostream& o, std::vector<T> const& data)
{
   std::copy_n(begin(data), data.size() - 1,
      std::ostream_iterator<T>{o, ", "});
   return o << data.back();
}

unsigned long long int countNoConsequtive(unsigned long long int n){

	vector<unsigned long long int>inclusive(2);
	vector<unsigned long long int>exclusive(2);
	inclusive[0] = 1;
	exclusive[0] = 1;
	for(unsigned long long int i = 1 ; i < n ; i++){
		inclusive[1] = exclusive[0]%MOD;
		exclusive[1] = (inclusive[0]+ exclusive[0])%MOD;
        inclusive[0] = inclusive[1] ; exclusive[0] = exclusive[1];
		//cout << inclusive << endl;
		//cout << exclusive << endl;
	}
	return (inclusive[0] + exclusive[0])%MOD;
}

int main(){
	int n_tc;
	cin >> n_tc;
	unsigned long long int n;
	while(n_tc--){
		cin >> n;
		cout << countNoConsequtive(n) << endl;
	}

}
