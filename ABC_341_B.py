import sys

def main():
    input = sys.stdin.readline

    N = int(input())
    A = list(map(int,input().split()))

    for i in range(N-1):
        S,T = map(int,input().split())
        x = A[i]//S
        A[i+1] += T*x

    print(A[-1])






if __name__ == '__main__':
    main()