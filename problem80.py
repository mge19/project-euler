result=0
for n in range(1,10):
    for i in range(n*n+1,(n+1)**2):
        number=0
        for j in range(0,100):
            k=0
            while((10*number+k)**2<=i*(10**(2*j))):
                k+=1
            result+=k-1
            number=10*number+k-1           
print(result)
x=input()
