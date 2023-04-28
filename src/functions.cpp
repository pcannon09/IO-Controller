#include "structs.hpp"
#include "ioController.hpp"

int startCallCount = 0;

namespace ioc
{
    /// @brief Makes setup for the program (It's highly recommended)
    void start()
    {
        if (startCallCount == 0)
        {
            ioc::rule::reset();
        }

        else if (startCallCount < 0)
        {
            error("Error starting code, make sure that variable 'startCallCount' is 0 ( 'startCallCount is'", startCallCount, ")");
        }

        else if (startCallCount > 0)
        {
            warn("Variable 'startCallCount' is bigger than 0, no impact occurred");
        }

        startCallCount++;
    }
}
