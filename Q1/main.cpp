#include "DataOperation.h"
#include "Functionalities.h"

int main()
{
    DataOperation *dataOperationInstance = DataOperation::getInstance();

    Functionalities::executeFunctionalities(dataOperationInstance);

    return 0;
}
