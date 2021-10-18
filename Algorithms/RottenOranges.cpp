//Problem Statement:
// Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
// 0 : Empty cell
// 1 : Cells have fresh oranges
// 2 : Cells have rotten oranges
// We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes:
// [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time.

//Example:
// Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
// Output: 1
// Explanation: The grid is-
// 0 1 2
// 0 1 2
// 2 1 1
// Oranges at positions (0,2), (1,2), (2,0) will rot oranges at (0,1), (1,1), (2,2) and (2,1) in unit time.

#include<bits/stdc++.h>
using namespace std;

//Function to find minimum time required to rot all oranges. 
int orangesRotting(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>>q;

        int one=0;  //to store initial count of fresh oranges present

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){    //rotten orange
                    q.push(make_pair(i,j));
                }
               if(grid[i][j]==1){     //fresh orange
                    one++;
                }
            }
        }
        int t=0;      //time for rottening

        //For traversing all four directions
        int dx[]={1, -1, 0, 0};
        int dy[]={0, 0, 1, -1};

        while(!q.empty()){
            int s=q.size();
            for(int k=0;k<s;k++){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                for(int p=0;p<4;p++){
                    int x=dx[p]+i;
                    int y=dy[p]+j;
                    if(x<n && x>=0 && y<m && y>=0 && grid[x][y]==1){
                        q.push(make_pair(x,y));
                        grid[x][y]=2;
                    }
                }
            }
            if(q.empty()){
                if(one==0){
                return t;
                }
                return -1;   //if q is empty and all fresh oranges have not been rotten
            }
            t++;             //time increases one unit after every level
            one-=q.size();   //decrease count of fresh oranges
        }
        return t;
}
int main(){

		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}

		int ans = orangesRotting(grid);
		cout << ans <<endl;

	return 0;
}
