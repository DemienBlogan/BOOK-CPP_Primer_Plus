#pragma once

#include <string>
#include <fstream>

enum ClassKind 
{ 
	EMPLOYEE,
	MANAGER,
	FINK,
	HIGHFINK
};

class abstr_emp
{
private:
	std::string fname;
	std::string lname;
	std::string job;

public:
	abstr_emp() = default;
	abstr_emp(const std::string& fn, const std::string& ln,	const std::string& j);
	
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void WriteAll(std::ofstream& file) const;
	virtual void ReadAll(std::ifstream& file);

	friend std::ostream& operator<<(std::ostream& os, const abstr_emp& e);

	virtual ~abstr_emp() = 0;
};

class employee : public abstr_emp
{
public:
	employee() = default;
	employee(const std::string& fn, const std::string& ln, const std::string& j);

	virtual void ShowAll() const override;
	virtual void SetAll() override;
	virtual void WriteAll(std::ofstream& file) const override;
	virtual void ReadAll(std::ifstream& file) override;

	virtual ~employee() = default;
};

class manager : virtual public abstr_emp
{
private:
	int inchargeof;

protected:
	int InChargeOf() const { return inchargeof; }
	int& InChargeOf() { return inchargeof; }

public:
	manager();
	manager(const std::string& fn, const std::string& ln, const std::string& j, int ico = 0);
	manager(const abstr_emp& e, int ico);
	manager(const manager& m);

	virtual void ShowAll() const override;
	virtual void SetAll() override;
	virtual void WriteAll(std::ofstream& file) const override;
	virtual void ReadAll(std::ifstream& file) override;

	virtual ~manager() = default;
};

class fink : virtual public abstr_emp
{
private:
	std::string reportsto;

protected:
	const std::string ReportsTo() const { return reportsto; }
	std::string& ReportsTo() { return reportsto; }

public:
	fink();
	fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo);
	fink(const abstr_emp& e, const std::string& rpo);
	fink(const fink& e);

	virtual void ShowAll() const override;
	virtual void SetAll() override;
	virtual void WriteAll(std::ofstream& file) const override;
	virtual void ReadAll(std::ifstream& file) override;

	virtual ~fink() = default;
};

class highfink : public manager, public fink
{
public:
	highfink() = default;
	highfink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo, int ico);
	highfink(const abstr_emp& e, const std::string& rpo, int ico);
	highfink(const fink& f, int ico);
	highfink(const manager& m, const std::string& rpo);
	highfink(const highfink& h);

	virtual void ShowAll() const override;
	virtual void SetAll() override;
	virtual void WriteAll(std::ofstream& file) const override;
	virtual void ReadAll(std::ifstream& file) override;

	virtual ~highfink() = default;
};