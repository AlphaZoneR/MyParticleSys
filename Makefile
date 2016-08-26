all:
	g++ -std=c++11 -O3 \
	-L library \
	-I include \
	-I source \
	source\Window\Cursor.cpp \
	source\Window\Exception.cpp \
	source\Utilities\Font.cpp \
	source\Window\Keyboard.cpp \
	source\Main.cpp \
	source\Utilities\MyPoint.cpp \
	source\Utilities\MyPoint2D.cpp \
	source\Utilities\MyVec.cpp \
	source\Utilities\MyVec2D.cpp \
	source\Window\OpenGL.cpp \
	source\Utilities\Quaternion.cpp \
	source\Window\Settings.cpp \
	source\Utilities\Shader.cpp \
	source\Utilities\Shapes.cpp \
	source\Utilities\Sound.cpp \
	source\Utilities\Texture.cpp \
	source\Window\Timer.cpp \
	source\Utilities\VMath.cpp \
	source\Window\Window.cpp \
	-lgdi32 -lopengl32 -lglu32 -openal32 -lfreetype -lfreeimage -lws2_32 \
	-o Collision.exe