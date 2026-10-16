from random import *
 
n = randint(1, 100)   # 隨機產生 1~100的整數
ch = chr(ord('a') + randint(0, 25)) # 隨機產生 'a'~'z' 其中一個字元
choiceSet = sample(s, 4)   # 從集合s選出4個不同的元素
choiceSet = sample(range(1, n+1), 4)  #從整數 1~n 選出 4 個不同的元素
shuffle(arr)  # 把序列 arr 順序打亂
# 隨機產生一組 1~n 的 permutation
from random import *
n = randint(3, 6)
arr = [i+1 for i in range(n)]
shuffle(arr)
print(n)
print(*arr)
s = ""
n = randint(1, 10)
# 隨機產生一個長度為 n 的小寫字母字串
for i in range(n):
    s += chr(ord('a') + randint(0, 25))
print(s)
#產生樹
from random import *
n = randint(3, 6)
print(n)
for i in range(2, n+1):
    print(randint(1, i-1), i)
#隨機產生無自環無重邊的一張連通圖
from random import *
n = randint(5, 10)
m = randint(n-1, n+3)
print(n, m)
edge = list()
#construct tree
for i in range(2, n+1):
    x = randint(1, i-1)
    y = i
    edge.append([min(x, y), max(x, y)])
    print(x, y)
#add extra edge
for i in range(m-(n-1)):
    x = randint(1, n)
    y = randint(1, n)
    while x == y or [min(x, y), max(x, y)] in edge:
        x = randint(1, n)
        y = randint(1, n)
    print(x, y)
    edge.append([min(x, y), max(x, y)])

