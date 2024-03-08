#include "Functionalities.h"

int main()
{
    try
    {
        using namespace Functionalities;

        // Create engine instances using async threads
        createEnginesAsync();

        // Find and display the engine number with maximum horsepower
        findMaxHorsepowerEngineNumberAsync();

        // Create an array of float values for the first and last instances
        getFirstLastTorqueAsync();

        // Calculate and display the average torque of all instances
        getAverageTorqueAsync();

        // Accept user input for _N
        setUserInputAsync();

        // Get and display engine types for the first _N instances
        getEngineTypesForFirstNAsync();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
