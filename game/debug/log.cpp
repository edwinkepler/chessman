#include "log.hpp"

namespace Debug
{
    Log& Log::info(string _s) {
        if(f_verbose_stdout) {
            cout << _s;
        } 
        if(f_verbose_file) {
            ofstream file_log;
            file_log.open(
                s_file_name, 
                ios::binary | 
                ios_base::app | 
                ios_base::out);
            file_log << _s;
            file_log.close();
        }
        return *this;
    }

    Log& Log::info(int _i) {
        if(f_verbose_stdout) {
            cout << _i;
        }
        if(f_verbose_file) {
            ofstream file_log;
            file_log.open(
                s_file_name, 
                ios::binary | 
                ios_base::app | 
                ios_base::out);
            file_log << _i;
            file_log.close();
        }
        return *this;
    }

    Log& Log::n() {
        if(f_verbose_stdout) {
            cout << endl;
        }
        if(f_verbose_file) {
            ofstream file_log;
            file_log.open(
                s_file_name, 
                ios::binary | 
                ios_base::app | 
                ios_base::out);
            file_log << "\n";
            file_log.close();
        }
        return *this;
    }

    Log& Log::t() {
        if(f_verbose_stdout) {
            cout << "\t";
        }
        if(f_verbose_file) {
            ofstream file_log;
            file_log.open(
                s_file_name, 
                ios::binary | 
                ios_base::app | 
                ios_base::out);
            file_log << "\t";
            file_log.close();
        }
        return *this;
    }

    Log& Log::l(int _l) {
        if(f_verbose_stdout) {
            cout << "[" << _l << "] ";
        }
        if(f_verbose_file) {
            ofstream file_log;
            file_log.open(
                s_file_name, 
                ios::binary | 
                ios_base::app | 
                ios_base::out);
            file_log << "[" << _l << "] ";
            file_log.close();
        }
        return *this;
    }

    Log& Log::piece_func_head(string _f, int _t, int _o, const pair<int, int>& _c) {
        if(f_verbose_stdout) {
            cout << "[" << _f << "][type: " 
                << _t << ", owner: " 
                << _o << ", at: ("
                << _c.first << ", " << _c.second << ")]\n";
        }
        if(f_verbose_file) {
            ofstream file_log;
            file_log.open(
                s_file_name, 
                ios::binary | 
                ios_base::app | 
                ios_base::out);
            file_log << "[" << _f << "][type: " 
                    << _t << ", owner: " 
                    << _o << ", at: ("
                    << _c.first << ", " << _c.second << ")]\n";
            file_log.close();
        }
        return *this;
    }

    Log& Log::board_func_head(string _f, const pair<int, int>& _c) {
        if(f_verbose_stdout) {
            cout << "[" << _f << "][coords: " 
                << _c.first << ", " << _c.second << ")]\n";
        }
        if(f_verbose_file) {
            ofstream file_log;
            file_log.open(
                s_file_name, 
                ios::binary | 
                ios_base::app | 
                ios_base::out);
            file_log << "[" << _f << "][coords: " 
                    << _c.first << ", " << _c.second << ")]\n";
            file_log.close();
        }
        return *this;
    }

    Log& Log::board_func_head(string _f, 
        const pair<int, int>& _c1, 
        const pair<int, int>& _c2) 
    {
        if(f_verbose_stdout) {
            cout << "[" << _f << "][from: " 
                << _c1.first << ", " << _c1.second << "), to: "
                << _c2.first << ", " << _c2.second << ")]\n";
        }
        if(f_verbose_file) {
            ofstream file_log;
            file_log.open(
                s_file_name, 
                ios::binary | 
                ios_base::app | 
                ios_base::out);
            file_log << "[" << _f << "][from: " 
                    << _c1.first << ", " << _c1.second << "), to: "
                    << _c2.first << ", " << _c2.second << ")]\n";
            file_log.close();
        }
        return *this;
    }

    void Log::test_func_head(const string _t) {
        if(f_verbose_stdout) {
            cout << "<--------- " << _t << " BEGIN ----------\n";
        }
        if(f_verbose_file) {
            ofstream file_log;
            file_log.open(
                s_file_name, 
                ios::binary | 
                ios_base::app | 
                ios_base::out);
            file_log << "<--------- " << _t << " BEGIN ----------\n";
            file_log.close();
        }
    }

    void Log::test_func_foot(const string _t) {
        if(f_verbose_stdout) {
            cout << "---------- " << _t << " END ----------->\n\n";
        }
        if(f_verbose_file) {
            ofstream file_log;
            file_log.open(
                s_file_name, 
                ios::binary | 
                ios_base::app | 
                ios_base::out);
            file_log << "---------- " << _t << " END ----------->\n\n";
            file_log.close();
        }
    }

    Log& Log::datetime_stamp() {
        if(f_verbose_stdout) {
            auto t = time(nullptr);
            auto tm = *localtime(&t);
            cout << "[" << put_time(&tm, "%d-%m-%Y %H:%M:%S") << "]";
        }
        if(f_verbose_file) {
            auto t = time(nullptr);
            auto tm = *localtime(&t);
            ofstream file_log;
            file_log.open(
                s_file_name, 
                ios::binary | 
                ios_base::app | 
                ios_base::out);
            file_log << "[" << put_time(&tm, "%d-%m-%Y %H:%M:%S") << "]";
            file_log.close();
        }
        return *this; 
    }

    Log& Log::coords(const pair<int, int>& _c) {
        if(f_verbose_stdout) {
            cout << "coords: (" << _c.first << ", " << _c.second << ")";
        }
        if(f_verbose_file) {
            ofstream file_log;
            file_log.open(
                s_file_name, 
                ios::binary | 
                ios_base::app | 
                ios_base::out);
            file_log << "coords: (" << _c.first << ", " << _c.second << ")";
            file_log.close();
        }
        return *this;
    }

    Log& Log::coords(const pair<int, int>& _c1, const pair<int, int>& _c2) {
        if(f_verbose_stdout) {
            cout << "coords: (" << _c1.first << ", " << _c1.second << "), ("
                                << _c2.first << ", " << _c2.second << ")";
        }
        if(f_verbose_file) {
            ofstream file_log;
            file_log.open(
                s_file_name, 
                ios::binary | 
                ios_base::app | 
                ios_base::out);
            file_log << "coords: (" << _c1.first << ", " << _c1.second << "), ("
                                    << _c2.first << ", " << _c2.second << ")";
            file_log.close();
        }
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

    void Log::verbose_stdout(bool _f) {
        f_verbose_stdout = _f;
    }

    void Log::verbose_file(bool _f) {
        f_verbose_file = _f;
    }
}
