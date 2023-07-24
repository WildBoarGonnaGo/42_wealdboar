#include <sigset.h>
#include <algorithm>

std::ofstream out;
std::string ofile;

void handler(int sig) {
    out << "\b\b\033[0K";
    try {
        out << "Interruption occured" << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "I/O error: " << ofile
            << ": can't output to filestream (signal delivery): " << e.what()
            << std::endl;
    }
}

void Err(const std::string &msg) {
    std::cerr << msg << strerror(errno) << std::endl;
    exit(EXIT_FAILURE);
}

void ErrMsg(const std::string &msg) {
    std::cerr << msg << strerror(errno) << std::endl;
}

int IStreamStateError(const std::ifstream &s, const std::string &ifile) {
    if (s.bad()) {
        ErrMsg("I/O error: " + ifile + ": can't read line (badbit): ");
        return 1;
    }
    if (s.fail()) {
        ErrMsg("I/O error: " + ifile + ": can't read line (failbit): ");
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    sigset_t cur, prev;
    FILE *posixOStream = nullptr;
    std::ifstream in;
    std::string line, ifile;
    int c = 0;
    
    if (signal(SIGINT, handler) == SIG_ERR)
        Err("signal error: can't setup hander for 'SIGINT' signal: ");
    if (argc > 1 && std::string(argv[1]) != "stdout") {
        out = std::ofstream(argv[1]);
        posixOStream = fopen(argv[1], "w");
        ofile = argv[1];
    }
    else {
        out = std::ofstream("/dev/stdout");
        ofile = "/dev/stdout";
        posixOStream = stdout;
    }
    if (!out.is_open())
        Err("I/O error: " + std::string(argv[1]) + ": can't open file as output destination: ");
    if (!posixOStream)
        Err("I/O error: "
            + std::string(argv[1]) + ": can't write into this filestream: ");
    
    in = std::ifstream((argc > 2 && std::string(argv[2]) != "stdin") ? argv[2] : "/dev/stdin");
    ifile = (argc > 2 && std::string(argv[2]) != "stdin") ? argv[2] : "/dev/stdin";
    if (!in.is_open())
        Err("I/O error: " + std::string(argv[1])
                + ": can't open file as source input: ");
    
    sigemptyset(&cur);
    sigaddset(&cur, SIGINT);
    sigprocmask(SIG_SETMASK, nullptr, &prev);
    PrintSig(&prev, posixOStream, "intial process signal set: ");
    while (std::getline((ifile == "/dev/stdin") ? std::cin : in, line)) {
        if (IStreamStateError(in, ifile)) {
            std::cerr << "closing input stream with associated file" << std::endl;
            in.close();
            std::cerr << "closing output stream with associated file" << std::endl;
            out.close();
            if (fclose(posixOStream))
                Err("I/O error: can't close output stream (POSIX): ");
            return EXIT_FAILURE;
        }
        std::string cmd = line;
        std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);
        if (cmd == "interoff") {
            sigaddset(&cur, SIGINT);
            sigprocmask(SIG_BLOCK, &cur, &prev);
            PrintSig(&cur, posixOStream, "current signal block: ");
        }
        else if (cmd == "interon") {
            sigprocmask(SIG_UNBLOCK, &cur, &prev);
            sigdelset(&cur, SIGINT);
            PrintSig(&cur, posixOStream, "current signal block: ");
        }
        else if (ifile == "/dev/stdin" && line == "exit")
            break ;
        else {
            try {
                out << "seq_" << ++c << ": " << line << std::endl;
            } catch (const std::exception &e) {
                std::cerr << "I/O error: " << ofile
                    << ": can't output to filestream: "
                    << line << ": " << e.what()
                    << std::endl;
                std::cerr << "closing input stream with associated file" << std::endl;
                in.close();
                std::cerr << "closing output stream with associated file" << std::endl;
                out.close();
                if (fclose(posixOStream))
                    Err("I/O error: can't close output stream (POSIX): ");
                return EXIT_FAILURE;
            }
        }
    }
    in.close();
    out.close();
    if (fclose(posixOStream))
        Err("I/O error: can't close output stream (POSIX): ");
    return EXIT_SUCCESS;
}
