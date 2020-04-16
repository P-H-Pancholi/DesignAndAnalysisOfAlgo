#include <iostream>
using namespace std;

void swap(int &a,int &b){
    int temp = b;
    b = a;
    a = temp;
}

int partition(int *A,int p,int r)
//partition the array into 3 parts, greater than pivot , less than pivot and equal to pivot
//returns the index of pivot
{
    int x = A[r];//pivot
    int i = p-1;
    int j = p;
    //loop invariant : prior to each iteration, The elements A[p....i] are the elements less than or equal to 
    //pivot and the elements A[i+1....j-1] are strictly greater than pivot
    while(j < r){
        if(A[j] <= x)
        //Checks, Whether the element is less than pivot, if no simply increament j
        //if yes, then increament i and swap that element in subarray of small elements i.e. A[i+1...j-1]        
        {
            i += 1;
            swap(A[j],A[i]);
        }
        j += 1;
    }
    swap(A[i+1],A[r]);
    return i+1;
}

void quicksort(int *A,int p,int r){
//Uses Divide-and-Conquer technique to Sort Array A
//Running time of O(nlgn)
    if (r > p){
        int q = partition(A,p,r);
        //partitions the Array A and returns the index of the element
        quicksort(A,p,q-1);
        quicksort(A,q+1,r);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    int A[n];
    for(int i = 0; i < n;i++){
        scanf("%d",&A[i]);
    }
    quicksort(A,0,n-1);
    printf("\n");
    for(int i = 0; i < n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
    return 0;
}

