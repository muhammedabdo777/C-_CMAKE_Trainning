#include"wordStrategy.hpp"



class ConcreteStrategyPop : public Strategy
{
public:
    int32_t DoAlgorithm(void) override
    {
        if(m_stack.empty())
            return false;
        m_stack.pop();

        return true;
    }
};

class ConcreteStrategyDup : public Strategy
{
public:
    int32_t DoAlgorithm(void) override
    {
        if(m_stack.empty())
            return false;
        m_stack.push(m_stack.top());
        return true;
    }
};

class ConcreteStrategyPlus : public Strategy
{
public:
    int32_t DoAlgorithm(void) override
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
                return result;
            }
};

class ConcreteStrategyMinus : public Strategy
{
public:
    int32_t DoAlgorithm(void) override
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
};


void ClientCode()
{
   /* Context *context = new Context(new ConcreteStrategyA);
    std::cout << "Client: Strategy is set to normal sorting.\n";
    context->DoSomeBusinessLogic();
    std::cout << "\n";
    std::cout << "Client: Strategy is set to reverse sorting.\n";
    context->set_strategy(new ConcreteStrategyB);
    context->DoSomeBusinessLogic();
    delete context;*/
/*
         // ceparate string content to perform operations
        std::vector<std::string> result;
        boost::split(result,S, boost::is_any_of(" "));
        for(auto m : result)
	{
		if(m == "+")
		{
			if(!this->ConcreteStrategyPlus->DoAlgorithm())
				return false;
		}
		else if(m == "-")
		{
			if(!this->ConcreteStrategyMinus->DoAlgorithm())
				return false;
		}
		else if(m == "POP")
		{
			if(!this->ConcreteStrategyPop->DoAlgorithm())
				return false;
		}
		else if(m == "DUP")
		{
			if(!this->ConcreteStrategyDup->DoAlgorithm())
				return false;
		}
		else
		{
			m_stack.push(std::stold(m));
		}
		std::cout<<"  "<<m<<"  ";*/
}