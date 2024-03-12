#ifndef DATAHANDLER_H
#define DATAHANDLER_H
#include <iostream>
#include <thread>
#include <numeric>
#include <vector>
#include <mutex>

class DataHandler {
private:
    static std::unique_ptr<DataHandler> instance;
    static std::mutex mutex;
    
    int _data[5];
    int _square_results[5];
    int _factorial_results[5];
    bool _flag;

    DataHandler();

public:
    static DataHandler* getInstance();
    void TakeInput();
    void ComputeSquare();
    void ComputeFactorial();
    void AverageValue();
};

#endif // DATAHANDLER_H