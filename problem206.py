numbers=list()
numbers.append(30)
numbers.append(70)
for i in range(0,4):
    n=len(numbers)
    for j in range(0,n):
        u=1
        v=100
        if(i==3):
            u=10
            v=20
        for k in range(u,v):
            s=100
            for b in range(0,i):
                s*=100
            b=s*k+numbers[0]
            x=str(b*b)
            if(len(x)>=2*i+5 and int(x[len(x)-2*i-5])==8-i and i<3):
                numbers.append(b)
            if(i==3):
                a=1
                while(int(x[2*a])==a+1 and a<5):
                    a+=1
                if(a==5):
                    print(b)
                    break
        numbers.remove(numbers[0])
x=input()
