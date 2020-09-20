class RgbaColor
{
public:
	float Red, Green, Blue, Alpha;
	RgbaColor(float red, float green, float blue, float alpha = 1)
	{
		this->Red = red;
		this->Green = green;
		this->Blue = blue;
		this->Alpha = alpha;
	}
	RgbaColor()
	{
		this->Red = 1;
		this->Blue = 1;
		this->Green = 1;
		this->Alpha = 1;
	}
};