#include <stdio.h>

int main(){
    int num=2;
    int count=1;
    int i;
    int flag;
    do{
        while (1){
            flag=0;
            for (i=2; i<num; i++){
                if (num%i==0){
                    flag=1;     //if num is not prime number
                    break;
                }
            }
            if (flag==0){
                break;
            }
            num++;  //if num is not prime number, then increase number to find prime num
        }
        printf("%d번째 소수는 %d\n", count, num);
        count+=1;
        num+=1;

    }while (count<=10);
    return 0;
}