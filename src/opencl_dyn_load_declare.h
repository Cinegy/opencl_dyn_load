#pragma once

#ifndef _OPENCL_FUNCS_DEFINITION_SECTION_
#define DECLARE_FUNC_OPENCL(function) extern decltype(function) *p##function;
#endif

/********************************************************************************************************/

/* Platform API */
DECLARE_FUNC_OPENCL(clGetPlatformIDs)
DECLARE_FUNC_OPENCL(clGetPlatformInfo)

/* Device APIs */
DECLARE_FUNC_OPENCL(clGetDeviceIDs)
DECLARE_FUNC_OPENCL(clGetDeviceInfo)
#ifdef CL_VERSION_1_2
DECLARE_FUNC_OPENCL(clCreateSubDevices)
DECLARE_FUNC_OPENCL(clRetainDevice)
DECLARE_FUNC_OPENCL(clReleaseDevice)
#endif
#ifdef CL_VERSION_2_1
DECLARE_FUNC_OPENCL(clSetDefaultDeviceCommandQueue)
DECLARE_FUNC_OPENCL(clGetDeviceAndHostTimer)
DECLARE_FUNC_OPENCL(clGetHostTimer)
#endif

/* Context APIs */
DECLARE_FUNC_OPENCL(clCreateContext)
DECLARE_FUNC_OPENCL(clCreateContextFromType)
DECLARE_FUNC_OPENCL(clRetainContext)
DECLARE_FUNC_OPENCL(clReleaseContext)
DECLARE_FUNC_OPENCL(clGetContextInfo)

/* Command Queue APIs */
#ifdef CL_VERSION_2_0
DECLARE_FUNC_OPENCL(clCreateCommandQueueWithProperties)
#endif
DECLARE_FUNC_OPENCL(clRetainCommandQueue)
DECLARE_FUNC_OPENCL(clReleaseCommandQueue)
DECLARE_FUNC_OPENCL(clGetCommandQueueInfo)

/* Memory Object APIs */
DECLARE_FUNC_OPENCL(clCreateBuffer)
#ifdef CL_VERSION_1_1
DECLARE_FUNC_OPENCL(clCreateSubBuffer)
#endif
#ifdef CL_VERSION_1_2
DECLARE_FUNC_OPENCL(clCreateImage)
#endif
#ifdef CL_VERSION_2_0
DECLARE_FUNC_OPENCL(clCreatePipe)
#endif
#ifdef CL_VERSION_3_0
DECLARE_FUNC_OPENCL(clCreateBufferWithProperties)
DECLARE_FUNC_OPENCL(clCreateImageWithProperties)
#endif
DECLARE_FUNC_OPENCL(clRetainMemObject)
DECLARE_FUNC_OPENCL(clReleaseMemObject)
DECLARE_FUNC_OPENCL(clGetSupportedImageFormats)
DECLARE_FUNC_OPENCL(clGetMemObjectInfo)
DECLARE_FUNC_OPENCL(clGetImageInfo)
#ifdef CL_VERSION_2_0
DECLARE_FUNC_OPENCL(clGetPipeInfo)
#endif
#ifdef CL_VERSION_1_1
DECLARE_FUNC_OPENCL(clSetMemObjectDestructorCallback)
#endif

/* SVM Allocation APIs */
#ifdef CL_VERSION_2_0
DECLARE_FUNC_OPENCL(clSVMAlloc)
DECLARE_FUNC_OPENCL(clSVMFree)
#endif

/* Sampler APIs */
#ifdef CL_VERSION_2_0
DECLARE_FUNC_OPENCL(clCreateSamplerWithProperties)
#endif
DECLARE_FUNC_OPENCL(clRetainSampler)
DECLARE_FUNC_OPENCL(clReleaseSampler)
DECLARE_FUNC_OPENCL(clGetSamplerInfo)

