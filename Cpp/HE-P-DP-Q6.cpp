#include<bits/stdc++.h>
using namespace std;
std::vector<long long int> result1;
std::vector<long long int> result2;

template <typename T>
std::ostream& operator<<(std::ostream& o, std::vector<T> const& data)
{
   std::copy_n(begin(data), data.size() - 1,
      std::ostream_iterator<T>{o, ", "});
   return o << data.back();
}

void buildData(std::vector<long long int>& v1 , std::vector<long long int>& v2){
	long n = v1.size();
	result1.resize(n+1,0);
	result2.resize(n+1,0);
	for(int i = 1 ; i <= n ; i++){
		if(i&1){
			result1[i] = result1[i-1] + v2[i-1];
			result2[i] = result2[i-1] + v1[i-1];
		}
		else{
			result1[i] = result1[i-1] + v1[i-1];
			result2[i] = result2[i-1] + v2[i-1];
		}
	}
	cout <<  result1 << endl;
	cout <<  result2 << endl;
}

long long int solve(int flag , long l , long r){
	if(flag&(1+l)){
		if((l+1)&1)
			return result2[r] - result2[l-1];
		else
			return result1[r] - result1[l-1];
	}
	else{
		if((l+1)&1)
			return result1[r] - result1[l-1];
		else
			return result2[r] - result2[l-1];
	}
}
int main(){
	long N, Q;
	cin >> N >> Q;
	std::vector<long long int> a(N,0);
	std::vector<long long int > b(N,0);
	for(long i = 0 ; i < N ; i++){
		cin >> a[i];
	}
	for(long i = 0 ; i < N ; i++){
		cin >> b[i];
	}
	buildData(a,b);
	long f,l,r;
	for(int i  = 0 ; i < Q ; i++){
		cin >> f >> l >> r;
		cout << solve(f,l,r) << endl;
	}
}
