def getFinalList(l):
  res = [l]
  while True:
    prev = res[-1]
    temp = [prev.count(i) for i in prev]
    if prev == temp:
      break
    res.append(temp)
  # print(res)
  return res

def solve():
  n = int(input().strip())
  l = list(map(int, input().strip().split()))
  l  = getFinalList(l)
  q = int(input().strip())
  for i in range(q):
    x,k = map(int,input().strip().split())
    k = min(k,len(l)-1)
    x-=1
    # print('k',k,'x',x)
    print(l[k][x])

t = int(input().strip())
for i in range(t):
  # print('running ', i)
  solve()


"""
Contests/CodeForces/751_Div2/DivineArray.py
2
7
2 1 1 4 3 1 2
4
3 0
1 1
2 2
6 1
2
1 1
2
1 0
2 1000000000

1
2
3
3
1
2


"""