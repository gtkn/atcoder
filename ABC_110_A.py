a,b,c = map(int,input().split())
ans = 0
ans = max(ans, a*10+b+c)
ans = max(ans, a+b*10+c)
ans = max(ans, a+b+c*10)
print(ans)