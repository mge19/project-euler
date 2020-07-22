result=0
for i in range(1,10):
    j=1
    while(len(str(i**j))==j):
        j+=1
        result+=1
print(result)
x=input()
