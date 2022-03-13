// Linked List

#include <iostream>
#include <memory>

struct LinkedList
{
private:
    struct ListNode
    {
        int data;
        std::shared_ptr<ListNode> prev;
        std::shared_ptr<ListNode> next;
    };
    std::shared_ptr<ListNode> head;
    std::shared_ptr<ListNode> end;

public:
    LinkedList() : head(nullptr), end(nullptr) {}

    LinkedList(int val)
    {
        std::shared_ptr<ListNode> temp(new ListNode);
        temp->data = val;
        temp->next = nullptr;
        temp->prev = nullptr;
        head = end = temp;
    }

    void pushFront(int val)
    {
        if (head == nullptr)
        {
            head = std::shared_ptr<ListNode>(new ListNode);
            head->data = val;
            head->prev = head->next = nullptr;
            end = head;
            return;
        }
        head->prev = std::shared_ptr<ListNode>(new ListNode);
        head->prev->next = head;
        head = head->prev;
        head->data = val;
        head->prev = nullptr;
    }

    void pushBack(int val)
    {
        if (head == nullptr)
        {
            head = std::shared_ptr<ListNode>(new ListNode);
            head->data = val;
            head->prev = head->next = nullptr;
            end = head;
            return;
        }
        end->next = std::shared_ptr<ListNode>(new ListNode);
        end->next->prev = end;
        end = end->next;
        end->data = val;
        end->next = nullptr;
    }

    void removeFront()
    {
        if (head == end)
        {
            head = end = nullptr;
            return;
        }
        std::shared_ptr<ListNode> temp;
        temp = head;
        head = head->next;
        head->prev = nullptr;
    }

    void removeBack()
    {
        if (head == end)
        {
            head = end = nullptr;
            return;
        }
        std::shared_ptr<ListNode> temp;
        temp = end;
        end = end->prev;
        end->next = nullptr;
    }

    void log()
    {
        std::cout << "Linked List: ";
        for (std::shared_ptr<ListNode> temp = head; temp != nullptr; temp = temp->next)
            std::cout << temp->data << (temp->next == nullptr ? "" : ", ");
    }

};


int main()
{
    LinkedList lst;

    lst.pushBack(1);
    lst.pushBack(2);
    lst.pushBack(3);
    lst.pushFront(4);
    lst.pushFront(5);
    lst.log();

    std::cout << std::endl;

    lst.removeBack();
    lst.removeFront();
    lst.log();

    std::cout << std::endl;

    lst.removeBack();
    lst.removeBack();
    lst.removeBack();
    lst.log();

    std::cout << std::endl;

    lst.pushBack(10);
    lst.pushBack(20);
    lst.log();
}
