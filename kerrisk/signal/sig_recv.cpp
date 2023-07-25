#include "siglib/sigset.h"
#include <unistd.h>

using std::stoi;

static int sigCount[NSIG];
static volatile sig_atomic_t interOc;

void handler(int sig) {
    if (sig == SIGINT)
        interOc = 1;
    else
        ++sigCount[sig];
}

int main(int argc, char *argv[]) {
    struct sigaction sigBlockSet;
    sigset_t sigEmptySet, sigPendingSet;

    cout << "PID of the process " << getpid() << endl;
    sigBlockSet.__sigaction_u.__sa_handler = handler;
    for (int i = 1; i < NSIG; ++i)
        sigaction(i, &sigBlockSet, nullptr);
    
    if (argc > 1) {
        size_t timeValue = stoi(argv[1]);
        if (sigprocmask(SIG_SETMASK, &sigBlockSet.sa_mask, nullptr) == -1)
            wildsigcpp::ErrMsgTermination("sigrecv: sigprocmask: full: ", cerr);
        cout << "sleeping for " << timeValue << " seconds" << endl;
        sleep(timeValue);
        //if (sigpending(&sigPendingSet) == -1)
        //    wildsigcpp::ErrMsgTermination("sigrecv: sigpending: ", cerr);
        cout << "Pending signals: " << endl;
        wildsigcpp::PrintPendingSigSet(&sigPendingSet, cout, "pending signal");
        sigemptyset(&sigEmptySet);
        if (sigprocmask(SIG_SETMASK, &sigEmptySet, nullptr) == -1)
            wildsigcpp::ErrMsgTermination("sigrecv: sigprocmask: empty: ", cerr);
    }
    while (!interOc) ;
    for (size_t i = 1; i < NSIG; ++i) {
        if (sigCount[i]) {
            cout << "Number of " << wildsigcpp::sigCodeToStrMap.at(i) << " ("
                << strsignal(i) << "): " << sigCount[i];
        }
    }
}