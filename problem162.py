result=4;
for i in range(4,17):
    result+=15*16**(i-1)-43*15**(i-1)+41*14**(i-1)-13**i;
print(str(hex(result)).upper()[2:])
