#include <string>
#include <iostream>
using namespace std;

// size of internal buffer storage
int k = 5;
// items
class Item
{
public:
    string data;
    int key;
    Item* next;
    // constructor
    Item(string _data, int _key)
    {
        data = _data;
        key = _key;
        next = nullptr;
    }
};
class Message : public Item
{
public:
    Message(string data, int key) : Item(data, key)
    {
    }
};
class Acknowledgment : public Item
{
public:
    Acknowledgment(string data, int key) : Item(data, key)
    {
    }
};

// queue
struct Queue
{
    Item* Front, * Rear;
    void init()
    {
        Front = nullptr;
        Rear = nullptr;
    }

    bool IsEmpty()
    {
        return Front == nullptr;
    }
    void Push(Item x)
    {
        Item* temp = new Item(x.data, x.key);
        if (Front == nullptr)
        {
            Front = temp;
            Rear = temp;
            Front->next = Rear;
            Rear->next = nullptr;
            return;
        }
        Rear->next = temp;
        Rear = temp;
    }
    void Pop()
    {
        if (IsEmpty())
        {
            return;
        }
        Item* next = Front->next;
        delete (Front);
        Front = next;
    }
    Item GetItem(int index)
    {
        int i = 0;
        Item* p = Front;
        while (i++ < index)
        {
            p = p->next;
        }
        return *p;
    }
};
Queue Message_queue;
Queue Acknowledgment_queue;

// Alice and Bill
class Alice
{
public:
    // number of messages that Bill told Alice that he had read.
    int A;
    // index of message
    int j;
    // recent message
    Message recent_message = Message("null", 0);

    Alice()
    {
        A = 0;
        j = 0;
    }
    void A1(string data)
    {
        Message mj(data, j);
        Message_queue.Push(mj);
        recent_message = mj;
        j++;
    }
    void A2()
    {
        if (Acknowledgment_queue.IsEmpty())
        {
            return;
        }
        if (recent_message.key >= k)
        {
            A = A + (Acknowledgment_queue.Front->key - A) % recent_message.key;
        }
        else
        {
            A = Acknowledgment_queue.Front->key;
            Acknowledgment_queue.Pop();
        }
    }
};
class Bill
{
public:
    // number of messages have been read & removed
    int B;
    // maximum index of messages that have been removed
    int jmax;
    // recent_message_key that Bill read
    int recent_message_key;

    Bill()
    {
        B = 0;
        jmax = 0;
        recent_message_key = 0;
    }
    void B1(string data)
    {
        if (B > k)
        {
            Acknowledgment bj(data, B % recent_message_key);
            Acknowledgment_queue.Push(bj);
        }
        else
        {
            Acknowledgment bj(data, B);
            Acknowledgment_queue.Push(bj);
        }
    }
    void B2()
    {
        if (Message_queue.IsEmpty())
        {
            return;
        }
        recent_message_key = Message_queue.Front->key;
        jmax = Message_queue.Front->key;
        Message_queue.Pop();
        if (jmax >= B)
        {
            B = jmax + 1;
        }
    }
};
