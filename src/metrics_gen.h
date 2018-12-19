#ifndef _GLUEY_METRICS_H
# error "Never include <metrics_gen.h> directly; include <metrics.h> instead."
#endif

enum group_id
{
	GROUP_CACHE,
	GROUP_SW,
	GROUP_HW,
	GROUP_PERF_EVENT,
	GROUP_GPU,

	GROUP_ID_MAX /* non-ABI */
};

enum member_id
{
	MEMBER_PERF_HW,
	MEMBER_PERF_SW,
	MEMBER_PERF_HW_CACHE,

	MEMBER_ID_MAX /* non-ABI */
};

extern const char* tag_names[];

extern void perf_event_module();
