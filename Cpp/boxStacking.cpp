#include<bits/stdc++.h>
#define all(c) c.begin() , c.end()
using namespace std;
struct Box{
	int h;
	int w;
	int l;
};

int maxStackHeight(std::vector<Box>& data){
	int n =  data.size();
	std::vector<Box> boxes(3*n);
	int index = 0;
	for(int i = 0 ; i < n ; i++){
		boxes[index++] = data[i];
		boxes[index++] = {data[i].w , min(data[i].h,data[i].l), max(data[i].h,data[i].l)};
		boxes[index++] = {data[i].l , min(data[i].h,data[i].w), max(data[i].h,data[i].w)};
	}
	sort(all(boxes),[](auto x, auto y){return x.w*x.l > y.w*y.l;});

	std::vector<int> dp(3*n);

	for(int i = 0 ; i < 3*n ; i++){
		dp[i] = boxes[i].h;
		for(int j = i-1 ; j >= 0 ; j--){
			if(boxes[j].w > boxes[i].w && boxes[j].l > boxes[i].l && dp[j]+boxes[i].h > dp[i]){
				dp[i] = dp[j] + boxes[i].h;
			}
		}
	}
	int maxElement = 0;
	maxElement = *max_element(dp.begin(), dp.end());
	return maxElement;
}
/* Driver program to test above function */
int main()
{
  std::vector<Box> boxes = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };

  printf("The maximum possible height of stack is %d\n",
         maxStackHeight(boxes) );

  return 0;
}
