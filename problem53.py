fact=list()
x=1
for i in range(1,102):
    fact.append(x)
    x*=i
result=0
for j in range(23,101):
    if(j%2==1):
        x=int((j-1)/2)
    else:
        x=int(j/2)
    while((fact[j]/(fact[j-x]*fact[x]))>1000000):
        if(j%2!=0 or x!=int(j/2)):
            result+=1
        result+=1
        x-=1
print(result)
x=input()
