#pragma once

#include <http_connection.hh>


namespace eve
{
    
class http_client;
class http_client_connection:public http_connection
{
public:
    std::string servaddr;
    unsigned int servport;

    http_client *client = nullptr;

	int retry_cnt = 0; /* retry count */
	int retry_max = 0; /* maximum number of retries */

public:
    http_client_connection(event_base *base, http_client *client);
    ~http_client_connection();

    void fail(http_connection_error error);

    void do_read_done();
    void do_write_active();

    void dispatch();

    void do_write_over();

    int connect();

};

} // nameeve
