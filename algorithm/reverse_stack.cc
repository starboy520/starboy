// write a cpp program to reverse a stack in plcace using recursion
// you can only use the following ADT function on stack:
// IsEmpty, IsFull, Push, Pop, Top,
// you can not use extra stack or any other data structure.

#include <stack>
#include <iostream>
using namespace std;

template <typename T>
void reverse(stack<T>* s) {
  if (s.empty())
    return;
  T top = s.top();
  s->pop();
  reverse(s);
  push(s, top);
}

template <typename T>
void push(stack<T> *s, T key) {
  if (s->empty()){
    s.push(key);
    return;
  }

  T top = s.top();
  s.pop();
  push(s, key);
  s.push(top);
}




