#include <iostream>
#include <string>
using namespace std;

int calculateRotations(string directions[], int size) 
{
    int netRotation = 0;
    int i = 0;

    while (i < size) 
    {
        if (directions[i] == "right") 
        {
            netRotation += 90;
        } else {
            if (directions[i] == "left") 
            {
                netRotation -= 90;
            }
        }
        i++;
    }

    if (netRotation < 0) 
    {
        netRotation = -netRotation;
    }

    return netRotation;
}

int main() 
{
    int size;

    cout << "Enter the number of directions: ";
    cin >> size;

    string directions[size];

    cout << "Enter the directions (\"left\" or \"right\"): ";
    int i = 0;
    while (i < size) 
    {
        cin >> directions[i];
        i++;
    }

    int result = calculateRotations(directions, size);
    cout << "Number of full 360 degree rotations: " << (result / 360) << endl;

}
