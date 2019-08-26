#include<bits/stdc++.h>
#include<cctype>
using namespace std;

vector<string> reorderLines(int logFileSize, vector<string> logfile){
	std::vector<pair<string,string>> logData;

	for(int i = 0 ; i < logFileSize; i++){
		istringstream iss(logfile[i]); string id, data;
		iss >> id ;
		getline(iss,data);
		logData.push_back({id,data});
	}
	auto sortingCriteria = [](auto x, auto y){
	    auto xalpha = find_if(x.second.begin(),x.second.end(),[](auto i){return isalpha(i);});
	    auto yalpha = find_if(y.second.begin(),y.second.end(),[](auto i){return isalpha(i);});
	    if(xalpha != x.second.end() && yalpha  == y.second.end())
	    	return true ;
        if(xalpha == x.second.end() && yalpha  != y.second.end())
	    	return false ;
		if(x.second < y.second)
			return true;
		else if(x.second == y.second)
			if(x.first < y.first)
				return true;
		return false;
	};
	sort(logData.begin(),logData.end(), sortingCriteria);

	std::vector<string> result;
	for(auto i : logData){
        string s = i.first + " " + i.second;
        result.push_back(s);
	}
    return result;
}
int main(){
	vector<string> result = reorderLines(5,{"g1 Act Car","a8 act dog", "ab1 off KEY dog","a1 9 2 3 1","zo4 4 7"});
	for(auto i: result)
		cout << i <<endl;
}
