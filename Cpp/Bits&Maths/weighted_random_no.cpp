#include <bits/stdc++.h>
using namespace std;

int random(vector<int>& elements, vector<int>& freeq){
	int n = freeq.size();
	int prefix[n];
	prefix[0] = freeq[0];
	for(int i = 1; i < n; i++){
		prefix[i] = prefix[i-1]+freeq[i];
	}
	int random_int = (rand() % prefix[n-1]) + 1;
	cout<< "Debug: " << random_int << " Prefix[n-1]: " << prefix[n-1] <<endl;
	int index = upper_bound(prefix, prefix+n, random_int) - prefix;
	return elements[index];
}

int main(){
	 vector<int> elements = {1, 2, 3, 4};
	 vector<int> freeq = {10, 5, 20, 30};
	 srand(time(0));
	 for(int i = 0; i < 20; i++)
        cout << random(elements, freeq) << endl;
}
