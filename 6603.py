array=[]
visited=[False]*13
while True:
    l=list(map(int, input().split()))
    if l[0]!=0:
        array.append(l)
    else:
        break

def dfs(i, start, count):
    if count==6:
        for j in range(1,len(array[i])):
            if visited[j]==True:
                print(array[i][j],end=' ')
        print("")
        return
    for j in range(start,len(array[i])):
        visited[j]=True
        dfs(i,j+1, count+1)
        visited[j]=False

for i in range(len(array)):
    dfs(i,1,0)
    print("")
