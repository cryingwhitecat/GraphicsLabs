#include "Figure.cpp"
class Rectangle : public Figure
{
public:
	Rectangle(Point a, Point b, Point c, Point d, RgbaColor fillColor, RgbaColor outlineColor) : Figure(fillColor, outlineColor)
	{
		this->Points->push_back(a);
		this->Points->push_back(b);
		this->Points->push_back(c);
		this->Points->push_back(d);
	}
	virtual void DrawSelf() override
	{
		if (this->Points->empty())
		{
			throw "Can't draw a polygon with no vertices";
		}
		this->DrawWithGLUT();
	}
private:
	void DrawWithGLUT()
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glColor4f(this->fillColor.Alpha, this->fillColor.Green,
			this->fillColor.Blue, this->fillColor.Alpha);
		glBegin(GL_POLYGON);
		for (int i = 0; i < this->Points->size(); i++)
		{
			glVertex2f(this->Points->at(i).m_x, this->Points->at(i).m_y);
		}
		glEnd();

		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glEnable(GL_POLYGON_OFFSET_LINE);
		glLineWidth(1.5f);
		glColor4f(this->outlineColor.Alpha, this->outlineColor.Green,
			this->outlineColor.Blue, this->outlineColor.Alpha);

		glBegin(GL_POLYGON);
		for (int i = 0; i < this->Points->size(); i++)
		{
			glVertex2f(this->Points->at(i).m_x, this->Points->at(i).m_y);
		}
		glEnd();

		glutSwapBuffers();
	}
};