#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")
#include <math.h>

int main()
{
	BlockID stone = createBlock(BLOCK_STONE);

	int sx, sy, sz, ex, ey, ez;

	printf("pos1:");
	scanf("%d %d %d", &sx, &sy, &sz);
	printf("pos2:");
	scanf("%d %d %d", &ex, &ey, &ez);

	int x1 = 0; // ū x�� ������
	int x2 = 0; // ���� x�� ������

	int y1 = 0; // ū y�� ������
	int y2 = 0; // ���� y�� ������

	int z1 = 0; // ū z�� ������
	int z2 = 0; // ���� z�� ������

	//x�� ����

	if (sx > ex)
	{
		sx = x1;
		ex = x2;
	}

	else
	{
		sx = x2;
		ex = x1;
	}

	//y�� ����

	if (sy > ey)
	{
		sy = y1;
		ey = y2;
	}

	else
	{
		sy = y2;
		ey = y1;
	}

	//z�� ����

	if (sz > ez)
	{
		sz = z1;
		ez = z2;
	}

	else
	{
		sz = z2;
		ez = z1;
	}

	// ����ü �𼭸���


	//x�࿡ ������ �𼭸� 4��
	for (int i1 = x2; i1 <= x1; i1++)
	{
		locateBlock(stone, i1, y2, z2);
	}

	for (int i2 = x2; i2 <= x1; i2++)
	{
		locateBlock(stone, i2, y1, z2);
	}

	for (int i3 = x2; i3 <= x1; i3++)
	{
		locateBlock(stone, i3, y2, z1);
	}

	for (int i4 = x2; i4 <= x1; i4++)
	{
		locateBlock(stone, i4, y1, z1);
	}

	//y�࿡ ������ �𼭸� 4��
	for (int j = y2; j <= y1; j++)
	{
		locateBlock(stone, x2, j, z2);
	}

	for (int j2 = y2; j2 <= y1; j2++)
	{
		locateBlock(stone, x1, j2, z2);
	}

	for (int j3 = y2; j3 <= y1; j3++)
	{
		locateBlock(stone, x2, j3, z1);
	}

	for (int j4 = y2; j4 <= y1; j4++)
	{
		locateBlock(stone, x1, j4, z1);
	}

	//z�࿡ ������ �𼭸� 4��
	for (int k = z2; k <= z1; k++)
	{
		locateBlock(stone, x2, y2, k);
	}

	for (int k2 = z2; k2 <= z1; k2++)
	{
		locateBlock(stone, x1, y2, k2);
	}

	for (int k3 = z2; k3 <= z1; k3++)
	{
		locateBlock(stone, x2, y1, k3);
	}

	for (int k4 = z2; k4 <= z1; k4++)
	{
		locateBlock(stone, x1, y1, k4);
	}

}