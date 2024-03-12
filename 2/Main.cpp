#include "DataHandler.h"
#include <thread>

int main() {
    DataHandler* dataHandler = DataHandler::getInstance();

    std::thread inputThread(&DataHandler::TakeInput, dataHandler);
    std::thread squareThread(&DataHandler::ComputeSquare, dataHandler);
    std::thread factorialThread(&DataHandler::ComputeFactorial, dataHandler);
    std::thread averageThread(&DataHandler::AverageValue, dataHandler);
    
    inputThread.join();
    squareThread.join();
    factorialThread.join();
    averageThread.join();
    
    return 0;
}