#include<bits/stdc++.h>

using namespace std;
void Merge(int *A, int l, int m, int r)
{
	int nl= m - l +1;
	int nr = r - m;
	int left[nl+1], right[nr+1];
	left[nl]= 123456798, right[nr] = 123456798;
	
	for(int i =0 ; i < nl; i++)
	{
		left[i] = A[l+ i];	
	}	
	for(int j =0 ; j < nr; j++)
	{
		right[j] = A[m+j+1];	
	}
	
	int i = 0, j = 0;
	for (int k = l; k <= r; k++) {
         if (left[i] <= right[j]) {
             A[k] = left[i];
             i++;
         } else {
             A[k] = right[j];
             j++;
         }
     }
}
void MergeSort(int *A, int l, int r)
{
	if(l < r)
	{
		int m = (l+r)/2;
		MergeSort(A, l, m);
		MergeSort(A, m+1, r);
		Merge(A, l, m, r);	
	}
}

void printArray(int *A, int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}
 
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Given array is \n";
    printArray(arr, arr_size);
 
    MergeSort(arr, 0, arr_size - 1);
 
    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
   

   return 0;
}









