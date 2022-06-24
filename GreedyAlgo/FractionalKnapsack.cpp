// Given the weights and values of n items, we need to put these items 
// in a knapsack of capacity W to get the maximum total value in the knapsack.

// Input:
// Items as (value, weight) pairs
// arr[] = {{60, 10}, {100, 20}, {120, 30}}
// Knapsack Capacity, W = 50;

// Output:
// Maximum possible value = 240
// by taking items of weight 10 and 20 kg and 2/3 fraction
// of 30 kg. Hence total price will be 60+100+(2/3)(120) = 240

#include <bits/stdc++.h>
using namespace std;


struct Item{
    int value,weight;

    Item(int value, int weight){
        this->value = value;
        this->weight = weight;
    }
};

bool cmp(struct Item a,struct Item b)
{
   double r1 = (double)a.value/ (double)a.weight;
   double r2 = (double)b.value/ (double)b.weight;
   return r1>r2;
};

 

double fractionalKnapsack(int W, struct Item arr[], int n)
{
    //    sorting Item on basis of ratio
    sort(arr, arr + n, cmp);
 
    //    Uncomment to see new order of Items with their
    //    ratio

 
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i].value << "  " << arr[i].weight << " "<< ((double)arr[i].value / arr[i].weight) <<endl;
    // }

   
    double finalvalue = 0.0;

    for(int i=0;i<n;i++){
        if(arr[i].weight<=W){
            W = W-arr[i].weight;
            finalvalue = finalvalue+arr[i].value;
        }

        else{
            finalvalue = finalvalue + arr[i].value * ((double)W / (double)arr[i].weight);
            break;
        }
    }
    return finalvalue;
}




int main()
{
    int W = 50; //    Weight of knapsack
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};

    int n = sizeof(arr) / sizeof(arr[0]);

    // Function call
    cout << "Maximum value we can obtain = "<< fractionalKnapsack(W, arr, n);
    return 0;
}