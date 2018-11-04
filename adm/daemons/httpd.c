
// ported to cctx by JackyBoy@CuteRabbits Studio 1999/3/10
//Lpc HTTPD Web Server

// Ported to CCTXII with V22.1b22 surport By JackyBoy@CuteRabbits Studio 1999/6/11

// Modifyed By JackyBoy again.Just Make it Work for Mud Of game.etang.com 2000/5/15

#define DEBUGGER "jackyboy"

#include <localtime.h>
#include <net/httpd.h>
#include <net/socket.h>
#include <net/socket_errors.h>

#define MAXIMUM_RETRIES	8

#define HTTP_HEADER "HTTP/1.0 %s%c"
#define DEFAULT_HEADER "Server: "+"JackyBoy@126.com"+"/0.2\nMIME-version: 1.0%c"

#define log_info(x, y) log_file(x, ctime(time()) + "\n"); log_file(x, y)

inherit F_DBASE;

static int httpSock;
static int persistent;
static int accesses;

static mapping sockets;
static mapping resolve_pending;

static string *months;

static mapping bad_cmd = BAD_CMD;
static mapping access_denied = ACCESS_DENIED;
static mapping not_found = NOT_FOUND;
static mapping bad_gateway = BAD_GATEWAY;


protected string common_date(int);

void create();
protected void setup();
void remove();

void write_data(int , mixed );
void set_persistent(int );
void save_data();
void log_http(int , int , int , string );
int file_exists(string );
void http_error(int, mapping , string);
void close_connection(int);
void listen_callback(int);
void write_callback(int);
void read_callback(int, string);

int query_accesses()
{
	return accesses;
}

void create()
{ 
	seteuid( ROOT_UID );
	set("channel_id","ϵͳ����");
	accesses = 0;
	set_persistent(1);
	months = ({"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct",
		"Nov","Dec"});
	sockets = ([]);//ά��sockets�б�
	resolve_pending = ([]);
	log_info(LOG_HTTP_ERR, "Created when uptime = " + uptime() + "\n");
	CHANNEL_D->do_channel(this_object(), "sys", "��ҳ�����������ɹ���\n");
	call_out("setup", 5);
}

string http_header(string code)
{
	return sprintf(HTTP_HEADER, code, 10) + sprintf(DEFAULT_HEADER, 10);
}

string http_error_header(string code)
{
	return http_header(code) + sprintf("Content-type: text/html%c%c", 10, 10);
}

// Leto obsolete here, can get ripped out later
int query_prevent_shadow(object nouse)
{
	return 1;
}

varargs string query_hostname(int fd, int t)
{
	mapping entry;

	entry = sockets[fd];
	if (!undefinedp(entry)) {
		if (t) {
			return entry["address"];
		} else {
			return entry["name"];
		}
	}
	return 0;
}

protected void setup()//��������ʼ����
{
	if ((httpSock =
		socket_create(STREAM, "read_callback", "close_callback")) < 0)
	{
		log_info(LOG_HTTP_ERR, "setup: Failed to create socket.\n");
		return;//Socket��������
	}
	if (socket_bind(httpSock, PORT_HTTP) < 0) {
		//��Socket�󶨵��˿ڳ������ܶ˿��Ѿ���ռ�ã�����ʱ����Socket�˳�
		socket_close(httpSock);
		log_info(LOG_HTTP_ERR, "setup: Failed to bind socket to port.\n");
		return;
	}
	if (socket_listen(httpSock, "listen_callback") < 0) {
		//�����˿ڳ����˳�
		socket_close(httpSock);
		log_info(LOG_HTTP_ERR, "setup: Failed to listen to socket.\n");
	}
}

void write_data_retry(int fd, mixed data, int counter)
{
	int rc;

	if (counter == MAXIMUM_RETRIES) {
		close_connection(fd);
		return;
	}
	rc = socket_write(fd, data);
	HTTP_DEBUG("write_data: rc = " + rc + ", counter = " + counter + "\n");
	sockets[fd]["write_status"] = rc;
	switch (rc) {
		case EESUCCESS:
			// we're finished with this fd.
			close_connection(fd);
			break;
		case EEALREADY:
			// driver must have set the socket marked as BLOCKED when
			// it was created by socket_accept().  Just wait for
			// write_callback to be called so that we can write out the
			// pending data.
			sockets[fd]["pending"] = data;
			break;
		case EECALLBACK:
			// wait for write_callback before accessing socket fd again.
			break;
		case EEWOULDBLOCK:
		case EESEND:
			// try again in two seconds
			if (counter < MAXIMUM_RETRIES) {
				call_out("retry_write", 2, ({fd, data, counter + 1}));
				return;
			}
			// fall through to the default case and write an error.
		default:
			log_info(LOG_HTTP_ERR, "write_data_retry: " + socket_error(rc) + "\n");
			close_connection(fd);
			break;
	}
}

