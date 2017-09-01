#include "log.hpp"

namespace Debug
{
    Log& Log::info(string s) {
        cout << s;
        return *this;
    }

    Log& Log::info(int i) {
        cout << i;
        return *this;
    }

    Log& Log::n() {
        cout << endl;
        return *this;
    }

    Log& Log::t() {
        cout << "\t";
        return *this;
    }

    Log& Log::piece_func_head(string f, int t, int o, const pair<int, int>& c) {
        cout << "[" << f << "][type: " 
            << t << ", owner: " 
            << o << ", at: ("
            << c.first << ", " << c.second << ")]\n";
        return *this;
    }

    Log& Log::board_func_head(string f, const pair<int, int>& c) {
        cout << "[" << f << "][coords: " 
            << c.first << ", " << c.second << ")]\n";
        return *this;
    }

    Log& Log::board_func_head(string f, 
        const pair<int, int>& c1, 
        const pair<int, int>& c2) 
    {
        cout << "[" << f << "][from: " 
            << c1.first << ", " << c1.second << "), to: "
            << c2.first << ", " << c2.second << ")]\n";
        return *this;
    }

    void Log::test_func_head(const string t) {
        cout << "<--------- " << t << " BEGIN ----------\n";
    }

    void Log::test_func_foot(const string t) {
        cout << "---------- " << t << " END ----------->\n\n";
    }

    Log& Log::coords(const pair<int, int>& c) {
        cout << "coords: (" << c.first << ", " << c.second << ")";
        return *this;
    }

    Log& Log::coords(const pair<int, int>& c1, const pair<int, int>& c2) {
        cout << "coords: (" << c1.first << ", " << c1.second << "), ("
                            << c2.first << ", " << c2.second << ")";
        return *this;
    }

    Log& Log::operator<<(string s) {
        info(s);
        return *this;
    }

    Log& Log::operator<<(int i) {
        info(i);
        return *this;
    }
}
