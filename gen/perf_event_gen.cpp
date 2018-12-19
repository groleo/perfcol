
struct __gluey::description perf_hw_counter_description[] =
{
	{ PERF_COUNT_HW_CPU_CYCLES, "CPU Cycles", "the count of CPU cycles (total/elapsed)"},
	{ PERF_COUNT_HW_INSTRUCTIONS, "CPU Instructions", "the count of instructions by applications running on the platform"},
	{ PERF_COUNT_HW_CACHE_REFERENCES, "CPU Cache Accesses", "the count of cache hits by applications running on the platform"},
	{ PERF_COUNT_HW_CACHE_MISSES, "CPU Cache Misses", "the count of cache misses by applications running on the platform"},
	{ PERF_COUNT_HW_BRANCH_INSTRUCTIONS, "CPU Branch Instructions", "the count of branch instructions by applications running on the platform"},
	{ PERF_COUNT_HW_BRANCH_MISSES, "CPU Branch Misses", "the count of branch misses by applications running on the platform"},
	{ PERF_COUNT_HW_BUS_CYCLES, "Bus Cycles", "the count of bus cycles by applications running on the platform"},
	{ PERF_COUNT_HW_STALLED_CYCLES_FRONTEND, "Stalled Cycles in the Frontend", "the count of stalled CPU cycles in the frontend of the instruction processor pipeline by applications running on the platform"},
	{ PERF_COUNT_HW_STALLED_CYCLES_BACKEND, "Stalled Cycles in the Backend", "the count of stalled CPU cycles in the backend of the instruction processor pipeline by applications running on the platform"},
	{ PERF_COUNT_HW_REF_CPU_CYCLES, "CPU Reference Cycles", "the count of total CPU cycles not affected by CPU frequency scaling by applications running on the platform"},
};

struct __gluey::description perf_sw_counter_description[] =
{
	{ PERF_COUNT_SW_CPU_CLOCK, "CPU Clock", "the count of CPU clock time, as measured by a monotonic high-resolution per-CPU timer, by applications running on the platform"},
	{ PERF_COUNT_SW_TASK_CLOCK, "Task Clock", "the count of task clock time, as measured by a monotonic high-resolution CPU timer, specific to the task that is run by applications running on the platform"},
	{ PERF_COUNT_SW_PAGE_FAULTS, "Page Faults", "the count of page faults by applications running on the platform. This includes minor, major, invalid and other types of page faults"},
	{ PERF_COUNT_SW_CONTEXT_SWITCHES, "Context Switches", "the count of context switches by applications running on the platform"},
	{ PERF_COUNT_SW_CPU_MIGRATIONS, "CPU Migrations", "the count of CPU migrations, that is, where the process moved from one logical processor to another, by applications running on the platform"},
	{ PERF_COUNT_SW_PAGE_FAULTS_MIN, "Minor Page Faults", "the count of minor page faults, that is, where the page was present in the page cache, and therefore the fault avoided loading it from storage, by applications running on the platform"},
	{ PERF_COUNT_SW_PAGE_FAULTS_MAJ, "Major Page Faults", "the count of major page faults, that is, where the page was not present in the page cache, and therefore had to be fetched from storage, by applications running on the platform"},
	{ PERF_COUNT_SW_ALIGNMENT_FAULTS, "Load and Store Alignment Faults", "the count of alignment faults, that is when the load or store is not aligned properly, by applications running on the platform"},
	{ PERF_COUNT_SW_EMULATION_FAULTS, "Instruction Emulation Faults", "the count of emulation faults, that is when the kernel traps on unimplemented instructions and emulates them for user space, by applications running on the platform"},
};

