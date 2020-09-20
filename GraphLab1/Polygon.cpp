#include "Figure.cpp"
#include <vector>
class Polygon : public Figure
{
public:
	Polygon(std::vector<Point>* points, RgbaColor fillColor, RgbaColor outlineColor): Figure(fillColor, outlineColor)
	{
		this->Points = points;
	}
	// Inherited via Figure
	virtual void DrawSelf() override
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