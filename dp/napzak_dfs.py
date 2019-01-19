# coding: utf-8

# N : 荷物の個数
# W : ナップザックの許容容量
N, W = map(int, input().split())

# v : 荷物の価値
# w : 荷物の重さ
v = [0]*N
w = [0]*N

for i in range(N):
    v[i], w[i] = map(int, input().split())

# i : 荷物のインデックス
# j : ナップザックの重さ
def dfs(i, j):
    res = 0
    if i == N:
        res = 0
    elif j < w[i]:
        res = dfs(i + 1, j)
    else:
        res = max(dfs(i + 1, j), dfs(i + 1, j - w[i]) + v[i])
    return res

print(dfs(0, W))