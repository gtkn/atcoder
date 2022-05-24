from pickle import TRUE
import sys


def main():
    input = sys.stdin.readline

    n = int(input())
    vs = []; vt=[]
    for _ in range(n):
        s,t = input().split()
        vs.append(s)
        vt.append(t)

    ans = "Yes"
    for i,(s,t) in enumerate( zip(vs,vt) ):
        fs = True
        ft = True
        for j in range(n):
            if i==j:
                continue
            if vs[j]==s or vt[j]==s:
                fs = False
            if vs[j]==t or vt[j]==t:
                ft = False
        if fs or ft:
            continue
        ans = "No"


    print(ans)


if __name__ == '__main__':
    main()