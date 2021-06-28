exp=input()
i=0
num=""
l=[]

while i<len(exp):
    if '0'<=exp[i]<='9':
        num+=exp[i]
    elif exp[i]=='+':
        i+=1
        temp=""
        while i<len(exp) and '0'<=exp[i]<='9':
            temp+=exp[i]
            i+=1
        num=str(int(num)+int(temp))
        i-=1
    elif exp[i]=='-':
        l.append(int(num))
        num=""
    i+=1

if num!="":     
    l.append(int(num))  

result=l[0]
for i in range(1,len(l)):
    result-=l[i]
print(result)