void retry_write(mixed* args)
{
	write_data_retry(args[0], args[1], args[2]);
}

void write_data(int fd, mixed data)
{
	write_data_retry(fd, data, 0);
}

void store_client_info(int fd)
{
	string addr;
//	mixed result;
	int port;

	sscanf(socket_address(fd), "%s %d", addr, port);
	sockets[fd] = ([
	 "address" : addr,
	 "name" : addr,
	 "port" : port,
	 "time" : time(),
	 "write_status" : EESUCCESS
	]);
}

void listen_callback(int fd)
{
	int nfd;

	if ((nfd = socket_accept(fd, "read_callback", "write_callback")) < 0) {
		log_info(LOG_HTTP_ERR, "listen_callback: socket_accept failed.\n");
		return;
	}
	store_client_info(nfd);
}

//
// The driver calls write_callback to indicate that the data sent
// by the last call to socket_write() is finally all written to the
// network (or to indicate that a socket created in the blocked state
// is now ready for writing).
//

void write_callback(int fd)
{
	// The status will be EEALREADY only in the event that the socket
	// was created in a blocked state (this object is smart enough not
	// to write to a socket it knows is blocked).
	//
	if (sockets[fd]["write_status"] == EEALREADY) {
		write_data(fd, sockets[fd]["pending"]);
		//
		// its safe to delete the pending data now since its already been sent
		// and since we won't ever have any more pending data for this
		// socket (we might have an EECALLBACK but the driver is
		// responsible for holding the pending data in that case).
		//
		map_delete(sockets[fd], "pending");
	} else {
		//
		// We can close the socket at this point since we only ever send one
		// thing on a given socket before we are through with it.
		//
		sockets[fd]["write_status"] = EESUCCESS;
		close_connection(fd);
	}
}

// todo make this a simul_efun
string common_date(int t)
{
	mixed* r;

	r = localtime(t);
	return sprintf("%02d/%s/%d:%02d:%02d:%02d -%02d00",
		r[LT_MDAY], months[r[LT_MON]], r[LT_YEAR], r[LT_HOUR],
		r[LT_MIN], r[LT_SEC], r[LT_GMTOFF] / 3600);
}

void log_http(int fd, int rc, int nbytes, string cmd)
{
	string msg;
	string bsent;

	if (!sockets[fd]) {
		return;
	}
	bsent = (nbytes) ? sprintf("%d", nbytes) : "-";
	msg = sprintf("%s unknown - [%s] \"%s\" %d %s\n",
		sockets[fd]["name"], common_date(time()), cmd, rc, bsent);
	log_file(LOG_HTTP, msg);
}

void do_get(int, string, string);
void do_post(int, string, string, string);

void read_callback(int fd, string str)//���ͻ��˷�������󣬼���˺���
{
	string cmd, args, file, url;
	string *request;
	string tmp, line0;

	if (!sizeof(str)) {//�������ִ�
		http_error(fd, bad_cmd, "400 Bad Request");
		return;
	}

	if (tmp = sockets[fd]["read"]) {
		str = tmp + str;
	}
	if (str[<1] != '\n') {
		sockets[fd]["read"] = str;
		return;
	} else {
		map_delete(sockets[fd], "read");
	}
	accesses++;
HTTP_DEBUG("read_callback: (" + str + ")\n");
	request = explode(replace_string(str, "\r", ""), "\n");
	line0 = request[0];
	sscanf(line0, "%s %s %s", cmd, file, args);
	switch(lower_case(cmd)) {//����Ĳ���
		case "get":
			do_get(fd, file, line0);
			break;
		case "post":
			url = request[<1]; // last line of the request
			do_post(fd, file, url, line0);
			break;
		default:
			http_error(fd, bad_cmd, "400 Bad Request");
			break;
	}
}

// close_callback is called when any socket is closed unexpectedly
// (by the driver instead of as a result of socket_close()).

void close_callback(int fd)
{
	if (fd == httpSock) {
		log_info(LOG_HTTP_ERR,
			"HTTP socket closed unexpectedly; restarting.\n");
		call_out("setup", 5);
	} else {
		if (undefinedp(sockets[fd])) {
			log_info(LOG_HTTP_ERR,
				sprintf("Client socket %d closed unexpectedly\n", fd));
		} else {
			log_info(LOG_HTTP_ERR,
				sprintf("Client socket %s %d closed unexpectedly.\n",
					sockets[fd]["name"], sockets[fd]["port"]));
		}
		map_delete(sockets, fd);
	}
}

