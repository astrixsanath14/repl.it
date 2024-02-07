def maximum_gifts(N, gifts):
  gifts.sort(key=lambda x: (x[0], x[1]))
  max_gifts = 0
  budget = 0
  for i in range(N):
      budget += gifts[i][0]
      if i > 0:
          budget -= gifts[i-1][0]
      if gifts[i][1] <= budget:
          budget -= gifts[i][1]
          max_gifts += 1
  return max_gifts
  
gifts = [
(3, 2),
(5, 4),
(6, 3)
]

gifts = [
(50, 50),
(51, 20),
(52, 20)
]
result = maximum_gifts(len(gifts), gifts)
print(result)