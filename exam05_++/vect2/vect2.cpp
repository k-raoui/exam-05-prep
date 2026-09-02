#include "vect2.hpp"

std::ostream &operator<<(std::ostream &os, const vect2 &v) {
        // os << "{" << v.n[0] << ", " << v.n[1] << "}";
    os << "{" << v[0] << ", " << v[1] << "}";
    return os;
}

vect2 operator*(int num, const vect2 &o) {
    return vect2(num * o[0], num * o[1]);
}