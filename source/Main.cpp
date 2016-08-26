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

int map[30][30] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

class Game : public Content {
    float x;
    MyPoint2D p;

    bool left, right;

    public:
	Game() {
	    x = 0;
	    p = MyPoint2D(MyVec2D(32 * 5, 32 * 12));
	    left = false;
	    right = false;
	}
	virtual void Init() {
		wglSwapIntervalEXT(true);

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

		// float tick = 1.0/60;//window->GetTick();
		float tick = window->GetTick();
		printf("%f\n", tick);

		int n = 1;
		for (int i = 0; i < n; ++i) {
			p.accelerate(MyVec2D(0, 2000));
			p.simulate(tick / n);

			{
				int ix = (int)(p.position.x / 32);
				int iy = (int)((p.position.y + 32) / 32);
	
				if (map[iy][ix]) {
					p.position.y = iy * 32 - 32;
					p.previous.y = p.position.y;
				}
			}
			{
				int ix = (int)((p.position.x + 32) / 32);
				int iy = (int)((p.position.y + 32) / 32);
	
				if (map[iy][ix]) {
					p.position.y = iy * 32 - 32;
					p.previous.y = p.position.y;
				}
			}
		}

		if (window->GetKey('A') == KEY_DOWN) {
			p.position.x -= 0.1 * 60;
			p.previous.x -= 0.1 * 60;
		}

		if (window->GetKey('D') == KEY_DOWN) {
			p.position.x += 0.1 * 60;
			p.previous.x += 0.1 * 60;
		}

		if (window->GetKey('W') == KEY_PRESSED) {
			p.previous.y += 10;
			// printf("OK\n");
		}

		// if (window->GetKey('W') == KEY_PRESSED) {
		// 	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		// }
		// if (window->GetKey('W') == KEY_RELEASED) {
		// 	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		// }
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

		gluOrtho2D(0, width, height, 0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();


		glColor3ub(255, 0, 0);
		for (int y = 0; y < 30; ++y) {
			for (int x = 0; x < 30; ++x) {
				if (map[y][x]) {
					DrawRect(x * 32, y * 32, 32.0f,32.0f,1);
				}
			}
		}

		glColor3ub(0, 255, 0);
		DrawRect(p.position.x,p.position.y,32.0f,32.0f,1);

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
