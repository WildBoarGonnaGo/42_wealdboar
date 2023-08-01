#include "siglib/sigset.h"
#include <unistd.h>

using std::stoi;

static int sigCount[NSIG];
static volatile sig_atomic_t interOc = 0;

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
    //sigBlockSet.sa_flags = SA_ONSTACK;
    sigfillset(&sigBlockSet.sa_mask);
    for (uint16_t i = 1; i < NSIG; ++i)
        sigaction(i, &sigBlockSet, nullptr);
    
    cout << "----------------------- BLOCKED SIGNALS -----------------------" << endl;
    wildsigcpp::PrintBlockingSigSet(&sigBlockSet.sa_mask, cout, "sig_recv: blocked signal: ");
    if (argc > 1) {
        size_t timeValue = stoi(argv[1]);
        //if (sigprocmask(SIG_SETMASK, &sigBlockSet.sa_mask, nullptr) == -1)
        //    wildsigcpp::ErrMsgTermination("sigrecv: sigprocmask: full: ", cerr);
        cout << "---------------------------------------------------------" << endl;
        cout << "sleeping for " << timeValue << " seconds" << endl;
        sleep(timeValue);
        cout << "----------------------- PENDING SIGNALS -----------------------" << endl;
        wildsigcpp::PrintPendingSigSet(&sigPendingSet, cout, "sig_recv: pending signal: ");
        sigemptyset(&sigEmptySet);
        wildsigcpp::PrintBlockingSigSet(&sigEmptySet, cout, "sig_recv: blocked signal: ");
        //if (sigprocmask(SIG_SETMASK, &sigEmptySet, nullptr) == -1)
        //    wildsigcpp::ErrMsgTermination("sigrecv: sigprocmask: empty: ", cerr);
    }
    cout << "---------------------------------------------------------" << endl;
    while (!interOc) ;
    for (size_t i = 1; i < NSIG; ++i) {
        if (sigCount[i]) {
            cout << "Number of " << wildsigcpp::sigCodeToStrMap.at(i) << " ("
                << strsignal(i) << "): " << sigCount[i] << endl;
        }
    }
}