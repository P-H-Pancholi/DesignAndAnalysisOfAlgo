#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;


void swap(int &a,int &b){
	int c = a;
	a = b;
	b = c;
}

int partition(int* A,int start,int end,int &pCount){
	int p = A[start];
	int j = start+1;
	for(int i = start+1;i <= end;i++){
		if(A[i] < p){
			swap(A[j],A[i]);
			j += 1;
		}
		pCount += 1;
	}
	swap(A[start],A[j-1]);
	return (j-1);
}

void QuickSort(int* A,int start,int end,int &pCount){
	cout << start << " " << end << endl;
	if(end-start <= 0){
		return;
	}else{
		srand(time(NULL));
		int i = (rand() % (end-start+1) + start);
		cout << "The value of index is " << i << endl;
		swap(A[i],A[start]);
		int p = partition(A,start,end,pCount);
		QuickSort(A,start,p-1,pCount);
		QuickSort(A,p+1,end,pCount);
	}
}


int main(){
	int A[10000];
	int Count = 0;
	ifstream Myfile("QuickSort.txt");
	int number;
	int i = 0;
	while (Myfile.eof() == false) {
		Myfile >> number;
		A[i] = number;
		i += 1;
    }
	QuickSort(A,0,(10000-1),Count);
	cout << endl;
	cout << "The number of comparison " << Count << endl; 
	return 0;


}
