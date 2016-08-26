#include <Utilities/VMath.h>
#include <Window/Window.h>
#include <Utilities/Texture.h>
#include <cstdio>
#include <Utilities/Shapes.h>
#include "Utilities/MyPoint2D.hpp"
using namespace wnd;
using namespace util;

int WIDTH = 800;
int HEIGTH = 600;



class Game : public Content {
    float x;
    MyPoint2D p;
    public:
	Game() {
	    x = 0;
	}
	virtual void Init() {
		wglSwapIntervalEXT(false);

		glClearColor(0.75f, 0.75f, 0.75f, 1.0f);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glAlphaFunc(GL_GREATER, 0.0f);
		glDepthFunc(GL_LEQUAL);

		glEnable(GL_DEPTH_TEST);
		glEnable(GL_POINT_SMOOTH);
		glEnable(GL_LINE_SMOOTH);
		glEnable(GL_BLEND);
	}
	virtual void Update() {
		Window * window = Window::Instance();

		float tick = window->GetTick();

		if (window->GetKey('W') == KEY_PRESSED) {
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		}
		if (window->GetKey('W') == KEY_RELEASED) {
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		}
		if (window->GetKey(VK_HOME) == KEY_PRESSED) {
			window->SwitchFullScreen();
		}
		if (window->GetKey(VK_ESCAPE) == KEY_PRESSED) {
			window->CloseWindow();
		}
		x+= tick*100;
		if(x > WIDTH){
            x = 0;
		}
	}
	void Render2D() {
		Window * window = Window::Instance();
		int height = window->GetHeight();
		int width = window->GetWidth();

		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		gluOrtho2D(0, width, 0, height);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		DrawRect(x,HEIGTH/2,32.0f,32.0f,1);

	}
	virtual void Render() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Render2D();
	}

	void DrawRect(float x, float y, int width, int heigth,float edge){
        glPushMatrix();
        glTranslatef(x,y,0);
        DrawRectangle(width,heigth,edge);
        glPopMatrix();
	}
};

int main() {
	try {
		Window * window = Window::Instance();

		Content * content = new Game();
		window->BuildWindow(content, 16);

		Settings * settings = new Settings();

		settings->SetTitle("Window");
		settings->SetFullScreen(false);
		settings->SetPositionCenter();
		settings->SetMinSize(WIDTH, HEIGTH);
		settings->SetSize(WIDTH, HEIGTH);

		window->Set(settings);

		window->SetCursorRelative(false);
		window->SetCursorVisible(true);

		window->MainLoop();
	}
	catch (WindowException e) {
		printf("%s (%d)\n", e.msg, e.code);
	}
}
