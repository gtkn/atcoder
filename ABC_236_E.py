n = int(input())
A = list(map(int,input().split()))


#---average---

l = 0
ten = 1e3
r = 1e9*ten+10
while r-l>1:
    m = (l+r)//2
    B = [ai*ten-m for ai in A]
    B.append(0)
    B.append(0)
    dp = [-1e18]*(n+10)
    dp[0] = 0
    for i in range(n):
        for j in [i+1,i+2]:
            dp[j] = max(dp[j],dp[i]+B[j-1])
    print(dp,l,r)
    if dp[n]>=0:
        l=m
    else:
        r=m
print(l/ten)


#---medium---
l = 0
r = 1e9+10
while r-l>1:
    m = (l+r)//2
    cnt = 0
    lst = True
    for i in range(n):
        if lst:
            if A[i]>=m:
                cnt+=1
            else:
                lst=False
        else:
            cnt += 1 if A[i]>=m else -1
            lst = True
    if cnt>0:
        l=m
    else:
        r=m
print(int(l))