// resolve_callback is called by the resolver object in response to our
// queries to resolve dotted decimal internet addresses into domain name
// style addresses.

void resolve_callback(string theName, string theAddr, int slot)
{
//	int *fds;
//	int i;
	int fd;

	fd = resolve_pending[slot];
	map_delete(resolve_pending, slot);
	if (!undefinedp(sockets[fd]) && (sockets[fd]["address"] == theAddr)) {
		sockets[fd]["name"] = theName;
	} else {
		log_info(LOG_HTTP_ERR,
			sprintf("Resolved %s to %s after connection closed.\n",
				theAddr, (sizeof(theName) ? theName : "NOT RESOLVED")));
	}
}

void http_error(int fd, mapping err, string code)
{
	string tens;

	tens = sprintf("%c%c", 10, 10);
	HTTP_DEBUG(http_error_header(code) + read_file(err["file"]) + tens);
	write_data(fd, http_error_header(code) + read_file(err["file"]) + tens);
}

void close_connection(int fd)
{
	if (sockets[fd]["write_status"] == EECALLBACK) {
		// write_callback() will call close_connection() when socket fd
		// is drained.
		return;
	}
	map_delete(sockets, fd);
	map_delete(resolve_pending, fd);
	socket_close(fd);
}

// respond to a client request for a file.
//
    
void do_get(int fd, string file, string line0)
{
	string dir;
	string *parts;
	mixed result;
	string ofile;
	string args, id;

	if (file[0] != '/') file = "/" + file;
	ofile = file;
	parts = explode(file, "/");
	if (!sizeof(parts)) {//������ļ���˵������Ĭ��ȡ��index.htm�ļ�
		file = sprintf("%s/index.htm", DIR_WWW);
	} else if (file[1] == '~') {//����ʦ�ṩһ�������ĸ���WEB�ռ�
		parts[0] = sprintf("%s%s", user_path(parts[0][1..<1]), USER_WWW_SUBDIR);
		file = implode(parts, "/");
	} else if (file[0..strlen(DIR_WWW)-1] != DIR_WWW) {
		file = sprintf("%s%s", DIR_WWW, file);
	}
	if (file_size(file) == -2) {//�����һ��Ŀ¼
		dir = file;
		file = sprintf("%s/index.htm", file);
		if (file_size(file) == -1) {//��Ȩ�ޱ��ܾ�����Ŀ¼�����ڵĴ���
			file = "/www/gateways/dirlist" + dir;
		}
	}

	HTTP_DEBUG("HTTP:" + file + ", " + sockets[fd]["name"] + "\n");

	if (!strsrch(file, DIR_WWW_GATEWAYS)) {
	    if ((sscanf(file, DIR_WWW_GATEWAYS+"/%s?%s", id, args) == 2) ||
	          (sscanf(file, DIR_WWW_GATEWAYS+"/%s/%s", id, args) == 2))
	        file = sprintf(DIR_WWW_GATEWAYS+"/%s", id);
	    if (catch(result = file->gateway(args))) {
		log_http(fd, 400, 0, line0);
		http_error(fd, bad_gateway, "400 Bad Request");
		return;
	    }
	} else if (!file_exists(file)) {
                // automagically map .html to .c files
                if (!strsrch(file, DIR_WWW) && file[<5..<1] == ".html") {
                    file = file[0..<6];
                    if (file_exists(file + ".c") && catch(result = file->gateway())) {
                        log_http(fd, 400, 0, line0);
                        http_error(fd, bad_gateway, "400 Bad Request");
                        return;
                    }
                } else {
                    log_http(fd, 404, 0, line0);
                    http_error(fd, not_found, "404 Not Found");
                    return;
                }
	} else {
		result = read_buffer(file);
	}
	log_http(fd, 200, sizeof(result), line0);
	write_data(fd, result);
}

void do_post(int fd, string file, string url, string line0)
{
	do_get(fd, file + "?" + url, line0);
}

void set_persistent(int which)
{
   persistent = which;
}

void remove()
{
	CHANNEL_D->do_channel(this_object(), "sys", "��ҳ�������Ѿ��رա�\n");
	socket_close(httpSock);
}

int file_exists(string str)
{
   if (file_length(str)>0)
     return 1;
   else 
     return 0;
}
