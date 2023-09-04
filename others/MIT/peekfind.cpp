#include <iostream>

using namespace std;

int peek(int A[],int start,int end)
//peek function is a recursive function that finds a "peek", if exists
//A element is called a peek, if the neighbours of that element are
//smaller than or equal to that element
//
//
//Time complexity : O(log(n)), Time complexity without recurrence : O(n)


{
	int mid;
	mid = (start + end) / 2;

	// if a number in the left is greater, then consider 
	// the left subarray and eliminate remaining
	if ((mid-1) >= start && A[mid] < A[mid-1]){
		return peek(A,start,mid-1);
	}

	//if a number in the right is greater, then consider
	//the right subarray and eliminate remaining
	else if ((mid+1) <= end && A[mid] < A[mid+1]){
		return peek(A,mid+1,end);
	}
	//The middle element is the peek element or it's the last or first element
	else{
		return A[mid];
	}
}

int main(){
	int n;
	cin >> n;
	int Arr[n];
	for(int i = 0;i < n;i++){
		cin >> Arr[i] ;
	}
	cout << peek(Arr,0,n-1);


}
