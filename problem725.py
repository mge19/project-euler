result=0
fact=[]
fact.append(1)
for i in range(1,10):
    fact.append(i*fact[i-1])
q=[]
for i in range(1,10):
    l=[]
    l.append(i)
    q.append(l)
while(len(q)>0):
    l=q.pop(0)
    s=0
    used=[]
    for i in range(0,9):
        used.append(0)
    for i in range(0,len(l)):
        used[l[i]-1]+=1
        s+=l[i]
    used[s-1]+=1
    if(s<9):
        for i in range(l[-1],10-s):
            l1=l.copy()
            l1.append(i)
            q.append(l1)
    for i in range(1,10):
        if(used[i-1]):
            divide=1
            n=0
            for j in range(0,16):
                n=10*n+i
            for j in range(1,10):
                if(i==j):
                    divide*=fact[used[j-1]-1]
                else:
                    divide*=fact[used[j-1]]
            x=1
            for j in range(2019,2019-len(l),-1):
                x*=j
            x=x*n//divide
            result+=x
print(result%10**16)
x=input()
