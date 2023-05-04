#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root){
    int largest = root;        //take the root as the largest
    int left = 2 * root + 1;       //define the left and right node of the largest
    int right = 2 * root + 2;

    if (left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != root){
        swap(arr[root], arr[largest]);
        heapify(arr, n, largest);       //recursively call heapify for if a swap happened
    }
   
  
   
}
  
// implementing heap sort
void heapSort(int arr[], int n){
   for(int i = n/2-1; i >= 0; i--){
        heapify(arr, n, i);
    }
    
    for(int i = n-1; i > 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
    int heap_arr[] = {4,17,3,12,9,6};
    int m = sizeof(heap_arr)/sizeof(heap_arr[0]);
    cout<<"Input array"<<endl;
    displayArray(heap_arr,m);
    heapSort(heap_arr, m);
    cout << "Sorted array"<<endl;
    displayArray(heap_arr, m);

    //for user inputs
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> heap_arr[i];
    }
    
    cout << "Input array" << endl;
    displayArray(heap_arr,n);
    heapSort(heap_arr, n);
    cout << "Sorted array: " << endl;
    displayArray(heap_arr, n);
    return 0;


}