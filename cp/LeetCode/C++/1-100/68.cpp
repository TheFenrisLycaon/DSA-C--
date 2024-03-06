#include <math.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
    public:
        vector<string> fullJustify(vector<string> &words, int L) {
            vector<string> result;
            int len=0;
            int start = 0;
            int end = 0;
            double space =0;
            bool lastLine = false;
            for (int i=0; i<words.size(); i++){
                len += words[i].size();
                if (len + i - start > L || i == words.size()-1) {
                    if (len + i - start > L) {  
                        len -= words[i].size();
                        end = i-1;
                        lastLine = false;
                    }else{
                        end = i;
                        lastLine = true;
                    }
                    space = L - len;
                    long mspace;
                    int extra;
                    if (lastLine){
                        mspace = 1;
                        extra = 0;
                    } else {
                        mspace = floor(space/(end-start));
                        extra = space - mspace * (end-start);
                    }
                    string line = words[start];
                    for (int j=start+1; j<=end; j++) {
                        for(int k=0; k<mspace && space>0; k++, space--) {
                            line += " ";
                        }   
                        if (j-start-1 < extra){
                            line += " ";
                            space--;
                        } 
                        line += words[j];
                    }
                    if (space>0){
                        for(; space>0; space--) {
                            line += " ";
                        }
                    }
                    result.push_back(line);
                    start = i;
                    i = end;
                    len = 0;
                } 
            }
            return result;
        }
};
void printVector(vector<string> &words, bool newline=false) {
    for(int i=0; i<words.size(); i++) {
        cout << "\"" << words[i] << "\", ";
        if (newline) cout << endl; 
    }
    cout << endl;
}
