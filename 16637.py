N=int(input())
exp=input()
data=[]
operator=[]

for i in range(N):
    if '0'<=exp[i]<='9':
        data.append(int(exp[i]))
    else:
        operator.append(exp[i])

max_value=data[0]
length=len(operator)
for i in range(length):
    if operator[i]=='+':
        max_value+=data[i+1]
    elif operator[i]=='-':
        max_value-=data[i+1]
    elif operator[i]=='*':
        max_value*=data[i+1]

def dfs(i,value):
    global max_value
    if i==length:
        max_value=max(max_value, value)
    else:
        if operator[i]=='+':
            dfs(i+1, value+data[i+1])
            dfs(i+1, value+data[i])
        elif operator[i]=='-':
            
        elif operator[i]=='*':
            

dfs(0,data[0])