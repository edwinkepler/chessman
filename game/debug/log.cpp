#include "log.hpp"

namespace Debug
{
    Log& Log::info(string s) {
        if(f_verbose)
            cout << s;
        return *this;
    }

    Log& Log::info(int i) {
        if(f_verbose)
            cout << i;
        return *this;
    }

    Log& Log::n() {
        if(f_verbose)
            cout << endl;
        return *this;
    }

    Log& Log::t() {
        if(f_verbose)
            cout << "\t";
        return *this;
    }

    Log& Log::l(int l) {
        if(f_verbose)
            cout << "[" << l << "] ";
        return *this;
    }

    Log& Log::piece_func_head(string f, int t, int o, const pair<int, int>& c) {
        if(f_verbose) {
            cout << "[" << f << "][type: " 
                << t << ", owner: " 
                << o << ", at: ("
                << c.first << ", " << c.second << ")]\n";
        }
        return *this;
    }

    Log& Log::board_func_head(string f, const pair<int, int>& c) {
        if(f_verbose) {
            cout << "[" << f << "][coords: " 
                << c.first << ", " << c.second << ")]\n";
        }
        return *this;
    }

    Log& Log::board_func_head(string f, 
        const pair<int, int>& c1, 
        const pair<int, int>& c2) 
    {
        if(f_verbose) {
            cout << "[" << f << "][from: " 
                << c1.first << ", " << c1.second << "), to: "
                << c2.first << ", " << c2.second << ")]\n";
        }
        return *this;
    }

    void Log::test_func_head(const string t) {
        if(f_verbose)
            cout << "<--------- " << t << " BEGIN ----------\n";
    }

    void Log::test_func_foot(const string t) {
        if(f_verbose)
            cout << "---------- " << t << " END ----------->\n\n";
    }

    Log& Log::coords(const pair<int, int>& c) {
        if(f_verbose)
            cout << "coords: (" << c.first << ", " << c.second << ")";
        return *this;
    }

    Log& Log::coords(const pair<int, int>& c1, const pair<int, int>& c2) {
        if(f_verbose) {
            cout << "coords: (" << c1.first << ", " << c1.second << "), ("
                                << c2.first << ", " << c2.second << ")";
        }
        return *this;
    }

    Log& Log::operator<<(string s) {
        if(f_verbose)
            info(s);
        return *this;
    }

    Log& Log::operator<<(int i) {
        if(f_verbose)
            info(i);
        return *this;
    }

    void Log::verbose(bool _f) {
        f_verbose = _f;
    }
}
