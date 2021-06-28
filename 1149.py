n=int(input())
rgb=[[0]*(n+1) for _ in range(3)]

for i in range(1,n+1):
    r, g, b=map(int, input().split())
    rgb[0][i], rgb[1][i], rgb[2][i]=r, g, b

for i in range(2,n+1):
    rgb[0][i]+=min(rgb[1][i-1], rgb[2][i-1])
    rgb[1][i]+=min(rgb[0][i-1], rgb[2][i-1])
    rgb[2][i]+=min(rgb[0][i-1], rgb[1][i-1])

print(min(rgb[0][n], rgb[1][n],rgb[2][n])