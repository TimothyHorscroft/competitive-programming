t=int(input())
for i in range(t):
    a,b=map(int,input().split())
    print(["NO","YES"][(a+b)%3==0 and a <= 2*b and b <= 2*a])
