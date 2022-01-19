# https://leetcode.com/problems/linked-list-cycle-ii/

# Definition for singly-linked list.
class ListNode():
    def __init__(self, val, index):
        self.val = val
        self.index = index
        self.next = None

class Solution():
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        return head

if __name__ == "__main__":
  print("Executing Main!")
  sol = Solution()
  head = ListNode(-1, 0)
  node = sol.detectCycle(head)
  print(node.index,node.val)

"""
FloydsTortoiseAndHare.py

[3,2,0,-4]
1
"""