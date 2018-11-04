/*
 * File    : rwho_a.c
 * Creator : Pinkfish@Discworld
 *         : Grendel@Tmi-2
 * When    : 93-08-15
 *
 * This file is part of the tmi mudlib.  Please keep this header intact.
 *
 * This protocol is used to send a reply to a remote who request.
 */
#undef DEBUG

#include <net/dns.h>
#include <net/macros.h>

inherit F_CLEAN_UP;
inherit F_DBASE;

// They have answered our remote who question.

void incoming_request(mapping info)
{
	object ob;
	mapping minfo;
	int code;

	if( !ACCESS_CHECK(previous_object())) return;

	if (stringp(info["PORTUDP"]) && stringp(info["HOSTADDRESS"])) {
		if (info["NAME"] == Mud_name())	return ;
		if (!DNS_MASTER->dns_mudp(info["NAME"]))
			PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);

		minfo = DNS_MASTER->query_mud_info(info["NAME"]);
#ifdef DEBUG
	CHANNEL_D->do_channel(this_object(),DEBUG,info["NAME"]);
#endif

		if (!(ob = find_player(lower_case(info["ASKWIZ"])))) return;

		code = LOCATE_A->encoding(minfo["HOSTADDRESS"]);
		if( minfo["ENCODING"] == "GB" )	code = 0;

		if( code == 1)
			ob->start_more( LANGUAGE_D->toGB(info["RWHO"]) );
		else
			ob->start_more( info["RWHO"] );
	}
}

void create()
{
	seteuid(ROOT_UID);
	set("channel_id", "��·����");
}
