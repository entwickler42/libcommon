#ifndef __WAVEFRONT_H
#define __WAVEFRONT_H

#include <GL/gl.h>
#include <vector>
#include <list>

using namespace std;

typedef struct __VERTEX3D{
	GLdouble x;
	GLdouble y;
	GLdouble z;
} VERTEX3D;

typedef struct __FACE3I{
	GLuint v1;
	GLuint v2;
	GLuint v3;
	GLuint n1;
	GLuint n2;
	GLuint n3;
} FACE3I;

typedef vector<VERTEX3D> WFVertexVector;
typedef vector<FACE3I> WFFaceVector;

class WavefrontObject
{
	public:
		WavefrontObject(const char* filename, double scale=1.0);
		~WavefrontObject();

		void paintGL();
		void setScale(double s);
		double getScale();
		
	protected:
		WFVertexVector vertices;
		WFVertexVector normals;
		WFFaceVector faces;
};

#endif 
