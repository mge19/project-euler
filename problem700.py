c=4503599627370517
euler=1504170715041707
result=euler+1
def inv(a,m):
    m0=m
    x0=0
    x1=1 
    while(a>1):
        q=a//m 
        t=m
        m=a%m
        a=t 
        t=x0 
        x0=x1-q*x0
        x1=t
    if(x1<0):
        x1+=m0
    return x1
n=inv(euler,c)
m=n
x=2
k=n
while(k>=10**8):
    k=(n*x)%c
    if(k<m):
        m=k
        result+=x
    x+=1
m=euler
for i in range(2,k):
    if((euler*i)%c<m):
        m=(euler*i)%c
        result+=m
print(result)
x=input()
