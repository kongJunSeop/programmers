#include <iostream>
using namespace std;
class DNode {
public:
    DNode(const int& data)
        : data_(data), link_(nullptr) {}
    int getData(void) const {
        return data_;
    }
private:
    int data_;
    DNode* link_;
    friend class LinkedQueue;
};
class LinkedQueue {
public:
    LinkedQueue(void)
        : head_(nullptr), tail_(nullptr), count_(0) {}
    ~LinkedQueue(void) {
        DNode* tNode = head_;
        while (tNode) {
            head_ = tNode->link_;
            delete tNode;
            tNode = head_;
        }
    }
    bool isEmpty(void) const { return head_ == nullptr; }
    int countNode(void) const { return count_; }
    DNode* frontNode(void) const { return head_; }

    DNode* rearNode(void) const {
        if (isEmpty()) return nullptr;
        return tail_;
    }
    void addRear(const int& e) {
        DNode* newNode = new DNode(e);
        if (isEmpty()) {
            head_ = newNode;
            tail_ = newNode;
        }
        else {
            tail_->link_ = newNode;
            tail_ = newNode;
        }
        count_++;
    }
    void removeFront(void) {
        if (isEmpty()) return;
        DNode* old = head_;
        head_ = head_->link_;
        if (head_ == nullptr) tail_ = nullptr;
        delete old;
        count_--;
    }
    void printLinkedList(void) const {
        if (isEmpty()) {
            cout << "\n입력된 데이터가 없습니다!!!" << endl;
            return;
        }
        cout << "\n\t### 입력된 데이터 ###" << endl;
        DNode* tNode = head_;
        while (tNode) {
            cout.width(3);
            cout << tNode->data_ << " ->>";
            tNode = tNode->link_;
        }
        cout << " NULL\n" << endl;
    }
    void addSort(const int& e) {
        DNode* newNode = new DNode(e);
        if (isEmpty() || head_->data_ >= e) {
            newNode->link_ = head_;
            head_ = newNode;
        }
        else {
            DNode* curNode = head_;
            while (curNode->link_ != nullptr && curNode->link_->data_ < e) {
                curNode = curNode->link_;
            }
            newNode->link_ = curNode->link_;
            curNode->link_ = newNode;
        }
        if (newNode->link_ == nullptr) tail_ = newNode;
        count_++;
    }
private:
    DNode* head_;
    DNode* tail_;
    int count_;
};
int main(void) {
    int num;
    LinkedQueue sList;
    while (true) {
        cout << "임의의 정수 입력(종료: 0): ";
        if (!(cin >> num) || num == 0) break;
        sList.addSort(num);
    }
    sList.printLinkedList();
    cout << "노드의 총 개수: " << sList.countNode() << endl;
    if (sList.isEmpty()) cout << "입력된 데이터가 없습니다!!!\n" << endl;
    else {
        cout << "첫 번째 노드의 데이터: " << sList.frontNode()->getData() << endl;
        cout << "마지막 노드의 데이터: " << sList.rearNode()->getData() << endl;
    }
    cout << endl;
    return 0;
}
