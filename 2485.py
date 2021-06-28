N=int(input())
array=[]
gaps=[]
count=0
for _ in range(N):
    array.append(int(input()))
array.sort()

for i in range(1,N):
    gaps.append(array[i]-array[i-1])
gaps.sort()

def find_gcd(x,y):
    while y:
        x,y=y,x%y
    return x

num1=gaps[0]
num2=gaps[1]
gcd=find_gcd(num1,num2)
for i in range(2, len(gaps)):
    gcd=find_gcd(gcd, gaps[i])

end=array[N-1]
start=array[0]
gap=((end-start)//gcd)-1
print(gap-(N-2))