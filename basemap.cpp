#include "basemap.h"

BaseMap::BaseMap() 
	: m_Width(10), m_Height(10)
{
	sel_name = -1;
	va = new Vertex3f[m_Width*m_Height*4];
	Vertex3f* vp = va;

	for(int i=0;i<(int)m_Width;i++)
		for(int j=0;j>(int)m_Height*-1;j--, vp+=4){
			vp[0].v[0] = i;
			vp[0].v[1] = 0;
			vp[0].v[2] = j;
			
			vp[1].v[0] = i+1.0f;
			vp[1].v[1] = 0;
			vp[1].v[2] = j;

			vp[2].v[0] = i+1.0f;
			vp[2].v[1] = 0;
			vp[2].v[2] = j+1.0f;

			vp[3].v[0] = i;
			vp[3].v[1] = 0;
			vp[3].v[2] = j+1.0f;
		}
}
BaseMap::~BaseMap()
{
	delete [] va;
}
void BaseMap::paintGL()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);	
	for(int i=0;i<(int)(m_Width*m_Height*4);i+=4){

		if( i == sel_name) glColor3f(1.0f, 1.0f, 0.0f);
		else glColor3f(0.0f,1.0f,0.0f);

		glLoadName(i);
		glBegin(GL_QUADS);
			glVertex3fv(va[i].v);
			glVertex3fv(va[i+1].v);
			glVertex3fv(va[i+2].v);
			glVertex3fv(va[i+3].v);
		glEnd();
	}
	
	return;
	glColor3f(1.0f,0.0f,0.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);	
	for(int i=0;i<(int)(m_Width*m_Height*4);i+=4){

		if( i == sel_name) glColor3f(0.0f, 1.0f, 1.0f);
		else glColor3f(1.0f,0.0f,0.0f);

		glBegin(GL_QUADS);
			glVertex3fv(va[i].v);
			glVertex3fv(va[i+1].v);
			glVertex3fv(va[i+2].v);
			glVertex3fv(va[i+3].v);
		glEnd();	
	}
}
