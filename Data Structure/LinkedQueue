#include <iostream>
using namespace std;
template<typename N>
class Node {
public:
	Node(const N& data)
		:data_(data), link_(nullptr) {}
private:
	Node<N>* link_;
	N data_;
	template<typename T> friend class LinkedQueue;
};
template<typename T>
class LinkedQueue {
public:
	LinkedQueue() : head_(nullptr), tail_(nullptr), count_(0) {}	
	~LinkedQueue() { while (!empty()) pop(); }
	bool empty() { return head_ == nullptr; }
	int size() { return count_; }
	void push(const T& data) {
		Node<T>* nnd = new Node<T>(data);
		if (empty()) {
			head_ = nnd;
			tail_ = nnd;
		}
		else {
			tail_->link_ = nnd;
			tail_ = nnd;
		}
		count_++;
	}
	void pop() {
		Node<T>* tn = head_;
		if (empty()) return;
		head_ = head_->link_;
		if (head_ == nullptr) tail_ = nullptr;
		delete tn;
		count_--;
	}
	T front() { return head_->data_; }
	T rear() { return tail_->data_; }
	void printQueue() {
		Node<T>* tn = head_;
		if (empty()) {
			cout << "NILL" << endl;
			return;
		}
		else {
			while (tn) {
				cout << tn->data_ << " -->> ";
				tn = tn->link_;
			}
		}
	}
private:
	Node<T>* head_;
	Node<T>* tail_;
	int count_;
};
int main(void) {
	LinkedQueue<int> queue;
	int choice, num;
	while (1) {
		cout << "\n\n### 큐 구현: 단순연결리스트 ###\n\n";
		cout << "1) 데이터 삽입: push\n"
			<< "2) 데이터 삭제: pop\n"
			<< "3) 전체 출력\n"
			<< "4) 프로그램 종료\n" << endl;
		cout << "메뉴 선택: ";
		cin >> choice;

		switch (choice) {
		case 1:
			while (1) {
				cout << "데이터 입력(종료: 0): ";
				cin >> num;
				if (num == 0) break;
				queue.push(num);
			}
			break;
		case 2:
			if (queue.empty()) cout << "데이터가 없습니다." << endl;
			else {
				cout << "삭제된 데이터: " << queue.front() << endl;
				queue.pop();
			}
			break;
		case 3:
			queue.printQueue();
			break;
		case 4:
			cout << "프로그램 종료!!!" << endl;
			return 0;
		default:
			cout << "\n\n잘못 선택하셨습니다!!!" << endl;
			break;
		}
		system("pause");
	}
	return 0;
}
