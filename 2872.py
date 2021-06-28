n=int(input())
books=[]
for _ in range(n):
    books.append(int(input()))

pivot=books[0]
smaller=[x for x in books if x<pivot]
result=len(smaller)
bigger=[x for x in books if x>pivot]
result+=(len(bigger)+1)

print(result)

