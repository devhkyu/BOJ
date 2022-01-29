#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    int count = 0;
    cin >> str;
    while(str.size() != 1){
        count++;
        int temp = 0;
        for(char x : str){
            temp += (int)x-48;
        }
        str.clear();
        str.assign(to_string(temp));
    }
    cout << count << endl;
    if(((int)str[0]-48) % 3 == 0)
        cout << "YES";
    else
        cout << "NO";
}