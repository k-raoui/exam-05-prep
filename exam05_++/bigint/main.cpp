#include "bigint.hpp"

int main()
{
    try
	{

        const bigint a(42);
        bigint b(21), c, d(1337), e(d);

        c = a;
     
        std::cout << "a = " << a << std::endl; // a = 42
        std::cout << "b = " << b << std::endl; // b = 21
        std::cout << "c = " << c << std::endl; // c = 84
        std::cout << "d = " << d << std::endl; // d = 1337
        std::cout << "e = " << e << std::endl; // e = 1337
        std::cout << "a + d = " << a + d << std::endl; // a + d = 1379
        std::cout << "a + b = " << a + b << std::endl; // a + b = 63
        std::cout << "(c += a) = " << (c += a) << std::endl; // c += a = 42 (c = 0 and a = 42 )

        std::cout << "b = " << b << std::endl; // b = 21
        std::cout << "++b = " << ++b << std::endl; // b = 22
        std::cout << "b++ = " << b++ << std::endl; // b = 22 then b will be after increment b = 23
        std::cout << "b = " << b << std::endl; // b = 23


        std::cout << "(b << 10) + 42 = " << ((b << 10) + 42) << std::endl; // (b << 10) + 42 = 230000000042 ; [(b << 10) = 230000000000]
        std::cout << "(d <<= 4) = " << (d <<= 4) << std::endl; // (d <<= 4) = 13370000
        std::cout << "(d >>= 2) = " << (d >>= (const bigint)2) << std::endl; // (d >>= 2) = 133700

        std::cout << "a = " << a << std::endl; // a = 42
        std::cout << "d = " << d << std::endl; // d = 133700

        std::cout << "(d < a) = " << (d < a) << std::endl; // 0
        bigint aa(4);
        bigint bb(5);
        std::cout << "(aa < bb) = " << (aa < bb) << std::endl; // 0
        std::cout << "(d > a) = " << (d > a) << std::endl; // 1
        std::cout << "(d == a) = " << (d == a) << std::endl; // 0
        std::cout << "(d != a) = " << (d != a) << std::endl; // 1
        std::cout << "(d <= a) = " << (d <= a) << std::endl; // 0
        std::cout << "(d >= a) = " << (d >= a) << std::endl; // 1
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}