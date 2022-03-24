x = int(input())

m = { i: i*i*i*i*i for i in range(-200,200,1)}

f = False
for a in range(-200,200,1):
    for b in range(-200,200,1):
        if m[a]-m[b]==x:
            print(a,b)
            f = True
            break
    if f:
        break
            

