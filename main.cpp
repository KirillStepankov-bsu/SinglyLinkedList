#include <iostream>
#include "list.h"

using namespace std;

int main() {
    List<int> f;
    f.push_back(6);
    f.push_back(9);
    f.push_back(3);
    for(int i = 0; i < f.getSize(); i++){
        cout << f[i] << " ";
    }
    cout << endl;
    f.insert(0,1);
    f.removeAt(1);
    for(int i = 0; i < f.getSize(); i++){
        cout << f[i] << " ";
    }
    cout << endl << f.getSize() << endl;
    f.pop_front();
    for(int i = 0; i < f.getSize(); i++){
        cout << f[i] << " ";
    }
    f.clear();
    for(int i = 0; i < f.getSize(); i++){
        cout << f[i] << " ";
    }
}

