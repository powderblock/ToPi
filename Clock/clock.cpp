#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <math.h>
#include <time.h>
#undef main

#define UTC (0)
#define EST (-5)

using namespace std;

const int width = 320, height = 320;

const int FPS = 60;

const float pi = 3.1415926535;
const float rad = pi / 180;

const float radius = 128;
const float radiusSmall = 96;
const float radiusMin = 122;

const float radiusMins = 90;
const float radiusHours = 64;

GLfloat thick = 3.0;

float s, m, h;

bool running = true;

Uint32 start;

void events();
void lockFPS();
void init();
void update();
void render();

int main(){
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);
	SDL_Surface *screen = SDL_SetVideoMode(width, height, 32, SDL_OPENGL | SDL_HWSURFACE);
	SDL_WM_SetCaption("T3H B357 CL0CK APPLICACHION", NULL);
	
	init();

	while(running){
		update();
	}
}

void lockFPS(){
	if(1000 / FPS > SDL_GetTicks() - start){
		SDL_Delay(1000 / FPS - (SDL_GetTicks() - start));
	}
}

void init(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-(width / 2), (width / 2), -(height / 2), (height / 2), -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void update(){
	start = SDL_GetTicks();
	time_t rawtime;

	struct tm * ptm;

	time(&rawtime);

	ptm = gmtime (&rawtime);

	events();
	render();
	
	s = -((ptm->tm_sec * 6) + 270);
	m = -((ptm->tm_min * 6) + 270);
	h = -((((ptm->tm_hour + EST) % 24) * 30) + 270);
	cout << h << endl;

	lockFPS();
}

void events(){
	SDL_Event event;
	while(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_QUIT:
				running = false;
				break;
		}
	}
}

void render(){
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1, 1, 1, 1.0);
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	for(int i = 0; i <= 360; ++i){
		glVertex2f(radius * (cos(i * rad)), radius * (sin(i * rad)));
	}
	glEnd();

	glLineWidth(thick);
	glBegin(GL_LINES);
	for(int i = -90; i <= 180; i += 90){
		glVertex2f(radius * (cos(i * rad)), (radius * (sin(i * rad))));
		glVertex2f(radiusSmall * (cos(i * rad)), radiusSmall * (sin(i * rad)));
	}
	glEnd();
	
	glLineWidth(1);
	for(int i = -90; i <= 270; i += 6){
		if(i % 30 == 0){
			glLineWidth(thick);
		}
		else{
			glLineWidth(1);
		}
		glBegin(GL_LINES);
			glVertex2f(radius * (cos(i * rad)), (radius * (sin(i * rad))));
			glVertex2f(radiusMin * (cos(i * rad)), radiusMin * (sin(i * rad)));
		glEnd();
	}
	
	//Seconds:
	glColor3f(1, 0, 0);
	glLineWidth(2);
	glBegin(GL_LINES);
		glVertex2f(0, 0);
		glVertex2f(radius * (cos(s * rad)), radius * (sin(s * rad)));
	glEnd();
	
	glLineWidth(1);
	//Minutes:
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
		glVertex2f(0, 0);
		glVertex2f(radiusMins * (cos(m * rad)), radiusMins * (sin(m * rad)));
	glEnd();
	
	//Hours
	glBegin(GL_LINES);
		glVertex2f(0, 0);
		glVertex2f(radiusHours * (cos(h * rad)), radiusHours * (sin(h * rad)));
	glEnd();
	SDL_GL_SwapBuffers();
}