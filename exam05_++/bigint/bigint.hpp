#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>


class bigint {
    private:
        std::string value;
    public:
        bigint(): value("0") {}
        bigint(int num) {
            std::stringstream ss;
            ss << num;
            value = ss.str();
        }
        bigint(const bigint &o): value(o.value) { }
        bigint &operator=(const bigint &o) {
            if (this != &o)
                value = o.value;
            return *this;
        }
        std::string getValue() const {
            return value;
        }
        ~bigint() {}

        bigint operator+(const bigint &o) const {
            int len = std::max(value.size(), o.value.size());
            std::string s1 = value;
            std::string s2 = o.value;
            s1.insert(0, len - s1.size(), '0');
            s2.insert(0, len - s2.size(), '0');
            std::string val;
            int carry = 0;
            for (int i = len - 1; i >= 0 ; i--)
            {
                int res = carry + (s1[i] - '0') + (s2[i] - '0');
                carry = res / 10;
                val.insert(0, 1, (res % 10) + '0');
            }
            bigint b;
            b.value = val;
            return b;
        }

        bigint &operator+=(const bigint &o) {
            *this = *this + o;
            return *this;
        }

        bigint &operator++() {
            *this += bigint(1);
            return *this;
        }

        bigint operator++(int) {
            bigint tmp(*this);
            *this += bigint(1);
            return tmp;
        }

        bigint operator<<(int shift) {
            bigint tmp(*this);
            for(int i = 0; i < shift; i++)
                tmp.value.push_back('0');
            return tmp;
        }

        bigint &operator<<=(int shift) {
            *this = *this << shift;
            return *this;
        }

        bigint &operator>>=(const bigint v) {
            int shift = std::atoi(v.value.c_str());
            if (shift >= this->value.size())
            {
                value = "0";
                return *this;
            }
            value.erase(value.size() - shift);
            return *this;
        }

        bool operator<(const bigint &o) {
            if (value.size() != o.value.size())
                return value.size() < o.value.size();
            return value < o.value;
        }

        bool operator>(const bigint &o) {
            if (value.size() != o.value.size())
                return value.size() > o.value.size();
            return value > o.value;
        }


        bool operator==(const bigint &o) {
            return value == o.value;
        }

        bool operator!=(const bigint &o) {
            return !(value == o.value);
        }

        bool operator<=(const bigint &o) {
            return *this < o || *this == o;
        }
        bool operator>=(const bigint &o) {
            return *this > o || *this == o;
        }

};

std::ostream &operator<<(std::ostream &o, const bigint &b);


#endif