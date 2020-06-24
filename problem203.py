result=1
numbers=set()
fact=list()
fact.append(1)
for i in range(2,51):
    fact.append(i*fact[i-2])
    for j in range(1,int(i/2)+1):
        numbers.add(fact[i-1]/(fact[i-j-1]*fact[j-1]))
while len(numbers)>0:
    x=numbers.pop()
    y=2
    while y<=round(x**0.5):
        if x%(y*y)==0:
            break
        y+=1
    if y>round(x**0.5):
        result+=x
        print(result)
x=input()
