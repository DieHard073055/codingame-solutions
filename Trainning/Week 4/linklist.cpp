#include <iostream>

using namespace std;

class list_element{
    public:
        list_element(int n = 0, list_element* ptr = 0):
            d(n), next(ptr){}
        int d;
        list_element* next;
};

class list{
    public:
        list():head(0), cursor(0){}
        void prepend(int n){
            if(head == 0){
                cursor = head = new list_element(n, head);
            }else{
                head = new list_element(n, head);
            }
        }
        int get_element(){return cursor->d;}
        void advance(){cursor=cursor->next;}
        void print(){
            list_element* h = head;
            while(h != 0){
                cout << h->d << ", ";
                h = h->next;
            }
            cout << "###" << endl;
        }
        
    private:
        list_element * head;
        list_element * cursor;
};

int main(){
    list a, b;
    
    for(int i = 0; i < 10; i++){
        a.prepend(i * 4 + 90 / 3);
    }
    a.print();
    return 0;
}

