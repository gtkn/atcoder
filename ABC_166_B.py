n,k = map(int,input().split())
cnt = [0]*n

for _i in range(k):
    d = int(input())
    a = list(map(int, input().split()))
    for ai in a:
        cnt[ai-1]+=1

ans = 0
for i in range(n):
    if cnt[i]==0:
        ans+=1

print(ans)


        