#pragma once

#define CL_USE_DEPRECATED_OPENCL_1_1_APIS // for clGetExtensionFunctionAddress
#define CL_USE_DEPRECATED_OPENCL_1_2_APIS
#define CL_USE_DEPRECATED_OPENCL_2_0_APIS
#define CL_USE_DEPRECATED_OPENCL_2_1_APIS

#define CL_TARGET_OPENCL_VERSION 210

#if defined(__APPLE__) && !defined(__IOS__)
#include <OpenCL/opencl.h>
#else
#include "CL/cl.h"
#include "CL/cl_ext.h"

#include "CL/cl_gl.h"
#endif

#define FUNC_OPENCL(function) function

#define CHECK_FUNC_OPENCL(function) \
	if (!FUNC_OPENCL(function)) { \
		fprintf(stderr, "OpenCL init error: failed to find required functions (%s) (File: %s Line %d)\n", #function, __FILE__, __LINE__); \
	}

#if defined(_WIN32)
#include <windows.h>
#else
typedef void* HMODULE;
#endif

extern HMODULE g_hOpenCL;

int LoadOpenClLib();
int UnLoadOpenClLib();

const char* GetOpenClErrorText(cl_int clres);

#include "opencl_dyn_load_declare.h"