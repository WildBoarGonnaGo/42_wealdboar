#include "siglib/sigset.h"

using std::stoi;
using std::to_string;

int main(int argc, char *argv[]) {
    if (argc != 4 || (argc > 1 && string(argv[2]) == "--help")) {
        cout << "Usage: sig_sndr <pid> <sig> <snd_number>" << endl;
        exit(EXIT_SUCCESS);
    }

    int proc = stoi(argv[1]);
    int sig = stoi(argv[2]);
    int sendNum = stoi(argv[3]);

    for (int i = 0; i < sendNum; ++i) {
        int sendSigRes = kill(proc, sig);
        if (sendSigRes == -1)
            wildsigcpp::ErrMsgTermination("sig_sndr: kill: ", cerr);
    }
    cout << "Signal " << wildsigcpp::sigCodeToStrMap.at(sig)
        << " was sent to process with PID (" << proc
        << ") " << sendNum << endl;
    
    return 0;
}