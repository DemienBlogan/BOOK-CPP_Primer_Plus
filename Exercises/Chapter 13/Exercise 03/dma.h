#pragma once
#include <iostream>

class abstractDMA
{
private:
	char* label;
	int rating;

protected:
	const char* GetLabel() const { return label; }
	int GetRating() const { return rating; }

public:
	abstractDMA(const char* l = "null", int r = 0);
	abstractDMA(const abstractDMA& other);

	virtual ~abstractDMA();

	virtual void View() const abstract;

	abstractDMA& operator=(const abstractDMA& other);

	friend std::ostream& operator<<(std::ostream& os, const abstractDMA& dma);
};

class baseDMA : public abstractDMA
{
public:
	baseDMA(const char* l = "null", int r = 0);
	baseDMA(const baseDMA& rs);
	
	virtual ~baseDMA();
	
	virtual void View() const override;

	baseDMA& operator=(const baseDMA& rs);
	
	friend std::ostream& operator<<(std::ostream& os, const baseDMA& rs);
};

class lacksDMA : public abstractDMA
{
private:
	enum { COL_LEN = 40 };
	char color[COL_LEN];

public:
	lacksDMA(const char* c = "blank", const char* l = "null", int r = 0);
	lacksDMA(const char* c, const abstractDMA& rs);

	virtual void View() const override;

	friend std::ostream& operator<<(std::ostream& os, const lacksDMA& ls);
};

class hasDMA : public abstractDMA
{
private:
	char* style;

public:
	hasDMA(const char* s = "none", const char* l = "null", int r = 0);
	hasDMA(const char* s, const abstractDMA& hs);
	hasDMA(const hasDMA& hs);

	~hasDMA();

	virtual void View() const override;

	hasDMA& operator=(const hasDMA& hs);

	friend std::ostream& operator<<(std::ostream& os, const hasDMA& hs);
};