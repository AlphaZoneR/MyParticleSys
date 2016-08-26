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
	1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
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
    bool first;
    float squarew;
    bool canjump;
    bool left, right;

    public:
	Game() {
	    x = 0;
	    squarew = 32;
	    p = MyPoint2D(MyVec2D(squarew * 5, squarew * 12));
	    left = false;
	    right = false;
	    first = true;

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
		if(first){
            tick = 1.0/60;
            first = false;
		}

        //printf("%f\n", tick);
		int n = 2;
		for (int i = 0; i < n; ++i) {
			p.accelerate(MyVec2D(0, 2000));
			p.simulate(tick);
            p.previous.x += ((p.position.x - p.previous.x)/7);
			{
                int ix = (int)((p.position.x - 1)/ squarew);
                int iy = (int)((p.position.y) / squarew);
                printf("%d %d\n", ix,iy);
                if(map[iy][ix]){
                    p.position.x = ix * squarew + 1;
                    p.previous.x = p.position.x;
                }
                ix = (int)((p.position.x)/ squarew);
                iy = (int)((p.position.y) / squarew);
                printf("%d %d\n", ix,iy);
				if(map[iy+1][ix]){
                    p.position.y = iy * squarew - 1;
                    p.previous.y = p.position.y;
                    canjump = true;
				}
				if(map[iy][ix+1]){
                    p.position.x = ix * squarew - 1;
                    p.previous.x = p.position.x;
				}
			}




		}

		if (window->GetKey('A') == KEY_DOWN) {
			p.position.x -= 0.5;
			//p.previous.x += 0.5;
		}

		if (window->GetKey('D') == KEY_DOWN) {
			p.position.x += 0.5;
			//p.previous.x -= 0.5;
		}

		if (window->GetKey('W') == KEY_PRESSED && canjump) {
			p.previous.y += 10;
			canjump = false;
			// printf("OK\n");
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

		gluOrtho2D(0, width, height, 0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

        for(int i = 0 ; i < 30 ; i++){
            for(int j = 0 ; j < 30; j++){
            glColor3ub(0, 0, 0);
            glBegin(GL_LINES);
                glVertex2f(i*squarew,j*squarew);
                glVertex2f(i*squarew + squarew,j*squarew);
            glEnd();
            glColor3ub(0, 0, 0);
            glBegin(GL_LINES);
                glVertex2f(i*squarew,j*squarew);
                glVertex2f(i*squarew,j*squarew + squarew);
            glEnd();
            }
        }

		glColor3ub(255, 0, 0);
		for (int y = 0; y < 30; ++y) {
			for (int x = 0; x < 30; ++x) {
				if (map[y][x]) {
					DrawRect(x * squarew, y * squarew, squarew,squarew,0);
				}
			}
		}

		glColor3ub(0, 255, 0);
		DrawRect(p.position.x,p.position.y,squarew,squarew,1);

	}
	virtual void Render() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Render2D();
	}


	void DrawRect(float x, float y, int width, int heigth,float edge){
        glBegin(GL_TRIANGLE_STRIP);
        glVertex2f(x,y);
        glVertex2f(x,y+heigth);
        glVertex2f(x+width,y);
        glVertex2f(x+width,y+heigth);
        glEnd();
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
