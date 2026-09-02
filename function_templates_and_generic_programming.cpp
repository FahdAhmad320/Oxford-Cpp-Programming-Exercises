#include <iostream>
using namespace std;

template <typename T>
bool Is_Equal(T number_or_float_1, T  number_or_float_2) {
    return number_or_float_1 == number_or_float_2;
}

int main() {

    //Int test 1
    cout << "25 == 25? " << (Is_Equal(25, 25) ? "Yes" : "No") << endl;

    //Int test 2
    cout << "7 == 11? " << (Is_Equal(7, 11) ? "Yes" : "No") << endl;

    //Float test 1
    cout << "3.2 == 3.2? " << (Is_Equal(3.2, 3.2) ? "Yes" : "No") << endl;

    //Float test 2
    cout << "10.75 == 7.25? " << (Is_Equal(10.75, 7.25) ? "Yes" : "No") << endl;

    return 0;
}