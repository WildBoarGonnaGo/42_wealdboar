#ifndef SIGSET_H
#define SIGSET_H

#include <signal.h>
#include <iostream>
#include <fstream>

void PrintSig(const sigset_t *set, std::ofstream &s);

#endif
