n,a,b,c = map(int,input().split())
v = [a,b,c]
u = ["A","B","C"]
nn = a+b+c


if nn==0:
    print("No")
    exit()
    







ans = []
for _ in range(n):
    s = input()
    x = -1
    if s=="AB":
        x = 0
    if s=="BC":
        x = 1
    if s=="AC":
        x = 2

    y = (x+1)%3
    
    v[x]+=1
    v[y]-=1
    cnt = 0
    for vi in v:
        if vi==0: cnt+=1
        if vi<0: cnt+=10
    if cnt<2:
        ans.append(u[x])
        continue

    v[x]-=2
    v[y]+=2
    cnt = 0
    for vi in v:
        if vi==0: cnt+=1
        if vi<0: cnt+=10
    if cnt<2:
        ans.append(u[y])
        continue

    break


if len(ans)==n:
    print("Yes")
    for ai in ans:
        print(ai)
else:
    print("No")