// Example program
#include <iostream>
#define _SIZE 5
using namespace std;

/*
    pop
    push
    empty
    top
    size
    swap
*/

class Stack {
    int top = -1;
    int size = _SIZE;
    int* buffer = new int[size];

    bool full() const {
        return (top == size - 1);
    }

public:
    Stack() = default;
    Stack(const Stack& st) : top(st.top), size(st.size),
        buffer(new int[size])
    {
        for (int i = 0; i <= top; i++)
            buffer[i] = st.buffer[i];
    }
    Stack& operator= (const Stack& st) {
        if (this != &st) {
            size = st.size;
            buffer = new int[size];
           
            for (int i = 0; i < st.top; i++)
                buffer[i] = st.buffer[i];
         
            top = st.top;
        }
        return *this;
    }

    bool empty() const {
        return (top == -1);
    }

    bool pop() {
        if (empty()) return false;
        top--;
        return true;
    }
    int get_size() const {
        return top + 1;
    }
    int get_top() const {
        if (empty()) exit(1);
        return buffer[top];
    }

    bool push(int element) {
        if (full()) {
            int* new_buffer = new int[size * 2];
            if (!new_buffer) return false;
            for (int i = 0; i <= top; i++)
                new_buffer[i] = buffer[i];
            size *= 2;
            delete[] buffer;
            buffer = new_buffer;
        }
        buffer[++top] = element;
        return true;
    }
    void swap(Stack& a, Stack& b) {
        Stack c = a; 
        a = b;
        b = c;
    }

};

int main()
{
    Stack st1;
    Stack st2;
    st1.push(1);
    st1.push(2);
    st2.push(3);
    st2.push(4);
    st2.push(0);
    st2.push(7);
    st2.push(9);
    st2.push(8);
   // swap(st1, st2);
 //   cout<<st1.get_top() << ' ' << st1.get_size() << ' ' << st2.get_size() << endl;
    st2 = st1;
    cout<<st2.get_size() << endl;

    return 0;
}

