#include "metrics.h"
#include <inttypes.h>


int list_group()
{
	unsigned count=-1;
	const char *brief;

	group_size(&count);
	printf("group_size: %d\n", count);

	for (unsigned i=0; i<count; ++i)
	{
		group_name(i, &brief);
		printf("group: id=%d name=%s\n", i, brief);
	}
	return 0;
}


int list_member(unsigned groupID)
{
	unsigned count=-1;

	list_group();

	__gluey::group_t es;
	group_add_member(es, groupID);

	group_select_count(es, count);
	printf("number of members included in group=(%d): %d\n", groupID, count);

	if (!count)
		return 0;

////////////////////////////////////////////////////////////////////////////////
	unsigned members_st[count];
	bool rv = group_select(es, members_st);
	if (!rv)
		return 0;

	const char* out_name;
	for (unsigned t=0; t<count; ++t)
	{
		unsigned member_sz=0;
		rv = member_size(members_st[t], &member_sz);
		if (!rv)
			continue;

		printf("members_st=%d #entities=%d\n", t, member_sz);

		for (unsigned k=0; k<member_sz; ++k)
		{
			member_name(__gluey::member_t(groupID, members_st[t],k), &out_name);
			printf("Entity Brief: %d %d %d -> %s\n", groupID, members_st[t], k, out_name);
		}
	}
	return 0;
}


int list_entities(unsigned groupID, unsigned memberID)
{
	unsigned count=-1;

	list_group();

	__gluey::group_t es;
	group_add_member(es, groupID);

	group_select_count(es, count);
	printf("number of members included in group=(%d): %d\n", groupID, count);

	if (!count)
		return 0;

////////////////////////////////////////////////////////////////////////////////
	unsigned member_st[count];
	bool rv = group_select(es, member_st);
	if (!rv)
		return 0;

	const char* out_name;
	{
		unsigned member_sz=0;
		rv = member_size(memberID, &member_sz);
		if (!rv)
			return -1;

		printf("member_st=%d #entities=%d\n", memberID, member_sz);

		for (unsigned entityID=0; entityID<member_sz; ++entityID)
		{
			member_name(__gluey::member_t(groupID, memberID, entityID), &out_name);
			printf("Entity Brief: %d %d %d -> %s\n", groupID, memberID, entityID, out_name);
		}
	}
	return 0;
}


int test(unsigned ta, unsigned tn, unsigned tc)
{
	uint64_t out_c1;
	const char* out_name;
	bool rv;

	__gluey::member_t c1(ta,tn,tc);
	rv = member_setup(c1);
	if (!rv)
	{
		fprintf(stderr, "failed to add member_st\n");
		return false;
	}
	rv = member_start(c1);
	if (!rv)
	{
		fprintf(stderr, "failed to start member_st\n");
		return false;
	}
	rv = member_stop(c1);
	if (!rv)
	{
		fprintf(stderr, "failed to stop member_st\n");
		return false;
	}
	rv = member_read(c1, &out_c1);
	if (!rv)
	{
		fprintf(stderr, "failed to read member_st\n");
		return false;
	}
	rv = member_name(c1, &out_name);
	if (!rv)
	{
		fprintf(stderr, "failed to get the member_st's name\n");
		return false;
	}
	printf("%" PRIu64 " %s\n", out_c1, out_name);
	return 0;
}


void usage()
{
	fprintf(stderr, "usage:\n");
	fprintf(stderr, "\tmag <groupID> <memberID> <entityID> [IP]\n");
}


int main(int argc, char* argv[])
{
	unsigned groupID, memberID, entityID;
	char* ip;
	/// assert on this
	mag_init();

	if (argc == 1)
	{
		list_group();
		usage();
		return EXIT_FAILURE;
	}

	if (argc == 2)
	{
		groupID = atoi(argv[1]);
		list_member(groupID);
		usage();
		return EXIT_FAILURE;
	}

	if (argc == 3)
	{
		memberID = atoi(argv[2]);
		list_entities(groupID, memberID);
		usage();
		return EXIT_FAILURE;
	}

	if (argc == 4)
	{
		entityID = atoi(argv[3]);
		test(groupID, memberID, entityID);
		return EXIT_SUCCESS;
	}


	return EXIT_SUCCESS;
}
