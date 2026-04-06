// This program finds the largest and smallest values in an array.
#include <iostream>
using namespace std;

void findMinAndMax(const int [], int, int*, int*);

int main()
{
    const int SIZE = 10;
    int array[SIZE] = {23, 5, 67, -2, 45, 87, 1, 99, 34, -10};
    int min, max;

    min = max = array[0];

    findMinAndMax(array, SIZE, &min, &max);

    cout << "The min is: " << min << endl;
    cout << "The max is: " << max << endl;

    return 0;
}

// Stores the smallest and largest values in the array arr in the variables
// at addresses min and max.
void findMinAndMax(const int arr[], int size, int* min, int* max)
{
    for (int count = 1; count < size; count++)
    {
        if (arr[count] < *min)
            *min = arr[count];
        else if (arr[count] > *max)
            *max = arr[count];
    }
}