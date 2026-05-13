#include "fossil/type/tribool.h"
#include "fossil/io/output.h"

static const char *tribool_to_string(tribool t)
{
    if (fossil_type_tribool_is_true(t))
        return "TRUE";
    if (fossil_type_tribool_is_false(t))
        return "FALSE";
    return "UNKNOWN";
}

int main(void)
{
    tribool yes   = fossil_type_tribool_make_true();
    tribool no    = fossil_type_tribool_make_false();
    tribool maybe = fossil_type_tribool_make_unknown();

    fossil_io_printf("{cyan,bold}Initial values{normal}\n");
    fossil_io_printf("yes   = %s\n", tribool_to_string(yes));
    fossil_io_printf("no    = %s\n", tribool_to_string(no));
    fossil_io_printf("maybe = %s\n", tribool_to_string(maybe));
    fossil_io_putchar('\n');

    tribool result_and = fossil_type_tribool_and(yes, maybe);
    tribool result_or  = fossil_type_tribool_or(no, maybe);
    tribool result_not = fossil_type_tribool_not(maybe);

    fossil_io_printf("{green,bold}Logic results{normal}\n");
    fossil_io_printf("TRUE AND UNKNOWN = %s\n",
                     tribool_to_string(result_and));
    fossil_io_printf("FALSE OR UNKNOWN = %s\n",
                     tribool_to_string(result_or));
    fossil_io_printf("NOT UNKNOWN      = %s\n",
                     tribool_to_string(result_not));

    fossil_io_draw_horizontal_line(40, '=');
    fossil_io_putchar('\n');

    return 0;
}
