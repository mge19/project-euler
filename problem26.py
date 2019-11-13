maxperiod=1
for i in range(3,1000):
    if(i%2!=0 and i%5!=0):
        n=9
        current=1
        while(n%i!=0):
            current+=1
            n=10*n+9
        if(current>maxperiod):
            result=i
            maxperiod=current
print(result)
x=input()
