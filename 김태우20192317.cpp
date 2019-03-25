
#include "pch.h"
#include <iostream>

#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")

#include <math.h>

#define M_PI       3.14159265358979323846   // pi

void getPlayerFrontSpace(int distance, int deltaX, int deltaY, int deltaZ, int* sx, int* sy, int* sz, int* ex, int* ey, int* ez)
{
	int px, py, pz;
	getPlayerLocation(&px, &py, &pz);

	double dir = getPlayerDirection();		
											
	double radian = dir * M_PI / 180.;		
	int dx = -distance * sin(radian);		
	int dz = distance * cos(radian);		

	if (dx > 0) {
		*sx = px + dx - deltaX / 2;
		*ex = *sx + deltaX - 1;
	}
	else {
		*ex = px + dx + deltaX / 2;
		*sx = *ex - deltaX + 1;
	}

	if (dz > 0) {
		*sz = pz + dz - deltaZ / 2;
		*ez = *sz + deltaZ - 1;
	}
	else {
		*ez = pz + dz + deltaZ / 2;
		*sz = *ez - deltaZ + 1;
	}

	*sy = py;
	*ey = *sy + deltaY - 1;
}

int main()
{
	int sx, sy, sz;
	int ex, ey, ez;

	const int delta = 9;
	getPlayerFrontSpace(10, delta, delta, delta / 2 + 1, &sx, &sy, &sz, &ex, &ey, &ez);

	printf("(%d, %d, %d) - (%d, %d, %d)\n", sx, sy, sz, ex, ey, ez);

	BlockID sandstone = createBlock(BLOCK_SAND_STONE);
	BlockID redsandstone = createBlock(BLOCK_RED_SANDSTONE);
	WoolID green = createWool(COLOR_GREEN);
	WoolID lightblue = createWool(COLOR_LIGHT_BLUE);
	WoolID yellow = createWool(COLOR_YELLOW);
	WoolID black = createWool(COLOR_BLACK);
	int x, y, z;
	for (y = 0; y < 3; y++) {
		for (x = y; x < delta - y; x++) {
			for (z = y; z < delta - y; z++) {
				locateBlock(sandstone, sx + x, sy + y, sz + z);
				locateBlock(redsandstone, sx + x, sy + y + 8, sz + z);
				locateWool(green, sx + x + 6, sy + y + 3, sz + z + 6);
				locateWool(lightblue, sx + x + 6, sy + y + 4, sz + z - 6);
				locateWool(yellow, sx + x - 6, sy + y + 5, sz + z - 6);
				locateWool(black, sx + x - 6, sy + y + 6, sz + z + 6);
			}
		}
	}

	BlockID lapis = createBlock(BLOCK_LAPIS_LAZULI);
	for (x = y; x < delta - y; x++) {
		for (z = y; z < delta - y; z++) {
			locateBlock(lapis, sx + x, sy + y + 2, sz + z);
		}
	}

	BlockID lapis2 = createBlock(BLOCK_LAPIS_LAZULI);
	for (x = y; x < delta - y; x++) {
		for (z = y; z < delta - y; z++) {
			locateBlock(lapis2 , sx + x, sy + y - 1, sz + z);
		}
	}

	BlockID lapis3 = createBlock(BLOCK_LAPIS_LAZULI);
	for (x = y; x < delta - y; x++) {
		for (z = y; z < delta - y; z++) {
			locateBlock(lapis3, sx + x, sy + y + 3, sz + z);
		}
	}

	BlockID lapis4 = createBlock(BLOCK_LAPIS_LAZULI);
	for (x = y; x < delta - y; x++) {
		for (z = y; z < delta - y; z++) {
			locateBlock(lapis4, sx + x, sy + y + 4, sz + z);
		}
	}

	BlockID lapis5 = createBlock(BLOCK_LAPIS_LAZULI);
	for (x = y; x < delta - y; x++) {
		for (z = y; z < delta - y; z++) {
			locateBlock(lapis5, sx + x, sy + y + 5, sz + z);
		}
	}

	BlockID lapis6 = createBlock(BLOCK_LAPIS_LAZULI);
	for (x = y; x < delta - y; x++) {
		for (z = y; z < delta - y; z++) {
			locateBlock(lapis6, sx + x, sy + y + 6, sz + z);
		}
	}

	BlockID lapis7 = createBlock(BLOCK_LAPIS_LAZULI);
	for (x = y; x < delta - y; x++) {
		for (z = y; z < delta - y; z++) {
			locateBlock(lapis7, sx + x, sy + y + 7, sz + z);
		}
	}

	BlockID glass = createBlock(BLOCK_GLASS);
	BlockID soul = createBlock(BLOCK_SOUL_SAND);
	int n;
	for (x = y, n = 0; x < delta - y; x++) {
		for (z = y; z < delta - y; z++, n++) {
			locateBlock((n % 2) ? glass : soul , sx + x, sy + y, sz + z);
		}
	}

	BlockID glass2 = createBlock(BLOCK_GLASS);
	BlockID soul2 = createBlock(BLOCK_SOUL_SAND);
	int k;
	for (x = y, k = 0; x < delta - y; x++) {
		for (z = y; z < delta - y; z++, k++) {
			locateBlock((k % 2) ? glass2 : soul2, sx + x, sy + y + 1, sz + z);
		}
	}


}