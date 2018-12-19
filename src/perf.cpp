#include <asm/unistd.h>
#include <errno.h>
#include <linux/perf_event.h>
#include <map>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include <inttypes.h>

#include "metrics.h"
#include "metrics_priv.h"
#include "metrics_gen.h"

struct read_format
{
	unsigned long long value;
	/* if PERF_FORMAT_TOTAL_TIME_ENABLED */
	unsigned long long time_enabled;
	/* if PERF_FORMAT_TOTAL_TIME_RUNNING */
	unsigned long long time_running;
};

struct perf_stuff_1
{
	uint64_t count=0;
	int fd=0;
};


static std::map<struct __gluey::member_t, perf_stuff_1, __gluey::member_comparator> subs;

////////////////////////////////////////////////////////////////////////////////

static bool perf_event_available()
{
	if (access("/proc/sys/kernel/perf_event_paranoid", F_OK) == -1)
		return false;
	return true;
}

static bool perf_event_start(struct __gluey::member_t c)
{
	if (ioctl(subs[c].fd, PERF_EVENT_IOC_ENABLE, 0) == -1)
	{
		fprintf(stderr, "failed to start events:%s\n", strerror(errno));
		return false;
	}
	return true;
}

static bool perf_event_stop(struct __gluey::member_t c)
{
	if (ioctl(subs[c].fd, PERF_EVENT_IOC_DISABLE, 0) == -1)
	{
		fprintf(stderr, "failed to stop events\n");
		return false;
	}
	return true;
}

//// @todo see if __gluey::member_t is really needed
static bool perf_event_add(struct __gluey::member_t c, unsigned type, unsigned config)
{
	struct perf_event_attr pe;
	static pid_t pid = getpid();

	memset(&pe, 0, sizeof(struct perf_event_attr));

	pe.size = sizeof(struct perf_event_attr);
	pe.disabled = 1;

	// For ARM performance counters do not support mode exclusion
	// setting any exclude_* will result in a -EOPNOTSUPP.
	pe.exclude_kernel = 0;
	pe.exclude_hv = 0;

	// PARAMETERS
	pe.type = type;
	pe.config = config;

	perf_stuff_1 tmp_perf_stuff_1;
	while (1)
	{
		errno =0;
		tmp_perf_stuff_1.fd = syscall(__NR_perf_event_open, &pe, pid, -1/*cpu*/, -1/*group*/, 0);
		if (tmp_perf_stuff_1.fd < 0)
		{
			if (errno == ENOENT)
			{
				fprintf(stderr, "__NR_perf_event_open: event unsupported. (%d:%s)\n", errno, strerror(errno));
				return false;
			}
			if (errno == EACCES)
			{
				pid = 0;
				continue;
			}
			fprintf(stderr, "__NR_perf_event_open: (%d)%s\n", errno, strerror(errno));
			return false;
		}
		break;
	}
	subs[c] = tmp_perf_stuff_1;
	return true;
}

static bool perf_event_read(struct __gluey::member_t c, uint64_t *out)
{
	int rv;
	rv = read(subs[c].fd, &subs[c].count, sizeof(uint64_t));
	if (rv != sizeof(uint64_t))
	{
		fprintf(stderr, "failed to read __gluey::member_t data: %d %s\n", rv, strerror(errno));
		return false;
	}
	*out = subs[c].count;
	return true;
}

static struct __gluey::backend   backend_perf_event =
{
	true,
	perf_event_available,
	nullptr,		/* setup_backend */
	perf_event_add,
	nullptr,		/* del*/
	perf_event_start,
	perf_event_stop,
	perf_event_read
};
//////////////////////////////////////////////////

#include "perf_event_gen.cpp"
