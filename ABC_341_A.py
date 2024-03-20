import sys

def main():
    input = sys.stdin.readline

    N = int(input())

    ans = "1"

    for _ in range(N):
        ans += "01"

    print(ans)

if __name__ == '__main__':
    main()