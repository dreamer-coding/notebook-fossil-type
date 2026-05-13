#include "fossil/type/feature.h"
#include "fossil/io/output.h"
#include <iostream>

using namespace fossil::type;
using namespace fossil::io;

int main()
{
    /* Create a feature that starts disabled */
    Feature darkMode("Dark Mode");

    out << "Feature: Dark Mode" << std::endl;
    out << "Enabled: "
        << (darkMode.enabled() ? "yes" : "no")
        << std::endl;

    /* Enable the feature */
    darkMode.enable();

    Output::printf("{green}After enabling:{normal}\n");
    out << "Enabled: "
        << (darkMode.enabled() ? "yes" : "no")
        << std::endl;

    /* Disable the feature */
    darkMode.disable();

    Output::printf("{yellow}After disabling:{normal}\n");
    out << "Enabled: "
        << (darkMode.enabled() ? "yes" : "no")
        << std::endl;

    /* Decorative separator */
    Output::draw_horizontal_line(30, '=');
    out << std::endl;

    return 0;
}
