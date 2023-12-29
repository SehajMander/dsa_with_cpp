#include<iostream>
#include<vector>
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

            // Old character store krlo
            chars[ansIndex++] = chars[i];

            int count = j - i;

            if (count > 1) {
                // Converting counting into string and saving in answer
                string cnt = to_string(count);
                for (char ch : cnt) {
                    chars[ansIndex++] = ch;
                }
            }

            // Moving to new/different character
            i = j;
        }
        return ansIndex;
}

int main(){
    int n;
    cout<<"Enter the size of the vector  string : ";
    cin>>n;

    vector<char> chars;
    char x;
    cout<<"Enter the character elements of the array : ";
    for(int i=0; i<n; i++){
        cin>>x;
        chars.push_back(x);
    }

    cout<<"New compressed string vector is : "<<compress(chars)<<endl;

    return 0;
}