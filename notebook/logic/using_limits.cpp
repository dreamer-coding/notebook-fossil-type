#include "fossil/type/limits.h"
#include "fossil/io/output.h"
#include <iostream>

using namespace fossil::type;
using namespace fossil::io;

int main()
{
    /* Query limits for a 32-bit signed integer */
    Limits i32("i32");

    Output::printf("{cyan,bold}Type: i32{normal}\n");
    out << "Minimum: " << i32.min() << std::endl;
    out << "Maximum: " << i32.max() << std::endl;
    out << "Size: " << i32.size() << " bytes" << std::endl;
    out << std::endl;

    /* Query limits for a 64-bit floating point value */
    Limits f64("f64");

    Output::printf("{green,bold}Type: f64{normal}\n");
    out << "Minimum: " << f64.min() << std::endl;
    out << "Maximum: " << f64.max() << std::endl;
    out << "Size: " << f64.size() << " bytes" << std::endl;
    out << std::endl;

    /* Query limits for a boolean */
    Limits boolean("bool");

    Output::printf("{yellow,bold}Type: bool{normal}\n");
    out << "Minimum: " << boolean.min() << std::endl;
    out << "Maximum: " << boolean.max() << std::endl;
    out << "Size: " << boolean.size() << " bytes" << std::endl;
    out << std::endl;

    Output::draw_horizontal_line(40, '=');
    out << std::endl;

    return 0;
}
