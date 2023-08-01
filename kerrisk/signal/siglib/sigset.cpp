#include "sigset.h" 

void wildsigcpp::ErrMsgTermination(const string &msg, ostream &s) {
    s << msg << strerror(errno) << endl;
    exit(errno); 
}

void wildsigcpp::ErrMsg(const string &msg, ostream &s) {
    s << msg << strerror(errno) << endl;
}

void wildsigcpp::PrintSig(const sigset_t *set, ostream &s, const string &msg) {
    if (!set) {
        cerr << "set variable is null: terminating the process" << endl;
        exit(EXIT_FAILURE);
    }
    
    for (uint16_t i = 1; i < NSIG; ++i) {
        if (sigismember(set, i))
            s << msg << sigCodeToStrMap.at(i) << ' ' << strsignal(i) << endl;
    }
}

void wildsigcpp::PrintBlockingSigSet(sigset_t *set, ostream &s, const string &msg) {
    if (sigprocmask(SIG_SETMASK, set, nullptr))
        ErrMsgTermination("can't get blocked signal set: ", cerr);
    
    PrintSig(set, s, msg);
}

void wildsigcpp::PrintPendingSigSet(sigset_t *set, ostream &s, const string &msg) {
    if (sigpending(set))
        ErrMsgTermination("can't get blocked signal set: ", cerr);
    
    PrintSig(set, s, msg);
}