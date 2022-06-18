import sys

class comb:
    nmax = 0
    fa = []
    def __init__(self, nmax=200020):
        self.nmax = nmax
        self.fa = [0]*(nmax+1)
        self.fa[0] = 1
        for i in range(nmax):
            self.fa[i+1] = self.fa[i]*(i+1)

    def c(self,n,k):
        if n>=k and k>=0 and n<=self.nmax:
            return self.fa[n]/self.fa[n-k]/self.fa[k]
        else:
            return 0




def main():
    input = sys.stdin.readline

    N,D = map(int, input().split())
    c = comb(N)


    n2=0
    n3=0
    n5=0
    while D%2==0:
        n2+=1
        D/=2
    while D%3==0:
        n3+=1
        D/=3
    while D%5==0:
        n2+=1
        D/=5

    if D>1:
        print(0)
        return

    cnt=0

    for m5 in range(n5,N+1):
        for m1 in range(0, N-m5+1):
            for m2 in range(0, N-m5-m1+1):
                for m3 in range(0, N-m5-m1-m2+1):
                    for m4 in range(0, N-m5-m1-m2+1):
                        m6 = N-m5-m1-m2-m3-m4

                        c2 = m2 + 2*m4 + m6
                        c3 = m3 + m6
                        if c2>=n2 and c3 >= n3:
                            cnt += c.c(N,m5) \
                                *c.c(N-m5,m1) \
                                *c.c(N-m5-m1,m2) \
                                *c.c(N-m5-m1-m2,m3) \
                                *c.c(N-m5-m1-m2-m3,m4)

    ans = cnt/(6**N)
    print(ans)






if __name__ == '__main__':
    main()