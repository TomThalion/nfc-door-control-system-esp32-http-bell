#include "TestingBell.h"




TestingBell::TestingBell(){
    ringCount = 0;
}


int TestingBell::ring() {
    ringCount++;
    return 0;
}

int TestingBell::stopRing() {
    ringCount--;
    return 0;
}