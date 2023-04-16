#include<stdio.h>
void main(){
    int item, maxWeight, a, weightAdded = 0, totalCost = 0;
    printf("Enter the no. of items:\n"); 
    scanf("%d", &item);
    printf("Enter the max weight of sack:\n");
    scanf("%d", &maxWeight);
    int weight[item], cost[item];
    double ratio[item];
    
    //Loop for taking weight and cost values and calculating ratio 
    for(int i = 0; i < item; i++){
        printf("\nEnter weight of %d: ", i+1);
        scanf("%d", &weight[i]);
        printf("Enter cost of %d: ", i+1);
        scanf("%d", &cost[i]);
        ratio[i] = cost[i] / weight[i];
    }

    //Loop will execute till the weight is added to the bag is less than total weight limit
    while(weightAdded < maxWeight){
        double max = ratio[0];
        a=0;
        for(int i = 1; i < item; i++){
            if(ratio[i] > max){
                max = ratio[i];
                a=i;
            }
        }
        //Full quantity
        if (weight[a] <= maxWeight - weightAdded){
            weightAdded += weight[a];
            totalCost += cost[a];
            printf("Element %d is added, (Quantity:FULL)",a+1);
        }
        //Partial quantity
        else{
            int restWeight = maxWeight - weightAdded;
            totalCost += restWeight * ratio[a];
            printf("Element %d is added, (Quantity:PARTIAL)",a+1);
            weightAdded += restWeight;
        }
        weight[a] = 0;
        cost[a] = 0;
        ratio[a] = 0;
    }
    printf("Total cost: %d\n", totalCost);
}
