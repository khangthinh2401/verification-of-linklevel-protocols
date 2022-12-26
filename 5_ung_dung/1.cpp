#include <iostream>
#include <cstdlib>
#include "Settings_1.h"
using namespace std;

Alice alice;
Bill bill;

// Count garbled messages
void Count_Garbled_Messages()
{
    srand((unsigned)time(NULL));
    // messages Alice want to send
    int r = 10;

    for (int i = 0; i < r; i++)
    {
        if (rand() % 2 == 1)
        {
            alice.A1("Hello");
        }
    }
    while (!Message_queue.IsEmpty())
    {
        bill.B2();
    }
    cout << "Alice sent: " << r << " messages" << endl;
    cout << "Bill received: " << bill.B << " messages" << endl;
}

// rename to 'main' to test out
int main()
{
    Message_queue.init();
    Acknowledgment_queue.init();

    // test here
    Count_Garbled_Messages();
    return 0;
}