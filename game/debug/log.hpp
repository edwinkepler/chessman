/**
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#ifndef LOG_HPP
#define LOG_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <iomanip>
#include <ctime>

using namespace std;

/**
 * @brief This namespace contains debug classes.
 */
namespace Debug
{
    static bool f_verbose_stdout = false;
    static bool f_verbose_file = false;
    static string s_file_name = "output.log";

    /**
     * @brief Logging to stdout and dumping info about objects.
     */
    class Log {
    public:
        /**
         * @brief Log standard info to stdout. Can be chained.
         * @param String to print.
         * @return Log object to enable chaining.
         */
        Log& info(string);
        /**
         * @brief Log standard info to stdout. Can be chained.
         * @param Integer to print.
         * @return Log object to enable chaining.
         */
        Log& info(int);
        /**
         * @brief Print new line. Can be chained.
         * @return Log object to enable chaining.
         */
        Log& n();
        /**
         * @brief Print tab. Can be chained.
         * @return Log object to enable chaining.
         */
        Log& t();
        /**
         * @brief Print two tab. Can be chained.
         * @return Log object to enable chaining.
         */
         Log& t2();
        /**
         * @brief Print line in a well formated manner.
         * @param Line to print.
         * @return Log object to enable chaining.
         */
        Log& l(int);
        /**
         * @brief Print START info about function to be logged.
         * @param Name of a function.
         */
        Log& func_head(string);
        /**
         * @brief Print STOP info about function to be logged.
         * @param Name of a function.
         */
        Log& func_foot(string);
        /**
         * @brief Print STOP info about function to be logged.
         * @param Name of a function.
         * @param Time taken to execute function (in ms).
         */
        Log& func_foot(string, int);
        /**
         * @brief Print basic info about piece to be logged.
         * @param Name of the function.
         * @param Type of the piece.
         * @param Owner of the piece.
         * @return Log object to enable chaining.
         */
        Log& piece_func_head(string, int, int, const pair<int, int>&);
        /**
         * @brief Print basic info about board to be logged.
         * @param Name of the function.
         * @param Pair of coordinates passed to function.
         * @return Log object to enable chaining.
         */
        Log& board_func_head(string, const pair<int, int>&);
        /**
         * @brief Print basic info about board to be logged.
         * @param Name of the function.
         * @param Pair of coordinates passed to function (from).
         * @param Pair of coordinates passed to function (to).
         * @return Log object to enable chaining.
         */
        Log& board_func_head(string,
            const pair<int, int>&,
            const pair<int, int>&);

        /**
         * @brief Print start for test case.
         * @param Name of test case.
         */
        static void test_func_head(const string);
        /**
         * @brief Print end for test case.
         * @param Name of test case.
         */
        static void test_func_foot(const string);

        /**
         * @brief Print current date and time.
         */
        Log& datetime_stamp();
        /**
         * @brief Print coordinates. Can be chained.
         * @param Pair of coordinates to print.
         * @return Log object to enable chaining.
         */
        Log& coords(const pair<int, int>&);
        /**
         * @brief Print coordinates. Can be chained.
         * @param Pair of coordinates to print.
         * @param Pair of coordinates to print.
         * @return Log object to enable chaining.
         */
        Log& coords(const pair<int, int>&, const pair<int, int>&);

        /**
         * @brief Log standard info to stdout.
         * @param String to print.
         */
        Log& operator<<(string);
        /**
         * @brief Log standard info to stdout.
         * @param Integer to print.
         */
        Log& operator<<(int);

        /**
         * @brief Sets path for a log file.
         * @param Path to log file.
         */
        void file_path(string);

        /**
         * @brief Turns on or off verbosity of a debug output to stdout.
         * @param Boolean to turn on or off verbosity.
         */
        static void verbose_stdout(bool);
        /**
         * @brief Turns on or off verbosity of a debug output to a file.
         * @param Boolean to turn on or off verbosity.
         */
        static void verbose_file(bool);
    };
}

#endif // LOG_HPP
