#include "siglib/sigset.h"

bool interruptionOccured;

void handler(int sig) {
    if (sig == SIGINT)
        interruptionOccured = true;
    else
        
}

int main(int argc, char *argv[]) {

}