// https://leetcode.com/problems/integer-to-roman/
map<int, string> mapping = {{1, "I"}, {5, "V"}, {10, "X"}, {50, "L"}, {100, "C"}, {500, "D"}, {1000, "M"},
 {4, "IV"}, {9, "IX"}, {40, "XL"}, {90, "XC"}, {400, "CD"}, {900, "CM"}};

class Solution {
public:

    string get_units(int num) const{
        string result = "";
        if(num == 0)
            return result;
        if(num < 4)
            result = "I" + get_units(num-1);
        else if(num == 4)
            return mapping[num];
        else if(num == 5)
            return mapping[num];
        else if(num == 9)
            return mapping[num];
        else if(num > 5)
            result = "V" + get_units(num-5);
        return result;
    }
    string get_tens(int num) const{
        string result = "";
        if(num == 0)
            return result;
        if(num < 40)
            result = "X" + get_tens(num-10);
        else if(num == 40)
            return mapping[num];
        if(num == 50)
            return mapping[num];
        else if(num == 90)
            return mapping[num];
        if(num > 50)
            result = "L" + get_tens(num-50);
        return result;
    }
    string get_hundreds(int num) const{
        string result = "";
        if(num == 0)
            return result;
        if(num < 400)
            result = "C" + get_hundreds(num-100);
        if(num == 400)
            return mapping[num];
        if(num == 500)
            return mapping[num];
        else if(num == 900)
            return mapping[num];
        if(num > 500)
            result = "D" + get_hundreds(num-500);
        return result;
    }
    string get_thousands(int num) const{
        string result = "";
        if(num == 0)
            return result;
        if(num < 4000)
            result = "M" + get_thousands(num-1000);
        return result;
    }

    string intToRoman(int num) {
        string result = "";
        int power = 1;

        while(num){
            int last = num%10;
            num /= 10;
            if(power == 1){
                result = get_units(last) + result;
            }
            else if(power == 2){
                 result = get_tens(last*10) + result;
            }
            else if(power == 3){
                 result = get_hundreds(last*100) + result;
            }
            else if(power == 4){
                 result = get_thousands(last*1000) + result;
            }
            power++;

        }
        return result;
    }

};