#include <iostream>
using namespace std;

int main(){
    char* temp = "hello";
    // cin >> temp ;
    
    for (int i=0;i>=0;i++){
        if (temp[i] == '\0')
        break;

        cout << temp[i]<< endl;
    }

    int j=0;
    while(true){
    if (temp[j] == '\0'){
            break;
        }

        cout << temp[j++] << endl;
    }

    return 0;
}


// The code you provided has a couple of issues:

// Uninitialized Pointer: You declare a character pointer temp, but you don't allocate any memory for it. So when you try to read input into temp using cin >> temp, it leads to undefined behavior because temp is pointing to some arbitrary memory location.
// Infinite Loop: In both the for loop and the while loop, your loop condition is i>=0 and true, respectively. This condition will never be false, resulting in an infinite loop.
// Here's a corrected version of your code:

// cpp
// Copy code
// #include <iostream>
// using namespace std;

// int main() {
//     const int MAX_SIZE = 100; // Define a maximum size for the input
//     char temp[MAX_SIZE]; // Declare an array to store the input

//     cin >> temp;

//     // Output characters using a for loop
//     for (int i = 0; temp[i] != '\0'; i++) {
//         cout << temp[i] << endl;
//     }

//     // Output characters using a while loop
//     int j = 0;
//     while (temp[j] != '\0') {
//         cout << temp[j++] << endl;
//     }

//     return 0;
// }
// In this corrected version:

// I've declared temp as an array of characters with a maximum size (MAX_SIZE). This avoids the issue of an uninitialized pointer.
// The loops now iterate until they encounter the null terminator '\0', ensuring they don't enter into infinite loops.
// Also, cout statements are corrected to print characters without extra line breaks, as endl adds a newline character which might make the output look different than expected.