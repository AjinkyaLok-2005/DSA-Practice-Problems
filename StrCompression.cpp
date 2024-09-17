#include <iostream>
#include <vector>
#include <string>

using namespace std;

int compress(vector<char>& chars) {
    int i = 0;
    int ansIndex = 0;
    int n = chars.size();

    while (i < n) {
        int j = i + 1;
        while (j < n && chars[i] == chars[j]) {
            j++;
        }

        // Store the current character
        chars[ansIndex++] = chars[i];

        int count = j - i;

        if (count > 1) {
            // Convert count to string and store characters
            string cnt = to_string(count);
            for (char ch : cnt) {
                chars[ansIndex++] = ch;
            }
        }

        i = j;
    }

    return ansIndex;
}

int main() {
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};

    int newLength = compress(chars);

    // Print the compressed vector
    for (int i = 0; i < newLength; i++) {
        cout << chars[i];
    }
    cout << endl;

    return 0;
}