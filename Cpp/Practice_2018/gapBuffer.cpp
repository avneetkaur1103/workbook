#include<bits/stdc++.h>
using namespace std;

class textPad{
	std::vector<char> buff1(1000);
	std::vector<char> buff2(1000);

	int cur1 = 0;
	int cur2 = 0;
	int lineWidth = 10;

	int move(int noOfChars){ 
		while(cur2 > 0 && noOfChars-- )
			buff1[cur++] = buff2[cur2--];
	}
	copy(int n){
		lineStart = (n-1)*10;
		lineEnd = (n)*10 - 1;

		if(cur1 > lineEnd){
			for(int i = lineEnd ; i <=lineEnd ; i++)
				buff1[curr++] = buff1[i];
		}
		//if in buff2
		lineStart = cur2 - (lineStart - cur1);
		lineEnd = lineStart - 10;
		for(int i = lineStart ; i>=lineEnd ; i--)
				buff1[cur++] = buff2[i];

 	}

}