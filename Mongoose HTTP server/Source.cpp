#include "mongoose.h"
#include <iostream>
#include <string>

using namespace std;

//	struct containing settings for how to serve HTTP with mongoose
static struct mg_serve_http_opts s_http_server_opts;

static void ev_handler(struct mg_connection* nc, int ev, void* p)
{
	if (ev == MG_EV_HTTP_REQUEST)
	{
		//	Serve html files;
		mg_serve_http(nc, (struct http_message*) p, s_http_server_opts);
	}
}

//	Server listening connection
int initServer(const int &port)
{
	//	Mongoose event manager
	struct mg_mgr mgr;
	//	Mongoose connection
	struct mg_connection *nc;

	string portToChar = to_string(port);
	static char const *chprt = portToChar.c_str();

	mg_mgr_init(&mgr, nullptr);
	cout << "Starting web server on port: " << chprt;

	nc = mg_bind(&mgr, chprt, ev_handler);

	if (nc == nullptr)
	{
		cout << "Failed to connect\n";
			return 1;
	}

	//	Set up HTTP server options
	mg_set_protocol_http_websocket(nc);

	s_http_server_opts.document_root = ".";
	s_http_server_opts.enable_directory_listing = "yes";

	for (;;)
		mg_mgr_poll(&mgr, 1000);

	//	Free up all memory 
	mg_mgr_free(&mgr);
}

int main()
{
	int port;

	cout << "Enter server port\n";
	cin >> port;
	
	if (cin.fail())
		port = 1000;

	initServer(port);
}