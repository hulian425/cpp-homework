#include <iostream>

using namespace std;

const int data_size = 15;

template<class T>
class Mydeque{
private:
	struct node{
		T* data;
		int front;
		int rear;
		node* next;
		node* back;
	};
	node* first;
	node* last;
public:
	Mydeque(){
		first = new node;
		first->next = NULL;
		last = first;
	}
	~Mydeque(){
		node* prev;
		node* now = first;
		while (now){
			delete[] now->data;
			prev = now;
			now = now->next;
			delete prev;
		}
		first=last=NULL;
	}
	int size(){
		node* now = first->next;
		int cnt = (now->rear + data_size - now->front)%data_size;
		now = now->next;
		while (now){
			if ((now->rear + 1)%data_size == now->front)
				cnt += data_size - 1;
			else
				cnt += (now->rear + data_size - now->front)%data_size;
			now = now->next;
		}
		return cnt;
	}
	T& operator[] (int pos){
		node* now = first->next;
		while (now){
			if (pos < (now->rear + data_size - now->front)%data_size)
				return now->data[(now->front + pos)%data_size];
			pos -= (now->rear + data_size - now->front)%data_size;
			now = now->next;
		}
		cout <<"ERROR"<<endl;
		return last->data[(last->rear+data_size)%data_size];
	}
	void push_back(const T x){
		node* now = last;
		if (now == first || (now->rear + 1)%data_size == now->front)
		{
			node* newnode = new node;
			now->next = newnode;
			newnode->data = new T[data_size];
			newnode->front = 0;
			newnode->rear = 1;
			newnode->data[0] = x;
			newnode->next = NULL;
			newnode->back = now;
			last = newnode;
		}
		else
		{
			now->data[now->rear] = x;
			now->rear = (now->rear + 1)%data_size;
		}	
	}
	void push_front(const T x)
	{
		if (first->next == NULL || (first->next->rear + 1)%data_size == first->next->front)
		{
			node* newnode = new node;
			newnode->data = new T[data_size];
			newnode->front = 0;
			newnode->rear = 1;
			newnode->data[0] = x;
			newnode->next = first->next;
			newnode->back = first;
			first->next = newnode;
		}
		else
		{
			first->next->front = (first->next->front + data_size - 1)%data_size;
			first->next->data[first->next->front] = x;
		}
	}
	void pop_back()
	{
		last->rear = (last->rear - 1 + data_size)%data_size;
		if (last->rear == last->front){
			last->back->next = NULL;
			node* tmp = last->back;
			delete[] last->data;
			delete[] last;
			last = tmp;
		} 
	}
	void pop_front()
	{
		if (first->next == NULL)
			return;
		first->next->front = (first->next->front + 1)%data_size;
		if (first->next->front == first->next->rear)
		{
			node* tmp = first->next->next;
			delete[] first->next->data;
			delete first->next;
			first->next = tmp;
		}
	}
};

int main(){
	
	Mydeque<int> dq;
	cout << "插入100个数字" << endl;
	int i;
	for (i = 1; i <= 100; i++)
		dq.push_back(i);
	int len = dq.size();
	for (i = 0; i < 100; i++) {
		if (i%10==0)cout<<endl;
		cout << dq[i] << " ";
	}
	cout << endl;
	cout << "去除前20个" << endl;
	for (i = 0; i < 20; i++) dq.pop_front();
	for (i = 0; i < 80; i++) {
		if (i%10==0)cout<<endl;
		cout << dq[i] << " ";
	}
	cout << endl;
	cout << "去除后20个" << endl;
	for (i = 0; i < 20; i++) dq.pop_back();
	for (i = 0; i < 60; i++) {
		if (i%10==0)cout<<endl;
		cout << dq[i] << " ";
	}
	cout << endl;
	cout << "插入前20个" << endl;
	for (i = 101; i <= 120; i++) dq.push_front(i);
	for (i = 0; i < 80; i++) {
		if (i%10==0)cout<<endl;
		cout << dq[i] << " ";
	}
	cout << endl;
	cout << "插入后20个" << endl;
	for (i = 121; i <= 140; i++) dq.push_back(i);
	for (i = 0; i < 100; i++) {
		if (i%10==0)cout<<endl;
		cout << dq[i] << " ";
	}
	return 0;
}
