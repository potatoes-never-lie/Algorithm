s=input()
one=0
zero=0
index=0

while index<len(s):
    if s[index]=='0':
        if index!=len(s)-1 and s[index+1]=='0':
            while index<len(s) and s[index]!='1':
                index+=1
        else:
            index+=1
        zero+=1
    elif s[index]=='1':
        if index!=len(s)-1 and s[index+1]=='1':
            while index<len(s) and s[index]!='0':
                index+=1
        else:
            index+=1
        one+=1

print(min(one,zero))

## 너무 복잡하게 풀었다... 숫자가 바뀌는 순간만 카운팅해주자
## 숫자 바뀌는 순간=구간의 숫자