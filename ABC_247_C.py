import sys


def main():
    input = sys.stdin.readline

    n = int(input())

    s = []
    for i in range(1,n+1):
        s = s+[i]+s
    ans = ''
    for si in s:
        ans += str(si)+' '
    print(ans)


if __name__ == '__main__':
    main()