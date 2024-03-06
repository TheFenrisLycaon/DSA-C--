#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> countBits(int num)
    {
        //if you keenly observe
        //we can use what we have already calculated
        //if a number is 8 then the number of set bits in it would be the number of set bits in half of its number ie., 4
        //since 8 - 100
        //      4-  010
        //when we right shift the 8 by 1 we are only gonna lose the last bit
        //and remaining set bits are same
        vector<int> res(num + 1);
        res[0] = 0;
        for (int i = 1; i <= num; i++)
        {
            res[i] = (i & 1) + res[i >> 1]; //if i is odd we will have set bit at last as we gonna lose it (ex- 101 )
        }
        return res;
    }
};

int main()
{
    Solution o;
    vector<int> res = o.countBits(161);

    for(int i=0;i<res.size(); i++)
        cout << res[i] << '\t';

}