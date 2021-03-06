/**
@author SwapnilB
@date 01/03/2018
*/

#include<bits/stdc++.h>

class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.size() == 0){
			return num2;
		}else if(num2.size() == 0){
			return num1;
		}

		int len1 = num1.length();
		int len2 = num2.length();

		int maxLen = len1 > len2 ? len1 : len2;

		std::reverse(num1.begin(), num1.end());
		std::reverse(num2.begin(), num2.end());
		
		//cout << "Reversed1: " << num1 << endl;
		//cout << "Reversed2: " << num2 << endl;
		string result = "";

		int sum = 0, carry = 0, it1 = 0, it2 = 0;
		for(int i = 0; i < maxLen; ++i){
			if(it1 < len1 && it2 < len2){
				sum = (((int)num1[it1] - '0') + ((int)num2[it2] - '0') + carry) % 10;
				carry = (((int)num1[it1] - '0') + ((int)num2[it2] - '0') + carry) / 10;
				it1++; it2++;
			}else if(it1 < len1 && it2 >= len2){ // second number out of range
				sum = (((int)num1[it1] - '0') + carry) % 10;
				carry = (((int)num1[it1] - '0') + carry) / 10;
				it1++;
			}else if(it1 >= len1 && it2 < len2){ // first number out of range
				sum = (((int)num2[it2] - '0') + carry) % 10;
				carry = (((int)num2[it2] - '0') + carry) / 10;
				it2++;
			}
			result += ((char)sum + '0');
		}
		if(carry != 0){
			result += ((char)carry + '0');
		}
		std::reverse(result.begin(), result.end());
		return result;
    }
};

int main(){
	Solution *s = new Solution();
	cout << s->addStrings("22","6"6) << endl;
	return 0;
}