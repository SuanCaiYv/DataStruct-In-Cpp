#include <bits/stdc++.h>
using namespace std;
/*
 * 队列的Cpp实现
 * Author:SuanCaiYv
 * Time:2019/9/26/23:02
 */
template <typename T>
class Queue//实现依旧采用了一个母节点保存属性
{
private:
    T value;
    Queue *head = nullptr;
    Queue *tail = nullptr;
    Queue *next = nullptr;
    int Size = 0;
public:
    Queue();
    void push_back(T t);
    void pop_front();
    T front();
    int size();
    bool empty();
};
template<typename T>
Queue<T>::Queue()
{
    this->tail = this;
    this->head = this;
}
template<typename T>
void Queue<T>::push_back(T t)
{
    Queue *temp = new Queue;
    temp->value = t;
    temp->next = nullptr;
    this->tail->next = temp;
    this->tail = temp;
    if (this->Size == 0) this->head = temp;
    ++this->Size;
}
template<typename T>
void Queue<T>::pop_front()
{
    if (this->Size == 0) return ;
    Queue *temp = this->head;
    this->head = this->head->next;
    delete temp;
    --this->Size;
}
template<typename T>
T Queue<T>::front()
{
    return this->head->value;
}
template<typename T>
int Queue<T>::size()
{
    return this->Size;
}
template<typename T>
bool Queue<T>::empty()
{
    return this->Size == 0;
}
int main()
{
    Queue<string> queue;
    queue.push_back("123");
    queue.push_back("456");
    queue.push_back("789");
    while (!queue.empty()) {
        cout << queue.front() << endl;
        queue.pop_front();
    }
    return 0;
}
