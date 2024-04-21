import sys

def main():
    input = sys.stdin.readline

    t = int(input())
    while t > 0:
        n,m,k = map(int,input().split())
        print( ((2**n)%(2**m - 2**k))%10 )
        t -= 1



if __name__ == '__main__':
    main()