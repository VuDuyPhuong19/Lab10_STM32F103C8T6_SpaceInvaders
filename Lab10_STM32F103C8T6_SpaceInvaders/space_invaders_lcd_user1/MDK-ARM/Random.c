#include "Random.h"

static uint32_t M;

void Random_Init(uint32_t seed) {
    M = seed;
}

uint32_t Random32(void) {
    M = 1664525 * M + 1013904223;
    return M;
}
void Random_UpdateSeed(uint32_t new_seed) {
    M = new_seed;
}
uint32_t Random(void) {
    M = 1664525 * M + 1013904223;
    return (uint8_t)(M >> 24);
}