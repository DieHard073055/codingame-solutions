#include <iostream>
#include <string>
#include "Person.h"


using namespace std;

int main(){
    Person * p = new Person();
    Person * p2 = new Person("Yolo", "Im so pro!");
    
    cout << p->getName() << endl;
    cout << p2->getName() << endl;
    string so("initial String");
    
    cout << so << endl;
    
    delete(p);
    return 0;
}