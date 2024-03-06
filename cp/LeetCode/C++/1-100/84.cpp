#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      if (heights.size()<=0) return 0;
    vector<int> stack;
    heights.push_back(0);
    int maxArea = 0;
    for(int i=0; i<heights.size(); i++){
        if ( stack.size()<=0 || heights[i] >= heights[stack.back()] ) {
            stack.push_back(i);
            continue;
        }
        int topIdx = stack.back();
        stack.pop_back();
        int area = heights[topIdx] * (stack.size()==0 ? i : i - stack.back() - 1 );
        if ( area > maxArea ) {
            maxArea = area;
        }
        i--;
    }
    return maxArea;
    }
};