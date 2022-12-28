#include <iostream>
#include "./Settings_1.h"
using namespace std;

// Alice sent 6 messages
// Bill sent acknowledgment b = 1
// Alice knew that she sent so many messages
Alice alice;
Bill bill;

void Check_Oversend_Message()
{
    // k = 5
    // change r to test
    int r = 4;

    for (int i = 0; i < r; i++)
    {
        alice.A1("Hello");
    }
    while (!Message_queue.IsEmpty())
    {
        bill.B2();
    }
    bill.B1("I receive it ");
    alice.A2();

    if (alice.A < r)
    {
        cout << "Alice has sent more than k messages";
    }
    else
    {
        cout << "Alice has sent less than k messages";
    }
}

int main()
{
    Message_queue.init();
    Acknowledgment_queue.init();

    // test here
    Check_Oversend_Message();
    return 0;
}