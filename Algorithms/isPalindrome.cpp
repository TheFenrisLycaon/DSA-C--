#include <iostream>
#include <algorithm>
#include <string>
#include <time.h>

using namespace std;

bool isAlphaNumeric(char *c) {
        if ((*c>='A' && *c<='Z')|| (*c>='a' && *c<='z') || (*c>='0' && *c<='9')) {
            if (*c>='A' && *c<='Z') {
                *c += 32;
            }
            return true;
        }
        return false;
}

bool isPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;
        cout<<s;
        if (s.size()==1){
          return true;
        }
        while(left<=right) {
            if (isAlphaNumeric(&s[left]) && isAlphaNumeric(&s[right])) {
            //   cout<<s[left]<<endl;
                if (s[left] != s[right]) {
                //   cout<<false;
                    return false;
                }
                left++;
                right--;
            }
            else {
                if (!isAlphaNumeric(&s[left])) {
                //   cout<<s[left]<<endl;
                    left++;
                }
                if (!isAlphaNumeric(&s[right])){
                    right--;
                }
            }
        }
        cout<<"true";
        return true;
    }

int main(){
  cout<<isPalindrome("A man, a plan, a canal: Panama")<<endl;
}