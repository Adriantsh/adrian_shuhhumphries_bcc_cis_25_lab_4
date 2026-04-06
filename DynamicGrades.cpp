// This program sorts a list of grades.
#include <iostream>
#include <iomanip>
using namespace std;

void getScores(double*, int);
void sortScores(double*, int);
void swap(double*, double*);
double calculateAverage(const double*, int);

int main()
{
    int num_grades;
    double avg, *grades = nullptr;

    cout << "How many grades would you like to enter? ";
    cin >> num_grades;

    if (num_grades > 0)
    {
        grades = new double[num_grades];

        getScores(grades, num_grades);
        sortScores(grades, num_grades);
        avg = calculateAverage(grades, num_grades); 

        cout << setprecision(2) << showpoint << fixed;
        cout << "Sorted grades: " << endl;
        for (int count = 0; count < num_grades; count++)
            cout << grades[count] << " ";
        cout << "\nAverage grade: " << avg << endl;
    }
    
    delete [] grades;
    grades = nullptr;
    return 0;
}

// Prompts the user to enter size grades and stores them in arr
void getScores(double* arr, int size)
{
    for (int count = 0; count < size; count++)
    {
        double input = 0;
        cout << "Enter grade #" << count + 1 << ": ";
        cin >> input;
        while (input < 0)
        {
            cout << "Please enter a positive number." << endl;
            cin >> input;
        }
        arr[count] = input;
    }
}

// Sorts an array using bubble sort
void sortScores(double* arr, int size)
{
    for (int maxElem = size; maxElem > 0; maxElem--)
    {
        for (int elem = 0; elem < maxElem - 1; elem++)
            if (arr[elem] > arr[elem + 1])
                swap(arr + elem, arr + elem + 1);
    }
}

// Swaps the values of two variables
void swap(double* a, double* b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}

// Finds the average of an array
double calculateAverage(const double* arr, int size) 
{
    double total = 0;
    for (int index = 0; index < size; index++)
        total += arr[index];

    return total / size;
}
