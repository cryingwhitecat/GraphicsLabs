#include "Figure.cpp"
#include <algorithm>
#include <gl/glut.h>
namespace foo {
	class Triangle : public Figure
	{
	public:
		Triangle(Point a, Point b, Point c, RgbaColor fillColor, RgbaColor outlineColor) :
			Figure(fillColor, outlineColor)
		{
			this->Points->push_back(a);
			this->Points->push_back(b);
			this->Points->push_back(c);
		}
		virtual void DrawSelf() override
		{
			if (this->Points->empty())
			{
				throw "Can't draw a triangle with no vertices";
			}
			else if (this->Points->size() < 3)
			{
				throw "A triangle should have three vertices";
			}
			this->DrawWithGLUT();
		}
	private:
		void DrawWithGLUT()
		{
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glColor4f(this->fillColor.Red, this->fillColor.Green,
				this->fillColor.Blue, this->fillColor.Alpha);
			glBegin(GL_TRIANGLES);
			for (int i = 0; i < this->Points->size(); i++)
			{

				glVertex2f(this->Points->at(i).m_x, this->Points->at(i).m_y);
			}
			glEnd();

			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			glEnable(GL_POLYGON_OFFSET_LINE);
			glLineWidth(1.5f);
			glColor4f(this->outlineColor.Red, this->outlineColor.Green,
				this->outlineColor.Blue, this->outlineColor.Alpha);

			glBegin(GL_TRIANGLES);
			for (int i = 0; i < this->Points->size(); i++)
			{
				glVertex2f(this->Points->at(i).m_x, this->Points->at(i).m_y);
			}
			glEnd();

			glutSwapBuffers();
		}
	};
	class Polygon : public Figure
	{
	public:
		Polygon(std::vector<Point>* points, RgbaColor fillColor, RgbaColor outlineColor) : Figure(fillColor, outlineColor)
		{
			this->Points = points;
		}
		// Inherited via Figure
		virtual void DrawSelf() override
		{
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glColor4f(this->fillColor.Red, this->fillColor.Green,
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
			glColor4f(this->outlineColor.Red, this->outlineColor.Green,
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
}