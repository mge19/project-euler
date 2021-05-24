from math import atan,sqrt,pi
n=1
while(50*(1+((n+1-sqrt(2*n))*(n-1)/(n*n+1))-pi/4-atan((n-1)/sqrt(2*n))+atan((n-1)/(n+1)))/(1-pi/4)<=99.9):
    n+=1;
print(n)
x=input()
