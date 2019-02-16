#ifndef __BASEMAP_H
#define __BASEMAP_H

#include <GL/gl.h>
#include <GL/glu.h>

typedef struct _vertex3f{
	GLfloat v[3];
} Vertex3f;

class BaseMap
{
	public:
		BaseMap();
		~BaseMap();

		void paintGL();

		int sel_name;

	protected:
		GLuint m_Width;
		GLuint m_Height;
		Vertex3f *va;
};

#endif

