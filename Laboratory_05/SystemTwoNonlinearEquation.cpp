#include "SystemTwoNonlinearEquation.hpp"
#include "..\..\..\Libraries\Matrix\Matrix.hpp"
#include "..\..\..\Projects\Computational_Mathematich_laboratory\Laboratory_01\Laboratory_01\GaussianMethods.hpp"

namespace cm
{
	
	SystemTwoNonlinearEquation::SystemTwoNonlinearEquation(const Function &functionOne, const Function &functionTwo,
							   const Function &derivativeOfFunctionOneByVariableX,
							   const Function &derivativeOfFunctionTwoByVariableX,
							   const Function &derivativeOfFunctionOneByVariableY,
							   const Function &derivativeOfFunctionTwoByVariableY,
							   const size_t &maxCountIteration) :
		functionOne_(functionOne), functionTwo_(functionTwo),
		derivativeOfFunctionOneByVariableX_(derivativeOfFunctionOneByVariableX),
		derivativeOfFunctionTwoByVariableX_(derivativeOfFunctionTwoByVariableX),
		derivativeOfFunctionOneByVariableY_(derivativeOfFunctionOneByVariableY),
		derivativeOfFunctionTwoByVariableY_(derivativeOfFunctionTwoByVariableY),
		maxCountIteration_(maxCountIteration)
	{
	}
	
	
	pair<BaseType, BaseType> SystemTwoNonlinearEquation::solve(const BaseType &x0, const BaseType &y0, const BaseType &epsilon) const
	{
		BaseType x = x0;
		BaseType y = y0;

		size_t countVariable = 2;

		size_t countIteration = size_t();
		while (countIteration < this->maxCountIteration_ && fabsl(this->functionOne_(x, y)) + fabsl(this->functionTwo_(x, y)) >= epsilon)
		{	
			cout << fixed << setprecision(7) << "x = " << x << "\n";
			cout << fixed << setprecision(7) << "y = " << y << "\n";
			cout << "\n";

			countIteration++;

			vector<vector<BaseType>> data =
			{
				{this->derivativeOfFunctionOneByVariableX_(x, y), this->derivativeOfFunctionOneByVariableY_(x, y), -1 * this->functionOne_(x, y)},
				{this->derivativeOfFunctionTwoByVariableX_(x, y), this->derivativeOfFunctionTwoByVariableY_(x, y), -1 * this->functionTwo_(x, y)}
			};

			Matrix<BaseType> matr(data);
			Matrix<BaseType> matrResult = SolvingSystemEquations(matr, countVariable);

			vector<BaseType> vecResult(2);
			for (size_t index = 0; index < countVariable; index++)
			{
				vecResult[index] = matrResult[index][0];
			}

			x += vecResult[0];
			y += vecResult[1];
		}

		if (countIteration == this->maxCountIteration_)
		{
			cout << "Было проведено слишком много итераций!\n\n";
		}

		return pair<BaseType, BaseType>(x, y);
	}

	size_t SystemTwoNonlinearEquation::getMaxCountIteration() const
	{
		return this->maxCountIteration_;
	}

	bool SystemTwoNonlinearEquation::checkSolve(const BaseType &x0, const BaseType &y0, const BaseType &epsilon) const
	{
		BaseType x = x0;
		BaseType y = y0;

		size_t countVariable = 2;

		size_t countIteration = size_t();
		while (countIteration < this->maxCountIteration_ && fabsl(this->functionOne_(x, y)) + fabsl(this->functionTwo_(x, y)) >= epsilon)
		{
			countIteration++;

			vector<vector<BaseType>> data =
			{
				{this->derivativeOfFunctionOneByVariableX_(x, y), this->derivativeOfFunctionOneByVariableY_(x, y), -1 * this->functionOne_(x, y)},
				{this->derivativeOfFunctionTwoByVariableX_(x, y), this->derivativeOfFunctionTwoByVariableY_(x, y), -1 * this->functionTwo_(x, y)}
			};

			Matrix<BaseType> matr(data);
			Matrix<BaseType> matrResult = SolvingSystemEquations(matr, countVariable);

			vector<BaseType> vecResult(2);
			for (size_t index = 0; index < countVariable; index++)
			{
				vecResult[index] = matrResult[index][0];
			}

			x += vecResult[0];
			y += vecResult[1];
		}

		return countIteration < this->maxCountIteration_;
	}

}
