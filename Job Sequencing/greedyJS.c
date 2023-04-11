#include<stdio.h>
void main(){
    int n, s, sub=0;
    printf("Enter the number of jobs: ");
    scanf("%d",&n);
    int jb[n], p[n], dl[n];
    for(int i=0; i<n; i++){
        printf("Profit of job%d : ",i);
        scanf("%d",&p[i]);
        printf("Dealline of job%d : ", i);
        scanf("%d", &dl[i]);
        jb[i] = i+1;
    }

    //Printing the input firts
    printf("\n\t\tINPUT\n\n");
    printf("JOBS\tPROFIT\tDEALLINE\n");
    for(int i=0; i<n; i++){
        printf("%d\t%d\t%d\n",jb[i], p[i], dl[i]);
    }

    //Sorting values by profit (decending order)
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if (p[i] > p[j]){
                s = p[i];
                p[i] = p[j];
                p[j] = s;

                s = jb[i];
                jb[i] = jb[j];
                jb[j] = s;

                s = dl[i];
                dl[i] = dl[j];
                dl[j] = s;
            }
        }
    }

    //Printing the sorted values
    printf("\n\t\tAfter sorting profit\n\n");
    printf("JOBS\tPROFIT\tDEALLINE\n");
    for (int i = 0; i < n; i++){
        printf("%d\t%d\t%d\n", jb[i], p[i], dl[i]);
    }

    printf("**NOTE: Here 'sub' is the variable that provides information about the total number of past days.\nWe are subtracting 'sub' to deadline array -> dl[] which help us to decide that current Job\ncan be done in remaning days. And as we select new Job, we are incrementing the 'sub'");
    printf("\n\n\t\tCummelative profits\n\n");
    printf("Jobs\tProfit\t\tDays used\n");
    //MAIN CODE STARTS
    int sum =0;
    for(int i = 0; i <n; i++){
        if(dl[i]-sub>0){
            sum += p[i];
            printf("%d\t:%d\t\t%d\n",jb[i],p[i],sub);
            //sub = dl[i];
            sub++;
        }
    }
    printf("\n\nTotal Profit: %d",sum);
    //MAIN CODE ENDS
}
