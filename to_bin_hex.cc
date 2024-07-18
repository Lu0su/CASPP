#include <cstdint>
#include <iostream>

using number_size = int32_t;

char hash_table[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                       '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

void to_bin(number_size n) {
  for (int i = 0; i < 32; ++i) {
    int h = (n & 0x80000000) >> 31;
    n <<= 1;
    std::cout << h;
  }
  std::cout << std::endl;
}

void to_hex(number_size n) {
  for (int i = 0; i < 32; i += 4) {
    int h4 = (n & 0xf0000000) >> 28;
    n <<= 4;
    std::cout << hash_table[h4];
  }
  std::cout << std::endl;
}

int main() {
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
  
  return 0;
}