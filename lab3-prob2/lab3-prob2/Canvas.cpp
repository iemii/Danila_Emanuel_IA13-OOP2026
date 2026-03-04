#include "Canvas.h"
#include <iostream>
#include <cmath>

Canvas::Canvas(int width, int height)
{
	this->width = width;
	this->height = height;
	matrix = new char* [height];
	for (int i = 0; i < height; i++)
		matrix[i] = new char[width];//aloc dinamic matricea
	Clear();//init cu spatii goale
}

Canvas::~Canvas()//pt stergerea matricii cand am terminat
{
	for (int i = 0; i < height; i++)
		delete[] matrix[i];
	delete[] matrix;
}

void Canvas::Clear()
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			matrix[i][j] = ' ';
}

void Canvas::Print()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			std::cout << matrix[i][j] << ' ';
		std::cout << std::endl;
	}
}

void Canvas::SetPoint(int x, int y, char ch)
{
	if (x >= 0 && x < width && y >= 0 && y < height)
		matrix[y][x] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	if (x1 == x2)//linie verticala (pt laturile stanga dreapta la dreptunghi)
	{
		int startY = std::min(y1, y2);
		int endY = std::max(y1, y2);
		for (int y = startY; y <= endY; y++)
			SetPoint(x1, y, ch);
		return;
	}
	if (y1 == y2)//laturile sus jos
	{
		int startX = std::min(x1, x2);
		int endX = std::max(x1, x2);
		for (int x = startX; x <= endX; x++)
			SetPoint(x,y1,ch);
		return;
	}
	//pt linii oblice
	if (x1 > x2)//desenam de la stanga la dreapta
	{
		std::swap(x1, x2);
		std::swap(y1, y2);
	}

	//alg bresenham
	int dx = x2 - x1;
	int dy = y2 - y1;
	int D = 2 * dy - dx;
	int y = y1;

	for (int x = x1; x <= x2; x++)
	{
		SetPoint(x, y, ch);
		if (D > 0)
		{
			y = y + 1;
			D = D + (2 * (dy - dx));
		}
		else
		{
			D = D + 2 * dy;
		}
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	DrawLine(left, top, right, top, ch);//sus
	DrawLine(left, bottom, right, bottom, ch);//jos
	DrawLine(left, top, left, bottom, ch);//stanga
	DrawLine(right, top, right, bottom, ch);//dreapta
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top; i <= bottom; i++)
		for (int j = left; j <= right; j++)
			SetPoint(j, i, ch);
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	for(int i=0;i<height;i++)
		for (int j = 0; j < width; j++)
		{
			int dist = (i - y) * (i - y)+(j - x) * (j - x);//distanta la patrat de la punctul curent la centru
			if (dist >= ray * (ray - 1) && dist <= ray * (ray + 1))//verific daca punctul este pe conturul cercului
				SetPoint(j, i, ch);
		}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for(int i=0;i<height;i++)
		for (int j = 0; j < width; j++)
		{
			int dist = (i - y) * (i - y)+(j - x) * (j - x);
			if (dist <= ray * ray)
				SetPoint(j, i, ch);
		}
}