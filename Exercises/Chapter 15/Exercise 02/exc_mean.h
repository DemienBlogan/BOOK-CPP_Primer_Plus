// exc_mean.h -- exception classes for hmean(), gmean()

#include <iostream>
#include <stdexcept>

class bad_hmean : public std::logic_error
{
public:
	bad_hmean() = default;
	bad_hmean(const char* message)
		: std::logic_error(message)
	{ }

	virtual const char* what() const override
	{
		return std::logic_error::what();
	}
};

class bad_gmean : public std::logic_error
{
public:
	bad_gmean() = default;
	bad_gmean(const char* message)
		: std::logic_error(message)
	{ }

	virtual const char* what() const override
	{
		return std::logic_error::what();
	}
};