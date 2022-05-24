import queue


n,m,t = map(int,input().split())
va = list(map(int,input().split()))

gf = [[] for _ in range(n)]
gr = [[] for _ in range(n)]

for _ in range(m):
    a,b,c = map(int, input().split())
    a-=1
    b-=1
    gf[a].append((b,c))
    gr[b].append((a,c))







df = [1e12]*n
dr = [1e12]*n
q = queue.Queue()

q.put((0,0))
df[0]=0
while not q.empty():
    now, c0 = q.get()
    if df[now]>c0:
        continue
    for to,cc in gf[now]:
        c1 = c0+cc
        if df[to] <= c1:
            continue
        df[to]=c1
        q.put((to,c1))

q.put((0,0))
dr[0]=0
while not q.empty():
    now, c0 = q.get()
    if dr[now]>c0:
        continue
    for to,cc in gr[now]:
        c1 = c0+cc
        if dr[to] <= c1:
            continue
        dr[to]=c1
        q.put((to,c1))


ans = 0
for i in range(n):
    rem = t-df[i]-dr[i]
    if rem<0:
        continue
    ans = max(ans, rem*va[i] )

print(ans)