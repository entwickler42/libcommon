#ifndef __LIB_COMMON_H
#define __LIB_COMMON_H

#include "MemImage.h"

class GLCommon
{
	public:
		static bool loadImageRAW(const char* filename, MemTexture* texture);
		static bool loadImageTGA(const char* filename, MemTexture* texture);
		static long getFileSize(FILE* file);
};

#endif

