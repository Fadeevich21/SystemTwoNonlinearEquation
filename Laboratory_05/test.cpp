#include "test.hpp"
#include "SystemTwoNonlinearEquation.hpp"
#include <iostream>
#include <iomanip>

using namespace std;
using namespace cm;

namespace test
{

	void test_solve(const SystemTwoNonlinearEquation &systemTwoNonlinearEquation, const BaseType &x0, const BaseType &y0, const BaseType &epsilon)
	{
		pair<BaseType, BaseType> result = systemTwoNonlinearEquation.solve(x0, y0, epsilon);
		bool check = systemTwoNonlinearEquation.checkSolve(x0, y0, epsilon);

		cout << "Результат:\n";
		cout << "Результат можно получить за " << systemTwoNonlinearEquation.getMaxCountIteration() <<  " итераций: " << boolalpha << check << "\n";
		
		if (check)
		{
			cout << fixed << setprecision(7) << "x = " << result.first << "\n";
			cout << fixed << setprecision(7) << "y = " << result.second << "\n";
		}

		cout << "\n";
	}

	void test_exampleMethod()
	{
		cout << "Test name: test_exampleMethod\n\n";


		Function functionOne = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(x * x + y * y - 4);
		};

		Function functionTwo = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(x * x - y);
		};

		Function derivativeOfFunctionOneByVariableX = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(2 * x);
		};

		Function derivativeOfFunctionTwoByVariableX = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(2 * x);
		};

		Function derivativeOfFunctionOneByVariableY = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(2 * y);
		};
		
		Function derivativeOfFunctionTwoByVariableY = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(-1);
		};
		
		size_t maxCountIteration = 1000;

		SystemTwoNonlinearEquation systemTwoNonlinearEquation(functionOne, functionTwo,
															  derivativeOfFunctionOneByVariableX,
															  derivativeOfFunctionTwoByVariableX,
															  derivativeOfFunctionOneByVariableY,
															  derivativeOfFunctionTwoByVariableY,
															  maxCountIteration);

		BaseType x0 = 1.5L;
		BaseType y0 = 1.5L;

		BaseType epsilon = 0.001L;

		test_solve(systemTwoNonlinearEquation, x0, y0, epsilon);
	}

	void test_internet_01()
	{
		cout << "Test name: test_internet_01\n\n";

		Function functionOne = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(x * x + y * y - 1);
		};

		Function functionTwo = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(x * x * x - y);
		};

		Function derivativeOfFunctionOneByVariableX = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(2 * x);
		};

		Function derivativeOfFunctionTwoByVariableX = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(3 * x * x);
		};

		Function derivativeOfFunctionOneByVariableY = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(2 * y);
		};

		Function derivativeOfFunctionTwoByVariableY = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(-1);
		};

		size_t maxCountIteration = 1000;

		SystemTwoNonlinearEquation systemTwoNonlinearEquation(functionOne, functionTwo,
															  derivativeOfFunctionOneByVariableX,
															  derivativeOfFunctionTwoByVariableX,
															  derivativeOfFunctionOneByVariableY,
															  derivativeOfFunctionTwoByVariableY,
															  maxCountIteration);

		BaseType x0 = 0.9L;
		BaseType y0 = 0.5L;

		BaseType epsilon = 0.0001L;

		test_solve(systemTwoNonlinearEquation, x0, y0, epsilon);
	}

	void test_internet_02()
	{
		cout << "Test name: test_internet_02\n\n";

		Function functionOne = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(sinl(2 * x - y) - 1.2L * x - 0.4L);
		};

		Function functionTwo = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(0.8L * x * x + 1.5L * y * y - 1);
		};

		Function derivativeOfFunctionOneByVariableX = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(2 * cosl(2 * x - y) - 1.2L);
		};

		Function derivativeOfFunctionTwoByVariableX = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(1.6 * x);
		};

		Function derivativeOfFunctionOneByVariableY = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(-cosl(2 * x - y));
		};

		Function derivativeOfFunctionTwoByVariableY = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(3 * y);
		};

		size_t maxCountIteration = 1000;

		SystemTwoNonlinearEquation systemTwoNonlinearEquation(functionOne, functionTwo,
															  derivativeOfFunctionOneByVariableX,
															  derivativeOfFunctionTwoByVariableX,
															  derivativeOfFunctionOneByVariableY,
															  derivativeOfFunctionTwoByVariableY,
															  maxCountIteration);

		BaseType x0 = 0.4L;
		BaseType y0 = -0.75L;

		BaseType epsilon = 0.001L;

		test_solve(systemTwoNonlinearEquation, x0, y0, epsilon);
	}

	void test_internet_03()
	{
		cout << "Test name: test_internet_03\n\n";

		Function functionOne = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(x * x + x - y * y - 0.15L);
		};

		Function functionTwo = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(x * x - y + y * y + 0.17L);
		};

		Function derivativeOfFunctionOneByVariableX = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(2 * x + 1);
		};

		Function derivativeOfFunctionTwoByVariableX = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(2 * x);
		};

		Function derivativeOfFunctionOneByVariableY = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(-2 * y);
		};

		Function derivativeOfFunctionTwoByVariableY = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(2 * y -1);
		};

		size_t maxCountIteration = 1000;

		SystemTwoNonlinearEquation systemTwoNonlinearEquation(functionOne, functionTwo,
															  derivativeOfFunctionOneByVariableX,
															  derivativeOfFunctionTwoByVariableX,
															  derivativeOfFunctionOneByVariableY,
															  derivativeOfFunctionTwoByVariableY,
															  maxCountIteration);

		BaseType x0 = 0.15L;
		BaseType y0 = 0.17L;

		BaseType epsilon =	0.0001L;

		test_solve(systemTwoNonlinearEquation, x0, y0, epsilon);
	}

	void test_variant_10()
	{
		cout << "Test name: test_variant_10\n\n";

		Function functionOne = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(sinl(4 * x) - 2.2L * y - 0.1L);
		};

		Function functionTwo = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(x * x + y * y - 4);
		};

		Function derivativeOfFunctionOneByVariableX = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(4 * cosl(4 * x));
		};

		Function derivativeOfFunctionTwoByVariableX = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(2 * x);
		};

		Function derivativeOfFunctionOneByVariableY = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(-2.2L);
		};

		Function derivativeOfFunctionTwoByVariableY = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(2 * y);
		};

		size_t maxCountIteration = 1000;

		SystemTwoNonlinearEquation systemTwoNonlinearEquation(functionOne, functionTwo,
															  derivativeOfFunctionOneByVariableX,
															  derivativeOfFunctionTwoByVariableX,
															  derivativeOfFunctionOneByVariableY,
															  derivativeOfFunctionTwoByVariableY,
															  maxCountIteration);

		BaseType x0 = 2.0L;
		BaseType y0 = 0.4L;

		BaseType epsilon = 0.001L;

		test_solve(systemTwoNonlinearEquation, x0, y0, epsilon);
	}

	void test_variant_18_notEnoughIterations()
	{
		cout << "Test name: test_variant_18_notEnoughIterations\n\n";

		Function functionOne = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(sinl(x) - 2.0L * y - 1.6L);
		};

		Function functionTwo = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(cosl(x - 3.0L) - y - 1.1L);
		};

		Function derivativeOfFunctionOneByVariableX = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(cosl(x));
		};

		Function derivativeOfFunctionTwoByVariableX = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(-sinl(x - 3.0L));
		};

		Function derivativeOfFunctionOneByVariableY = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(-2.0L);
		};

		Function derivativeOfFunctionTwoByVariableY = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(-1.0L);
		};

		size_t maxCountIteration = 2;

		SystemTwoNonlinearEquation systemTwoNonlinearEquation(functionOne, functionTwo,
															  derivativeOfFunctionOneByVariableX,
															  derivativeOfFunctionTwoByVariableX,
															  derivativeOfFunctionOneByVariableY,
															  derivativeOfFunctionTwoByVariableY,
															  maxCountIteration);

		BaseType x0 = 1.5L;
		BaseType y0 = 1.5L;

		BaseType epsilon = 0.001L;

		test_solve(systemTwoNonlinearEquation, x0, y0, epsilon);
	}

	void test_variant_18_EnoughIterations()
	{
		cout << "Test name: test_variant_18_EnoughIterations\n\n";

		Function functionOne = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(sinl(x) - 2.0L * y - 1.6L);
		};

		Function functionTwo = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(cosl(x - 3.0L) - y - 1.1L);
		};

		Function derivativeOfFunctionOneByVariableX = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(cosl(x));
		};

		Function derivativeOfFunctionTwoByVariableX = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(-sinl(x - 3.0L));
		};

		Function derivativeOfFunctionOneByVariableY = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(-2.0L);
		};

		Function derivativeOfFunctionTwoByVariableY = [](const BaseType &x, const BaseType &y)
		{
			return static_cast<BaseType>(-1.0L);
		};

		size_t maxCountIteration = 1000;

		SystemTwoNonlinearEquation systemTwoNonlinearEquation(functionOne, functionTwo,
															  derivativeOfFunctionOneByVariableX,
															  derivativeOfFunctionTwoByVariableX,
															  derivativeOfFunctionOneByVariableY,
															  derivativeOfFunctionTwoByVariableY,
															  maxCountIteration);

		BaseType x0 = 1.5L;
		BaseType y0 = 1.5L;

		BaseType epsilon = 0.001L;

		test_solve(systemTwoNonlinearEquation, x0, y0, epsilon);
	}

}
