from math import atan,sqrt,pi
n=1
x=50.0
while(x<=99.9):
    n+=1;
    x=50*(1+((n+1-sqrt(2*n))*(n-1)/(n*n+1))-pi/4-atan((n-1)/sqrt(2*n))+atan((n-1)/(n+1)))/(1-pi/4)
    print(str(n)+" "+str(x))
x=input()