struct __gluey::description perf_hw_cache_counter_description[] =
{
	{ ((PERF_COUNT_HW_CACHE_L1D)  |  (PERF_COUNT_HW_CACHE_OP_READ  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_ACCESS  <<  16)), "Level 1 Data Cache Loads", ""},
	{ ((PERF_COUNT_HW_CACHE_L1D)  |  (PERF_COUNT_HW_CACHE_OP_READ  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_MISS  <<  16)), "Level 1 Data Cache Load Misses", ""},
	{ ((PERF_COUNT_HW_CACHE_L1D)  |  (PERF_COUNT_HW_CACHE_OP_WRITE  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_ACCESS  <<  16)), "Level 1 Data Cache Stores", ""},
	{ ((PERF_COUNT_HW_CACHE_L1D)  |  (PERF_COUNT_HW_CACHE_OP_WRITE  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_MISS  <<  16)), "Level 1 Data Cache Store Misses", ""},
	{ ((PERF_COUNT_HW_CACHE_L1D)  |  (PERF_COUNT_HW_CACHE_OP_PREFETCH  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_ACCESS  <<  16)), "Level 1 Data Cache Prefetches", ""},
	{ ((PERF_COUNT_HW_CACHE_L1D)  |  (PERF_COUNT_HW_CACHE_OP_PREFETCH  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_MISS  <<  16)), "Level 1 Data Cache Prefetch Misses", ""},
	{ ((PERF_COUNT_HW_CACHE_L1I)  |  (PERF_COUNT_HW_CACHE_OP_READ  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_ACCESS  <<  16)), "Level 1 Instruction Cache Loads", ""},
	{ ((PERF_COUNT_HW_CACHE_L1I)  |  (PERF_COUNT_HW_CACHE_OP_READ  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_MISS  <<  16)), "Level 1 Instruction Cache Load Misses", ""},
	{ ((PERF_COUNT_HW_CACHE_L1I)  |  (PERF_COUNT_HW_CACHE_OP_WRITE  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_ACCESS  <<  16)), "Level 1 Instruction Cache Stores", ""},
	{ ((PERF_COUNT_HW_CACHE_L1I)  |  (PERF_COUNT_HW_CACHE_OP_WRITE  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_MISS  <<  16)), "Level 1 Instruction Cache Load Misses", ""},
	{ ((PERF_COUNT_HW_CACHE_L1I)  |  (PERF_COUNT_HW_CACHE_OP_PREFETCH  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_ACCESS  <<  16)), "Level 1 Instruction Cache Prefetches", ""},
	{ ((PERF_COUNT_HW_CACHE_L1I)  |  (PERF_COUNT_HW_CACHE_OP_PREFETCH  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_MISS  <<  16)), "Level 1 Instruction Cache Prefetch Misses", ""},
	{ ((PERF_COUNT_HW_CACHE_LL)  |  (PERF_COUNT_HW_CACHE_OP_READ  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_ACCESS  <<  16)), "Last-Level Cache Loads", ""},
	{ ((PERF_COUNT_HW_CACHE_LL)  |  (PERF_COUNT_HW_CACHE_OP_READ  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_MISS  <<  16)), "Last-Level Cache Load Misses", ""},
	{ ((PERF_COUNT_HW_CACHE_LL)  |  (PERF_COUNT_HW_CACHE_OP_WRITE  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_ACCESS  <<  16)), "Last-Level Cache Stores", ""},
	{ ((PERF_COUNT_HW_CACHE_LL)  |  (PERF_COUNT_HW_CACHE_OP_WRITE  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_MISS  <<  16)), "Last-Level Cache Store Misses", ""},
	{ ((PERF_COUNT_HW_CACHE_LL)  |  (PERF_COUNT_HW_CACHE_OP_PREFETCH  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_ACCESS  <<  16)), "Last-Level Cache Prefetches", ""},
	{ ((PERF_COUNT_HW_CACHE_LL)  |  (PERF_COUNT_HW_CACHE_OP_PREFETCH  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_MISS  <<  16)), "Last-Level Cache Prefetch Misses", ""},
	{ ((PERF_COUNT_HW_CACHE_DTLB)  |  (PERF_COUNT_HW_CACHE_OP_READ  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_ACCESS  <<  16)), "Data TLB Loads", ""},
	{ ((PERF_COUNT_HW_CACHE_DTLB)  |  (PERF_COUNT_HW_CACHE_OP_READ  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_MISS  <<  16)), "Data TLB Load Misses", ""},
	{ ((PERF_COUNT_HW_CACHE_DTLB)  |  (PERF_COUNT_HW_CACHE_OP_WRITE  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_ACCESS  <<  16)), "Data TLB Stores", ""},
	{ ((PERF_COUNT_HW_CACHE_DTLB)  |  (PERF_COUNT_HW_CACHE_OP_WRITE  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_MISS  <<  16)), "Data TLB Store Misses", ""},
	{ ((PERF_COUNT_HW_CACHE_DTLB)  |  (PERF_COUNT_HW_CACHE_OP_PREFETCH  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_ACCESS  <<  16)), "Data TLB Prefetches", ""},
	{ ((PERF_COUNT_HW_CACHE_DTLB)  |  (PERF_COUNT_HW_CACHE_OP_PREFETCH  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_MISS  <<  16)), "Data TLB Prefetch Misses", ""},
	{ ((PERF_COUNT_HW_CACHE_ITLB)  |  (PERF_COUNT_HW_CACHE_OP_READ  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_ACCESS  <<  16)), "Instruction TLB Loads", ""},
	{ ((PERF_COUNT_HW_CACHE_ITLB)  |  (PERF_COUNT_HW_CACHE_OP_READ  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_MISS  <<  16)), "Instruction TLB Load Misses", ""},
	{ ((PERF_COUNT_HW_CACHE_ITLB)  |  (PERF_COUNT_HW_CACHE_OP_WRITE  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_ACCESS  <<  16)), "Instruction TLB Stores", ""},
	{ ((PERF_COUNT_HW_CACHE_ITLB)  |  (PERF_COUNT_HW_CACHE_OP_WRITE  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_MISS  <<  16)), "Instruction TLB Store Misses", ""},
	{ ((PERF_COUNT_HW_CACHE_ITLB)  |  (PERF_COUNT_HW_CACHE_OP_PREFETCH  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_ACCESS  <<  16)), "Instruction TLB Prefetches", ""},
	{ ((PERF_COUNT_HW_CACHE_ITLB)  |  (PERF_COUNT_HW_CACHE_OP_PREFETCH  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_MISS  <<  16)), "Instruction TLB  Prefetch Misses", ""},
	{ ((PERF_COUNT_HW_CACHE_BPU)  |  (PERF_COUNT_HW_CACHE_OP_READ  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_ACCESS  <<  16)), "Branch Prediction Unit Loads", ""},
	{ ((PERF_COUNT_HW_CACHE_BPU)  |  (PERF_COUNT_HW_CACHE_OP_READ  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_MISS  <<  16)), "Branch Prediction Unit Load Misses", ""},
	{ ((PERF_COUNT_HW_CACHE_BPU)  |  (PERF_COUNT_HW_CACHE_OP_WRITE  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_ACCESS  <<  16)), "Branch Prediction Unit Stores", ""},
	{ ((PERF_COUNT_HW_CACHE_BPU)  |  (PERF_COUNT_HW_CACHE_OP_WRITE  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_MISS  <<  16)), "Branch Prediction Unit Store Misses", ""},
	{ ((PERF_COUNT_HW_CACHE_BPU)  |  (PERF_COUNT_HW_CACHE_OP_PREFETCH  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_ACCESS  <<  16)), "Branch Prediction Unit Prefetches", ""},
	{ ((PERF_COUNT_HW_CACHE_BPU)  |  (PERF_COUNT_HW_CACHE_OP_PREFETCH  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_MISS  <<  16)), "Branch Prediction Unit Prefetch Misses", ""},
	{ ((PERF_COUNT_HW_CACHE_NODE)  |  (PERF_COUNT_HW_CACHE_OP_READ  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_ACCESS  <<  16)), "Local Memory Accesses Loads", ""},
	{ ((PERF_COUNT_HW_CACHE_NODE)  |  (PERF_COUNT_HW_CACHE_OP_READ  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_MISS  <<  16)), "Local Memory Accesses Loads Misses", ""},
	{ ((PERF_COUNT_HW_CACHE_NODE)  |  (PERF_COUNT_HW_CACHE_OP_WRITE  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_ACCESS  <<  16)), "Local Memory Accesses Stores", ""},
	{ ((PERF_COUNT_HW_CACHE_NODE)  |  (PERF_COUNT_HW_CACHE_OP_WRITE  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_MISS  <<  16)), "Local Memory Accesses Store Misses", ""},
	{ ((PERF_COUNT_HW_CACHE_NODE)  |  (PERF_COUNT_HW_CACHE_OP_PREFETCH  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_ACCESS  <<  16)), "Local Memory Accesses Prefetches", ""},
	{ ((PERF_COUNT_HW_CACHE_NODE)  |  (PERF_COUNT_HW_CACHE_OP_PREFETCH  <<  8)  |  (PERF_COUNT_HW_CACHE_RESULT_MISS  <<  16)), "Local Memory Accesses Prefetch Misses", ""},
};

