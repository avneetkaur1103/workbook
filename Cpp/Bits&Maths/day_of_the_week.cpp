/* Write a function that calculates the day of the week for any particular date in the past or future. -No Anchor day */
#include <bits/stdc++.h>
using namespace std;

int dayofweek(int d, int m, int y){
	static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 }; // extra day w.r.t Mar as begininng of the year => no leap calculation untill it post feb
	y -= m < 3;

	return (y + y/4 -y/100 +y/400 + t[m-1] + d) % 7;
}
int main()  
{  
    int day = dayofweek(30, 8, 2010);  
    cout << day;  
  
    return 0;  
}