#include "fossil/type/limits.h"
#include "fossil/io/output.h"

int main(void)
{
    /* Query limits for a 32-bit signed integer */
    const fossil_type_limits *i32 = fossil_type_limits_get("i32");

    if (i32)
    {
        fossil_io_printf("{cyan,bold}Type:%s{normal}\n", i32->type_id);
        fossil_io_printf("Minimum: %.0Lf\n", i32->min_value);
        fossil_io_printf("Maximum: %.0Lf\n", i32->max_value);
        fossil_io_printf("Size: %zu bytes\n", i32->size);
    }

    fossil_io_putchar('\n');

    /* Query limits for a 64-bit floating point value */
    const fossil_type_limits *f64 = fossil_type_limits_get("f64");

    if (f64)
    {
        fossil_io_printf("{green,bold}Type:%s{normal}\n", f64->type_id);
        fossil_io_printf("Minimum: %Le\n", f64->min_value);
        fossil_io_printf("Maximum: %Le\n", f64->max_value);
        fossil_io_printf("Size: %zu bytes\n", f64->size);
    }

    fossil_io_putchar('\n');

    /* Query limits for a boolean */
    const fossil_type_limits *boolean = fossil_type_limits_get("bool");

    if (boolean)
    {
        fossil_io_printf("{yellow,bold}Type:%s{normal}\n", boolean->type_id);
        fossil_io_printf("Minimum: %.0Lf\n", boolean->min_value);
        fossil_io_printf("Maximum: %.0Lf\n", boolean->max_value);
        fossil_io_printf("Size: %zu bytes\n", boolean->size);
    }

    fossil_io_draw_horizontal_line(40, '=');
    fossil_io_putchar('\n');

    return 0;
}