struct __gluey::member_priv_t member_perf_hw = { 10, PERF_TYPE_HARDWARE, &backend_perf_event, perf_hw_counter_description};

struct __gluey::member_priv_t member_perf_sw = { 9, PERF_TYPE_SOFTWARE, &backend_perf_event, perf_sw_counter_description};

struct __gluey::member_priv_t member_perf_hw_cache = { 42, PERF_TYPE_HW_CACHE, &backend_perf_event, perf_hw_cache_counter_description};

void perf_event_module()
{
	__gluey::group_set_tag(GROUP_PERF_EVENT, MEMBER_PERF_HW);
	__gluey::group_set_tag(GROUP_PERF_EVENT, MEMBER_PERF_SW);
	__gluey::group_set_tag(GROUP_PERF_EVENT, MEMBER_PERF_HW_CACHE);
	__gluey::group_set_tag(GROUP_HW, MEMBER_PERF_HW);
	__gluey::group_set_tag(GROUP_HW, MEMBER_PERF_HW_CACHE);
	__gluey::group_set_tag(GROUP_SW, MEMBER_PERF_SW);
	__gluey::group_set_tag(GROUP_CACHE, MEMBER_PERF_HW_CACHE);

	__gluey::member_set(MEMBER_PERF_HW, member_perf_hw);
	__gluey::member_set(MEMBER_PERF_SW, member_perf_sw);
	__gluey::member_set(MEMBER_PERF_HW_CACHE, member_perf_hw_cache);
}
