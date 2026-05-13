#include "fossil/type/types.h"
#include "fossil/io/output.h"

int main(void)
{
    /* Signed integers */
    i32 count = -42;
    i64 population = 8045312345LL;

    /* Unsigned and semantic aliases */
    u32 flags_value = 0x0000000F;
    h32 color = 0xFFAA33CC;
    o16 permissions = 0755;
    b8 mask = 0xAA; /* 10101010 */

    /* Floating point */
    f32 ratio = 0.75f;
    f64 pi = 3.141592653589793;

    /* Size types */
    usize length = 128;
    isize delta = -12;

    /* Text */
    char_t letter = 'F';
    cstr message = "Hello from Fossil Types";

    /* Generic pointers */
    int value = 123;
    ptr data = &value;
    cptr view = data;

    /* Metadata */
    type_id tid = "i32";
    symbol key = "max_items";

    /* Flags and identifiers */
    flags options = (1ULL << 0) | (1ULL << 3);
    node_id node = 42;
    entropy uncertainty = 0.73;

    fossil_io_printf("{cyan,bold}Signed integers{normal}\n");
    fossil_io_printf("count      = %d\n", count);
    fossil_io_printf("population = %lld\n", (long long)population);
    fossil_io_putchar('\n');

    fossil_io_printf("{green,bold}Aliases{normal}\n");
    fossil_io_printf("flags      = 0x%08X\n", flags_value);
    fossil_io_printf("color      = 0x%08X\n", color);
    fossil_io_printf("permissions= %04o\n", permissions);
    fossil_io_printf("mask       = 0x%02X\n", mask);
    fossil_io_putchar('\n');

    fossil_io_printf("{yellow,bold}Floating point{normal}\n");
    fossil_io_printf("ratio      = %.2f\n", ratio);
    fossil_io_printf("pi         = %.15f\n", pi);
    fossil_io_putchar('\n');

    fossil_io_printf("{magenta,bold}Metadata{normal}\n");
    fossil_io_printf("length     = %zu\n", length);
    fossil_io_printf("delta      = %td\n", delta);
    fossil_io_printf("letter     = %c\n", letter);
    fossil_io_printf("message    = %s\n", message);
    fossil_io_printf("value      = %d\n", *(int *)data);
    fossil_io_printf("view       = %d\n", *(const int *)view);
    fossil_io_printf("type_id    = %s\n", tid);
    fossil_io_printf("symbol     = %s\n", key);
    fossil_io_printf("options    = 0x%016llX\n", (unsigned long long)options);
    fossil_io_printf("node_id    = %llu\n", (unsigned long long)node);
    fossil_io_printf("entropy    = %.2f\n", uncertainty);

    fossil_io_draw_horizontal_line(50, '=');
    fossil_io_putchar('\n');

    return 0;
}
