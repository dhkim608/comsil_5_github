#ifndef __STACK__
#define __STACK__
#include "LinkedList.h"

//템플릿 클래스로 확장
//Stack형식으로 Delete함수 재정의
//first,current_size는 class의 멤버 변수이므로 this 포인터 사용해 가져옴.

//LinkedList class를 상속받음.
template <class T>
class Stack : public LinkedList<T>{
	public:
		bool Delete(T &element);
};

template <class T>
bool Stack <T>::Delete(T &element){
	if(this->first){
		Node<T> *a=this->first;
		int b=this->current_size;
		element=this->first->data;
		this->current_size--;
		delete a;
		return true;
		}
		else return false;
};
#endif

