#include "metrics.h"
#include "metrics_priv.h"
#include "metrics_gen.h"

#include <string.h> /* strcmp */

void mag_init()
{
	perf_event_module();
}
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
static struct __gluey::member_priv_t member_tbl[MEMBER_ID_MAX]={0, };
static std::bitset<MEMBER_ID_MAX> group_tags[GROUP_ID_MAX];

void __gluey::member_set(unsigned id, struct __gluey::member_priv_t t)
{
	member_tbl[id] = t;
}

void __gluey::group_set_tag(unsigned tag, unsigned group)
{
	group_tags[tag].set(group);
}

bool group_size(unsigned *out)
{
	*out = GROUP_ID_MAX;
	return true;
}

bool group_name(unsigned in_id, const char **out)
{
	*out = tag_names[in_id];
	return true;
}

bool group_id(const char*in_name, unsigned *out)
{
	for (int i=0; i<GROUP_ID_MAX; ++i)
	{
		if (!strcmp(tag_names[i], in_name))
		{
			*out = i;
			return true;
		}
	}
	return false;
}

void group_add_member(__gluey::group_t& es, unsigned id)
{
	es.bs.set(id);
}

bool group_select_count(__gluey::group_t es, unsigned &out)
{
	std::bitset<MEMBER_ID_MAX> acc = ~0;
	unsigned long in_tag_bitpos = es.bs.to_ulong();

	for (int i; (i = ffs(in_tag_bitpos)); )
	{
		--i;
		acc &= group_tags[i];
		in_tag_bitpos &= ~(1 << i);
	}
	out = acc.count();
	return true;
}

bool group_select(__gluey::group_t es, unsigned out_idx[])
{
	std::bitset<MEMBER_ID_MAX> acc = ~0;
	unsigned in_tag_bitpos = es.bs.to_ulong();
	for (int i; (i = ffs(in_tag_bitpos)); )
	{
		--i;
		acc &= group_tags[i];
		in_tag_bitpos &= ~(1 << i);
	}
	uint64_t acc_bits = acc.to_ullong();
	int k=0;
	for (int i; (i = ffs(acc_bits)); )
	{
		--i;

		if (! member_tbl[i].backend->available())
		{
			acc_bits &= ~(1 << i);
			continue;
		}

		out_idx[k] = i;
		k+=1;
		acc_bits &= ~(1 << i);
	}
	return true;
}

bool member_size(unsigned id, unsigned *out_count)
{
	*out_count = member_tbl[id].size;
	return true;
}

bool group_set_select(__gluey::group_t es, unsigned out_idx[])
{
	std::bitset<MEMBER_ID_MAX> acc = ~0;
	unsigned in_tag_bitpos = es.bs.to_ulong();
	for (int i; (i = ffs(in_tag_bitpos)); )
	{
		--i;
		acc &= group_tags[i];
		in_tag_bitpos &= ~(1 << i);
	}
	uint64_t acc_bits = acc.to_ullong();
	int k=0;
	for (int i; (i = ffs(acc_bits)); )
	{
		--i;

		if (! member_tbl[i].backend->available())
		{
			continue;
		}

		out_idx[k] = member_tbl[i].size;
		out_idx[k+1] = i;
		k+=2;
		acc_bits &= ~(1 << i);
	}
	return true;
}
////////////////////////////////////////////////////////////////////////////////
bool member_name(__gluey::member_t in, const char**out)
{
	*out = member_tbl[in.member_id].desc[in.id].brief;
	return true;
}

bool member_setup(__gluey::member_t e)
{
	unsigned type = member_tbl[e.member_id].type;
	unsigned config = member_tbl[e.member_id].desc[e.id].config;

	if (member_tbl[e.member_id].backend->setup_backend)
		member_tbl[e.member_id].backend->setup_backend();
	return member_tbl[e.member_id].backend->add(e, type, config);
}

bool member_start(__gluey::member_t in)
{
	return member_tbl[in.member_id].backend->start(in);
}

bool member_stop(__gluey::member_t in)
{
	return member_tbl[in.member_id].backend->stop(in);
}

bool member_read(__gluey::member_t in, uint64_t *out)
{
	return member_tbl[in.member_id].backend->read(in, out);
}
