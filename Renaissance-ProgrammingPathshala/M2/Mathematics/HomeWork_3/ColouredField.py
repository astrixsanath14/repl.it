# your code goes here
modulo = 3

crops = ['Carrots', 'Kiwis', 'Grapes']

n, m, k, t = map(int, input().split())

wasteland_data = [[] for i in range(n)]

for i in range(k):
    x, y = map(int, input().split())
    wasteland_data[x-1].append(y-1)

total_wastelands = 0
prefix_wastelands_sum = [0]*n
for i in range(1, n):
    total_wastelands += len(wasteland_data[i-1])
    prefix_wastelands_sum[i] = total_wastelands


for i in range(t):
    x, y = map(int, input().split())
    if y-1 in wasteland_data[x-1]:
        print('Waste')
    else:
        wate_land_count = 0
        for idx in wasteland_data[x-1]:
            if idx < y-1:
                wate_land_count += 1

        print(crops[((x-1)*m+y-1-wate_land_count -
              prefix_wastelands_sum[x-1]) % modulo])


"""
Renaissance-ProgrammingPathshala/M2/Mathematics/HomeWork_3/ColouredField.py
4 5 5 6  
4 3  
1 3  
3 3  
2 5  
3 2  
1 3  
1 4  
2 3  
2 4  
1 1  
1 1

Input
4 5 5 6  
4 3  
1 3  
3 3  
2 5  
3 2  
1 3  
1 4  
2 3  
2 4  
1 1  
1 1

Output
Waste  
Grapes  
Carrots  
Kiwis  
Carrots  
Carrots

"""
