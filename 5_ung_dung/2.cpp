//#include <iostream>
//#include "./Settings_1.h"
//using namespace std;
//
//// check if transmission line is broken
//// when A != B
//
//Alice alice;
//Bill bill;
//
//void Check_Transmission_Broken()
//{
//    srand((unsigned)time(NULL));
//    // messages Alice want to send
//    int r = 5;
//
//    bool result = true;
//    int sent_messages = 0;
//
//    for (int i = 0; i < r; i++)
//    {
//        // simulate transmission broken
//        alice.A1("Hello");
//        sent_messages++;
//    }
//    while (!Message_queue.IsEmpty())
//    {
//        bill.B2();
//    }
//
//    if (sent_messages != bill.B)
//    {
//        result = false;
//    }
//
//    // conclusion
//    if (result)
//    {
//        cout << "Transmission line is fine" << endl;
//    }
//    else
//    {
//        cout << "Transmission line is broken" << endl;
//    }
//}
//
//int main()
//{
//    // create queue
//    Message_queue.init();
//    Acknowledgment_queue.init();
//
//    // test here
//    Check_Transmission_Broken();
//    return 0;
//}