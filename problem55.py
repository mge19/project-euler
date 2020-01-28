def plus_reverse(n):
    s=str(n)
    s_rev=str()
    for i in range(0,len(s)):
        s_rev+=s[len(s)-1-i]
    n_rev=int(s_rev)
    return n+n_rev
def palindromic(n):
    s=str(n)
    for i in range(0,int(len(s)/2)):
        if(s[i]!=s[len(s)-1-i]):
            return False
    return True
result=0
for i in range(1,10000):
    number=i
    x=0
    while(x<50):
        number=plus_reverse(number)
        x+=1
        if(palindromic(number)):
            break
    if(x==50 and palindromic(number)==False):
        result+=1
print(result)
x=input()
