// include *_priv.h files only from source files or from other private headers.

namespace __gluey {


struct backend
{
	unsigned	enable;
	bool (*available)();
	bool (*setup_backend)();
	bool (*add)(member_t, unsigned, unsigned);
	bool (*del)(member_t);
	bool (*start)(member_t);
	bool (*stop)(member_t);
	bool (*read)(member_t, uint64_t*);
};

struct description
{
	unsigned config;
	const char* brief;
	const char* description;
};

struct member_priv_t {
	unsigned		size;
	unsigned		type;
	struct backend*		backend;
	struct description*	desc;
};

void group_set_tag(unsigned tag, unsigned group);
void member_set(unsigned id, struct __gluey::member_priv_t t);


}; // namespace __gluey
