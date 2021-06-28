n=int(input())
str=input()
result=n+1
count=0

for x in str:
    if x=='L':
        count+=1

result-=(count/2)
if result>n:
    print(n)
else:
    print(int(result))



