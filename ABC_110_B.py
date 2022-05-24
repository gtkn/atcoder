import sys





def main():
    input = sys.stdin.readline

    n,m,x,y = map(int,input().split())
    vx = list(map(int,input().split()))
    vy = list(map(int,input().split()))

    for xi in vx:
        x = max(x,xi)
    for yi in vy:
        y = min(y,yi)
    
    print("War" if x>=y else "No War")




if __name__ == '__main__':
    main()