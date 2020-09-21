#include "Figures.cpp"

void render_foxy();
void keyPressed(unsigned char, int, int);
void keyDepressed(unsigned char, int, int);
void idle();
bool pressed_keys[2] = { false, false };
bool not_moved = true;

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);

	glutCreateWindow("A Cute Foxy :)");

	glutDisplayFunc(render_foxy);
	glutKeyboardFunc(keyPressed);
	glutKeyboardUpFunc(keyDepressed);
	glutIdleFunc(idle);
	glutMainLoop();
	return 0;
}

void render_foxy()
{
	auto pts = new std::vector<Point>();
	pts->push_back(Point(-0.025, -0.1));
	pts->push_back(Point(-0.3, -0.4));
	pts->push_back(Point(0.4, -0.4));
	pts->push_back(Point(0.025, -0.1));

	auto pts2 = new std::vector<Point>();
	pts2->push_back(Point(-0.8, -0.2));
	pts2->push_back(Point(-0.8, 0));
	pts2->push_back(Point(-0.5, 0));
	pts2->push_back(Point(-0.5, -0.2));

	auto pts3 = new std::vector<Point>();
	pts3->push_back(Point(0.6, -0.1));
	pts3->push_back(Point(0.6, 0.1));
	pts3->push_back(Point(0.9, 0.3));
	pts3->push_back(Point(0.9, 0.1));
	glClearColor(1, 0.8, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	auto defaultFillColor = RgbaColor(0, 1, 0);
	auto defaultOutlineColor = RgbaColor(0,0,0);
	std::vector<Figure*>* figures = new std::vector<Figure*>();
	figures->push_back( new foo::Triangle(Point(-0.7, 0.4), Point(-0.8, 0), Point(-0.6, 0.2), 
		defaultFillColor, defaultOutlineColor));
	figures->push_back(new foo::Triangle(Point(-0.8, 0), Point(-0.5, 0), Point(-0.5, 0.3),
		defaultFillColor, defaultOutlineColor));
	figures->push_back(new foo::Triangle(Point(-0.5, -0.6), Point(-0.5, -0.1), Point(-0.025, -0.1),
		defaultFillColor, defaultOutlineColor));

	figures->push_back(new foo::Polygon(pts, defaultFillColor, defaultOutlineColor));
	figures->push_back(new foo::Polygon(pts2, defaultFillColor, defaultOutlineColor));
	figures->push_back(new foo::Triangle(Point(0.6,-0.6), Point(0.025, -0.1), Point(0.6,-0.1), defaultFillColor, defaultOutlineColor));
	
	figures->push_back(new foo::Polygon(pts3, defaultFillColor, defaultOutlineColor));

	for (auto i = figures->begin(); i != figures->end(); i++)
	{
		(*i)->DrawSelf();
	}
}

void keyPressed(unsigned char key, int x, int y) {
	switch (key)
	{
		case 'd':
			pressed_keys[0] = true;
			break;
		case 'w':
			pressed_keys[1] = true;
			break;
	}
}
void idle()
{
	if (pressed_keys[0] && pressed_keys[1] && not_moved)
	{
		glTranslated(-0.1, 0.1, 0);
		glutPostRedisplay();
		not_moved = false;
	}
}
void keyDepressed(unsigned char key, int x, int y)
{
	not_moved = true;
	switch (key)
	{
	case 'd':
		pressed_keys[0] = false;
		break;
	case 'w':
		pressed_keys[1] = false;
		break;
	}
}
