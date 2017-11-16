#include "stdafx.h"
#include <iostream>
#include <ctype.h>
#include "Checker.h"

Checker::Checker()
{

}
Checker::Checker(Colour col, char column, char row)
{
	colour = col;
	SetPosition(column, row);
}

Checker::~Checker()
{

}

void Checker::SetPosition(char c, int r)
{
	column = c;
	row = r;
}

