#include <iostream>
using namespace std;

void input1(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void display1(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int linearSearchArray(int arr[], int x, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int n, int x)
{
    int s = 0;
    int e = n;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (mid == x)
        {
            return mid;
        }
        else if (arr[mid] > x)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
}

void selelctionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                swap(arr, i, j);
            }
        }
    }
}

int choclate(int money, int price, int wrap)
{
    if (money < price)
        return 0;
    ;

    int choc = money / price;

    choc = choc + (choc - 1) / (wrap - 1);
    return choc;
}

void bubbleSort(int arr[], int n)
{
    int counter = 1;
    while (counter < n)
    {
        for (int i = 0; i < n - counter; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr, i, (i + 1));
            }
        }
            counter++;
    }
}

int insertionSort(int arr[], int n){
    for(int i = 0;i<n;i++){
        int current = arr[i];
        int j = i-1;
        while(arr[j]>current && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
}


int main()
{
    int n;
    cin >> n;

    int arr[n];
    input1(arr, n);

    // int x;
    // cin >> x;

    insertionSort(arr, n);

    display1(arr, n);

    return 0;
}