n=int(input())
array=[]
stronly=[]
for i in range(n):
    word=input()
    if word not in stronly:
        stronly.append(word)
        array.append((len(word), word))

array=sorted(array, key=lambda x: (x[0], x[1]))
for word in array:
    print(word[1])