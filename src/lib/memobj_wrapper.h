/*   
 * This file is part of cf4ocl (C Framework for OpenCL).
 * 
 * cf4ocl is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as 
 * published by the Free Software Foundation, either version 3 of the 
 * License, or (at your option) any later version.
 * 
 * cf4ocl is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public 
 * License along with cf4ocl. If not, see 
 * <http://www.gnu.org/licenses/>.
 * */
 
 /** 
 * @file
 * @brief OpenCL cl_mem wrapper object.
 * 
 * @author Nuno Fachada
 * @date 2014
 * @copyright [GNU Lesser General Public License version 3 (LGPLv3)](http://www.gnu.org/licenses/lgpl.html)
 * */
 
#include "abstract_wrapper.h"
#include "event_wrapper.h"
#include "queue_wrapper.h"

#ifndef _CCL_MEMOBJ_WRAPPER_H_
#define _CCL_MEMOBJ_WRAPPER_H_

/**
 * @defgroup MEMOBJ_WRAPPER Memory object wrapper
 *
 * @brief A wrapper object for OpenCL memory objects (buffers and 
 * images) and functions to manage them.
 * 
 * Todo: detailed description of module with code examples.
 * 
 * @{
 */

typedef struct ccl_memobj CCLMemObj;

/** @brief Get the cl_mem wrapper for the given OpenCL memory object. */
CCLMemObj* ccl_memobj_new_wrap(cl_mem mem_object);

/** @brief Decrements the reference count of the wrapper object. If it 
 * reaches 0, the wrapper object is destroyed. */
void ccl_memobj_destroy(CCLMemObj* mo);

CCLEvent* ccl_memobj_unmap(CCLMemObj* mo, CCLQueue* cq, 
	void* mapped_ptr, CCLEventWaitList evt_wait_lst, GError** err);
	
#ifdef CL_VERSION_1_2

CCLEvent* ccl_memobj_migrate(CCLMemObj** mos, cl_uint num_mos,
 	CCLQueue* cq, cl_mem_migration_flags flags, 
 	CCLEventWaitList evt_wait_lst, GError** err);

#endif

/**
 * @brief Get a ::CCLWrapperInfo memory object information object.
 * 
 * @param mo The memory object wrapper object.
 * @param param_name Name of information/parameter to get.
 * @param err Return location for a GError, or NULL if error reporting
 * is to be ignored.
 * @return The requested memory object information object. This object will
 * be automatically freed when the memory object wrapper object is 
 * destroyed. If an error occurs, NULL is returned.
 * */
#define ccl_memobj_get_info(mo, param_name, err) \
	ccl_wrapper_get_info((CCLWrapper*) mo, NULL, param_name, \
		(ccl_wrapper_info_fp) clGetMemObjectInfo, CL_TRUE, err)

/** 
 * @brief Macro which returns a scalar memory object information value. 
 * 
 * Use with care. In case an error occurs, zero is returned, which 
 * might be ambiguous if zero is a valid return value. In this case, it
 * is necessary to check the error object. 
 * 
 * @param mo The memory object wrapper object.
 * @param param_name Name of information/parameter to get value of.
 * @param param_type Type of parameter (e.g. cl_uint, size_t, etc.).
 * @param err Return location for a GError, or NULL if error reporting
 * is to be ignored.
 * @return The requested memory object information value. This value will be 
 * automatically freed when the memory object wrapper object is destroyed. 
 * If an error occurs, zero is returned.
 * */
#define ccl_memobj_get_scalar_info(mo, param_name, param_type, err) \
	*((param_type*) ccl_wrapper_get_info_value((CCLWrapper*) mo, \
		NULL, param_name, (ccl_wrapper_info_fp) clGetMemObjectInfo, \
		CL_TRUE, err))

/** 
 * @brief Macro which returns an array memory object information value. 
 * 
 * Use with care. In case an error occurs, NULL is returned, which 
 * might be ambiguous if NULL is a valid return value. In this case, it
 * is necessary to check the error object. 
 * 
 * @param mo The memory object wrapper object.
 * @param param_name Name of information/parameter to get value of.
 * @param param_type Type of parameter (e.g. char*, size_t*, etc.).
 * @param err Return location for a GError, or NULL if error reporting
 * is to be ignored.
 * @return The requested memory object information value. This value will be 
 * automatically freed when the memory object wrapper object is destroyed. 
 * If an error occurs, NULL is returned.
 * */
#define ccl_memobj_get_array_info(mo, param_name, param_type, err) \
	(param_type) ccl_wrapper_get_info_value((CCLWrapper*) mo, \
		NULL, param_name, (ccl_wrapper_info_fp) clGetMemObjectInfo, \
		CL_TRUE, err)

/** 
 * @brief Increase the reference count of the cl_mem wrapper object.
 * 
 * @param mo The cl_mem wrapper object. 
 * */
#define ccl_memobj_ref(mo) \
	ccl_wrapper_ref((CCLWrapper*) mo)

/**
 * @brief Alias to ccl_memobj_destroy().
 * 
 * @param mo cl_mem wrapper object to destroy if reference count 
 * is 1, otherwise just decrement the reference count.
 * */
#define ccl_memobj_unref(mo) ccl_memobj_destroy(mo)

/**
 * @brief Get the OpenCL cl_mem object.
 * 
 * @param mo The cl_mem wrapper object.
 * @return The OpenCL cl_mem object.
 * */
#define ccl_memobj_unwrap(mo) \
	((cl_mem) ccl_wrapper_unwrap((CCLWrapper*) mo))		

/** @} */

#endif