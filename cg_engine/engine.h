#pragma once


#ifdef _WINDOWS 	
// Export API:
// Specifies i/o linkage (VC++ spec):
#ifdef _ENGINE_EXPORTS
#define LIB_API __declspec(dllexport)
#else
#define LIB_API __declspec(dllimport)
#endif      	
#else // Under Linux
#define LIB_API  // Dummy declaration
#endif

#include "class01.h"
#include "glm/glm.hpp"
#include "glm/gtx/string_cast.hpp"

