#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char destination, char temporary) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }
    towerOfHanoi(n - 1, source, temporary, destination);
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    towerOfHanoi(n - 1, temporary, destination, source);
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;

    cout << "The sequence of moves is: " << endl;
    towerOfHanoi(n, 'A', 'C', 'B'); 
}