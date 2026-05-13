#include "fossil/type/tribool.h"
#include "fossil/io/output.h"
#include <iostream>

using namespace fossil::type;
using namespace fossil::io;

static const char *to_string(const Tribool& t)
{
    if (t.is_true())
        return "TRUE";
    if (t.is_false())
        return "FALSE";
    return "UNKNOWN";
}

int main()
{
    Tribool yes(fossil_type_tribool_make_true());
    Tribool no(fossil_type_tribool_make_false());
    Tribool maybe; /* Defaults to UNKNOWN */

    Output::printf("{cyan,bold}Initial values{normal}\n");
    out << "yes   = " << to_string(yes) << std::endl;
    out << "no    = " << to_string(no) << std::endl;
    out << "maybe = " << to_string(maybe) << std::endl;
    out << std::endl;

    Tribool result_and = yes && maybe;
    Tribool result_or  = no || maybe;
    Tribool result_not = !maybe;

    Output::printf("{green,bold}Logic results{normal}\n");
    out << "TRUE AND UNKNOWN = " << to_string(result_and) << std::endl;
    out << "FALSE OR UNKNOWN = " << to_string(result_or) << std::endl;
    out << "NOT UNKNOWN      = " << to_string(result_not) << std::endl;

    Output::draw_horizontal_line(40, '=');
    out << std::endl;

    return 0;
}
