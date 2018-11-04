/*
 * File    : gtell.c
 * Creator : Pinkfish@Discworld
 *         : Grendel@Tmi-2
 * When    : 93-08-15
 *
 * This file is part of the tmi mudlib.  Please keep this header intact.
 *
 * This protocol is used to convey intermud tells.
 */

// Ported to ES2 mudlib by Annihilator (06/16/95)

#include <command.h>
#include <net/dns.h>
#include <net/macros.h>
#include <net/daemons.h>

inherit F_CLEAN_UP;
inherit F_DBASE;

// Tell to someone on another mud.

void send_gtell(string mud, string wiz_to, object source, string msg)
{
	mapping minfo;
	int code;
	set("channel_id", "��·����");

	if(!ACCESS_CHECK(previous_object())) return;
//	&&	base_name(previous_object()) != TELL_CMD) return;

	mud = htonn( mud );

	if(mud == mud_nname() || !geteuid(source)) return;

	minfo = (mapping)DNS_MASTER->query_mud_info(mud);
	if (!minfo) return ;

	code = LOCATE_A->encoding(minfo["HOSTADDRESS"]);
	if( minfo["ENCODING"] == "GB" )	code = 0;

	msg = replace_string(msg, "|", "");
	msg = replace_string(msg, "@@@", "");
	if( code == 1 ) {
		DNS_MASTER->send_udp(minfo["HOSTADDRESS"], minfo["PORTUDP"],
		"@@@" + DNS_GTELL +
		"||NAME:" + LANGUAGE_D->toBig5(Mud_name()) +
		"||PORTUDP:" + udp_port() +
		"||WIZTO:" + wiz_to +
		"||WIZFROM:" + capitalize(geteuid(source)) +
		"||CNAME:" + LANGUAGE_D->toBig5(source->name(1)) +
		"||MSG:"+LANGUAGE_D->toBig5(msg)+"@@@\n");
	} else {
		DNS_MASTER->send_udp(minfo["HOSTADDRESS"], minfo["PORTUDP"],
		"@@@" + DNS_GTELL +
		"||NAME:" + Mud_name() +
		"||PORTUDP:" + udp_port() +
		"||WIZTO:" + wiz_to +
		"||WIZFROM:" + capitalize(geteuid(source)) +
		"||CNAME:" + source->name(1) +
		"||MSG:"+msg+"@@@\n");

	}
}

// Someone on another mud has sent us a tell.
void incoming_request(mapping info)
{
	mapping minfo;
	string reply;
	int code;

	if (info["NAME"] && info["PORTUDP"]) {
		// dont want to tell to ourselves
		if (info["NAME"] == Mud_name())	return;

		// get our info about the sender, ping them if we don't have any
		minfo = DNS_MASTER->query_mud_info(info["NAME"]);
		if (!minfo || !DNS_MASTER->dns_mudp(info["NAME"]))
			PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);

		if (minfo && minfo["HOSTADDRESS"] != info["HOSTADDRESS"]) {
			// Its been faked! 
			dns_log("dns_fake", "Tell: "+info["WIZFROM"]+"@"+info["NAME"]+
				"("+info["HOSTADDRESS"]+") telling "+info["WIZTO"]
				+" "+ info["MSG"]+"\n");
			DNS_MASTER->send_udp(minfo["HOSTADDRESS"], minfo["PORTUDP"],
				"@@@"+DNS_WARNING+
				"||MSG: Faked gtell message "+info["WIZFROM"]+
				"@"+info["NAME"]+"> "+info["WIZTO"]+
				" "+info["MSG"]+
				"||FAKEHOST:"+info["name"]+
				"@@@\n");
			return ;
		}


	code = LOCATE_A->encoding(minfo["HOSTADDRESS"]);
	if( minfo["ENCODING"] == "GB" )	code = 0;

	if( code == 1 ) {
		reply =(string)TELL_CMD->remote_tell( LANGUAGE_D->toGB(info["CNAME"]), info["WIZFROM"],
			LANGUAGE_D->toGB(info["NAME"]),info["WIZTO"], LANGUAGE_D->toGB(info["MSG"]) );

		(AUX_PATH+"affirmation_a")->send_affirmation_a(info["HOSTADDRESS"],
			info["PORTUDP"], LANGUAGE_D->toBig5(MUD_NAME),
			info["WIZFROM"], LANGUAGE_D->toBig5(reply), "gtell");
	} else {
		// ReWrite By JackyBoy @ CuteRabbit Studios For CCTX
		// codeΪ��ʱ����
		code =TELL_CMD->remote_tell( info["CNAME"], info["WIZFROM"],
				info["NAME"],info["WIZTO"], info["MSG"] );
		if(code)
            reply = "�����"+"("+capitalize(info["WIZTO"])+"@"+Mud_name()+")��" + info["MSG"];
    	else
            reply = "û������ˡ�\n";
		(AUX_PATH+"affirmation_a")->send_affirmation_a(info["HOSTADDRESS"],
			info["PORTUDP"], MUD_NAME,
			info["WIZFROM"], reply, "gtell");
		}
	} //if (info["NAME"] && info["PORTUDP"])
}
