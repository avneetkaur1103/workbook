// https://leetcode.com/problems/water-and-jug-problem/
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x+y < z || z < 0)
            return false;
        if(z == 0)
            return true;
        if(x == 0)
            return z == y;
        if(y == 0)
            return x == y;
        return z%__gcd(x, y) == 0;
    }
};