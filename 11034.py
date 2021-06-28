while True:
    try:
        a, b, c = map(int, input().split())
        result = 0

        while b-a != 1 or c-b != 1:
            if b-a > c-b:
                c = b
                b = a+1
            else:
                a = b
                b = a+1
            result += 1
        print(result)
    except EOFError:
        break


    ## 간단한 사칙연산으로도 가능. 처음 아이디어가 맞았음. 괜히 복잡하게 생각하지 말것.
    