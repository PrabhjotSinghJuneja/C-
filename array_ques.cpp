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

int maxTillI(int arr[], int n)
{
    int mx = -1e9;

    for (int i = 0; i < n; i++)
    {
        mx = max(mx, arr[i]);
    }
    return mx;
}

int sumSubArray(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n - 1; j++)
        {
            sum = sum + arr[j];
        }
    }
    return sum;
}

int longestAirthmaticSubarray(int arr[], int n)
{
    int ans = 0;
    int curr = 2;
    int j = 2;
    int pd = arr[1] - arr[0];
    while (j < n)
    {
        if (pd == arr[j] - arr[j - 1])
        {
            curr++;
        }
        else
        {
            pd = arr[j] - arr[j - 1];
            curr = 2;
        }
        ans = max(ans, curr);
        j++;
    }
    return ans;
}
int recordBreaker(int arr[], int n)
{
    if (n == 1)
    {
        cout << "1" << endl;
        return 0;
    }
    arr[n] = -1;
    int count = 0;
    int mx = -1e9;
    for (int i = 0; i < n; i++)
    {

        if (arr[i] > mx && arr[i] > arr[i + 1])
        {
            count++;
        }
        mx = max(mx, arr[i]);
    }
    return count;
}

int firstRepeatingElement(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
    }
    if (count == 0)
    {
        return -1;
    }
    return count;
}

int subArraySum(int arr[], int n, int s)
{
    // for (int i = 0; i < n - 1; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (arr[j] < arr[i])
    //         {
    //             swap(arr, i, j);
    //         }
    //     }
    // }

    int sum = 0, i = 0, j = 0, st = -1, en = -1;

    while (j < n && sum + arr[j] <= s)
    {
        sum = sum + arr[j];
        j++;
    }
    if (sum == s)
    {
        cout << (i + 1) << endl
             << j;
        return 0;
    }
    while (j < n)
    {
        sum += arr[j];
        while (sum > s)
        {
            sum -= arr[i];
            i++;
        }
        if (sum == s)
        {
            st = i + 1;
            en = j + 1;
            break;
        }
        j++;
    }
    cout << st << endl
         << en;
}

void smallestMissingNumber(int arr[], int n)
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
    int j = 0;
    while (j < n)
    {
        if (arr[j] <= 0)
        {
            j++;
        }
        else
        {
            cout << (arr[j] + 1);
            break;
        }
    }
}

int maxSubArraySum(int arr[], int n) // KADANE'S ALGO//
{
    int sum = 0;
    int maxSum = -1e9;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
        }
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

int circularArray(int arr[], int n)
{ // MAXIMUM CIRCULAR SUBARRAY SUM//
    int wrapsum;
    int nonwrapsum;

    nonwrapsum = maxSubArraySum(arr, n);
    int totalsum = 0;
    for (int i = 0; i < n; i++)
    {
        totalsum += arr[i];
        arr[i] = -arr[i];
    }
    wrapsum = totalsum + maxSubArraySum(arr, n);
    cout << max(wrapsum, nonwrapsum);
}

int pairSumProblem(int arr[], int n, int k)
{ // First approach//
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[i] + arr[j] == k)
            {
                cout << i << " " << j;
                break;
            }
        }
    }
}

int pairSumProblem2(int arr[], int n, int k)// More efficient APPROACH//
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
    int low = 0;
    int high = n - 1;

    while (low < high)
    {
        if (arr[low] + arr[high] == k)
        {
            cout << low << " " << high;
            return true;
        }
        else if ((arr[low] + arr[high]) < k)
        {
            low++;
        }
        else if ((arr[low] + arr[high]) > k)
        {
            high--;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;

    int s;
    cin >> s;

    int arr[n];
    input1(arr, n);

    pairSumProblem2(arr, n, s);

    return 0;
}