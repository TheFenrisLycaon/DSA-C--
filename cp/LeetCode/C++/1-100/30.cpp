class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
    if ( s.size()<=0 || l.size() <=0 ){
        return result;
    }
    int n = s.size(), m = l.size(), l = l[0].size();
    map<string, int> expected;
    for(int i=0; i<m; i++){
        if (expected.find(l[i])!=expected.end()){
            expected[l[i]]++;
        }else{
            expected[l[i]]=1;
        }
    }
    for (int i=0; i<l; i++){
        map<string, int> actual;
        int count = 0; 
        int winleft = i;
        for (int j=i; j<=n-l; j+=l){
            string word = s.substr(j, l);
            if (expected.find(word) == expected.end() ) {
                actual.clear();
                count=0;
                winleft = j + l;
                continue;
            }
            count++;
            if (actual.find(word) == actual.end() ) {
                actual[word] = 1;
            }else{
                actual[word]++;
            }
            if (actual[word] > expected[word]){
                string tmp;
                do {
                    tmp = s.substr( winleft, l );
                    count--;
                    actual[tmp]--;
                    winleft += l; 
                } while(tmp!=word);
            }
            if ( count == m ){
                result.push_back(winleft);
                string tmp = s.substr( winleft, l );
                actual[tmp]--;
                winleft += l;
                count--;
            }
        }
    }
    return result;
    }
};