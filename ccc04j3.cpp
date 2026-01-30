#include <iostream>
using namespace std;

int main(){
    int a, b, height; cin >> a >> b >> height;
    for(int i = 0; i < a; i++){
        for(int i = 0; i < 3; i++){
            cout << "*";
            if (i < 2){
                for(int i = 0; i < b; i++){
                    cout << " ";
                }
            }
        }
        cout << "\n";
    }
    for(int i = 0; i < b*2+3; i++){
        cout << "*";
    }
    cout << "\n";
    for(int i = 0; i < height; i++){
        for(int i = 0; i <= b; i++){
            cout << " ";
        }
        cout << "*" << "\n";
    }
}
