import sys

def main():
    # N = int(input())
    # S = input()

    N = 200000
    S = '1' * N

    ans = 0
    tot = 0

    for i in range(N):
        x = int(S[i])

        tot = tot * 10 + x * (i + 1)
        ans += tot

    print(ans)



if __name__ == '__main__':
    main()