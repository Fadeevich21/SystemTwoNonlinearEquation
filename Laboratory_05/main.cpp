#include <iostream>
#include <windows.h>

#include "test.hpp"

using namespace test;
using namespace std;

void test_();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Привет, Мир!" << "\n\n";

	test_();

	return 0;
}

void test_()
{
	test_exampleMethod();

	test_internet_01();
	test_internet_02();
	test_internet_03();

	test_variant_10();

	test_variant_18_notEnoughIterations();
	test_variant_18_EnoughIterations();
}
