#include "Functionalities.h"
#include <iostream>

void Functionalities::executeFunctionalities(DataOperation* dataOperationInstance) {
    try {
        std::thread t1(&DataOperation::findMax, dataOperationInstance);
        std::thread t2(&DataOperation::sumofFirstN, dataOperationInstance, 3);
        std::thread t3(&DataOperation::FindNthValue, dataOperationInstance, 2);
        std::thread t4(&DataOperation::findOddNumber, dataOperationInstance);
        std::thread t5(&DataOperation::findFactorial, dataOperationInstance);
        std::thread t6(&DataOperation::Takeinput, dataOperationInstance);
        std::thread t7(&DataOperation::Checkprime, dataOperationInstance);

        t1.join();
        t2.join();
        t3.join();
        t4.join();
        t5.join();
        t6.join();
        t7.join();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
