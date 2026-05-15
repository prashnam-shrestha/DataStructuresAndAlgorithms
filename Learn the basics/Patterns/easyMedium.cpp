#include <iostream>
using namespace std;

int reverseNum(int num) {
    if (num == 1) {
        return 0;
    }
    return 1;
}

int main() {
    int n ;
    cin >> n;

    // 1
    // for (int i = 0; i < 5; i++) {
    //     cout << "*****" << "\n";
    // }

    // 2
    // for (int i = 0; i < 5; i++) {
    //     for (int j = 0; j <= i; j++) {
    //         cout << "*";
    //     }
    //     cout << "\n";
    // }

    // 3
    // for (int i = 1; i <= 5; i++) {
    //     for (int j = 1; j <= i; j++) {
    //         cout << j;
    //     }
    //     cout << "\n";

    // }

    // 4
    // for (int i = 1; i <= 5; i++) {
    //     for (int j = 1; j <= i; j++) {
    //         cout << i;
    //     }
    //     cout << "\n";
    // }
    
    // 5
    // for (int i = 5; i > 0; i--) {
    //     for (int j = 0; j < i; j++) {
    //         cout << "*";
    //     }
    //     cout << "\n";
    // }

    // 6
    // for (int i = 5; i > 0; i--) {
    //     for (int j = 1; j <= i; j++) {
    //         cout << j;
    //     }

    //     cout << "\n";
    // }


    // 7
    // 1 3 5 7 9
    // for (int i = 0; i < 5; i++) {

    //     for (int j = 4; j > i; j--) {
    //         cout << " ";
    //     }

    //     for (int k = 0; k < (2*i+1); k++) {
    //         cout << "*";
    //     }
    //     cout << "\n";
    // }

    // 8
    // for (int i = 4; i >= 0; i--) {

    //     for (int k = i; k < 4; k++) {
    //         cout << " ";
    //     }
    //     for (int j = 0; j < (2*i+1); j++) {
    //         cout << "*";
    //     }
    //     cout << "\n";
    // }

    // 9
    // for (int i = 0; i < 5; i++) {
    //     // space
    //     for (int j = i; j < 4; j++ ) {
    //         cout << " ";
    //     }
    //     // stars
    //     for (int k = 0; k < (2*i+1); k++) {
    //         cout << "*";
    //     }
    //     cout << "\n";
    // }

    // for (int i = 0; i < 5; i++) {
    //     // space 
    //     for (int j = 0; j < i; j++) {
    //         cout << " ";
    //     }

    //     for (int k = (2*i+1); k <= 9; k++) {
    //         cout << "*";
    //     }
    //     cout << "\n";
    // }

    // 10
    // int n;
    // cin >> n;
    // for (int i = 0; i < n; i++) {
    //     int num = (n+1)/2;
    //     for (int j = 0; j < (num - abs(num - (i+1))); j++ ) {
    //         cout << "*";
    //     }
    //     cout << "\n";
    // }

    //11
    // int numColumn = 1;
    // for (int i = 0; i < 5; i++) {

    //     int numRow = numColumn;
        
    //     for (int j = 0; j <= i; j++) {
    //         // print
    //         cout << numRow;
    //         numRow = reverseNum(numRow);
    //     }

    //     numColumn = reverseNum(numColumn);

    //     cout << "\n";
    // }

    // 12

    // for (int i = 0; i < n; i++) {

    //     for (int j = 0; j <= i; j++) {
    //         cout << j + 1; 
    //     }
    //     for (int k = 0; k < 2 * (n - (i+1)); k++) {
    //         cout << " ";
    //     }
    //     for (int l = 0; l <= i; l++) {
    //         cout << (i + 1) - l;
    //     }
    //     cout << "\n";
    // }

    // 13

    // int num = 1;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j <= i; j++) {
    //         cout << num;
    //         num++;
    //     }
    //     cout << "\n";
    // }

    // 14
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j <= i; j++) {
    //         char alpha = 65 + j;
    //         cout << alpha;
    //     }
    //     cout << "\n";
    // }

    // 15
    
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j <= ((n-1) - i); j++ ) {
    //         char alpha = 65 + j;
    //         cout << alpha;
    //     }

    //     cout << "\n";
    // }

    // 16
    // char alpha = 65;
    // for (int i = 0; i < n; i++) {
    //     alpha = 65 + i;
    //     for (int j = 0; j <= i; j++) {
    //         cout << alpha;
    //     }
    //    cout << "\n";
    // }

    // 17
    // for (int i = 0; i < n; i++) {

    //     for (int k = 0; k < (n-i); k++) {
    //         cout << " ";
    //     }

    //     for (int j = 0; j < (2*i + 1); j++) {
    //         char x;
    //         if (j > i) { x = (65 + i)- (j-i); }
    //         else { x = 65 + j; }

    //         cout << x;
    //     }
    //     cout << "\n";
        
    // }       

    // 18

    // for (int i = 0; i < n; i++) {

    //     for (int j = 0; j <= i; j++) {
    //         char x = 65 + (n-1) - i + j;
    //         cout << x << " ";
    //     }
    //     cout << "\n";
    // }

    // 19

    // for (int i = 0; i < n; i++) {

    //     int stars = n - i;
    //     int spaces = 2 * i;

    //     for (int j = 0; j < stars; j++) {
    //         cout << "*";
    //     }
    //     for (int k = 0; k < spaces; k++) {
    //         cout << " ";
    //     }

    //     for (int j = 0; j < stars; j++) {
    //         cout << "*";
    //     }
    //     cout << "\n";
    // }

    // for (int i = 0; i < n; i++) {

    //     int stars = i;
    //     int spaces = 2*(n- i - 1);

    //     for (int j = 0; j <= stars; j++) {
    //         cout << "*";
    //     }
    //     for (int k = 0; k < spaces ; k++) {
    //         cout << " ";
    //     }

    //     for (int j = 0; j <= stars; j++) {
    //         cout << "*";
    //     }
    //  cout << "\n";
    // }   

    // 20

    // for (int i = 0; i < (2*n); i++) {
    //     int stars;
    //     int spaces;
    //     if (i >= n) {
    //         stars = 2*n - i;
    //     }
    //     else {
    //         stars = i;
    //     }
    //     spaces = (2*n) - 2* stars;

    //     for (int j = 0; j < stars; j++) {
    //         cout << "*";
    //     }
    //     for (int k = 0; k < spaces; k++) {
    //         cout << " ";
    //     }
    //     for (int j = 0; j < stars; j++) {
    //         cout << "*";
    //     }
    //     cout << "\n";
    // }

    // 21

    // for (int i = 0; i < n; i++) {
    //     int stars;
    //     int spaces;

    //     if (i == 0 || i == (n-1)) {
    //         for (int j = 0; j < n; j++) {
    //             cout << "*";
    //         }
    //         cout << "\n";
    //         continue;
    //     }
    //     stars = 1;
    //     spaces = n - 2* stars;

    //     for (int j = 0; j < stars; j++) {
    //         cout << "*";
    //     }

    //     for (int k = 0; k < spaces; k++) {
    //         cout << " ";
    //     }

    //     for (int j = 0; j < stars; j++) {
    //         cout << "*";
    //     }
    //     cout << "\n";

    // }

    // 22
    for (int i = 0; i < (2* n) -1; i++) {
        for (int j = 0; j < n; j++) {
            int num;
            if (i)
            cout << "*";
        }
        cout << "\n";
    }
  






    return 0;

}