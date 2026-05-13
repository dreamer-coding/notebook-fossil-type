#include "fossil/type/types.h"
#include "fossil/io/output.h"
#include <iostream>

using namespace fossil::type;
using namespace fossil::io;

int main()
{
    /* Numeric wrappers */
    I32 count(-42);
    I64 population(8045312345LL);

    /* Semantic aliases */
    H32 color(0xFFAA33CC);
    O16 permissions(0755);
    B8 mask(0xAA);

    /* Floating point */
    F32 ratio(0.75f);
    F64 pi(3.141592653589793);

    /* Size wrappers */
    Usize length(128);
    Isize delta(-12);

    /* Text wrappers */
    Char_t letter('F');
    Cstr message("Hello from Fossil Types");

    /* Pointer wrappers */
    int value = 123;
    Ptr data(&value);
    Cptr view(&value);

    /* Metadata wrappers */
    Type_id tid("i32");
    Symbol key("max_items");

    /* Bit flags and IDs */
    Flags options((1ULL << 0) | (1ULL << 3));
    Node_id node(42);
    Entropy uncertainty(0.73);

    /* Arithmetic using wrapper types */
    I32 total = count + I32(100);

    Output::printf("{cyan,bold}Numeric wrappers{normal}\n");
    out << "count       = " << static_cast<int32_t>(count) << std::endl;
    out << "population  = " << static_cast<int64_t>(population) << std::endl;
    out << "total       = " << static_cast<int32_t>(total) << std::endl;
    out << std::endl;

    Output::printf("{green,bold}Semantic aliases{normal}\n");
    out << "color       = 0x" << std::hex
        << static_cast<uint32_t>(color) << std::dec << std::endl;
    out << "permissions = " << static_cast<uint16_t>(permissions) << std::endl;
    out << "mask        = " << static_cast<unsigned>(static_cast<uint8_t>(mask))
        << std::endl;
    out << std::endl;

    Output::printf("{yellow,bold}Other wrappers{normal}\n");
    out << "ratio       = " << static_cast<float>(ratio) << std::endl;
    out << "pi          = " << static_cast<double>(pi) << std::endl;
    out << "length      = " << static_cast<size_t>(length) << std::endl;
    out << "delta       = " << static_cast<ptrdiff_t>(delta) << std::endl;
    out << "letter      = " << static_cast<char>(letter) << std::endl;
    out << "message     = " << static_cast<const char *>(message) << std::endl;
    out << "value       = " << *static_cast<int *>(data) << std::endl;
    out << "view        = " << *static_cast<const int *>(view) << std::endl;
    out << "type_id     = " << static_cast<const char *>(tid) << std::endl;
    out << "symbol      = " << static_cast<const char *>(key) << std::endl;
    out << "options     = " << static_cast<uint64_t>(options) << std::endl;
    out << "node_id     = " << static_cast<uint64_t>(node) << std::endl;
    out << "entropy     = " << static_cast<double>(uncertainty) << std::endl;

    Output::draw_horizontal_line(50, '=');
    out << std::endl;

    return 0;
}
