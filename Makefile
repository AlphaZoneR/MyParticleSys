all: object\source\Window\Cursor.o object\source\Window\Exception.o object\source\Window\Keyboard.o object\source\Main.o object\source\Utilities\MyPoint2D.o object\source\Utilities\MyVec2D.o object\source\Window\OpenGL.o object\source\Utilities\Quaternion.o object\source\Window\Settings.o object\source\Utilities\Shader.o object\source\Utilities\Shapes.o object\source\Window\Timer.o object\source\Utilities\VMath.o object\source\Window\Window.o
	g++ -m32 -std=c++11 -O3 -L library \
	object\source\Window\Cursor.o object\source\Window\Exception.o object\source\Window\Keyboard.o object\source\Main.o object\source\Utilities\MyPoint2D.o object\source\Utilities\MyVec2D.o object\source\Window\OpenGL.o object\source\Utilities\Quaternion.o object\source\Window\Settings.o object\source\Utilities\Shader.o object\source\Utilities\Shapes.o object\source\Window\Timer.o object\source\Utilities\VMath.o object\source\Window\Window.o \
	-lgdi32 \
	-lopengl32 \
	-lglu32 \
	-lopenal32 \
	-lws2_32 \
	-o binary\Collision.exe

Run:
	binary\Collision.exe

object\source\Window\Cursor.o: source\Window\Cursor.cpp
	g++ -m32 -c -std=c++11 -I include -I source source\Window\Cursor.cpp -o object\source\Window\Cursor.o
object\source\Window\Exception.o: source\Window\Exception.cpp
	g++ -m32 -c -std=c++11 -I include -I source source\Window\Exception.cpp -o object\source\Window\Exception.o
object\source\Window\Keyboard.o: source\Window\Keyboard.cpp
	g++ -m32 -c -std=c++11 -I include -I source source\Window\Keyboard.cpp -o object\source\Window\Keyboard.o
object\source\Main.o: source\Main.cpp
	g++ -m32 -c -std=c++11 -I include -I source source\Main.cpp -o object\source\Main.o
object\source\Utilities\MyPoint2D.o: source\Utilities\MyPoint2D.cpp
	g++ -m32 -c -std=c++11 -I include -I source source\Utilities\MyPoint2D.cpp -o object\source\Utilities\MyPoint2D.o
object\source\Utilities\MyVec2D.o: source\Utilities\MyVec2D.cpp
	g++ -m32 -c -std=c++11 -I include -I source source\Utilities\MyVec2D.cpp -o object\source\Utilities\MyVec2D.o
object\source\Window\OpenGL.o: source\Window\OpenGL.cpp
	g++ -m32 -c -std=c++11 -I include -I source source\Window\OpenGL.cpp -o object\source\Window\OpenGL.o
object\source\Utilities\Quaternion.o: source\Utilities\Quaternion.cpp
	g++ -m32 -c -std=c++11 -I include -I source source\Utilities\Quaternion.cpp -o object\source\Utilities\Quaternion.o
object\source\Window\Settings.o: source\Window\Settings.cpp
	g++ -m32 -c -std=c++11 -I include -I source source\Window\Settings.cpp -o object\source\Window\Settings.o
object\source\Utilities\Shader.o: source\Utilities\Shader.cpp
	g++ -m32 -c -std=c++11 -I include -I source source\Utilities\Shader.cpp -o object\source\Utilities\Shader.o
object\source\Utilities\Shapes.o: source\Utilities\Shapes.cpp
	g++ -m32 -c -std=c++11 -I include -I source source\Utilities\Shapes.cpp -o object\source\Utilities\Shapes.o
object\source\Window\Timer.o: source\Window\Timer.cpp
	g++ -m32 -c -std=c++11 -I include -I source source\Window\Timer.cpp -o object\source\Window\Timer.o
object\source\Utilities\VMath.o: source\Utilities\VMath.cpp
	g++ -m32 -c -std=c++11 -I include -I source source\Utilities\VMath.cpp -o object\source\Utilities\VMath.o
object\source\Window\Window.o: source\Window\Window.cpp
	g++ -m32 -c -std=c++11 -I include -I source source\Window\Window.cpp -o object\source\Window\Window.o