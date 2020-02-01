num1=2
num2=3
for i in range(0,98):
    m=1
    if i%3==0:
        m=int(2*i/3+2)
    temp=num1
    num1=num2
    num2=temp+m*num1
result=0
for i in range(0,len(str(num2))):
    result+=int(str(num2)[i])
print(result)
x=input()
