# https://leetcode.com/problems/linked-list-cycle-ii/

# Definition for singly-linked list.
class ListNode():
  def __init__(self, val, index, isCycleNode=False):
      self.val = val
      self.index = index
      self.isCycleNode = isCycleNode
      self.next = None

def printLinkedList(head):
  temp = head
  isCycleNodeVisited = False
  while temp != None:
    if temp.isCycleNode:
      if isCycleNodeVisited:
        print(temp.index, temp.val, '-> Cycle Node')
        break
      isCycleNodeVisited = True
    print(temp.index, temp.val)
    temp = temp.next

def createLinkedList(nodesList:list,cyclePos:int):
  head = None
  tail = head
  cycleNode = None
  noOfNodes = len(nodesList)
  index = 0
  for val in nodesList:
    node = ListNode(val, index)
    if head == None:
      head = node
      tail = head
    else:
      tail.next = node
      tail = node
    if cyclePos == index:
      cycleNode = node
      cycleNode.isCycleNode = True
    index += 1
  
  if cycleNode != None:
    tail.next = cycleNode
  return head

class Solution():
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        cycleNode = None
        if head == None:
          return None
        hare = head
        tortoise = head
        while True:
          hare = hare.next
          if hare == None:
            return None
          hare = hare.next
          if hare == None:
            return None
          tortoise = tortoise.next
          if hare == tortoise:
            cycleNode = hare
            break
        temp = head
        while temp != cycleNode:
          temp = temp.next
          cycleNode = cycleNode.next
        return cycleNode

if __name__ == "__main__":
  print("Executing Main!")
  sol = Solution()
  while True:
    inputStr = input().strip()
    inputStr = inputStr.replace("[","")
    inputStr = inputStr.replace("]","")
    nodesList = [int(i) for i in inputStr.split(',') if i.lstrip('-').isnumeric()]
    cyclePos = int(input().strip())
    
    print('nodesList',nodesList)
    print('cyclePos',cyclePos)
    
    head = createLinkedList(nodesList, cyclePos)
    printLinkedList(head)
    
    node = sol.detectCycle(head)
    if node == None:
      print('No cycle present!')
    else:
      print('Cycle Found!')
      print('index',node.index)
      print('val',node.val)

    choice = input('Do you want to continue? (y/n)')

    if not(choice == 'y' or choice == 'Y'):
      break
    print('\n\n')

"""
LeetCodeSolutions/FloydsTortoiseAndHare.py
[3,2,0,-4]
1
Y
[1,2]
0
Y
[1]
-1
Y
[]
-1
N
"""