/* Program Object APIs */
DECLARE_FUNC_OPENCL(clCreateProgramWithSource)
DECLARE_FUNC_OPENCL(clCreateProgramWithBinary)
#ifdef CL_VERSION_1_2
DECLARE_FUNC_OPENCL(clCreateProgramWithBuiltInKernels)
#endif
#ifdef CL_VERSION_2_1
DECLARE_FUNC_OPENCL(clCreateProgramWithIL)
#endif
DECLARE_FUNC_OPENCL(clRetainProgram)
DECLARE_FUNC_OPENCL(clReleaseProgram)
DECLARE_FUNC_OPENCL(clBuildProgram)
#ifdef CL_VERSION_1_2
DECLARE_FUNC_OPENCL(clCompileProgram)
DECLARE_FUNC_OPENCL(clLinkProgram)
#endif
#ifdef CL_VERSION_2_2
DECLARE_FUNC_OPENCL(clSetProgramReleaseCallback)
DECLARE_FUNC_OPENCL(clSetProgramSpecializationConstant)
#endif
#ifdef CL_VERSION_1_2
DECLARE_FUNC_OPENCL(clUnloadPlatformCompiler)
#endif
DECLARE_FUNC_OPENCL(clGetProgramInfo)
DECLARE_FUNC_OPENCL(clGetProgramBuildInfo)

/* Kernel Object APIs */
DECLARE_FUNC_OPENCL(clCreateKernel)
DECLARE_FUNC_OPENCL(clCreateKernelsInProgram)
#ifdef CL_VERSION_2_1
DECLARE_FUNC_OPENCL(clCloneKernel)
#endif
DECLARE_FUNC_OPENCL(clRetainKernel)
DECLARE_FUNC_OPENCL(clReleaseKernel)
DECLARE_FUNC_OPENCL(clSetKernelArg)
#ifdef CL_VERSION_2_0
DECLARE_FUNC_OPENCL(clSetKernelArgSVMPointer)
DECLARE_FUNC_OPENCL(clSetKernelExecInfo)
#endif
DECLARE_FUNC_OPENCL(clGetKernelInfo)
#ifdef CL_VERSION_1_2
DECLARE_FUNC_OPENCL(clGetKernelArgInfo)
#endif
DECLARE_FUNC_OPENCL(clGetKernelWorkGroupInfo)
#ifdef CL_VERSION_2_1
DECLARE_FUNC_OPENCL(clGetKernelSubGroupInfo)
#endif

/* Event Object APIs */
DECLARE_FUNC_OPENCL(clWaitForEvents)
DECLARE_FUNC_OPENCL(clGetEventInfo)
#ifdef CL_VERSION_1_1
DECLARE_FUNC_OPENCL(clCreateUserEvent)
#endif
DECLARE_FUNC_OPENCL(clRetainEvent)
DECLARE_FUNC_OPENCL(clReleaseEvent)
#ifdef CL_VERSION_1_1
DECLARE_FUNC_OPENCL(clSetUserEventStatus)
DECLARE_FUNC_OPENCL(clSetEventCallback)
#endif

/* Profiling APIs */
DECLARE_FUNC_OPENCL(clGetEventProfilingInfo)

/* Flush and Finish APIs */
DECLARE_FUNC_OPENCL(clFlush)
DECLARE_FUNC_OPENCL(clFinish)

