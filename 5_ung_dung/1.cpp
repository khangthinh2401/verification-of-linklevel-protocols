//#include <iostream>
//#include <cstdlib>
//#include "Settings_1.h"
//using namespace std;
//
//Alice alice;
//Bill bill;
//
//// Count garbled messages
//void Count_Garbled_Messages()
//{
//    srand((unsigned)time(NULL));
//    // messages Alice want to send
//    int r = 10;
//
//    for (int i = 0; i < r; i++)
//    {
//        // simulate broken transmisison line
//        // return 1 -> Send
//        // return 0 -> Not send
//        if (rand() % 2 == 1)
//        {
//            alice.A1("Hello");
//        }
//    }
//    while (!Message_queue.IsEmpty())
//    {
//        bill.B2();
//    }
//
//    // conclusion
//    cout << "Alice sent: " << r << " messages" << endl;
//    cout << "Bill received: " << bill.B << " messages" << endl;
//}
//
//int main()
//{
//    Message_queue.init();
//    Acknowledgment_queue.init();
//
//    // test here
//    Count_Garbled_Messages();
//    return 0;
//}