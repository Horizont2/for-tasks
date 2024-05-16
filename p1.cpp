#include <iostream>
using namespace std;

int main() {
    int lower,upper,number;
    cout<<"Введіть нижню межу діапазону: ";
    cin>>lower;
    cout<<"Введіть верхню межу діапазону: ";
    cin>>upper;
    if (lower >= upper) {
        cout<<"Нижня межа повинна бути менше верхньої. введіть їх знову"<<endl;
        return 1;
    }
    cout<<"Введіть число: ";
    cin>>number;
    for (;;) {
        if (number >= lower && number <= upper) {
            cout<< "Число "<< number<<" потрапляє в діапазон "<<lower<<", "<<upper<<endl;
            break;
        } 
        else{
            cout<<"Число не потрапило в діапазон. введіть число знову: ";
            cin>>number;
        }
    }
    return 0;
}
