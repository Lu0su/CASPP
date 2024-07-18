#include <cstdint>
#include <iostream>

using number_size = int32_t;
using byte_type = unsigned char;
using byte_ptr = byte_type*;

char hash_table[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

void to_bin(number_size n)
{
    for (int i = 0; i < 32; ++i)
    {
        int h = (n & 0x80000000) >> 31;
        n <<= 1;
        std::cout << h;
    }
    std::cout << std::endl;
}

void to_hex(number_size n)
{
    for (int i = 0; i < 32; i += 4)
    {
        int h4 = (n & 0xf0000000) >> 28;
        n <<= 4;
        std::cout << hash_table[h4];
    }
    std::cout << std::endl;
}

void to_bin_any(byte_ptr bytes, int n)
{
    for (int i = n - 1; i > -1; --i)
    {
        // 每个字节，由高字节到第字节
        byte_type byte = bytes[i];
        for (int k = 0; k < 8; ++k)
        {
            int h = (byte & 0x80) >> 7;
            byte <<= 1;
            std::cout << h;
        }
    }
    std::cout << std::endl;
}

void to_hex_any(byte_ptr bytes, int n)
{
    for (int i = n - 1; i > -1; --i)
    {
        byte_type byte = bytes[i];
        for (int k = 0; k < 8; k += 4)
        {
            int h4 = (byte & 0xf0) >> 4;
            byte <<= 4;
            std::cout << hash_table[h4];
        }
    }
    std::cout << std::endl;
}

void show_bytes(byte_ptr bytes, int n)
{
    for (size_t i = 0; i < n; ++i)
    {
        printf(" %.2x", bytes[i]);
    }
    puts("\n");
}

void show_int(int x)
{
    show_bytes((byte_ptr) &x, sizeof(int));
}

void show_float(float x)
{
    show_bytes((byte_ptr) &x, sizeof(float));
}

void showo_ptr(void* x)
{
    show_bytes((byte_ptr) x, sizeof(void*));
}

int main()
{
    to_bin(1);
    to_bin(2);
    to_bin(4);
    to_bin(8);
    to_bin(16);

    to_hex(1);
    to_hex(2);
    to_hex(10);
    to_hex(11);
    to_hex(12);
    to_hex(13);
    to_hex(14);
    to_hex(15);

    to_bin(3096);
    to_bin(-3096);

    // show_int(3510593);
    // to_hex(3510593);
    // show_float(3510593.0);

    int x = 100;
    to_bin(x);
    to_bin_any((byte_ptr) &x, sizeof(int));

    int y = 1023;
    to_hex(y);
    to_hex_any((byte_ptr) &y, sizeof(int));

    std::cout << "-----------test for float--------------" << std::endl;
    float zf = 302945.0;
    int zi = 302945;
    to_hex_any((byte_ptr) &zf, sizeof(float));
    to_hex_any((byte_ptr) &zi, sizeof(int));

    to_bin_any((byte_ptr) &zf, sizeof(float));
    to_bin_any((byte_ptr) &zi, sizeof(int));

    return 0;
}