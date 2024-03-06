class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows<=1 || numRows>=s.size()) return s;
     
    vector<string> r(numRows);
    int row = 0;
    int step = 1;
    for(int i=0; i<s.size(); i ++) {
        if (row == numRows-1) step = -1;
        if (row == 0) step = 1;
        //cout << row <<endl;
        r[row] += s[i];
        row += step;
    }
    
    string result;
    for (int i=0; i<numRows; i++){
        result += r[i];
    }
    return result; 
    }
};