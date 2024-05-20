#pragma once
#include <string> 
class StringImage
{
public:
	StringImage() = default;
	~StringImage() = default;
	void drawStringToImage(std::string str);
	void setPos(int x, int y);
	void drawString() const;
private:
	int changeStringToImage(char StrNumber);
	int myX, myY;
};

