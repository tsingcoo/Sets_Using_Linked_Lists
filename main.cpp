#include <iostream>

struct Node {
    int data;
    Node *next;

    Node(int d) {
        data = d;
        next = nullptr;
    }
};

Node *Build() {
    Node *head = nullptr;
    int x;
    while (true) {
        std::cin >> x;

        if (x != -1) {
            Node *p = new Node(x);
            if (head == nullptr) {
                head = p;
            } else {
                int flag = 0;
                auto temp = head;
                for (; temp->next != nullptr; temp = temp->next) {
                    if (temp->data == x) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    if (temp->data != x) {
                        temp->next = p;
                    }
                }
            }
        } else {
            break;
        }
    }
    return head;
}

//并集
Node *Union(Node *a, Node *b) {
    Node *head = nullptr;
    Node *p = nullptr;
    for (auto q = a; q != nullptr; q = q->next) {//复制a
        auto temp_a = new Node(q->data);
        if (p == nullptr) {
            p = temp_a;
            head = p;
        } else {
            while (p->next != nullptr) {
                p = p->next;
            }
            p->next = temp_a;
        }
    }

    for (auto q = b; q != nullptr; q = q->next) {
        auto temp_b = new Node(q->data);
        Node *tp = head;
        int flag = 0;
        while (tp != nullptr) {
            if (tp->data == temp_b->data) {
                flag = 1;
                break;
            } else {
                tp = tp->next;
            }
        }
        if (flag == 0) {
            p = p->next;
            p->next = temp_b;
        }
    }

    return head;
}

//交集
Node *Intersect(Node *a, Node *b) {
    Node *head = nullptr;
    Node *tp = nullptr;
    for (auto p = a; p != nullptr; p = p->next) {
        for (auto q = b; q != nullptr; q = q->next) {
            if (q->data == p->data) {
                Node *temp = new Node(p->data);
                if (head == nullptr) {
                    head = temp;
                    tp = head;
                } else {
                    tp->next = temp;
                    tp = tp->next;
                }
            }
        }
    }
    return head;
}

//差集
Node *Difference(Node *a, Node *b) {
    Node *head = nullptr;
    Node *tp = nullptr;
    for (auto p = a; p != nullptr; p = p->next) {
        int flag = 0;
        for (auto q = b; q != nullptr; q = q->next) {
            if (q->data == p->data) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            auto temp = new Node(p->data);
            if (head == nullptr) {
                head = temp;
                tp = temp;
            } else {
                tp->next = temp;
                tp = tp->next;
            }
        }
    }
    return head;
}

void Print(Node *head) {
    for (auto p = head; p != nullptr; p = p->next) {
        std::cout << p->data << " ";
    }
    std::cout << std::endl;
}

int main() {

    std::cout << "输入a,以-1结尾" << std::endl;
    auto a = Build();
//    std::cout << "a:" << std::endl;
//    Print(a);

    std::cout << "输入b,以-1结尾" << std::endl;
    auto b = Build();
//    std::cout << "b:" << std::endl;
//    Print(b);

    auto u = Union(a, b);
    std::cout << "u:" << std::endl;
    Print(u);

    auto i = Intersect(a, b);
    std::cout << "i:" << std::endl;
    Print(i);

    auto d = Difference(a, b);
    std::cout << "d:" << std::endl;
    Print(d);
    return 0;
}