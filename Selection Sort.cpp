#include <iostream>
using namespace std;

void selectionS(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int min_ind = i;

        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[min_ind])
            {
                min_ind = j;
            }
        }
        if (min_ind != i)
        {
            swap(arr[i], arr[min_ind]);
        }
    }
    cout << "Sorted Array: ";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << "UNSORTED ARRAY: ";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    selectionS(arr, n);

    return 0;
}
