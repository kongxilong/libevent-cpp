#include "event_base.hh"

#include <sys/time.h>
#include <poll.h>

#include <map>

namespace eve
{

class rw_event;
class poll_base : public event_base
{
private:
	std::map<int, struct pollfd *> fd_map_poll;

public:
	poll_base() {}
	~poll_base() {}
	int add(std::shared_ptr<rw_event> ev) override;
	int del(std::shared_ptr<rw_event> ev) override;
	int recalc() override;
	int dispatch(struct timeval *tv) override;

private:
	void poll_check();
};

} // namespace eve
