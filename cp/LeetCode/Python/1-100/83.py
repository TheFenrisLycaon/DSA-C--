class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head==None:
            return head
        current= head.next
        prev=head
        while current!=None:
            if current.val==prev.val:
                prev.next=current.next
                current=current.next
            else:
                current=current.next
                prev=prev.next
        return head