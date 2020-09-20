#include <gl\glut.h>
struct Point
{
public:
	GLfloat m_x;
	GLfloat m_y;
	Point(GLfloat x, GLfloat y) : m_x(x),m_y(y)
	{}
};