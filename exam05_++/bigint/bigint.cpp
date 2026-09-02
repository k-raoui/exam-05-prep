#include "bigint.hpp"

std::ostream &operator<<(std::ostream &o, const bigint &b) {
    o << b.getValue();
    return o;
}