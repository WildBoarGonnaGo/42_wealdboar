#ifndef SIGSET_H
#define SIGSET_H

#include <signal.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <unordered_map>

using std::ofstream;
using std::cerr;
using std::endl;
using std::string;
using std::ostream;
using std::unordered_map;
using std::cout;

namespace wildsigcpp {
    const unordered_map<uint8_t, string> sigCodeToStrMap = {
        {1 ,    string("SIGHUP ")},          //terminate process    terminal line hangup
        {2 ,    string("SIGINT ")},          //terminate process    interrupt program
        {3 ,    string("SIGQUIT")},          //create core image    quit program
        {4 ,    string("SIGILL ")},          //create core image    illegal instruction
        {5 ,    string("SIGTRAP")},          //create core image    trace trap
        {6 ,    string("SIGABRT")},          //create core image    abort program (formerly SIGIOT)
        {7 ,    string("SIGEMT ")},          //create core image    emulate instruction executed
        {8 ,    string("SIGFPE ")},          //create core image    floating-point exception
        {9 ,    string("SIGKILL")},          //terminate process    kill program
        {10,    string("SIGBUS ")},          //create core image    bus error
        {11,    string("SIGSEGV")},          //create core image    segmentation violation
        {12,    string("SIGSYS ")},          //create core image    non-existent system call invoked
        {13,    string("SIGPIPE")},          //terminate process    write on a pipe with no reader
        {14,    string("SIGALRM")},          //terminate process    real-time timer expired
        {15,    string("SIGTERM")},          //terminate process    software termination signal
        {16,    string("SIGURG ")},          //discard signal       urgent condition present on socket
        {17,    string("SIGSTOP")},          //stop process         stop (cannot be caught or ignored)
        {18,    string("SIGTSTP")},          //stop process         stop signal generated from keyboard
        {19,    string("SIGCONT")},          //discard signal       continue after stop
        {20,    string("SIGCHLD")},          //discard signal       child status has changed
        {21,    string("SIGTTIN")}          //stop process         background read attempted from control termina
    };
    void ErrMsgTermination(const string &msg, ostream &s);
    void ErrMsg(const string &msg, ostream &s);
    void PrintSig(const sigset_t *set, ostream &s, const string &msg);
    void PrintBlockingSigSet(sigset_t *set, ostream &s, const string &msg);
    void PrintPendingSigSet(sigset_t *set, ostream &s, const string &msg);
}

#endif
