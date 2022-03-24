n,m = map(int,input().split())
h = list(map(int,input().split()))

g = [[] for _ in range(n)]

for _ in range(m):
    a,b = map(int, input().split())
    a-=1
    b-=1
    g[a].append(b)
    g[b].append(a)

ans = 0
for i in range(n):
    f = True
    for j in g[i]:
        if h[i] <= h[j]:
            f = False
    if f:
        ans+=1

print(ans)