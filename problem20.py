def factorial(n):
    if(n==0):
        return 1
    else:
        return factorial(n-1)*n
result=0
number=str(factorial(100))
for digit in number:
    result+=int(digit)
print(result)
x=input()
