from re import I
import sys


def main():
    input = sys.stdin.readline

    n = int(input())
    x = 1000010

    isok = [True]*x
    isok[0]=False
    isok[1]=False

    v = []

    for i in range(x):
        if not isok[i]:
            continue
        v.append(i)
        j = i
        while j<x:
            isok[j]=False
            j+=i

    nn = len(v)

    s = set()
    for i in range(nn):
        for j in range(i+1,nn):
            p = v[i]
            q = v[j]
            k = p*q*q*q
            if k<=n:
                s.add(k)
            else:
                break

    print(len(s))


if __name__ == '__main__':
    main()