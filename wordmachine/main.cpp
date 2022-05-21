#include "wordmachine.hpp"

int main()
{
	std::string test = "3 5 7 - 1 6 +";
	std::cout<<solution(test)<<std::endl;

	std::string test1 = "3 7 POP 2 - 1 6 +";
	std::cout<<solution(test1)<<std::endl;

	std::string test2 = "3 5 7 DUP - 6 +";
	std::cout<<solution(test2)<<std::endl;

	std::string test3 = "3 2 -";
	std::cout<<solution(test3)<<std::endl;
	
	std::string test4 = "4 5 6 - 7 +";
	std::cout<<solution(test4)<<std::endl;

	return true;
}