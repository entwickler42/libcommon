#include "wavefront.h"

#include <fstream>
#include <string.h>

WavefrontObject::WavefrontObject(const char* filename, double scale)
{
	ifstream *in = new ifstream(filename);
	if(in->is_open()){
		char line[256];
		VERTEX3D v;
		FACE3I f;

		while(!in->eof()){
			in->getline(line,256);
			switch(line[0]){
				case 'o':
					break;
				case 'v':
					sscanf(line,"%*s %lf %lf %lf",&v.x,&v.y,&v.z);
					if(scale != 1.0){
						v.x *= scale;
						v.y *= scale;
						v.z *= scale;
					}
					switch(line[1]){
						case ' ':
							vertices.push_back(v);
							break;
						case 'n':
							normals.push_back(v);
							break;
					}
					break;
				case 'f':
					if(strchr(line,'/') == NULL){
						sscanf(line,"%*s %i %i %i",&f.v1,&f.v2,&f.v3);
						f.n1 = 0;
						f.n2 = 0;
						f.n3 = 0;
					}else{
						sscanf(line,"%*s %i//%i %i//%i %i//%i",&f.v1,&f.n1,&f.v2,&f.n2,&f.v3,&f.n3);
						f.n1 -= 1;
						f.n2 -= 1;
						f.n3 -= 1;
					}
					f.v1 -= 1;
					f.v2 -= 1;
					f.v3 -= 1;
					faces.push_back(f);
				break;
			}
		}
		in->close();
	}
	delete in;
}

WavefrontObject::~WavefrontObject()
{
	vertices.clear();
	normals.clear();
	faces.clear();
}

void WavefrontObject::paintGL()
{
	glBegin(GL_TRIANGLES);
	for(WFFaceVector::iterator f = faces.begin(); f != faces.end(); f++){
		glNormal3dv( (GLdouble*)&normals[f->n1] );	
		glVertex3dv( (GLdouble*)&vertices[f->v1] );	
		
		glNormal3dv( (GLdouble*)&normals[f->n2] );	
		glVertex3dv( (GLdouble*)&vertices[f->v2] );	
		
		glNormal3dv( (GLdouble*)&normals[f->n3] );	
		glVertex3dv( (GLdouble*)&vertices[f->v3] );	
	}
	glEnd();
}

void WavefrontObject::setScale(double s)
{
	for(WFVertexVector::iterator i = vertices.begin(); i != vertices.end(); i++){
		i->x *= s;
		i->y *= s;
		i->z *= s;
	}
	for(WFVertexVector::iterator i = normals.begin(); i != normals.end(); i++){
		i->x *= s;
		i->y *= s;
		i->z *= s;
	}
}