/* Enqueued Commands APIs */
DECLARE_FUNC_OPENCL(clEnqueueReadBuffer)
#ifdef CL_VERSION_1_1
DECLARE_FUNC_OPENCL(clEnqueueReadBufferRect)
#endif
DECLARE_FUNC_OPENCL(clEnqueueWriteBuffer)
#ifdef CL_VERSION_1_1
DECLARE_FUNC_OPENCL(clEnqueueWriteBufferRect)
#endif
#ifdef CL_VERSION_1_2
DECLARE_FUNC_OPENCL(clEnqueueFillBuffer)
#endif
DECLARE_FUNC_OPENCL(clEnqueueCopyBuffer)
#ifdef CL_VERSION_1_1
DECLARE_FUNC_OPENCL(clEnqueueCopyBufferRect)
#endif
DECLARE_FUNC_OPENCL(clEnqueueReadImage)
DECLARE_FUNC_OPENCL(clEnqueueWriteImage)
#ifdef CL_VERSION_1_2
DECLARE_FUNC_OPENCL(clEnqueueFillImage)
#endif
DECLARE_FUNC_OPENCL(clEnqueueCopyImage)
DECLARE_FUNC_OPENCL(clEnqueueCopyImageToBuffer)
DECLARE_FUNC_OPENCL(clEnqueueCopyBufferToImage)
DECLARE_FUNC_OPENCL(clEnqueueMapBuffer)
DECLARE_FUNC_OPENCL(clEnqueueMapImage)
DECLARE_FUNC_OPENCL(clEnqueueUnmapMemObject)
#ifdef CL_VERSION_1_2
DECLARE_FUNC_OPENCL(clEnqueueMigrateMemObjects)
#endif
DECLARE_FUNC_OPENCL(clEnqueueNDRangeKernel)
DECLARE_FUNC_OPENCL(clEnqueueNativeKernel)
#ifdef CL_VERSION_1_2
DECLARE_FUNC_OPENCL(clEnqueueMarkerWithWaitList)
DECLARE_FUNC_OPENCL(clEnqueueBarrierWithWaitList)
#endif
#ifdef CL_VERSION_2_0
DECLARE_FUNC_OPENCL(clEnqueueSVMFree)
DECLARE_FUNC_OPENCL(clEnqueueSVMMemcpy)
DECLARE_FUNC_OPENCL(clEnqueueSVMMemFill)
DECLARE_FUNC_OPENCL(clEnqueueSVMMap)
DECLARE_FUNC_OPENCL(clEnqueueSVMUnmap)
#endif
#ifdef CL_VERSION_2_1
DECLARE_FUNC_OPENCL(clEnqueueSVMMigrateMem)
#endif

#ifdef CL_VERSION_1_2
DECLARE_FUNC_OPENCL(clGetExtensionFunctionAddressForPlatform)
#endif

#ifdef CL_USE_DEPRECATED_OPENCL_1_0_APIS
DECLARE_FUNC_OPENCL(clSetCommandQueueProperty)
#endif

/* Deprecated OpenCL 1.1 APIs */
DECLARE_FUNC_OPENCL(clCreateImage2D)
DECLARE_FUNC_OPENCL(clCreateImage3D)
DECLARE_FUNC_OPENCL(clEnqueueMarker)
DECLARE_FUNC_OPENCL(clEnqueueWaitForEvents)
DECLARE_FUNC_OPENCL(clEnqueueBarrier)
DECLARE_FUNC_OPENCL(clUnloadCompiler)
DECLARE_FUNC_OPENCL(clGetExtensionFunctionAddress)

/* Deprecated OpenCL 2.0 APIs */
DECLARE_FUNC_OPENCL(clCreateCommandQueue)
DECLARE_FUNC_OPENCL(clCreateSampler)
DECLARE_FUNC_OPENCL(clEnqueueTask)

/********************************************************************************************************/

DECLARE_FUNC_OPENCL(clCreateFromGLBuffer)
#ifdef CL_VERSION_1_2
DECLARE_FUNC_OPENCL(clCreateFromGLTexture)
#endif
DECLARE_FUNC_OPENCL(clCreateFromGLRenderbuffer)
DECLARE_FUNC_OPENCL(clGetGLObjectInfo)
DECLARE_FUNC_OPENCL(clGetGLTextureInfo)
DECLARE_FUNC_OPENCL(clEnqueueAcquireGLObjects)
DECLARE_FUNC_OPENCL(clEnqueueReleaseGLObjects)

/* Deprecated OpenCL 1.1 APIs */
//DECLARE_FUNC_OPENCL(clCreateFromGLTexture2D)
//DECLARE_FUNC_OPENCL(clCreateFromGLTexture3D)

//DECLARE_FUNC_OPENCL(clGetGLContextInfoKHR)
//DECLARE_FUNC_OPENCL(clCreateEventFromGLsyncKHR)

/********************************************************************************************************/

#ifndef _OPENCL_FUNCS_DEFINITION_SECTION_
#undef DECL_OPENCL_FUNC

