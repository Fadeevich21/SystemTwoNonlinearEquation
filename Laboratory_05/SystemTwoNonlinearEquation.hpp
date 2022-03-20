#pragma once

#include "utility.hpp"
#include <utility>

using namespace std;
using namespace utility;

// cm - computational mathematics
namespace cm
{
	using Function = BaseType (*) (const BaseType &x, const BaseType &y);

	class SystemTwoNonlinearEquation
	{
	private:
		Function functionOne_;
		Function functionTwo_;

		Function derivativeOfFunctionOneByVariableX_;
		Function derivativeOfFunctionTwoByVariableX_;

		Function derivativeOfFunctionOneByVariableY_;
		Function derivativeOfFunctionTwoByVariableY_;

		size_t maxCountIteration_;

	public:
		SystemTwoNonlinearEquation(const Function &functionOne, const Function &functionTwo,
								   const Function &derivativeOfFunctionOneByVariableX,
								   const Function &derivativeOfFunctionTwoByVariableX,
								   const Function &derivativeOfFunctionOneByVariableY,
								   const Function &derivativeOfFunctionTwoByVariableY,
								   const size_t &maxCountIteration);

		pair<BaseType, BaseType> solve(const BaseType &x0, const BaseType &y0, const BaseType &epsilon) const;
		bool checkSolve(const BaseType &x0, const BaseType &y0, const BaseType &epsilon) const;

		size_t getMaxCountIteration() const;
	};

}
