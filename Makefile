all:
	g++ \
	-m32 \
	-std=c++11 -O3 \
	-L library \
	-I include \
	-I source \
	source\Window\Cursor.cpp \
	source\Window\Exception.cpp \
	source\Window\Keyboard.cpp \
	source\Main.cpp \
	source\Utilities\MyPoint2D.cpp \
	source\Utilities\MyVec2D.cpp \
	source\Window\OpenGL.cpp \
	source\Utilities\Quaternion.cpp \
	source\Window\Settings.cpp \
	source\Utilities\Shader.cpp \
	source\Utilities\Shapes.cpp \
	source\Window\Timer.cpp \
	source\Utilities\VMath.cpp \
	source\Window\Window.cpp \
	-lgdi32 \
	-lopengl32 \
	-lglu32 \
	-lopenal32 \
	-lws2_32 \
	-o binary\Collision.exe