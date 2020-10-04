#pragma once

namespace Zebra
{
	__declspec(dllimport) void Print();
}

void main()
{
	Zebra::Print();
}