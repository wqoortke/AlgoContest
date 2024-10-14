
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>

class Node
{
public:
    Node(int val, Node* next = nullptr) : val(val), next(next) {}

    ~Node() = default;
    int getVal() const {
        return val;
    }
    void setVal(int n) {
        val = n;
    }
    Node* getNext() const {
        return this->next;
    }
    void setNext(Node* n) {
        this->next = n;
    }
    void printNode() {
        std::cout << val << '\n';
    }

private:
    int val;
    Node* next;
};

void swapNodes(Node* a, Node* b) {
    int x = b->getVal();
    b->setVal(a->getVal());
    a->setVal(x);
}

class LinkedList
{
public:
    LinkedList(Node* s) : first(s), length(1) {}
    ~LinkedList() {
        Node* current = first;
        while (current) {
            Node* next = current->getNext();
            delete current;
            current = next;
        }
    }
    int getLen() const {
        return length;
    }
    Node* getFirst() {
        return first;
    }

    void addNode(Node* nextNode) {
        Node* ptr = first;
        while (ptr->getNext() != nullptr) {
            ptr = ptr->getNext();
        }
        ptr->setNext(nextNode);
        length += 1;
        heapify();
    }

    void printArray() {
        Node* current = this->getFirst();
        while (current != nullptr) {
            std::cout << current->getVal() << " ";
            current = current->getNext();
        }
        std::cout << '\n'<< '\n';
    }

    Node* at(int index) const {
        Node* ptr = first;
        if (index >= 0 and index < length) {
            for (int i = 0; i < index; i++) {
                ptr = ptr->getNext();
            }
            return ptr;
        }
        return ptr;
    }

    void heapify(int start = 0) {
        if (!start) {
            start = length / 2;
        }
        for (int i = start; i >= 0; i--) {
            if ((this->at(2*i + 1)) != (this->at(0))) {
                if ((this->at(i))->getVal() > (this->at(2*i + 1))->getVal()) {
                    swapNodes(this->at(i), this->at(2*i + 1));
                    heapify(2*i + 1);
                }
            }
            if (this->at(2*i + 2) != this->at(0)) {
                if (this->at(i)->getVal() > this->at(2*i + 2)->getVal()) {
                    swapNodes(this->at(i), this->at(2*i + 2));
                    heapify(2*i + 2);
                }
            }
        }
    }

    int removeMax() {
        if (length == 1) {
            return (this->at(0))->getVal();
        }
        int max = 0;
        int maxIndex = 0;
        for (int i = length; i >= (length / 2); i--) {
            if (this->at(i)->getVal() > max) {
                max = this->at(i)->getVal();
                maxIndex = i;
            }
        }
        swapNodes(this->at(maxIndex), this->at(length - 1));
        max = this->at(length - 1)->getVal();
        delete this->at(length - 1);
        this->at(length - 2)->setNext(nullptr);
        length -= 1;
        return max;
    }

private:
    Node* first;
    int length;
};







int main() {
    bool heapExists = false;
    LinkedList* l = new LinkedList(new Node(1));
    std::string inp;
    std::ifstream f;
    f.open("input.txt");
    if (!f.is_open()) {
        return 1;
    }
    while (getline(f, inp))
    {
        if (inp == "EXTRACT") {
            if (!heapExists) {
                std::cout << "CANNOT\n";
            } else if (l->getLen() == 1) {
                std::cout << l->removeMax() << '\n';
                delete l;
                l = nullptr;
                heapExists = false;
            } else {
                std::cout << l->removeMax() << '\n';
            }
        } else if (inp == "CLEAR") {
            heapExists = false;
            delete l;
            l = nullptr;
        } else {
            int d = inp.find_first_of(' ');
            std::string op = inp.substr(0, d);
            std::string val = inp.substr(d, inp.length());
            int value = std::stoi( val );
            if (op == "ADD") {
                if (heapExists == false) {
                    l = new LinkedList(new Node(value));
                    heapExists = true;
                } else if (heapExists) {
                    l->addNode(new Node(value));
                }
            }
        }
    }
    f.close();
}
