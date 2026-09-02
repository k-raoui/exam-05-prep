#ifndef VECT2_HTTP
#define VECT2_HTTP

#include <iostream>

class vect2 {
private:
    int n[2];
public:
    vect2() {
        n[0] = 0;
        n[1] = 0;
    }
    vect2(int x, int y) {
        n[0] = x;
        n[1] = y;
    }
    vect2(const vect2 &o) {
        n[0] = o.n[0];
        n[1] = o.n[1];
    }
    vect2 &operator=(const vect2 &o) {
        if (this != &o) {
            n[0] = o.n[0];
            n[1] = o.n[1];
        }
        return *this;
    }

    int operator[](int id) const {
        return (id == 0 ? n[0] : n[1]);
    }

    int &operator[](int id) {
        return n[id];
    }

    vect2 operator++(int) {
        vect2 tmp(*this);
        this->n[0]++;
        this->n[1]++;
        return tmp;
    }

    vect2 &operator++() {
        this->n[0]++;
        this->n[1]++;
        return *this;
    }
    vect2 operator--(int) {
        vect2 tmp(*this);
        this->n[0]--;
        this->n[1]--;
        return tmp;
    }

    vect2 &operator--() {
        this->n[0]--;
        this->n[1]--;
        return *this;
    }

    vect2 &operator+=(const vect2 &o) {
        n[0] += o.n[0];
        n[1] += o.n[1];
        return *this;
    }
    vect2 &operator-=(const vect2 &o) {
        n[0] -= o.n[0];
        n[1] -= o.n[1];
        return *this;
    }

    vect2 operator+(const vect2 &o) const {
        vect2 tmp(*this);
        tmp += o;
        return tmp;
    }

    vect2 operator-(const vect2 &o) const {
        return vect2(n[0] - o[0], n[1] - o[1]);
    }

    vect2 operator*(int num) const {
        vect2 tmp(*this);
        tmp.n[0] = tmp.n[0] * num;
        tmp.n[1] = tmp.n[1] * num;
        return tmp;
    }

    vect2 &operator*=(int num) {
        n[0] *= num;
        n[1] *= num;
        return *this;
    }

    vect2 operator-() {
        return vect2(-n[0], -n[1]);
    }

    bool operator==(const vect2 &o) {
        return n[0] == o.n[0] && n[1] == o.n[1];
    }

     bool operator!=(const vect2 &o) {
        return n[0] != o.n[0] || n[1] != o.n[1];
    }
    
};

vect2 operator*(int num, const vect2 &o);
std::ostream &operator<<(std::ostream &os, const vect2 &v);

#endif