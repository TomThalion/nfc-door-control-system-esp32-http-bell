#include "BellManagerForTesting.h"

BellManagerForTesting::BellManagerForTesting(std::shared_ptr<TestingBell> bell) {
    this->bell = bell;
}