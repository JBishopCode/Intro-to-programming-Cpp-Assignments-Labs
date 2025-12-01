#include <iostream>
#include <cstdlib>

using namespace std;

///steps 
// check if there is two arguments and if not tell them how it should be wrote
// check if the number provided is between 1-1000
//get a mid number

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Format is: 'guess.exe <number>" << endl;
        return 1;
    }
    
    int TrueNumber = atoi(argv[1]);

    if (TrueNumber < 1 or TrueNumber > 1000) {
        cout << "Invalid number!" << endl;
        return 1;
    }

    int lower = 1;
    int upper = 1000;
    int mid;

    while (lower < upper) {
        mid = (lower + upper + 1 )/2;

        cout << "Is the number you are thinking of less than " << mid << "? ";

        if (TrueNumber < mid){
            cout << "Y" << endl;
            upper = mid - 1;

        } else {
            cout << "N" << endl;
            lower = mid;
        }
    }

    cout << "Your number is " << lower << "!" << endl;
    
    return 0;
}