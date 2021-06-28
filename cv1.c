#include <stdio.h>
#include <math.h>

int main(void){
    int i,j,val;
    int m,K,D;
    int c=0;
    scanf("%d %d %d",&m,&K,&D);
    int x[D];
    for (i=0; i<D; i++){
        scanf("%d",&x[i]);
    }
    double y[m];
    double o[K];
    double a[m][1];
    double b[K][1];
    for (i=0; i<m; i++){
        val=0;
        for (j=0; j<D; j++){
            val+=(a[i][j]*x[j]);
        }
        y[i]=(double)1/(1+exp(val*(-1)));
    }
    for (i=0; i<K; i++){
        val=0;
        for (j=0; j<m; j++){
            val+=(b[i][j]*y[j]);
        }
        o[i]=(double)1/(1+exp(val*(-1)));
    }
    for (i=0; i<K; i++){
        if (c<o[i]){
            c=o[i];
        }
    }
    print(c);
}