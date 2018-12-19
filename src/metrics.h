#ifndef _GLUEY_METRICS_H
#define _GLUEY_METRICS_H 1

#include <stdbool.h>
#include <bitset>

namespace __gluey {

struct group_t
{
        std::bitset<64>        bs;
};

struct member_t
{
        unsigned        group_id;
        unsigned        member_id;
        unsigned        id;
        member_t(unsigned x, unsigned k, unsigned z) : group_id(x), member_id(k), id(z) {}
};

struct member_comparator
{
        bool operator() (const __gluey::member_t& l, const __gluey::member_t& r) const
        {
                return  l.group_id < r.group_id
                        && l.member_id < r.member_id
                        && l.id < r.id;
        }
};

}; /* namespace __gluey */

bool group_size(unsigned *out);
bool group_name(unsigned in_id, const char**out);
bool group_id(const char *in_name, unsigned *out);

void group_add_member(__gluey::group_t& es, unsigned id);
//void group_del_member(__gluey::group_t& es, unsigned id);
bool group_select_count(__gluey::group_t es, unsigned &out);
bool group_select(__gluey::group_t es, unsigned out_idx[]);

bool member_size(unsigned in, unsigned *out_count);
bool member_name(__gluey::member_t in, const char**out);
bool member_setup(__gluey::member_t in);
bool member_start(__gluey::member_t in);
bool member_stop(__gluey::member_t in);
bool member_read(__gluey::member_t in, uint64_t *out);


void mag_init();

#endif /* metrics.h */
