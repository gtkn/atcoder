import sys

def main():
    input = sys.stdin.readline

    N,K,M = list(map(int,input().split()))
    A = list(map(int,input().split()))


    tot = 0
    for ai in A:
        tot += ai
    
    ans = N*M-tot
    if ans<0:
        ans = 0

    if ans>K:
        ans = -1

    print(ans)


if __name__ == '__main__':
    main()