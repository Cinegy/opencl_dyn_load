//#pragma once

#if defined(_WIN32)
#include <windows.h> // for HMODULE, LoadLibrary/GetProcAddress
#endif

#include <vector>
#include <string>
#include <mutex>

#define _OPENCL_FUNCS_DEFINITION_SECTION_
#define DECLARE_FUNC_OPENCL(f) decltype(f) *p##f = 0;
#include "opencl_dyn_load.h"
#undef  _OPENCL_FUNCS_DEFINITION_SECTION_

#if defined(_WIN32)
//#define OPENCL_FILENAME "OpenCL.dll"
static const std::vector<std::string> opencl_paths = {
	"OpenCL.dll" // Default
};
#else
#include <dlfcn.h>
#define LoadLibraryA(name) dlopen(name, RTLD_LAZY)
#define FreeLibrary(lib) dlclose(lib)
#define GetProcAddress(lib, func) dlsym(lib, func)
typedef void* FARPROC;
typedef void* HMODULE;
//#define OPENCL_FILENAME "OpenCL.so"
// "/etc/OpenCL/vendors/*.icd"
static const std::vector<std::string> opencl_paths = {
	"libOpenCL.so", // Default
	"/usr/lib/x86_64-linux-gnu/libOpenCL.so", // Linux amd64
	"/usr/lib/aarch64-linux-gnu/libOpenCL.so", // Linux aarch64
	// Qualcomm Adreno
	"/system/vendor/lib/libOpenCL.so",
	"/system/lib/libOpenCL.so",
	// Mali
	"/system/vendor/lib/egl/libGLES_mali.so",
	"/system/lib/egl/libGLES_mali.so",
	// PowerVR
	"/system/vendor/lib/libPVROCL.so"
};
#endif
static std::string str_opencl_path = "";

static std::mutex g_mutex_hOpenCL;
HMODULE g_hOpenCL = nullptr;

#define STRINGIZE_NX(A) #A
#define STRINGIZE(A) STRINGIZE_NX(A)

