class Solution(object):

    def buildTree(self, preorder, inorder):
        n = len(inorder)
        inOrderMap = {inorder[i]: i for i in range(n)}
        return self.buildTreeUtil(preorder, inorder, inOrderMap, 0, n - 1, 0, n - 1)

    def buildTreeUtil(self, preorder, inorder, inOrderMap, pStart, pEnd, iStart, iEnd):
        if pStart > pEnd or iStart > iEnd: return None
        root = TreeNode(preorder[pStart])
        rootIdx = inOrderMap[root.val]
        root.left = self.buildTreeUtil(preorder, inorder, inOrderMap, pStart + 1, pStart + rootIdx - iStart + 1, iStart,
                                       rootIdx - 1)
        root.right = self.buildTreeUtil(preorder, inorder, inOrderMap, pStart + rootIdx - iStart + 1, pEnd, rootIdx + 1,
                                        iEnd)
        return root
