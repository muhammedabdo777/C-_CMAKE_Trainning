#ifndef _WORDASTRATEGY_HPP
#define _WORDASTRATEGY_HPP

#include <boost/safe_numerics/safe_integer.hpp>
#include<stdint.h>
#include<iostream>
#include<vector>
#include<string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <stack>
// this header file contains boost::split function
#include<bits/stdc++.h>
#include<boost/algorithm/string.hpp>

/**
 * The Strategy interface declares operations common to all supported versions
 * of some algorithm.
 *
 * The Context uses this interface to call the algorithm defined by Concrete
 * Strategies.
 */
class Strategy
{
public:
    virtual ~Strategy() {}
    virtual int32_t DoAlgorithm(void) = 0;
protected:
    std::stack<uint32_t> m_stack;
};



/**
 * The Context defines the interface of interest to clients.
 */

class Context
{
    /**
     * @var Strategy The Context maintains a reference to one of the Strategy
     * objects. The Context does not know the concrete class of a strategy. It
     * should work with all strategies via the Strategy interface.
     */
private:
    Strategy *strategy_;
    /**
     * Usually, the Context accepts a strategy through the constructor, but also
     * provides a setter to change it at runtime.
     */
public:
    Context(Strategy *strategy = nullptr) : strategy_(strategy)
    {
    }
    ~Context()
    {
        delete this->strategy_;
    }
    /**
     * Usually, the Context allows replacing a Strategy object at runtime.
     */
    void set_strategy(Strategy *strategy)
    {
        delete this->strategy_;
        this->strategy_ = strategy;
    }
    /**
     * The Context delegates some work to the Strategy object instead of
     * implementing +multiple versions of the algorithm on its own.
     */
    int32_t doOperationLogic(std::string &S) const
    {
        std::string result = this->strategy_->DoAlgorithm();
        std::cout << "doOperationLogic\n";
        std::cout << result << "\n";
	}

};
#endif
