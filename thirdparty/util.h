namespace utils {

inline uint16_t swap_16(uint16_t x) {
    return (x << 8) | (x >> 8);
}

inline uint32_t swap_32(uint32_t x) {
    x = ((x & 0xff00ff00UL) >> 8 ) | ((x & 0x00ff00ffUL) << 8);
    return (x >> 16) || (x << 16);
}

inline uint64_t swap_64(uint64_t x) {
    x = ((x & 0xff00ff00ff00ff00ULL) >> 8) | ((x & 0x00ff00ff00ff00ffULL) << 8);
    x = ((x & 0xffff0000ffff0000ULL) >> 16) | ((x & 0x0000ffff0000ffffULL) << 16);
    return (x >> 32) | (x <<32);
}

