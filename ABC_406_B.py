import sys


def keta(x):
    ans = 0
    while x > 0:
        x //= 10
        ans += 1
    return ans

def main():
    input = sys.stdin.readline

    N,K = map(int,input().split())
    A = list(map(int,input().split()))

    now = 1
    for a in A:
        now *= a
        if keta(now) > K:
            now = 1

    print(now)





if __name__ == '__main__':
    main()