#define clGetPlatformIDs                             pclGetPlatformIDs
#define clGetPlatformInfo                            pclGetPlatformInfo
#define clGetDeviceIDs                               pclGetDeviceIDs
#define clGetDeviceInfo                              pclGetDeviceInfo
#define clCreateSubDevices                           pclCreateSubDevices
#define clRetainDevice                               pclRetainDevice
#define clReleaseDevice                              pclReleaseDevice
#define clSetDefaultDeviceCommandQueue               pclSetDefaultDeviceCommandQueue
#define clGetDeviceAndHostTimer                      pclGetDeviceAndHostTimer
#define clGetHostTimer                               pclGetHostTimer
#define clCreateContext                              pclCreateContext
#define clCreateContextFromType                      pclCreateContextFromType
#define clRetainContext                              pclRetainContext
#define clReleaseContext                             pclReleaseContext
#define clGetContextInfo                             pclGetContextInfo
#define clCreateCommandQueueWithProperties           pclCreateCommandQueueWithProperties
#define clRetainCommandQueue                         pclRetainCommandQueue
#define clReleaseCommandQueue                        pclReleaseCommandQueue
#define clGetCommandQueueInfo                        pclGetCommandQueueInfo
#define clCreateBuffer                               pclCreateBuffer
#define clCreateSubBuffer                            pclCreateSubBuffer
#define clCreateImage                                pclCreateImage
#define clCreatePipe                                 pclCreatePipe
#define clCreateBufferWithProperties                 pclCreateBufferWithProperties
#define clCreateImageWithProperties                  pclCreateImageWithProperties
#define clRetainMemObject                            pclRetainMemObject
#define clReleaseMemObject                           pclReleaseMemObject
#define clGetSupportedImageFormats                   pclGetSupportedImageFormats
#define clGetMemObjectInfo                           pclGetMemObjectInfo
#define clGetImageInfo                               pclGetImageInfo
#define clGetPipeInfo                                pclGetPipeInfo
#define clSetMemObjectDestructorCallback             pclSetMemObjectDestructorCallback
#define clSVMAlloc                                   pclSVMAlloc
#define clSVMFree                                    pclSVMFree
#define clCreateSamplerWithProperties                pclCreateSamplerWithProperties
#define clRetainSampler                              pclRetainSampler
#define clReleaseSampler                             pclReleaseSampler
#define clGetSamplerInfo                             pclGetSamplerInfo
#define clCreateProgramWithSource                    pclCreateProgramWithSource
#define clCreateProgramWithBinary                    pclCreateProgramWithBinary
#define clCreateProgramWithBuiltInKernels            pclCreateProgramWithBuiltInKernels
#define clCreateProgramWithIL                        pclCreateProgramWithIL
#define clRetainProgram                              pclRetainProgram
#define clReleaseProgram                             pclReleaseProgram
#define clBuildProgram                               pclBuildProgram
#define clCompileProgram                             pclCompileProgram
#define clLinkProgram                                pclLinkProgram
#define clSetProgramReleaseCallback                  pclSetProgramReleaseCallback
#define clSetProgramSpecializationConstant           pclSetProgramSpecializationConstant
#define clUnloadPlatformCompiler                     pclUnloadPlatformCompiler
#define clGetProgramInfo                             pclGetProgramInfo
#define clGetProgramBuildInfo                        pclGetProgramBuildInfo
#define clCreateKernel                               pclCreateKernel
#define clCreateKernelsInProgram                     pclCreateKernelsInProgram
#define clCloneKernel                                pclCloneKernel
#define clRetainKernel                               pclRetainKernel
#define clReleaseKernel                              pclReleaseKernel
#define clSetKernelArg                               pclSetKernelArg
#define clSetKernelArgSVMPointer                     pclSetKernelArgSVMPointer
#define clSetKernelExecInfo                          pclSetKernelExecInfo
#define clGetKernelInfo                              pclGetKernelInfo
#define clGetKernelArgInfo                           pclGetKernelArgInfo
#define clGetKernelWorkGroupInfo                     pclGetKernelWorkGroupInfo
#define clGetKernelSubGroupInfo                      pclGetKernelSubGroupInfo
#define clWaitForEvents                              pclWaitForEvents
#define clGetEventInfo                               pclGetEventInfo
#define clCreateUserEvent                            pclCreateUserEvent
#define clRetainEvent                                pclRetainEvent
#define clReleaseEvent                               pclReleaseEvent
#define clSetUserEventStatus                         pclSetUserEventStatus
#define clSetEventCallback                           pclSetEventCallback
#define clGetEventProfilingInfo                      pclGetEventProfilingInfo
#define clFlush                                      pclFlush
#define clFinish                                     pclFinish
#define clEnqueueReadBuffer                          pclEnqueueReadBuffer
#define clEnqueueReadBufferRect                      pclEnqueueReadBufferRect
#define clEnqueueWriteBuffer                         pclEnqueueWriteBuffer
#define clEnqueueWriteBufferRect                     pclEnqueueWriteBufferRect
#define clEnqueueFillBuffer                          pclEnqueueFillBuffer
#define clEnqueueCopyBuffer                          pclEnqueueCopyBuffer
#define clEnqueueCopyBufferRect                      pclEnqueueCopyBufferRect
#define clEnqueueReadImage                           pclEnqueueReadImage
#define clEnqueueWriteImage                          pclEnqueueWriteImage
#define clEnqueueFillImage                           pclEnqueueFillImage
#define clEnqueueCopyImage                           pclEnqueueCopyImage
#define clEnqueueCopyImageToBuffer                   pclEnqueueCopyImageToBuffer
#define clEnqueueCopyBufferToImage                   pclEnqueueCopyBufferToImage
#define clEnqueueMapBuffer                           pclEnqueueMapBuffer
#define clEnqueueMapImage                            pclEnqueueMapImage
#define clEnqueueUnmapMemObject                      pclEnqueueUnmapMemObject
#define clEnqueueMigrateMemObjects                   pclEnqueueMigrateMemObjects
#define clEnqueueNDRangeKernel                       pclEnqueueNDRangeKernel
#define clEnqueueNativeKernel                        pclEnqueueNativeKernel
#define clEnqueueMarkerWithWaitList                  pclEnqueueMarkerWithWaitList
#define clEnqueueBarrierWithWaitList                 pclEnqueueBarrierWithWaitList
#define clEnqueueSVMFree                             pclEnqueueSVMFree
#define clEnqueueSVMMemcpy                           pclEnqueueSVMMemcpy
#define clEnqueueSVMMemFill                          pclEnqueueSVMMemFill
#define clEnqueueSVMMap                              pclEnqueueSVMMap
#define clEnqueueSVMUnmap                            pclEnqueueSVMUnmap
#define clEnqueueSVMMigrateMem                       pclEnqueueSVMMigrateMem
#define clGetExtensionFunctionAddressForPlatform     pclGetExtensionFunctionAddressForPlatform
#define clSetCommandQueueProperty                    pclSetCommandQueueProperty
#define clCreateImage2D                              pclCreateImage2D
#define clCreateImage3D                              pclCreateImage3D
#define clEnqueueMarker                              pclEnqueueMarker
#define clEnqueueWaitForEvents                       pclEnqueueWaitForEvents
#define clEnqueueBarrier                             pclEnqueueBarrier
#define clUnloadCompiler                             pclUnloadCompiler
#define clGetExtensionFunctionAddress                pclGetExtensionFunctionAddress
#define clCreateCommandQueue                         pclCreateCommandQueue
#define clCreateSampler                              pclCreateSampler
#define clEnqueueTask                                pclEnqueueTask

#define clCreateFromGLBuffer                         pclCreateFromGLBuffer
#define clCreateFromGLTexture                        pclCreateFromGLTexture
#define clCreateFromGLRenderbuffer                   pclCreateFromGLRenderbuffer
#define clGetGLObjectInfo                            pclGetGLObjectInfo
#define clGetGLTextureInfo                           pclGetGLTextureInfo
#define clEnqueueAcquireGLObjects                    pclEnqueueAcquireGLObjects
#define clEnqueueReleaseGLObjects                    pclEnqueueReleaseGLObjects
//#define clCreateFromGLTexture2D                    pclCreateFromGLTexture2D
//#define clCreateFromGLTexture3D                    pclCreateFromGLTexture3D 
//#define clGetGLContextInfoKHR                      pclGetGLContextInfoKHR
//#define clCreateEventFromGLsyncKHR                 pclCreateEventFromGLsyncKHR
#endif