#define LOAD_OPENCL_FUNC(function) \
	FUNC_OPENCL(p##function) = (decltype(function)*)GetProcAddress(g_hOpenCL, STRINGIZE(function)); CHECK_FUNC_OPENCL(p##function)

int LoadOpenClLib()
{
	std::lock_guard<std::mutex> guard(g_mutex_hOpenCL);

	if (g_hOpenCL)
		return 0;

	for (size_t i = 0; i < opencl_paths.size(); i++)
	{
		std::string str_opencl_lib_path = opencl_paths[i];
		g_hOpenCL = LoadLibraryA(str_opencl_lib_path.c_str());
		if (g_hOpenCL)
		{
			str_opencl_path = str_opencl_lib_path;
			break;
		}
	}

	if (g_hOpenCL)
	{
		/* Platform API */
		LOAD_OPENCL_FUNC(clGetPlatformIDs)
		LOAD_OPENCL_FUNC(clGetPlatformInfo)

		/* Device APIs */
		LOAD_OPENCL_FUNC(clGetDeviceIDs)
		LOAD_OPENCL_FUNC(clGetDeviceInfo)
#ifdef CL_VERSION_1_2
		LOAD_OPENCL_FUNC(clCreateSubDevices)
		LOAD_OPENCL_FUNC(clRetainDevice)
		LOAD_OPENCL_FUNC(clReleaseDevice)
#endif
#ifdef CL_VERSION_2_1
		LOAD_OPENCL_FUNC(clSetDefaultDeviceCommandQueue)
		LOAD_OPENCL_FUNC(clGetDeviceAndHostTimer)
		LOAD_OPENCL_FUNC(clGetHostTimer)
#endif

		/* Context APIs */
		LOAD_OPENCL_FUNC(clCreateContext)
		LOAD_OPENCL_FUNC(clCreateContextFromType)
		LOAD_OPENCL_FUNC(clRetainContext)
		LOAD_OPENCL_FUNC(clReleaseContext)
		LOAD_OPENCL_FUNC(clGetContextInfo)

		/* Command Queue APIs */
#ifdef CL_VERSION_2_0
		LOAD_OPENCL_FUNC(clCreateCommandQueueWithProperties)
#endif
		LOAD_OPENCL_FUNC(clRetainCommandQueue)
		LOAD_OPENCL_FUNC(clReleaseCommandQueue)
		LOAD_OPENCL_FUNC(clGetCommandQueueInfo)

		/* Memory Object APIs */
		LOAD_OPENCL_FUNC(clCreateBuffer)
#ifdef CL_VERSION_1_1
		LOAD_OPENCL_FUNC(clCreateSubBuffer)
#endif
#ifdef CL_VERSION_1_2
		LOAD_OPENCL_FUNC(clCreateImage)
#endif
#ifdef CL_VERSION_2_0
		LOAD_OPENCL_FUNC(clCreatePipe)
#endif
#ifdef CL_VERSION_3_0
		LOAD_OPENCL_FUNC(clCreateBufferWithProperties)
		LOAD_OPENCL_FUNC(clCreateImageWithProperties)
#endif
		LOAD_OPENCL_FUNC(clRetainMemObject)
		LOAD_OPENCL_FUNC(clReleaseMemObject)
		LOAD_OPENCL_FUNC(clGetSupportedImageFormats)
		LOAD_OPENCL_FUNC(clGetMemObjectInfo)
		LOAD_OPENCL_FUNC(clGetImageInfo)
#ifdef CL_VERSION_2_0
		LOAD_OPENCL_FUNC(clGetPipeInfo)
#endif
#ifdef CL_VERSION_1_1
		LOAD_OPENCL_FUNC(clSetMemObjectDestructorCallback)
#endif

		/* SVM Allocation APIs */
#ifdef CL_VERSION_2_0
		LOAD_OPENCL_FUNC(clSVMAlloc)
		LOAD_OPENCL_FUNC(clSVMFree)
#endif

		/* Sampler APIs */
#ifdef CL_VERSION_2_0
		LOAD_OPENCL_FUNC(clCreateSamplerWithProperties)
#endif
		LOAD_OPENCL_FUNC(clRetainSampler)
		LOAD_OPENCL_FUNC(clReleaseSampler)
		LOAD_OPENCL_FUNC(clGetSamplerInfo)

		/* Program Object APIs */
		LOAD_OPENCL_FUNC(clCreateProgramWithSource)
		LOAD_OPENCL_FUNC(clCreateProgramWithBinary)
#ifdef CL_VERSION_1_2
		LOAD_OPENCL_FUNC(clCreateProgramWithBuiltInKernels)
#endif
#ifdef CL_VERSION_2_1
		LOAD_OPENCL_FUNC(clCreateProgramWithIL)
#endif
		LOAD_OPENCL_FUNC(clRetainProgram)
		LOAD_OPENCL_FUNC(clReleaseProgram)
		LOAD_OPENCL_FUNC(clBuildProgram)
#ifdef CL_VERSION_1_2
		LOAD_OPENCL_FUNC(clCompileProgram)
		LOAD_OPENCL_FUNC(clLinkProgram)
#endif
#ifdef CL_VERSION_2_2
		LOAD_OPENCL_FUNC(clSetProgramReleaseCallback)
		LOAD_OPENCL_FUNC(clSetProgramSpecializationConstant)
#endif
#ifdef CL_VERSION_1_2
		LOAD_OPENCL_FUNC(clUnloadPlatformCompiler)
#endif
		LOAD_OPENCL_FUNC(clGetProgramInfo)
		LOAD_OPENCL_FUNC(clGetProgramBuildInfo)

		/* Kernel Object APIs */
		LOAD_OPENCL_FUNC(clCreateKernel)
		LOAD_OPENCL_FUNC(clCreateKernelsInProgram)
#ifdef CL_VERSION_2_1
		LOAD_OPENCL_FUNC(clCloneKernel)
#endif
		LOAD_OPENCL_FUNC(clRetainKernel)
		LOAD_OPENCL_FUNC(clReleaseKernel)
		LOAD_OPENCL_FUNC(clSetKernelArg)
#ifdef CL_VERSION_2_0
		LOAD_OPENCL_FUNC(clSetKernelArgSVMPointer)
		LOAD_OPENCL_FUNC(clSetKernelExecInfo)
#endif
		LOAD_OPENCL_FUNC(clGetKernelInfo)
#ifdef CL_VERSION_1_2
		LOAD_OPENCL_FUNC(clGetKernelArgInfo)
#endif
		LOAD_OPENCL_FUNC(clGetKernelWorkGroupInfo)
#ifdef CL_VERSION_2_1
		LOAD_OPENCL_FUNC(clGetKernelSubGroupInfo)
#endif

		/* Event Object APIs */
		LOAD_OPENCL_FUNC(clWaitForEvents)
		LOAD_OPENCL_FUNC(clGetEventInfo)
#ifdef CL_VERSION_1_1
		LOAD_OPENCL_FUNC(clCreateUserEvent)
#endif
		LOAD_OPENCL_FUNC(clRetainEvent)
		LOAD_OPENCL_FUNC(clReleaseEvent)
#ifdef CL_VERSION_1_1
		LOAD_OPENCL_FUNC(clSetUserEventStatus)
		LOAD_OPENCL_FUNC(clSetEventCallback)
#endif

		/* Profiling APIs */
		LOAD_OPENCL_FUNC(clGetEventProfilingInfo)

		/* Flush and Finish APIs */
		LOAD_OPENCL_FUNC(clFlush)
		LOAD_OPENCL_FUNC(clFinish)

		/* Enqueued Commands APIs */
		LOAD_OPENCL_FUNC(clEnqueueReadBuffer)
#ifdef CL_VERSION_1_1
		LOAD_OPENCL_FUNC(clEnqueueReadBufferRect)
#endif
		LOAD_OPENCL_FUNC(clEnqueueWriteBuffer)
#ifdef CL_VERSION_1_1
		LOAD_OPENCL_FUNC(clEnqueueWriteBufferRect)
#endif
#ifdef CL_VERSION_1_2
		LOAD_OPENCL_FUNC(clEnqueueFillBuffer)
#endif
		LOAD_OPENCL_FUNC(clEnqueueCopyBuffer)
#ifdef CL_VERSION_1_1
		LOAD_OPENCL_FUNC(clEnqueueCopyBufferRect)
#endif
		LOAD_OPENCL_FUNC(clEnqueueReadImage)
		LOAD_OPENCL_FUNC(clEnqueueWriteImage)
#ifdef CL_VERSION_1_2
		LOAD_OPENCL_FUNC(clEnqueueFillImage)
#endif
		LOAD_OPENCL_FUNC(clEnqueueCopyImage)
		LOAD_OPENCL_FUNC(clEnqueueCopyImageToBuffer)
		LOAD_OPENCL_FUNC(clEnqueueCopyBufferToImage)
		LOAD_OPENCL_FUNC(clEnqueueMapBuffer)
		LOAD_OPENCL_FUNC(clEnqueueMapImage)
		LOAD_OPENCL_FUNC(clEnqueueUnmapMemObject)
#ifdef CL_VERSION_1_2
		LOAD_OPENCL_FUNC(clEnqueueMigrateMemObjects)
#endif
		LOAD_OPENCL_FUNC(clEnqueueNDRangeKernel)
		LOAD_OPENCL_FUNC(clEnqueueNativeKernel)
#ifdef CL_VERSION_1_2
		LOAD_OPENCL_FUNC(clEnqueueMarkerWithWaitList)
		LOAD_OPENCL_FUNC(clEnqueueBarrierWithWaitList)
#endif
#ifdef CL_VERSION_2_0
		LOAD_OPENCL_FUNC(clEnqueueSVMFree)
		LOAD_OPENCL_FUNC(clEnqueueSVMMemcpy)
		LOAD_OPENCL_FUNC(clEnqueueSVMMemFill)
		LOAD_OPENCL_FUNC(clEnqueueSVMMap)
		LOAD_OPENCL_FUNC(clEnqueueSVMUnmap)
#endif
#ifdef CL_VERSION_2_1
		LOAD_OPENCL_FUNC(clEnqueueSVMMigrateMem)
#endif

#ifdef CL_VERSION_1_2
		LOAD_OPENCL_FUNC(clGetExtensionFunctionAddressForPlatform)
#endif

#ifdef CL_USE_DEPRECATED_OPENCL_1_0_APIS
		LOAD_OPENCL_FUNC(clSetCommandQueueProperty)
#endif

		/* Deprecated OpenCL 1.1 APIs */
		LOAD_OPENCL_FUNC(clCreateImage2D)
		LOAD_OPENCL_FUNC(clCreateImage3D)
		LOAD_OPENCL_FUNC(clEnqueueMarker)
		LOAD_OPENCL_FUNC(clEnqueueWaitForEvents)
		LOAD_OPENCL_FUNC(clEnqueueBarrier)
		LOAD_OPENCL_FUNC(clUnloadCompiler)
		LOAD_OPENCL_FUNC(clGetExtensionFunctionAddress)

		/* Deprecated OpenCL 2.0 APIs */
		LOAD_OPENCL_FUNC(clCreateCommandQueue)
		LOAD_OPENCL_FUNC(clCreateSampler)
		LOAD_OPENCL_FUNC(clEnqueueTask)

		////////////////////////////////////////////

		LOAD_OPENCL_FUNC(clCreateFromGLBuffer)
#ifdef CL_VERSION_1_2
		LOAD_OPENCL_FUNC(clCreateFromGLTexture)
#endif
		LOAD_OPENCL_FUNC(clCreateFromGLRenderbuffer)
		LOAD_OPENCL_FUNC(clGetGLObjectInfo)
		LOAD_OPENCL_FUNC(clGetGLTextureInfo)
		LOAD_OPENCL_FUNC(clEnqueueAcquireGLObjects)
		LOAD_OPENCL_FUNC(clEnqueueReleaseGLObjects)

		/* Deprecated OpenCL 1.1 APIs */
		//LOAD_OPENCL_FUNC(clCreateFromGLTexture2D)
		//LOAD_OPENCL_FUNC(clCreateFromGLTexture3D)

		//LOAD_OPENCL_FUNC(clGetGLContextInfoKHR)
		//LOAD_OPENCL_FUNC(clCreateEventFromGLsyncKHR)
	}
	else
		return fprintf(stderr, "OpenCL load error: failed to load!\n"), -1;

	return 0;
}

int UnLoadOpenClLib()
{
	std::lock_guard<std::mutex> guard(g_mutex_hOpenCL);

	if (g_hOpenCL)
	{
		FreeLibrary(g_hOpenCL);
	}

	g_hOpenCL = nullptr;

	return 0;
}

class CRunLoadOpenClLib
{
public:
	CRunLoadOpenClLib()
	{
		LoadOpenClLib();
	}
	~CRunLoadOpenClLib()
	{
		UnLoadOpenClLib();
	}
};

//CRunLoadOpenClLib g_runOCL;

//---------------------------------------------------------------
const char* GetOpenClErrorText(cl_int clres)
//---------------------------------------------------------------
{
	switch (clres)
	{
#define __CASE_ERROR(code) case code: return #code

		__CASE_ERROR(CL_SUCCESS);

		__CASE_ERROR(CL_DEVICE_NOT_FOUND);
		__CASE_ERROR(CL_DEVICE_NOT_AVAILABLE);
		__CASE_ERROR(CL_COMPILER_NOT_AVAILABLE);
		__CASE_ERROR(CL_MEM_OBJECT_ALLOCATION_FAILURE);
		__CASE_ERROR(CL_OUT_OF_RESOURCES);
		__CASE_ERROR(CL_OUT_OF_HOST_MEMORY);
		__CASE_ERROR(CL_PROFILING_INFO_NOT_AVAILABLE);
		__CASE_ERROR(CL_MEM_COPY_OVERLAP);
		__CASE_ERROR(CL_IMAGE_FORMAT_MISMATCH);
		__CASE_ERROR(CL_IMAGE_FORMAT_NOT_SUPPORTED);
		__CASE_ERROR(CL_BUILD_PROGRAM_FAILURE);
		__CASE_ERROR(CL_MAP_FAILURE);
		__CASE_ERROR(CL_MISALIGNED_SUB_BUFFER_OFFSET);
		__CASE_ERROR(CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST);
		__CASE_ERROR(CL_COMPILE_PROGRAM_FAILURE);
		__CASE_ERROR(CL_LINKER_NOT_AVAILABLE);
		__CASE_ERROR(CL_LINK_PROGRAM_FAILURE);
		__CASE_ERROR(CL_DEVICE_PARTITION_FAILED);
		__CASE_ERROR(CL_KERNEL_ARG_INFO_NOT_AVAILABLE);

		__CASE_ERROR(CL_INVALID_VALUE);
		__CASE_ERROR(CL_INVALID_DEVICE_TYPE);
		__CASE_ERROR(CL_INVALID_PLATFORM);
		__CASE_ERROR(CL_INVALID_DEVICE);
		__CASE_ERROR(CL_INVALID_CONTEXT);
		__CASE_ERROR(CL_INVALID_QUEUE_PROPERTIES);
		__CASE_ERROR(CL_INVALID_COMMAND_QUEUE);
		__CASE_ERROR(CL_INVALID_HOST_PTR);
		__CASE_ERROR(CL_INVALID_MEM_OBJECT);
		__CASE_ERROR(CL_INVALID_IMAGE_FORMAT_DESCRIPTOR);
		__CASE_ERROR(CL_INVALID_IMAGE_SIZE);
		__CASE_ERROR(CL_INVALID_SAMPLER);
		__CASE_ERROR(CL_INVALID_BINARY);
		__CASE_ERROR(CL_INVALID_BUILD_OPTIONS);
		__CASE_ERROR(CL_INVALID_PROGRAM);
		__CASE_ERROR(CL_INVALID_PROGRAM_EXECUTABLE);
		__CASE_ERROR(CL_INVALID_KERNEL_NAME);
		__CASE_ERROR(CL_INVALID_KERNEL_DEFINITION);
		__CASE_ERROR(CL_INVALID_KERNEL);
		__CASE_ERROR(CL_INVALID_ARG_INDEX);
		__CASE_ERROR(CL_INVALID_ARG_VALUE);
		__CASE_ERROR(CL_INVALID_ARG_SIZE);
		__CASE_ERROR(CL_INVALID_KERNEL_ARGS);
		__CASE_ERROR(CL_INVALID_WORK_DIMENSION);
		__CASE_ERROR(CL_INVALID_WORK_GROUP_SIZE);
		__CASE_ERROR(CL_INVALID_WORK_ITEM_SIZE);
		__CASE_ERROR(CL_INVALID_GLOBAL_OFFSET);
		__CASE_ERROR(CL_INVALID_EVENT_WAIT_LIST);
		__CASE_ERROR(CL_INVALID_EVENT);
		__CASE_ERROR(CL_INVALID_OPERATION);
		__CASE_ERROR(CL_INVALID_GL_OBJECT);
		__CASE_ERROR(CL_INVALID_BUFFER_SIZE);
		__CASE_ERROR(CL_INVALID_MIP_LEVEL);
		__CASE_ERROR(CL_INVALID_GLOBAL_WORK_SIZE);
		__CASE_ERROR(CL_INVALID_PROPERTY);
		__CASE_ERROR(CL_INVALID_IMAGE_DESCRIPTOR);
		__CASE_ERROR(CL_INVALID_COMPILER_OPTIONS);
		__CASE_ERROR(CL_INVALID_LINKER_OPTIONS);
		__CASE_ERROR(CL_INVALID_DEVICE_PARTITION_COUNT);
		//__CASE_ERROR(CL_INVALID_PIPE_SIZE                        );
		//__CASE_ERROR(CL_INVALID_DEVICE_QUEUE                     );
#undef __CASE_ERROR
	}

	return "??? Unknown OpenCL error";
};
