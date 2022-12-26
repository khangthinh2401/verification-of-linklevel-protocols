#include <iostream>
#include "Settings.h"
using namespace std;

Alice alice;
Bill bill;

void Test_Lemma_1()
{
    int r = 3;
    // create message queue
    for (int j = 0; j < r; j++)
    {
        alice.A1("Hello");
    }

    // acknowledgment queue b1...br
    for (int j = 0; j < r; j++)
    {
        bill.B2();
        bill.B1("I receive it");
    }

    int b1 = Acknowledgment_queue.Front->key;
    int br = Acknowledgment_queue.Rear->key;
    // result
    cout << endl;
    cout << "b1 = 0;   br = " << br << endl;
    cout << "A = " << alice.A << endl;
    cout << "B = " << bill.B << endl;

    // conclusion
    if (alice.A <= b1 && b1 <= br && br <= bill.B)
    {
        cout << "--- Lemma 1 remains TRUE! ---" << endl;
    }
    else
    {
        cout << "--- Lemma 1 is FALSE! ---" << endl;
    }
}
void Test_Lemma_2()
{
    // message queue Mj1...Mjr
    int r = 3;
    for (int j = 0; j <= r; j++)
    {
        alice.A1("Hello");
    }
    int j[1000];
    j[0] = bill.jmax;
    j[r + 1] = alice.A;

    for (int i = 0; i <= r; i++)
    {
        j[i] = Message_queue.GetItem(i).key;
    }

    // result
    bool result = true;
    for (int i_comma = 1; i_comma <= r + 1; i_comma++)
    {
        for (int i = 0; i < i_comma; i++)
        {
            // check if ji < ji' + k
            if (j[i] >= j[i_comma] + k)
            {
                result = false;
                break;
            }
        }
        if (!result)
        {
            break;
        }
    }

    // conclusion
    if (result)
    {
        cout << "--- Lemma 2 remains TRUE! ---" << endl;
    }
    else
    {
        cout << "--- Lemma 2 is FALSE! ---" << endl;
    }
}
void Test_Theorem_1()
{
    // theorem 1
    // B-k <= j < B+k
    // message queue Mj1...Mjr
    int r = 3;
    for (int j = 0; j <= r; j++)
    {
        alice.A1("Hello");
    }
    int j[1000];
    for (int i = 0; i <= r; i++)
    {
        j[i] = Message_queue.GetItem(i).key;
    }

    // result
    bool result = true;
    for (int i = 0; i <= r; i++)
    {
        // B - k <= j < B + k
        if (bill.B - k > j[i] || j[i] > bill.B + k)
        {
            result = false;
            break;
        }
    }

    // conclusion
    if (result)
    {
        cout << "--- Theorem 1 is TRUE! ---" << endl;
    }
    else
    {
        cout << "--- Theorem 1 is FALSE! ---" << endl;
    }
}
void Test_Theorem_2()
{
    // create message queue
    int r = 3;
    for (int j = 0; j <= r; j++)
    {
        alice.A1("Hello");
    }
    // acknowledgment queue b1...br
    for (int j = 0; j <= r; j++)
    {
        bill.B1("I receive it");
        bill.B2();
    }

    int b[1000];
    for (int i = 0; i <= r; i++)
    {
        b[i] = Acknowledgment_queue.GetItem(i).key;
    }

    // result
    bool result = true;
    for (int i = 0; i <= r; i++)
    {
        if (b[i] < alice.A || b[i] > alice.A + k)
        {
            result = false;
            break;
        }
    }

    // conclusion
    if (result)
    {
        cout << "--- Theorem 2 is TRUE! ---" << endl;
    }
    else
    {
        cout << "--- Theorem 2 is FALSE! ---" << endl;
    }
}
void Test_Extended_Case() {
    // Alice sent 6 messages
    for (int i = 0; i < 6; i++)
    {
        alice.A1("Halo guys");
    }
    // Bill read 6 messages
    for (int i = 0; i < 6; i++)
    {
        bill.B2();
    }
    // Bill sent acknowledgment
    bill.B1("I receive it");
    // Alice received acknowledgment
    alice.A2();

    cout << "A: " << alice.A << endl;
};

int main()
{
    // create message queue
    Message_queue.init();
    // create acknowledgment queue
    Acknowledgment_queue.init();
    system("cls");


    // start test
    Test_Extended_Case();
    // end test

    return 0;
}
