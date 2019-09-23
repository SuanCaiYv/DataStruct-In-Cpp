#include <bits/stdc++.h>
using namespace std;
/*
 * 双向链表的C++实现
 * Author:SuanCaiYv
 */
template <typename T>
class List//此实现利用一个一直存在的节点记录链表的信息,可以理解成有一个母节点,她指向,或定义了构成链表的子节点,她本身不参与存放数据的链表构造
{
private:
    T value;
    List *prev = nullptr;//用来记录子节点的前节点
    List *next = nullptr;//用来记录子节点的后节点
    List *head = nullptr;//用来记录此链表的头结点
    List *tail = nullptr;//用来记录此链表的尾节点
    int size_ = 0;
public:
    void push_back(T t);//后压
    void pop_back();//后出
    void push_front(T t);//前压
    void pop_front();//前出
    int size();
    bool empty();
    T top_back();//末位元素
    T top_front();//首元素
};
//具体函数的实现细节
template<typename T>
inline void List<T>::push_back(T t)
{
    auto p = new List<T>;
    p->value = t;
    if (this->size_ == 0) this->head = this->tail = p;
    p->prev = this->tail;
    this->tail->next = p;
    this->tail = p;
    p->next = nullptr;
    this->head->prev = nullptr;
    ++this->size_;
}
template<typename T>
inline void List<T>::push_front(T t)
{
    auto p = new List<T>;
    p->value = t;
    if (this->size_ == 0) this->head = this->tail = p;
    p->next = this->head;
    this->head->prev = p;
    this->head = p;
    p->prev = nullptr;
    this->tail->next = nullptr;
    ++this->size_;
}
template<typename T>
inline void List<T>::pop_front()
{
    if (this->size_ == 0) return ;
    auto p = this->head;
    this->head = p->next;
    if (this->head != nullptr) this->head->prev = nullptr;
    p->prev = p->next = nullptr;
    --this->size_;
    delete p;
}
template<typename T>
inline void List<T>::pop_back()
{
    if (this->size_ == 0) return ;
    auto p = this->tail;
    this->tail = p->prev;
    if (this->tail != nullptr) this->tail->next = nullptr;
    p->prev = p->next = nullptr;
    --this->size_;
    delete p;
}
template<typename T>
inline int List<T>::size()
{
    return this->size_;
}
template<typename T>
inline bool List<T>::empty()
{
    return this->size_ == 0;
}
template<typename T>
T List<T>::top_back()
{
    return this->tail->value;
}
template<typename T>
T List<T>::top_front()
{
    return this->head->value;
}
int main()//测试主函数
{
    List<int> list;
    for (int i = 0; i < 10; ++ i) {
        list.push_back(i*2+1);
        list.push_front(i*2);
    }
    while (!list.empty()) {
        cout << list.top_front() << ' ';
        list.pop_front();
    }
    return 0;
}
