/*
 * This file is part of cf4ocl (C Framework for OpenCL).
 *
 * cf4ocl is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * cf4ocl is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with cf4ocl.  If not, see <http://www.gnu.org/licenses/>.
 * */

 /**
 * @file
 * OpenCL stub object implementations.
 *
 * @author Nuno Fachada
 * @date 2014
 * @copyright [GNU General Public License version 3 (GPLv3)](http://www.gnu.org/licenses/gpl.html)
 * */

#ifndef _CCL_OCL_STUB_H_
#define _CCL_OCL_STUB_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <glib/gprintf.h>
#include "ccl_oclversions.h"

/** Stub for cl_event objects. */
struct _cl_event {
	cl_ulong t_queued;
	cl_ulong t_submit;
	cl_ulong t_start;
	cl_ulong t_end;
	cl_command_queue command_queue;
	cl_context context;
	cl_command_type command_type;
	cl_int exec_status;
	cl_uint ref_count;
	/* Registered callbacks. */
#ifdef CL_VERSION_1_1
	void (CL_CALLBACK *pfn_notify[3])(cl_event, cl_int, void*);
	void* user_data[3];
#endif

};

/** Stub for cl_command_queue objects. */
struct _cl_command_queue {
	cl_context context;
	cl_device_id device;
	cl_uint ref_count;
	cl_command_queue_properties properties;
};

struct _cl_device_id {
	const cl_uint address_bits;
	const cl_bool available;
	char* built_in_kernels; /* Not const because it can change in sub-devices. */
	const cl_bool compiler_available;
	const cl_device_fp_config double_fp_config;
	const cl_bool endian_little;
	const cl_bool error_correction_support;
	const cl_device_exec_capabilities execution_capabilities;
	const char* extensions;
	cl_ulong global_mem_cache_size; /* Not const because it can change in sub-devices. */
	const cl_device_mem_cache_type global_mem_cache_type;
	const cl_uint global_mem_cacheline_size;
	const cl_ulong global_mem_size;
	const cl_device_fp_config half_fp_config;
	const cl_bool host_unified_memory;
	const cl_bool image_support;
	const size_t image2d_max_height;
	const size_t image2d_max_width;
	const size_t image3d_max_depth;
	const size_t image3d_max_height;
	const size_t image3d_max_width;
	const size_t image_max_buffer_size;
	const size_t image_max_array_size;
	const cl_bool linker_available;
	const cl_ulong local_mem_size;
	const cl_device_local_mem_type local_mem_type;
	const cl_uint max_clock_frequency;
	cl_uint max_compute_units; /* Not const because it can change in sub-devices. */
	const cl_uint max_constant_args;
	const cl_ulong max_constant_buffer_size;
	const cl_ulong max_mem_alloc_size;
	const size_t max_parameter_size;
	const cl_uint max_read_image_args;
	const cl_uint max_samplers;
	const size_t max_work_group_size;
	const cl_uint max_work_item_dimensions;
	const size_t* max_work_item_sizes;
	const cl_uint max_write_image_args;
	const cl_uint mem_base_addr_align;
	const cl_uint min_data_type_align_size;
	const char* name;
	const cl_uint native_vector_width_char;
	const cl_uint native_vector_width_short;
	const cl_uint native_vector_width_int;
	const cl_uint native_vector_width_long;
	const cl_uint native_vector_width_float;
	const cl_uint native_vector_width_double;
	const cl_uint native_vector_width_half;
	const char* opencl_c_version;
	cl_device_id parent_device; /* Not const because it can change in sub-devices. */
	cl_uint partition_max_sub_devices; /* Not const because it can change in sub-devices. */
	const cl_device_partition_property* partition_properties;
	const cl_device_affinity_domain partition_affinity_domain;
	cl_device_partition_property* partition_type; /* Not const because it can change in sub-devices. */
	const cl_platform_id platform_id;
	const cl_uint preferred_vector_width_char;
	const cl_uint preferred_vector_width_short;
	const cl_uint preferred_vector_width_int;
	const cl_uint preferred_vector_width_long;
	const cl_uint preferred_vector_width_float;
	const cl_uint preferred_vector_width_double;
	const cl_uint preferred_vector_width_half;
	const size_t printf_buffer_size;
	const cl_bool preferred_interop_user_sync;
	const char* profile;
	const size_t profiling_timer_resolution;
	const cl_command_queue_properties queue_properties;
	const cl_device_fp_config single_fp_config;
	const cl_device_type type;
	const char* vendor;
	const cl_uint vendor_id;
	const char* version;
	const char* driver_version;
	cl_uint ref_count; /* Not const because it can change in sub-devices. */
};

struct _cl_platform_id {
	const char* profile;
	const char* version;
	const char* name;
	const char* vendor;
	const char* extensions;
	const cl_image_format* image_formats;
	const cl_uint num_image_formats;
	const guint num_devices;
	const struct _cl_device_id* devices;
};

struct _cl_context {
	cl_context_properties* properties;
	cl_uint prop_len;
	cl_device_id* devices;
	cl_uint num_devices;
	cl_bool d3d;
	cl_uint ref_count;
};

struct _cl_program {
	cl_uint ref_count;
	cl_context context;
	cl_uint num_devices;
	cl_device_id* devices;
	char* source;
	size_t* binary_sizes;
	unsigned char** binaries;
#ifdef CL_VERSION_1_2
	cl_program_binary_type* binary_type;
#endif
	size_t num_kernels;
	char* kernel_names;
	cl_build_status* build_status;
	char** build_options;
	char** build_log;
};

struct _cl_kernel {
	cl_uint ref_count;
	cl_program program;
	cl_context context;
	const char* function_name;
	cl_uint num_args;
	const char* attributes;
};

#ifndef CL_VERSION_1_2
typedef struct _cl_image_desc {
    cl_mem_object_type      image_type;
    size_t                  image_width;
    size_t                  image_height;
    size_t                  image_depth;
    size_t                  image_array_size;
    size_t                  image_row_pitch;
    size_t                  image_slice_pitch;
    cl_uint                 num_mip_levels;
    cl_uint                 num_samples;
    cl_mem                  buffer;
} cl_image_desc;
#endif

struct _cl_mem {
	cl_uint ref_count;
	cl_mem_object_type type;
	cl_mem_flags flags;
	size_t size;
	void* host_ptr;
	cl_uint map_count;
	cl_context context;
	cl_mem associated_object;
	size_t offset;
	GSList* callbacks;
	void* mem;
	/* Image only. */
	struct _cl_image_format image_format;
	struct _cl_image_desc image_desc;
	size_t image_elem_size;
};

struct _cl_sampler {
	cl_uint ref_count;
	cl_context context;
	cl_bool normalized_coords;
	cl_addressing_mode addressing_mode;
	cl_filter_mode filter_mode;
};

#endif

