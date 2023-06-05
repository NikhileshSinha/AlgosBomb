#include <stdio.h>

int main()
{
    int n;
    printf("Enter the size of data:\n");
    scanf("%d",&n);
    int a[n], b[2*n];
    printf("Enter the value:\n");
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    int c=0;
    int j=-1;
    int ns=0;
    for(int i=0; i<n; i++){
        if(a[i]==1)
            c++;
        else
            c=0;
        if(c==5 && i+1<n && a[i+1]==1){
            b[++j]=1;
            b[++j]=0;
            ns++;
        }
        else{
            b[++j]=a[i];
        }
        
    }
    
    for(int i=0; i<n+ns; i++){
        printf("%d",b[i]);
    }
    
    return 0;
}
