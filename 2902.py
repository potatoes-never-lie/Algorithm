s=input()
l=s.split('-')
res=""
for char in l:
    for j in range(len(char)):
        if 'A'<=char[j]<='Z':
            res+=char[j]
print(res)