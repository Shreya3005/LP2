#include <iostream>
using namespace std;
void selectionSort()
{
int min_idx, size;
cout << "Enter size of array:" << endl;
cin >> size;
int arr[size];
for (int i = 0; i < size; i++)
{
cout << "Enter number:" << endl;
cin >> arr[i];
}
for (int i = 0; i < size - 1; i++)
{
min_idx = i;
for (int j = i + 1; j < size; j++)
if (arr[j] < arr[min_idx])
min_idx = j;

int temp = arr[min_idx];
arr[min_idx] = arr[i];
arr[i] = temp;
}
cout << "Array is:" << endl;
for (int i = 0; i < size; i++)
cout << arr[i] << " ";
cout << endl;
}


int main()
{

cout << "Selection sort "<<endl;

selectionSort();
return 0;
}
