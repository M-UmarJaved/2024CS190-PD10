#include <iostream>
using namespace std;

// Find the minimum value in array
int findMin(int arr[], int size) 
{
    int minVal = arr[0];
    int i = 1;
    while (i < size) {
        if (arr[i] < minVal) 
        {
            minVal = arr[i];
        }
        i++;
    }
    return minVal;
}

// Find the maximum value in array
int findMax(int arr[], int size) 
{
    int maxVal = arr[0];
    int i = 1;
    while (i < size) 
    {
        if (arr[i] > maxVal) 
        {
            maxVal = arr[i];
        }
        i++;
    }
    return maxVal;
}

// Check that all elements are unique
bool areElementsUnique(int arr[], int size, int minVal) 
{
    bool seen[size] = {false}; // Track seen numbers
    int i = 0;
    while (i < size) 
    {
        int index = arr[i] - minVal; // Map element
        if (index < 0) 
        {
            return false; // Out of range
        } 
        else
        {
            if (index >= size) 
            {
                return false; // Out of range
            } else
            {
                if (seen[index]) 
                {
                    return false; // Duplicate found
                } 
                else 
                {
                    seen[index] = true;
                }
            }
        }
        i++;
    }
    return true;
}

// Check of consecutive sequence
bool canFormConsecutiveSequence(int arr[], int size) 
{
    int minVal = findMin(arr, size);
    int maxVal = findMax(arr, size);

    if (maxVal - minVal + 1 != size) 
    {
        return false;
    } 
    else 
    {
        if (areElementsUnique(arr, size, minVal)) 
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
}

int main() 
{
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];

    cout << "Enter " << size << " elements of the array: ";
    int i = 0;
    while (i < size) 
    {
        cin >> arr[i];
        i++;
    }

    // CHeck of consectiuve sequnce
    if (canFormConsecutiveSequence(arr, size)) 
    {
        cout << "True" << endl;
    } 
    else 
    {
        cout << "False" << endl;
    }

}
