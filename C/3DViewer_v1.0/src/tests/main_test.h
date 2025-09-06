#ifndef _3D_VIEWER_TESTS_H
#define _3D_VIEWER_TESTS_H

#include <check.h>

#include "../3D_Viewer_core.h"
#include "../3D_Viewer_utils.h"

#define IDENTITY                                        \
  {                                                     \
    {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, { 0.0, 0.0, 1.0 } \
  }
#define ONES                                            \
  {                                                     \
    {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, { 1.0, 1.0, 1.0 } \
  }

#define PERMUTATION                                     \
  {                                                     \
    {0.0, 0.0, 1.0}, {0.0, 1.0, 0.0}, { 1.0, 0.0, 0.0 } \
  }

#define VECTOR_0 \
  { 0.0, 0.0, 0.0 }
#define VECTOR_1 \
  { 1.0, 1.0, 1.0 }
#define VECTOR_2 \
  { 1.0, 2.0, 3.0 }
#define VECTOR_3 \
  { 2.0, 1.0, 0.0 }

#define OBJ_FILE_1 "models/cube.obj"
#define OBJ_FILE_2 "models/building.obj"
#define OBJ_FILE_3 "models/test_0.obj"
#define OBJ_FILE_4 "models/test_1.obj"
#define OBJ_FILE_5 "models/test_2.obj"

Suite *transform_vertex_suite(void);
Suite *scale_vertex_suite(void);
Suite *rotation_scale_suite(void);
Suite *motion_vertex_suite(void);
Suite *count_lines_suite(void);
Suite *get_array_suite(void);
Suite *transform_vertex_massive_suite(void);
Suite *backend_suite(void);
Suite *test_find_max_coord_of_vert(void);

#endif  // #ifndef _3D_VIEWER_UTIL_H
