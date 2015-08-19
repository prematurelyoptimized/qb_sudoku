#ifndef SUDOKU_UTILS
#define SUDOKU_UTILS

#include<cstdint>
#include<cstddef>
#include"defs.hpp"

uint32_t extractLowBit(const uint32_t v);

inline bool powerof2(const uint32_t v) {
	return  v!=0 && (v&(v-1))==0;
}

template<int n>
uint32_t bitwiseAllButOne(const uint32_t v[]) {
	uint32_t seenAZero = 0;
	uint32_t seen2Zeros = 0;
	for(size_t i=0;i<n;i++) {
		seen2Zeros |= (seenAZero & ~v[i]);
		seenAZero |= ~v[i];
	}
	return seenAZero & ~seen2Zeros;
}

inline uint32_t popcount(uint32_t v) {
	// From: http://graphics.stanford.edu/~seander/bithacks.html
	v = v - ((v >> 1) & 0x55555555);                   	 	// reuse input as temporary
	v = (v & 0x33333333) + ((v >> 2) & 0x33333333);		     	// temp
	return (((v + (v >> 4)) & 0xF0F0F0F) * 0x1010101) >> 24; // count
}
#endif
