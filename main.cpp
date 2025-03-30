#include <SFML/Graphics.hpp>
#include "Shapes.h"
/*
    This version of the SFML "hello world" is statically linked, you may wish to try the dynamically linked version as well.
*/
#ifdef _DEBUG
int main()
#else
int WinMain()
#endif
{
	unsigned int width = 640;
	unsigned int height = 480;

	Shapes shape(width, height);
	shape.Run();

	return 0;
}