#include "operations.hpp"
#include <boost/safe_numerics/safe_integer.hpp>

int32_t calculate::operation(std::string &S)
{
	std::cout<<"operations"<<std::endl;
	// ceparate string content to perform operations
	std::vector<std::string> result;
	boost::split(result,S, boost::is_any_of(" "));

	for(auto m : result)
	{
		if(m == "+")
		{
			if(!plus())
				return false;
		}
		else if(m == "-")
		{
			if(!min())
				return false;
		}
		else if(m == "POP")
		{
			if(!pop())
				return false;
		}
		else if(m == "DUP")
		{
			if(!dup())
				return false;
		}
		else
		{
			m_stack.push(std::stold(m));
		}
		std::cout<<"  "<<m<<"  ";
	}
	std::cout<<"\noperations done result = ";
	return m_stack.top();
}

bool calculate::pop()
{
	//
	if(m_stack.empty())
		return false;
	m_stack.pop();
	return true;
}
bool calculate::dup()
{
	//
	if(m_stack.empty())
		return false;
	m_stack.push(m_stack.top());
	return true;
}
bool calculate::min()
{
	using namespace boost::safe_numerics;
	if(m_stack.size() < 2)
		return false;
	safe<uint32_t> num1 = m_stack.top();
	m_stack.pop();
	safe<uint32_t> num2 = m_stack.top();
	m_stack.pop();

	// //check no negative
	if(num2 < num1)
		{
			std::cout<<"underflow error \n";
			return false;
		}
	safe<uint32_t> result = num2 - num1;
	m_stack.push(num2-num1);
	return true;
}
bool calculate::plus()
{
	using namespace boost::safe_numerics;
	if(m_stack.size() < 2)
		return false;
	safe<uint32_t> num1 = m_stack.top();
	m_stack.pop();
	safe<uint32_t> num2 = m_stack.top();
	m_stack.pop();
	std::cout<<"num1 = "<<num1<<" "<<"num2 = "<<num2;

	safe<uint32_t> result = num1 + num2;
	m_stack.push(num1+num2);
	return true;
}