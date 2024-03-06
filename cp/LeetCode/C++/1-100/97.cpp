#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Dynamic Programming
bool isInterleave(string s1, string s2, string s3) {
    
    if (s1.size() + s2.size() != s3.size()) {
        return false;
    }

    vector< vector<int> > match(s1.size()+1, vector<int>(s2.size()+1, false) );

    match[0][0] = true;
    for(int i=1; i<=s1.size(); i++) {
        if (s1[i-1] == s3[i-1] ) {
            match[i][0] = true;
        }else{
            break;
        }
    }
    for(int i=1; i<=s2.size(); i++) {
        if (s2[i-1] == s3[i-1] ) {
            match[0][i] = true;
        }else{
            break;
        }
    }

    
    for(int i=1; i<=s1.size(); i++) {
        for(int j=1; j<=s2.size(); j++) {
            if (s1[i-1] == s3[i+j-1]) {
                match[i][j] = match[i-1][j] || match[i][j];
            }
            if (s2[j-1] == s3[i+j-1]) {
                match[i][j] = match[i][j-1] || match[i][j];
            }
        }
    }
    return match[s1.size()][s2.size()];
}