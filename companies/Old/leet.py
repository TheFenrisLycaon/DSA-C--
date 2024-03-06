# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def allPossibleFBT(self, n: int) -> List[Optional[TreeNode]]:
        if n%2==0:
			return []

		dp = defaultdict(list)
		dp[1].append(TreeNode(0))

		temp = TreeNode(0)
		temp.left = TreeNode(0)
		temp.right= TreeNode(0)
		dp[3].append(temp)

		for i in range(5,n+1,2):
			left = 1
			right= (i-1)-1
			while right>=1:
				for l_tree in dp[left]:
					for r_tree in dp[right]:
						temp = TreeNode(0)
						temp.left = l_tree
						temp.right = r_tree
						dp[i].append(temp)
				right-=2
				left+=2

		return dp[n]