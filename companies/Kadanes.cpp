// contraints n <= 10

#include <iostream>

using namespace std;

int kadane(int arr[], int n)
{

    // int x[10];

    // x[0] = arr[0];
    // int finalAns = arr[0];
    // for(int i=1; i<n; i++) {
    // 	x[i] = max(arr[i], arr[i]+x[i-1]);
    // 	if(x[i] > finalAns) {
    // 		finalAns = x[i];
    // 	}
    // }

    int finalAns = arr[0];
    int x = arr[0];
    for (int i = 1; i < n; i++)
    {
        x = max(arr[i], arr[i] + x);
        if (x > finalAns)
        {
            finalAns = x;
        }
    }

    return finalAns;
}

int main()
{

    int arr[] = {-2, -3, -4, -5};
    int n = sizeof(arr) / sizeof(int);

    cout << kadane(arr, n) << endl;

    return 0;
}