numerator=1393
denominator=985
result=1
for i in range(8,1000):
    temp=denominator
    denominator+=numerator
    numerator+=2*temp
    result+=len(str(numerator))>len(str(denominator))
print(result)
x=input()
