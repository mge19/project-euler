result=0
for i in range(2,100):
    for j in range(2,100):
        temp=0
        for char in str(i**j):
            temp+=int(char)
        result=max(temp,result)
print(result)
x=input()
