#include <iostream>
using namespace std;

void Delete(char s[], int pos, int len) {
    int length = 0, i = 0;

    //here we are Calculating the length of the string
    while (s[i] != '\0') {
        length++;
        i++;
    }

    //here we are checking Validate position and length
    if (pos < 0 || pos >= length || len < 0 || pos + len > length) {
        cout << "Invalid position or length!" << endl;
        return;
    }

    //here we are Shift characters to delete the specified portion
    for (int j = pos; j <= length; j++) {
        s[j] = s[j + len];
    }

    cout << "Updated string: " << s << endl;
}

int main() {
    char arr[50];
    
    // Input the string
    cout << "Please enter your string: ";
    cin.getline(arr, 50);

    int position;
    // Input the starting position for deletion
    cout << "Please enter the position from where you want to start deleting: ";
    cin >> position;

    int length;
    // Input the length of the substring to delete
    cout << "Please enter the length to delete: ";
    cin >> length;

    // Call the Delete function
    Delete(arr, position, length);

    return 0;
}
