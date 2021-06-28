'''
s=input()
blanklist=[]
count=0
for i in range(len(s)):
    if s[i]==' ':
        blanklist.append(i)

for i in blanklist:
    if i>0 and i<len(s)-1:
        count+=1

if len(blanklist)==1 and blanklist[0]==0:
    print(count)
else:
    print(count+1)
'''

a = input().split()     ##list 로 받는다. 
print(a)
print(len(a))