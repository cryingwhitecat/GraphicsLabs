#include "Point.cpp"
#include "RgbaColor.cpp"
#include <vector>
class Figure
{
protected:
	std::vector<Point>* Points = new std::vector<Point>();
	RgbaColor fillColor;
	RgbaColor outlineColor;

public:
	virtual void DrawSelf() = 0;
		Figure(RgbaColor fillColor, RgbaColor outlineColor)
		{
			this->fillColor = fillColor;
			this->outlineColor = outlineColor;
		}
};