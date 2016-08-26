#pragma once

#include <Utilities/VMath.h>

namespace util {
	void DrawBox(float width, float length, float height);
	void DrawPyramid(float width, float length, float height);
	void DrawCylinder(float radius, float height);
	void DrawSphere(float radius);
	void DrawCone(float radius1, float radius2, float height);
	void DrawCircle(float radius, int sides, float edge);
	void DrawCircleEdge(float radius, float thickness, int sides, float edge);
	void DrawRectangle(float width, float height, float edge);
	void DrawRectangleEdge(float width, float height, float thickness, float edge);
	void DrawLine(Vec2f start, Vec2f end, float thickness, float edge);
};
