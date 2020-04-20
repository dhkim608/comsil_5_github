#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <iostream>
using namespace std;

//LinkedList Node

template <class T>
class Node{
	public:
		//데이터 저장 변수
		T data;
		//노드구조체 이용해 다음 노드의 주소 저장하는 포인터
		Node *link;

		Node(T element){
			data=element;
			link=NULL;
		}
};

//LinkedList Class
template <class T>
class LinkedList{
	protected:
		//첫번째 노드 주소 저장 포인터
		Node<T> *first;
		int current_size;
	public:
		//생성자, 초기히ㅘ
		LinkedList(){
			first=0;
			current_size=0;
		};

		//노드의 개수를 반환
		int GetSize(){
			return current_size;
		};

		//맨앞에 원소 삽입, LinkedList와 Stack 둘다 같다
		
		void Insert(T element);
		virtual bool Delete(T &element);
		void Print();
};

//새 노드를 맨앞에 붙이고 값 삽입
template <class T>
void LinkedList<T>::Insert(T element){
	//노드 생성
	Node<T> *newnode=new Node<T>(element);
	
	//새 노드가 첫번째 노드 가리킴
	//newnode는 포인터이므로 ->를 사용해 함수,변수 불러옴
	//newnode, link와 같은 뜻
	newnode -> link=first;
	first=newnode;
	current_size++;
}

//마지막 노드의 값을 리턴하며 메모리에서 할당 해제
template <class T>
bool LinkedList<T>::Delete(T &element){
	
	if(first==0){
		return false;
	}

	Node<T> *current=first;
	Node<T> *previous=0;

	//마지막 노드까지 찾아가는 반복문
	while(1){
		if(current->link==0){
			if(previous){
				previous->link=current->link;
			}
			else{
				first=first->link;
			}
			break;
		}
		previous=current;
		current=current->link;
	}
	element=current->data;
	delete current;
	current_size--;

	return true;
}

//리스트를 출력하는 Print 함수
template <class T>
void LinkedList<T>::Print(){
	Node<T> *i;
	int index=1;

	if(current_size != 0){
		for(i=first;i !=NULL;i=i->link){
			if(index==current_size){
				cout<<"["<<index<<"|";
				cout<<i->data<<"]";
			}
			else{
				cout<<"["<<index<<"|";
				cout<<i->data<<"]->";
				index++;
			}
		}
		cout<<endl;
	}
}

#endif

