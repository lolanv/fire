#ifndef DATAOPERATION_H
#define DATAOPERATION_H

#include <vector>
#include <thread>
#include <mutex>
#include <stdexcept>

class DataOperation {
private:
    static std::mutex instanceMutex;
    static DataOperation* instance;
    std::vector<int> _dataVector;
    unsigned int _magicNumber;

    DataOperation() {}

public:
    static DataOperation* getInstance();

    void findMax();

    void sumofFirstN(int N);

    void FindNthValue(int N);

    void findOddNumber();

    void findFactorial();

    void Takeinput();

    void Checkprime();

    ~DataOperation();
};

#endif // DATAOPERATION_H
