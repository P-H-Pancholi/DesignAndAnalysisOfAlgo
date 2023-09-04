#include <iostream>
using namespace std;

void countingSort(int *A,int k,int *b,int size){
    int C[k+1];
    for(int i = 0; i <= k;i++){
        C[i] = 0; 
    }
    for(int i = 0; i < size; i++){
        C[A[i]] += 1;
    }
    //Now the array C[0...k] contains no of times a element i is in Array A
    for(int i = 1; i <= k;i++){
        C[i] += C[i-1];
    }
    //In the Array C[0....k], the element C[i] contains the no of elements less than i.
    //If we assume the all elements are distinct than the position of i element in 
    //Output array is determined by C[i]
    for(int i = size - 1; i >= 0; i--){
        b[C[A[i]]-1] = A[i] ;
        C[A[i]] -= 1;
    }
    //Now we place The element in correct order 
    //I have started the loop in decending order so that the sort remains stable i.e.
    //The if two elements are same than the element that appears first in the original 
    //sort remains first in the sorted Array b
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    int A[n];
    int B[n];
    for(int i = 0; i < n; i ++){
        scanf("%d",&A[i]);
    }
    countingSort(A,6,B,n);
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("%d ",B[i]);
    }
    printf("\n");
    return 0;
}
