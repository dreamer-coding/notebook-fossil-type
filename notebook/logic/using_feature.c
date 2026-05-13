#include "fossil/type/feature.h"
#include "fossil/io/output.h"

int main(void)
{
    /* Create a feature that starts disabled */
    feature dark_mode = fossil_type_feature_make("Dark Mode", 0);

    fossil_io_printf("Feature: %s\n", dark_mode.name);
    fossil_io_printf("Enabled: %s\n",
                     fossil_type_feature_is_enabled(&dark_mode) ? "yes" : "no");

    /* Enable the feature */
    fossil_type_feature_enable(&dark_mode);

    fossil_io_printf("{green}After enabling:{normal}\n");
    fossil_io_printf("Enabled: %s\n",
                     fossil_type_feature_is_enabled(&dark_mode) ? "yes" : "no");

    /* Disable the feature */
    fossil_type_feature_disable(&dark_mode);

    fossil_io_printf("{yellow}After disabling:{normal}\n");
    fossil_io_printf("Enabled: %s\n",
                     fossil_type_feature_is_enabled(&dark_mode) ? "yes" : "no");

    /* Decorative separator */
    fossil_io_draw_horizontal_line(30, '=');
    fossil_io_putchar('\n');

    return 0;
}
