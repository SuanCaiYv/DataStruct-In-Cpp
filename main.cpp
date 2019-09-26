#include <bits/stdc++.h>
using namespace std;
/*
 * 堆栈的Cpp实现
 * Author:SuanCaiYv
 * Time:2019/9/26/21:33
 */
template <typename T>
class Stack//同双向队列,用一个母节点保存信息
{
private:
    T value;
    Stack *next = nullptr;
    Stack *prev = nullptr;
    Stack *tail = nullptr;
    int Size = 0;
public:
    void push(T t);
    void pop();
    T top();
    int size();
    bool empty();
    Stack();
};
template<typename T>
void Stack<T>::push(T t)
{
    Stack *curr = new Stack;
    curr->next = nullptr;
    curr->value = t;
    curr->prev = this->tail;
    this->tail->next = curr;
    this->tail = curr;
    ++this->Size;
}
template<typename T>
int Stack<T>::size()
{
    return this->Size;
}
template<typename T>
void Stack<T>::pop()
{
    if (this->Size == 0) return ;
    Stack *temp = this->tail;
    this->tail = this->tail->prev;
    delete temp;
    --this->Size;
}
template<typename T>
T Stack<T>::top()
{
    return this->tail->value;
}
template<typename T>
bool Stack<T>::empty()
{
    return this->Size == 0;
}
template<typename T>
Stack<T>::Stack()
{
    this->tail = this;
}

int main()
{
    Stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);
    while (!s.empty()) {
        cout << s.top() << ' ' << s.size() << endl;
        s.pop();
    }
    return 0;
}
