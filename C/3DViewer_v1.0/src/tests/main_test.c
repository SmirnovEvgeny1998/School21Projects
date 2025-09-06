#include "main_test.h"

int main(void) {
  Suite *test_suites[] = {
      transform_vertex_suite(),
      scale_vertex_suite(),
      rotation_scale_suite(),
      motion_vertex_suite(),
      count_lines_suite(),
      get_array_suite(),
      transform_vertex_massive_suite(),
      backend_suite(),
      test_find_max_coord_of_vert()
  };

  SRunner *sr = srunner_create(test_suites[0]);
  srunner_set_fork_status(sr, CK_NOFORK);

  int failed;

  for (size_t i = 1; i < sizeof(test_suites) / sizeof(SRunner *); i++)
    srunner_add_suite(sr, test_suites[i]);

  srunner_run_all(sr, CK_ENV);
  failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return failed == 0 ? 0 : 1;
}
