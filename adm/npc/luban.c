// luban.c ³��
// Written by Doing Lu 1998/11/17
// ³���Ǹ����췿���NPC�� ���ȣ����ȥ³��������Ҫͼֽ��Ȼ���뽨���ĵص����ͼֽ��
// ����Ҫ��30�����ϵĻ滭���ɲſ��ԣ��������30�������Ժ�³��ѧϰ��
// Ȼ�����Ҫ��ͼֽ��³�࣬³��ѯ�ʷ��ݵ����ƣ����ܺ��������еķ���������Ȼ����ѯ�ʷ���
// �����ͣ����ݵ����Ͷ�������roomtype.h���У�����ѯ��ÿ�������������ÿ���������ܳ�����
// �ٶ�ʮ���ַ�����������У����������еķ����short ���ɷ����������ɣ�����Ҫ������룬
// Ȼ��³���¼���е���Ϣ������ʾ��ҵȴ���ʦ��Ȩ����hufa���ϣ�����׼��
// ��ʦ���ߺ�³�ദ��³����ʾ��ʦ������ҵ���Ϣ�������ʦ��׼�ˣ��͸�����Ϣ���������
// ���ߺ�³�ദ��³����ʾ��ҿ��Խ��������û�б���׼������ʾԭ�������Ϣ������ҽ�
// һ���ķ��ã��Ϳ������ɷ����ļ������޸���ҵĵ�������¼����Ѿ���������������һ��Կ�ס�
// Ȼ�������¼����Ϣ��
//
// �����Ҷ���Կ�ף����Ե�³�ദ������һ��Կ�ף���������Ҫ����Կ�ף�Ҳ������³��Ҫ��
//
// ��������Ҫ������ݣ�������³�����������ȷ�Ϻ�ɾ�����ݵ�����

// ���ɷ��ݵ�˵��
// ��ѡ��÷�������ʱ��³�ཫ��¼��Ҫ����ķ���ԭ�͵������ļ�����Щ�ļ�һ��Ҫ��/d/room/
// XXXX/�ڣ��������ѡ���˶��־ӣ������ļ�����/d/room/dulu/�ڡ������ɷ����ļ�ʱ��³��
// ������Щ�ļ�������/data/room/playerid/��ͬʱԭ�ͷ��ݱ�����һ�����ڣ�/d/room/xiaoyuan
// ³�ཫ����������滻����ҽ����ĵص㣬ԭ�ͷ���Ӧ����һ����xiaoyuan������СԺ��
// ����ԭ�ͷ�����һЩ����Ҫ�󣬱���ԭ�ͷ��̳е���ROOM���ͣ�������ķ����̳�PRIVATE_ROOM
// ���ͣ������ԭ�ͷ����ļ��У�inherit ROOM֮ǰҪ����/**/������,����inhert PRIVATE_ROOM
// ֮ǰ��Ҫ��//**����������Ϊ³����Զ��Ľ�����/**/����ȥ������ȥ��//**��������
// ���⣬�������ŵ�ԭ�ͷ�����������������䣬set ("key", "ROOM_KEY");����Ϊ�˸����õķ�
// �����Կ�ס�ͬʱԭ�ͷ������������set ("owner", "ROOM_OWNER")�����͵����á�

// ����Կ�׵�һ��˵��
// ÿ����ҷ���Կ��Ҫ����һ���ļ�����ʵ����ȫ������һ��ͨ�õ�Կ���ļ���ÿ��AUTOLOAD��ʱ
// ���Զ��ĸ��£�֮���Բ���ô������ΪΪ��ʹ��ҵķ��������ܹ�����һ�������ԣ������ڹ���
// ��ɢ��������һ�������ϴ����Կ�׵�ʱ�����ڹ��ڷ�����

// һЩ������˵��
// �������̸ʱ��¼������
// contract/luban : ��¼��̸���ݵ�mapping�����¼����ҵ���ʱ����
// contract/luban/room     : ��¼����������Ϣ��mapping������room_example��һ��Ԫ��
// contract/luban/descs    : ��¼����������mapping
// contract/luban/questing : �����̸״̬ quest_name/quest_id/quest_desc
// contract/luban/value    : ���跿������Ҫ�ļ۸�(��coinΪ��λ)
// contract/luban/position : ���췿�ݵĵص�

// ³���¼������������
// form : ��¼�������ı�
// form/player/player   : �����ߵ�����
// form/player/position : ���뽨���ĵص�
// form/player/room     : ���뽨������������
// form/player/type     : ���뽨�������ʹ���
// form/player/name     : ���ݵ�����
// form/player/id       : ���ݵĴ���
// form/player/status   : ����״̬ - ����/����/�ܾ�
// form/player/time     : �����ʱ��
// form/player/wizard   : ���������ʦ
// form/player/memo     : ��ʦ��д�ı�ע
// form/player/descs    : �����д������

// ����������ݵ��޸�
// private_room/build   : �Ѿ���������
// private_room/position: �������ڵ�λ�ã�����ڴ����ڳ������ļ�·��	:: �����Ѿ���build����
// private_room/entry   : ������ڴ����ļ�·��				:: �����Ѿ���build����
// private_room/name    : ��������						:: �����Ѿ���build����
// private_room/id      : ����ID						:: �����Ѿ���build����
// private_room/type    : ������������					:: �����Ѿ���build����

// ʵ�ַ���
// ��̸������һ���򵥵��Զ�������״̬�������û������ݽṹ�е�contract/luban�ֶΣ�������
// Ϣ�ĺ�����do_answer�� �����������״̬������յ���Ϣ���ַ�������Ҫ�ǵ��ò�ͬ���жϺ�
// �����������1���Ѽ�¼�������Ϣ���������0���ʾ���봦�������ֹ��̸������û�����̸
// ����������stop��������Զ�����״̬���û����ݿ��м�¼����̸��Ϣ��

// ���ݴ��
// �׶�1 - ��̸
// ���ݴ����player->contract/luban/���mapping��

// �׶�2 - ����
// ���ݴ����luban->form/player/���mapping��

// �׶�3 - �������
// ���ݴ����player->private_room/���mapping��
// ���ɵ��ļ������/data/room/player/���Ŀ¼��
// ��ҷ��ݵĴ����ļ������/data/room/player/���Ŀ¼��
// �������Ĵ����ļ������/data/room/d/...���Ŀ¼�У�/d/...����������ļ���·��
// ���ݴ����ļ�����ROOM_D�Ͽɵģ������Ҫ�޸ģ������޸�/adm/daemons/roomd

// ����ļ�
// inherit::PRIVATE_ROOM(/inherit/room/private_rom.c)
// �����û�����ķ��������е����ԣ���Ҫ����Կ�׿��źʹ����Ʒ
// inherit::RECODABLE_ROOM(/inherit/room/recordable_rom.c)
// ���ǽ������Ļ��������е����ԣ���Ҫ�ǿ��Լ�¼���ӵĳ��ڣ����޸�LONG����

#include <ansi.h>

inherit	NPC;
inherit	F_SAVE;

// �����¼�˸�����ʽ����
// ������һ��mapping���飬����ÿһ��mappingָ����һ���ͺŵķ��ݡ� ÿһ��mapping��������
// Ԫ�أ�һ�����֡��������͡����Ƿ����ַ������飺�ַ�������ָ�������ַ�����ӵ�е��ļ���
// files�еı�����һ��������ļ�(���е�/d/room/xiaoyuan�ĳ���)�����򽨷�ʱ����������

// ���⣺type �� name ��������Ϊ�������͵ı�־��ֻ����һ�������ģ���һ����Ӣ�ĵĶ��ѣ�
// �����ձ�����������ݿ��е������ĵ���������name�ֶΡ�

// ע�⣺����³����һ����Ҫ�������ݵ�NPC���ڸĶ�³����ļ�����ܻᷢ��һЩ���⣬��ʱ����
// �����Ĵ����ļ�ɾ����
mapping *room_example = ({
([	"name"		: "���־�",
	"type"		: "dule",
	"value"	: 20000000,
	"files"	: ([
	"xiaoyuan"	: "/d/room/dule/xiaoyuan.c",
	"xiaowu"	: "/d/room/dule/room1.c" ,
		]),
]),

([	"name"		: "�ʺ��",
	"type"		: "caihong",
	"value"	: 50000000,
	"files"	: ([
	"xiaoyuan"	: "/d/room/caihong/xiaoyuan.c",
	"room2"	: "/d/room/caihong/room1.c",
	"room3"	: "/d/room/caihong/room2.c",
	"room4"	: "/d/room/caihong/room3.c",
		]),
]),
});

#define	WIZLEVEL	6	// �ܹ����������ʦ�ȼ�

// ͨ������
int	save();
int	ask_me();
int	ask_paper();
int	ask_drawing();
int	ask_demolish();
int	ask_rebuild();
int	ask_modify();
int	ask_key();
int	ask_desc();
int	recognize_apprentice(object me);
int	accept_object(object me, object ob);
void	luban_say(string msg);
void	user_say();
int	do_answer(string arg);
int	do_stop();
int	do_desc(string arg);
int	do_show(string arg);
int	do_changename(string arg);
int	do_changeid(string arg);
int	do_changetype(string arg);
int	do_changedesc(string arg);
int	do_finish();
int	do_withdraw();
int	decide_withdraw();
int	do_destory();
void	show_desc(string player_id, string arg);
int	quest_user(object me);
int	quest_info(object me);
int	check_name(object me, string arg);
int	check_id(object me, string arg);
int	check_type(object me, string arg);
int	check_legal_name(string name, string position);
int	check_legal_id(string name);
mixed	check_legal_type(string type);
string	obey_description(string desc);
object	get_object(string file_name);
int	record_desc(object me, string room_name, string desc);
void	record_contract(object me);
int	modify_desc_in_form(string player_id, string room_name, string desc);
string	sort_desc(string desc);

// ��ʦʹ�õĹ���������صĺ���
void	show_brief(string player_id);
int	exist_form();
int	do_list(string arg);
int	do_type(string arg);
int	do_agree(string arg);
int	do_reject(string arg);
int	do_delete(string arg);
void	show_apply();
void	show_agree();
void	show_reject();
void	show_old();
void	show_brief_title();
void	show_brief_list(string info, string msg);

// ���ɷ��ݵĺ���
void	create_room(object me);
string	to_player(string player_id, string file_name);

mapping* forms;
mapping my_form;	// һ��������������û��ύ�Ľ�����Ϣ

// �����ṩ�ĺ�����֮�����ú궨�壬������Ϊ�˼�С����ʱ�Ŀ���
// ��ѯform
#define	query_form(pid, item)		query("form/" + pid + "/" + item)
// ����form�ڵ�ֵ
#define set_form(pid, item, content)	set("form/" + pid + "/" + item, content)
// �жϸ�����Ƿ����ύ����
#define submit_form(pid)		mapp(query("form/" + pid))

void create()
{
	restore();

	set_name("³��", ({ "lu ban", "lu", "luban" }));
	set("title", "�ڶ��ɽ�");
	set("nickname", HIC "���񹤽�" NOR);
	set("shen_type", 0);

	set("str", 10000);		// ��ֹ���յĶ�����������¶�ʧ
	set("int", 100);

	set("gender", "����");
	set("age", 1450);
	set("long",@LONG
����Ǻų����µڶ��ɽ��Ľ�����ʦ����࣬��������ʲô���ӷ��ݣ���������
���������⡣
LONG
);
	set("attitude", "friendly");
	set("inquiry", ([
		"�췿"	: (: ask_me :),
		"����"	: (: ask_me :),
		"����"	: (: ask_me :),
		"����"	: (: ask_me :),
		"room"	: (: ask_me :),
		"house"	: (: ask_me :),
		"ͼֽ"	: (: ask_paper :),
		"ֽ��"	: (: ask_paper :),
		"ֽ"	: (: ask_paper :),
		"paper"	: (: ask_paper :),
		"����"  : (: ask_demolish :),
		"��"  : (: ask_demolish :),
		"���"  : (: ask_demolish :),
		"�ؽ�"  : (: ask_rebuild :),
		"�ٽ�"  : (: ask_rebuild :),
		"Կ��"	: (: ask_key :),
		"����"	: (: ask_key :),
		"��Կ"	: (: ask_key :),
		"key"	: (: ask_key :),
		"����"	: (: ask_desc :),
		"��д"	: (: ask_desc :),
		"desc"	: (: ask_desc :),
		"����"	: (: ask_desc :),
		"�޸�"  : (: ask_modify :),
		"�޸���Ϣ": (: ask_modify :),
		"�滭"    : (: ask_drawing :),
		"��"      : (: ask_drawing :),
		"�滭����": (: ask_drawing :),
		"drawing" : (: ask_drawing :),
	]));
	
	set_skill("literate", 500);		// ����д��
	set_skill("drawing",  500);		// �滭����

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

// ���̺���
int save()
{
	object *inv;
	int i;

	// ÿ�δ���ǰ�ͷ�������Ʒ
	inv = all_inventory(this_object());
	for(i=0; i<sizeof(inv); i++) destruct(inv[i]);

	::save();
}

void init()
{
	object me;
	
	::init();

	if (interactive(me = this_player()))
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me);
	}

	me->delete_temp("decide_withdraw");
	me->delete_temp("demolish_room");

	add_action("do_stop", "stop");
	add_action("do_answer", "answer");
	add_action("do_desc", "desc");
	add_action("do_show", "show");
	add_action("do_changename", "changename");
	add_action("do_changeid",   "changeid");
	add_action("do_changetype", "changetype");
	add_action("do_changedesc", "changedesc");
	add_action("do_finish", "finish");
	add_action("do_finish", "ok");
	add_action("do_withdraw", "withdraw");
	add_action("do_withdraw", "chexiao");
	add_action("decide_withdraw", "decide");
	add_action("do_demolish", "demolish");

	// ������������ʸ��������ʦ�����Ӵ����������
	if (wizardp(me) && wiz_level(me) > WIZLEVEL)
	{
		add_action("do_list", "list");
		add_action("do_type", "type");
		add_action("do_agree", "agree");
		add_action("do_reject", "reject");
		add_action("do_delete", "delete");
	}
}

// �����ĵ�
string query_save_file()
{
	return "/data/npc/luban";
}

void greeting(object me)
{
	if (!objectp(me) || environment(me) != environment())
	{
		return;
	}

	// ����ʦ��ʾ����Ϣ
	if (wizardp(me) && wiz_level(me) > WIZLEVEL)
	{
		if (query("form") && sizeof(query("form")) >= 1)
		{
			message_vision("³���$N�����������ã���������Щ������Ҫ�����ء�\n", me);
			tell_object(me, HIG "³������㣺����" HIW "list" HIG "�쿴��" +
				        HIW "type" HIG "��ʾ��ϸ��Ϣ��" HIW "agree" HIG +
					"ע�ᣬ" HIW "reject" HIG "�ܾ���" HIW "delete" HIG "ɾ������\n" NOR);
		} else
		{
			message_vision("³���$N���ͷ����������������ڿΣ�����Զӭ��ʧ���ˣ�\n", me);
		}
		return ;
	} else
	if (query("form/" + me->query("id")))
	{
		// ������ύ�˱������ݱ���״̬������ʾ��Ϣ
		switch (query("form/" + me->query("id") + "/status")) {
		case "����" :
			luban_say("��ʦ��û�в���������룬Ҫ��鿴���ύ�ı�������show��������޸Ŀ������ҡ�\n");
			break;

		case "�ܾ�" :
			luban_say("������뱻�ܾ��ˣ��������show�鿴���飬������޸Ŀ������ҡ�\n");
			break;

		case "ͬ��" :
			luban_say("��������Ѿ�����׼�ˣ������ֽ𼴿ɽ������鿴��������show��������޸Ŀ������ҡ�\n");
			break;
		}
	} else
	// �������ʾ����Ϣ
	if (me->query_temp("contract/luban"))
	{
		message_vision("³���$NЦ������λ" + RANK_D->query_respect(me) +
			"���ղ���ô̸��̸�ž����ˣ��������⣬���Ǽ���̸�\n", me);
	} else
	switch(random(3)) {
	case 0 :
		message_vision("³���$N˵������λ" + RANK_D->query_respect(me) +
			"�������뽨�����ӣ�\n", me);
		break;
	case 1 :
		message_vision("³���$NЦ������λ" + RANK_D->query_respect(me) +
			"�����߽���������û�и����֮����ô�а���\n", me);
		break;
	case 2 :
		message_vision("³���$Nһ���֣�˵������λ" + RANK_D->query_respect(me) +
			"���ܾ�û��������������\n", me);
		break;
	}
}

// ��֤ѧϰ
int recognize_apprentice(object me)
{
	if (me->query_temp("mark/³��"))
	{
		message_vision("³���$N˵���ã����Ȼ����ѧ���Ҿͽ���һ��ɡ�\n", me);
	}
	me->set_temp("mark/³��", 1);
	return 1;
}

// ������Ʒ��ͼֽ
int accept_object(object me, object ob)
{
	object build;		// �����ĵص�

	if (ob->query("id") == "key" && ob->query("item_make"))
	{
		// ������յ���Կ�ף�������
		message_vision("³����ͷ��������" + ob->query("name") + "��\n", me);
		return 1;
	}

	if (ob->query("ͼֽ"))
	{
		if (mapp(me->query("private_room")))
		{
			message_vision("³��Ǻ�Ц����Ī������һ��ס�����ǲ�����\n", me);
			return 0;
		}
		// ����Ϊ�˷�ֹ���ֲ���ȷ��build_room�ı��
		me->delete("private_room");

		if (query("form/" + me->query("id")))
		{
			message_vision("³��Ц�����������㲻���Ѿ��ύ������ô��������show�쿴���롣\n", me);
			return 0;
		}
		if (me->query_temp("contract/luban"))
		{
			message_vision("³���ɻ�Ķ�$N˵������ʲô���ղŲ��Ǹ�������ô��������ʲô�뷨�����Ը�����̸(stop)��\n", me);
			return 0;
		}

		if (! ob->query("draw"))
		{
			message_vision("³�࿴��һ�£���$N˵���������һ�Ű�ֽ��ʲô����Ҫ�ǲ���ͺ���ѧѧ�滭����(drawing)�ɡ�\n", me);
			return 0;
		}
		if ( ob->query("draw") < 30)
		{
			message_vision("³��ӹ�ͼֽ�����˰��죬��$N�������⻭����ʲô��������Ҫ�ǲ������ѧѧ�滭����(drawing)��\n", me);
			return 0;
		}
		if ( ob->query("draw") < 80)
		{
			message_vision("³��ӹ�ͼֽ���˿�����$NЦ�������Ļ��У��������ɡ�\n", me);			
		} else
		{
			message_vision("³�࿴�˿�$N����ͼֽͼֽ���Ȳʵ������ˣ��������츳����\n", me);
		}

		build = get_object(ob->query("position"));
		if (! objectp(build))
		{
			message_vision("³����ϸ���˿���̾�˿���˵�����Ǹ��ط����ں����Ѿ���������...\n", me);
			return 0;
		}

		if (! build->query("recordable_room"))
		{
			message_vision("³����ϸ���˿�������������ü����$N˵�����Ǹ��ط������ܽ�����...\n", me);
			return 0;
		}

		me->set_temp("contract/luban/position", ob->query("position"));
		quest_user(me);
		return 1;
	}

	// �����Ƿ���д�˱�
	if (ob->query("money_id") && mapp(query("form/" + me->query("id"))))
	{
		if (query("form/" + me->query("id") + "/status") != "ͬ��")
		{
			message_vision("³��ҡҡͷ����$N������ʦ��û����׼������룬������ذɡ�\n", me);
			return 0;
		}
		if (ob->value() < query("form/" +me->query("id") + "/value"))
		{
			message_vision("³��ӹ�Ǯ���˵࣬��$N�Ǻ�Ц������Ǯ�ƺ������ɣ�\n", me);
			return 0;
		}
		create_room(me);
		return 1;
	}

	// �����Ƿ񹻶���
	if (ob->query("money_id"))
	{		
		if (me->query_temp("contract/luban/questing") != "quest_desc")
		{
			message_vision("³��΢΢һЦ����$N������ʲô��ô�������Ҳ����޹�֮»��\n", me);
			return 0;
		}
		if (ob->value() < 50000)
		{
			message_vision("³���Ȼ��Ц����$N���������ƽ��㶼��ϧ���ߺߣ��������������٣���Ҳ�����ۿۡ�\n", me);
			return 0;
		}
		message_vision("³������Ķ�$N˵�����ܺã��Ҿ͸����¼�ڰ�������������Ϣ��һ��֪ͨ�㡣\n", me);
		record_contract(me);
		me->delete_temp("contract");
		return 1;
	}
	message_vision("³��ڰ��֣���$N�����㻹���Լ����Űɣ��ҿ��ò��š�\n", me);
	return 0;
}

// �ش��йؽ�������Ϣ
int ask_me()
{
	object me;
	me = this_player();

	if (mapp(me->query("private_room")))
	{
		message_vision("³����ͷ����$N˵������ô����ס�ÿ����⣿���ǲ����⣬���������ؽ�Ŷ��\n", me);
		return 1;
	}
	message_vision("³��΢һ̾����˵�����뽭����Ů��һ���ݺᣬ������𣬳۳����£�����û�и����֮����\n" +
		       "�������ˣ������������У���ݼ����մ����������⣬�β�����ͼֽ���ң����ǵص���ʣ���\n" +
		       "�������������ʽ���Ҹ��㽨��ס�����������������پ��Ƿ��ꡣ\n", me);
	return 1;
}

// �ش��й�ͼֽ����Ϣ
int ask_paper()
{
	object	me;
	object	ob;

	me = this_player();

	if (is_busy())
	{
		write("³����æ���أ�û��������...\n");
		return 1;
	}

	message_vision("³����ͷ����$N˵�����ܺã��������ͼֽ��������Ҫ�����ĵص㣬�������ûظ��ҿ�����\n", me);
	ob = new("/d/room/obj/paper");
	if (objectp(ob))
	{
		message_vision("³�෭�˷����ҵ�һ��ͼֽ���ݸ���$N��\n", me);
		ob->move(me);
	} else
	{
		message_vision("³�෭�˰���Ҳû�ҵ�������һ����˵������ô���£�û���ˣ���ȥ����ʦ���ʰɣ�\n", me);
	}

	start_busy(4);
	return 1;
}

// �ش��йػ滭���ɵ���Ϣ
int ask_drawing()
{
	int	skl;
	object	me;

	me =this_player();
	skl = me->query_skill("drawing", 1);

	message_vision("³���$N˵����Ҫ�뻭�źõ��ͼֽ�������滭�����ǲ��еģ�û���������ͻ�" +
		       "����������ѧϰ���������⣬��������ѧѧ��", me);
	if (skl < 30)
	{
		message_vision("�����ڵĻ滭���ɿ�̫���ˡ�\n", me);
	} else
	if (skl < 80)
	{
		message_vision("�����ڵĻ滭����Ҳ�����������ˡ�\n", me);
	} else
	{
		message_vision("��Ȼ�ˣ������ڵ�ˮƽ���൱�����ˡ�\n", me);
	}
	return 1;
}

// �������ݵ���Ϣ
int ask_demolish()
{
	object me;

	me = this_player();
	if (me->query_temp("contract/luban"))
	{
		message_vision("³���$N˵���㲻��Ҫ����ô����ô��û���þ�Ҫ���ˣ�����δ����Ѱ���\n", me);
		return 1;
	}
	if (query("form/" + me->query("id")))
	{
		message_vision("³�����һ������$N������ķ��ӻ�û�������أ���Ҫ�ǲ��뽨�ˣ��ͳ���(withdraw)�������ˡ�\n", me);
		return 1;
	}
	if (! mapp(me->query("private_room")))
	{
		message_vision("³�������Ц����$N�������ݣ��㻹û���أ���ʲô���Ҳ���˵����ӿ��Ƿ����ģ�\n", me);
		return 1;
	}	
	if (me->query_temp("demolish_room"))
	{
		message_vision("³���$N˵����Ҫ���������ݣ������¾���(demolish)��\n", me);
		return 1;
	}
	message_vision("³���������۾�����ֵĿ���$N���������ò�˵���������浽Ҫ���ݣ����¾��İ�(demolish)��\n", me);
	me->set_temp("demolish_room", 1);
	return 1;
}

// �����ؽ�����Ϣ
int ask_rebuild()
{
	object me;

	me = this_player();
	if (! mapp(me->query("private_room")))
	{
		message_vision("³��ҡҡͷ����$N˵���㻹û�з����أ�̸ʲô�ؽ���\n", me);
		return 1;
	}	
	message_vision("³��̾�˿�������$N˵��������Ҫ�ؽ������Ȳ𷿣�\n", me);
	return 1;
}

// ��������Կ��
int ask_key()
{
	object me;

	me = this_player();

	if (is_busy())
	{
		write("³����æ���أ�û������...\n");
		return 1;
	}

	if (! mapp(me->query("private_room")))
	{
		message_vision("³�࿴�˰��죬�Ŷ�$N˵��û�з�����ҪԿ�׸�ʲô��\n", me);
		return 1;
	}

	clone_object("/data/room/" + me->query("id") + "/key")->move(me);
	message_vision("³���ó�һ��Կ�ף���$N˵��ŵ������Կ�ף��պ��ˣ�\n", me);
	start_busy(4);
	return 1;
}

// ��������������Ϣ
int ask_desc()
{
	luban_say(@INFORMATION
������Ϣ����ʹ����ɫ�����ҿ��Է��У�������಻�ܳ���160�����֣�

��ɫ�Ĺ���
$BLK$ - ��ɫ		$NOR$ - �ָ�������ɫ
$RED$ - ��ɫ		$HIR$ - ����ɫ
$GRN$ - ��ɫ		$HIG$ - ����ɫ
$YEL$ - ����ɫ		$HIY$ - ��ɫ
$BLU$ - ����ɫ		$HIB$ - ��ɫ
$MAG$ - ǳ��ɫ		$HIM$ - �ۺ�ɫ
$CYN$ - ����ɫ		$HIC$ - ����ɫ
$WHT$ - ǳ��ɫ		$HIW$ - ��ɫ

���У�
ֻҪ��������Ϣ�����һ��\n�Ϳ��ԡ����磺������һ��СԺ��\nԺ�ӱ��ϵ�ǽ�ܰ�����
ʵ�ʿ���������ʹ������ӵģ�
����һ��СԺ��
Ժ�ӱ��ϵ�ǽ�ܰ���

˵����
ϵͳ�Զ����������ַ�����β�˼�һ�� $NOR$ �� \n�����������ò�Ҫ��\n����������
����̫�ࡣ���⣬ϵͳ���Զ��Ĺ淶�������������Ϣ������㲻��Ҫ��������Ϣǰ����
�Ӷ�����ʼ�Ŀո�ͬʱҲ����Ҫ��һ�������ڲ�����\n��ʵ�ֻ��У����ڹ����Ķ���ϵ
ͳ���Զ�����ӻ��з���


INFORMATION );
	return 1;
}

// �����޸ĵ���Ϣ
int ask_modify()
{
	object me;

	me = this_player();
	if (! submit_form(me->query("id")) && me->query_temp("contract/luban/questing") != "quest_desc")
	{
		message_vision("³��ҡҡͷ����$N˵����ֻ������ʱ�����ύ�������Ժ���õ����޸ġ�\n", me);
		return 1;
	}

	message_vision("³����ͷ����$N˵��������޸����ύ�������еĸ�����Ϣ��\n" +
		"\n�����ͨ������ָ���޸ķ��ݵĸ�����Ϣ��\n" +
		HIW "changename " NOR "name : �޸ķ��ݵ��������֡�\n" +
		HIW "changeid   " NOR "id   : �޸ķ��ݵ�Ӣ�Ĵ��š�\n" +
		HIW "changetype " NOR "type : �޸ķ��ݵ����͡�\n" +
		HIW "changedesc " NOR "room desc : �޸�ĳ�䷿�ݵ�������\n", me);
	return 1;
}

// ���³��˵��ʱ�ı���
void luban_say(string msg)
{
	object me;
	me = this_player();
	message("vision", "³���" + me->query("name") + "���ֹ���˵��Щ����\n", environment(me), ({ me }));
	write("³��˵����" + msg);
}

// ����û�˵��ʱ�ı���
void user_say()
{
	object me;
	message("vision", me->query("name") + "��³�����ֹ���˵��Щ����\n", environment(me), ({ me }));
}

// �û���ֹ��̸
int do_stop()
{
	object me;
	me = this_player();
	if (! me->query_temp("contract/luban"))
	{
		message_vision("³��һ��ɵ��......\n", me);
		return 1;
	}
	me->delete_temp("contract/luban");
	message_vision("³���$N���ͷ��˵������Ȼ��ˣ�������̸Ҳ������\n", me);
	return 1;
}

// �û��ش�����
// ���ݵ�ǰ״̬������Ӧ�ķ�Ӧ
int do_answer(string arg)
{
	object me;
	string questing;

	me = this_player();
	questing = me->query_temp("contract/luban/questing");

	// �ж������Ƿ�������̸
	if (! questing)
		return 0;

	switch (questing) {
	// ��̸��������
	case "quest_name" :
	check_name(me, arg);
	break;

	case "quest_id" :
	check_id(me, arg);
	break;

        case "quest_type" :
	check_type(me, arg);
	break;

	default:
	write("û���������⣬����ش�ʲô��\n");
	}
	return 1;
}

// ��¼�û������������Ϣ
int do_desc(string arg)
{
	object me;
	string room_name;
	string desc;

	me = this_player();

	if (me->query_temp("contract/luban/questing") != "quest_desc")
		return 0;

	if (arg)
	{
		if (sscanf(arg, "%s %s", room_name, desc) != 2)
		{
			room_name = arg;
			desc = 0;
		}
	}
	else
	{
		show_desc(me->query("id"), 0);
		return 1;
	}

	record_desc(me, room_name, desc);
	return 1;
}

// ��ʾ�û��Լ������������Ϣ
int do_show(string arg)
{
	show_desc(this_player()->query("id"), arg);
	return 1;
}

// �ı䷿������
// ������״̬������̸�л���������
int do_changename(string arg)
{
	object me;
	string player_id;
	string position;

	me = this_player();
	player_id = me->query("id");

	if (submit_form(player_id))
	{
		// ��������
		position = query_form(player_id, "position");
		if (! check_legal_name(arg, position)) return 1;

		luban_say("�ðɣ��͸ĳ�" + arg + "������ְɣ�\n");
		set_form(player_id, "name", arg);
		set_form(player_id, "status", "����");
		save();
		return 1;
	} else
	if (me->query_temp("contract/luban/questing") != "quest_desc")
		return 0;

	// ������̸
	if (check_legal_name(arg, me->query_temp("contract/luban/position")))
	{
		me->set_temp("contract/luban/name", arg);
		luban_say("�ðɣ��͸ĳ�" + arg + "������ְɣ�\n");
	}
	return 1;
}

// �ı䷿�ݴ���
// ������״̬������̸�л���������
int do_changeid(string arg)
{
	object me;
	string player_id;
//	string position;

	me = this_player();
	player_id = me->query("id");

	if (submit_form(player_id))
	{
		// ��������
		if (! check_legal_id(arg)) return 1;
		luban_say("�а����͸ĳ�" + arg + "������ݴ��Űɣ�\n");
		set_form(player_id, "id", arg);
		set_form(player_id, "status", "����");
		save();
		return 1;
	} else
	if (me->query_temp("contract/luban/questing") != "quest_desc")
		return 0;

	// ������̸
	if (check_legal_id(arg))
	{
		me->set_temp("contract/luban/id", arg);
		luban_say("�а����͸ĳ�" + arg + "������ݴ��Űɣ�\n");
	}
	return 1;
}

// �ı䷿������
// ������״̬������̸�л���������
int do_changetype(string arg)
{
	object me;
	int value;
	string player_id;
//	string position;
	mapping example;

	me = this_player();
	player_id = me->query("id");

	if (submit_form(player_id))
	{
		// ��������
		if (! (example = check_legal_type(arg)))
		{
			write("�Ҳ����������͵ķ��ݣ�����û�иı䷿�ݵ����͡�\n");
			return 1;
		}
		set_form(player_id, "room", example["name"]);
		value = example["value"];
		if (wizardp(me)) value = 0;
		set_form(player_id, "value", value);
		set_form(player_id, "descs", ([ ]));
		set_form(player_id, "status", "����");
		save();
		luban_say("��һ�ַ���Ҳ�У�����������д�µ�����(changedesc)��\n");
		return 1;
	} else
	if (me->query_temp("contract/luban/questing") != "quest_desc")
		return 0;

	// ������̸
	if (! check_type(me, arg))
	{
		write("û�иı䷿�����͡�\n");
	}
	return 1;
}

// �ı䷿������
// ������״̬������̸�л���������
int do_changedesc(string arg)
{
	object me;
	string player_id;
//	mapping example;
	string room_name;
	string room_desc;

	me = this_player();
	player_id = me->query("id");

	if (submit_form(player_id))
	{
		// ��������
		if (! arg || arg == "")
			return notify_fail("�밴����ȷ��ʽ���룺changedesc room_name description\n");

		if (sscanf(arg, "%s %s", room_name, room_desc) != 2)
		{
			room_name = arg;
			room_desc = 0;
		}

		// �޸�������Ϣ
		modify_desc_in_form(player_id, room_name, room_desc);
		set_form(player_id, "status", "����");
		save();
		return 1;
	} else
	if (me->query_temp("contract/luban/questing") != "quest_desc")
		return 0;

	// ������̸
	do_desc(arg);
	return 1;
}

// ��������
int do_finish()
{
	object me;
	int value;
	string msg;

	me = this_player();
	if (me->query_temp("contract/luban/questing") != "quest_desc")
		return 0;

	show_desc(me->query("id"), 0);

	msg = "���ٲ����������̣�����˹��Ķ�$N˵����Ҫ�������ķ��ӣ���˵Ҳ��" + chinese_number(value/10000) + "���ƽ𣬲����ۣ�\n";
	if (wizardp(me))
	{
		msg += "³��Խ��ٺȵ����������������Ͻ�����...�ٺ٣���ʱ��˼��˼�����˰ɡ�\n";
	}
	msg += "³����һ������Ȼ��˵�����㿴����û��ʲô����ô������û�У����Ƚ������ƽ�Ķ���\n";
	message_vision(msg, me);

	return 1;
}

// ������
int do_withdraw()
{
	object me;

	me = this_player();
	if ( me->query_temp("contract/luban"))
	{
		do_stop();
		return 1;
	}
	if (! query("form/" + me->query("id")))
	{
		message_vision("³��һ��ãȻ......��$N˵�������������û���ύ������ɣ�\n", me);
		return 1;
	}

	if (me->query_temp("decide_withdraw"))
	{
		message_vision("³���$N˵����������Ҫ�������룬�����¾���(decide)��\n", me);
		return 1;
	}

	switch (query("form/" + me->query("id") + "/status")) {
	case "����":
	luban_say("��ϧ������ô��ͷ����ˣ�\n");
	break;

	case "ͬ��":
	luban_say("��ѽ�����ǿ�ϧ����ʦ��ͬ���ˣ�����ô�����ù��ˣ�\n");
	break;

	case "�ܾ�":
	luban_say("����û�ܱ���׼Ҳ��ʹ����ù�ô��������ô������˵ô��\n");
	break;
	}
	message_vision("³��̾�˿�������$N˵������Ȼ��ˣ�����Ҳ������ǿ�����������ˣ����¾���(decide)�ɣ�\n", me);
	me->set_temp("decide_withdraw", 1);
	return 1;
}

// ɾ����
int decide_withdraw()
{
	object me;

	me = this_player();
	if (! me->query_temp("decide_withdraw")) return 0;
	
	me->delete_temp("decide_withdraw");
	delete("form/" + me->query("id"));
	save();
	message_vision("³��ҡҡͷ���ͳ�һ���˱������˷�����֪��������ʲô������\n", me);
	return 1;
}

// ��ٷ���
// ������ѯ��³���йز𷿵���Ϣ
int do_demolish()
{
	mapping example;
	string *names;

	object me;
	object ob;

	int i;

	me = this_player();

	if (! me->query_temp("demolish_room"))
		return 0;

	me->delete_temp("demolish_room");
	if (! me->query("private_room")) return 0;
	if (! mapp(me->query("private_room")))
	{
		write("����������Ѿ���ɾ����\n");
		me->delete("private_room");
		return 1;
	}

	// ɾ���û������������ļ�
	// ����Կ���ļ�����ΪԿ���п�������ĳЩ�������
	example = check_legal_type(me->query("private_room/type"));
	if (mapp(example))
	{
		seteuid(getuid());
		names = keys(example["files"]);
		// ɾ���ļ�
		for (i = 0; i < sizeof(names); i++)
			rm(to_player(me->query("id"), example["files"][names[i]]));
	}

	ob = get_object(me->query("private_room/position"));
	if (! objectp(ob))
	{
		write("�����ĵص��Ѿ��Ҳ����ˣ�ɾ�����йط��ݵ���Ϣ��\n");
		me->delete("private_room");
		return 1;
	}

	ob->demolish_room(me->query("private_room/name"));
	ob->save();
	me->delete("private_room");
	message_vision("³����ͷ����$N˵�����ˣ�ʣ�µ������һ���׵ģ���Կ�׸��ң�Ȼ����Ϳ������ˡ�\n", me);
	return 1;
}

// ��ʾ�û������������Ϣ
// ����û�������̸������ʾ�û��������������Ϣ������û��ڵȴ�����������ʾ�û�
// ��ǰ�����������Ϣ
// ���һ��player�Է��ݵ�����
// room_name���û�ָ���ķ����е�ĳһ���short����
void show_desc(string player_id, string room_name)
{
	mapping filesp;		// ԭ�ͷ����������ļ�mapping
	mapping descsp;		// ��ҵ�����mapping

	int i;
	int value;		// �������
	int count;		// ��ʾ��������Ϣ����Ŀ
	object me;		// ���øú����Ķ���
	object player;	// ����ʾ��player��object
	object ob;		// �������ķ��ݵ�object���ǽ���������object

	string desc;		// ����������mapping
	string *names;		// ����mapping�Ĺؼ��ֵ��ַ�����
	string room_nameid;	// �������ּ�ID
	string room_type;		// ��������
	string position;		// ������λ��

	string ids;			// ��ѯʱʹ��

	string info;		// ����������ʾ��Ϣ
	string msg;			// ��ʱ������������ʾ��Ϣ

	me = this_player();
	info = "";

	if (mapp(query("form/" + player_id)))
	{
		// �ڱ����и�����ύ�ı�
		ids = "form/" + player_id + "/";
		room_type = query(ids + "type");
		for (i = 0; i < sizeof(room_example); i++)
		{
			if (room_example[i]["type"] == room_type)
			{
				filesp = room_example[i]["files"];
				break;
			}
		}
		if (! mapp(filesp))
		{
			write("������ķ�������(" + room_type + ")�Ѿ��������ˣ������ʦ��ϵ��\n");
			return;
		}
		descsp = query(ids + "descs");
		room_type = query(ids + "room") + "(" + room_type + ")";
		room_nameid = query(ids + "name") + "(" + query(ids + "id") + ")";
		value = query(ids + "value");
		position = query(ids + "position");
		// ��ʾ��Ϣ�и����÷��ݵ�������
		msg = query(ids + "wizard");
		switch (query(ids + "status")) {
		case "����" :
			info = "��ʦ��û�в���������롣";
			break;

		case "�ܾ�" :
			info = msg + "�Ѿ��ܾ���������룡";
			if (query(ids + "memo") != "��")
				info += "\nԭ���ǣ�" + query(ids + "memo");
			break;

		case "ͬ��" :
			info = msg + "�Ѿ�ͬ����������룡";
			break;
		}

		if (this_player()->query("id") == player_id)
		{
			if (query(ids + "status") == "ͬ��")
			{
				info += HIW "\n�����ڿ��Խ��췿���ˡ������ʱ�޸��˷��ݵ���Ϣ����Ҫ�õ���ʦ���ٴ���׼��" NOR;
			} else
			if (query(ids + "status") == "�ܾ�")
			{
				info += HIR "\n����������޸ķ��ݵ���Ϣ�Ի����ʦ����׼�������볷�����롣" NOR;
			}
			info += "\n����Գ���(withdraw)���ύ�����롣";
		}
	} else
	if (objectp(player = present(player_id, environment(this_object()))) &&
	    player->query_temp("contract/luban/questing") == "quest_desc")
	{
		filesp = player->query_temp("contract/luban/room/files");
		descsp = player->query_temp("contract/luban/descs");
		room_type = player->query_temp("contract/luban/room/name");
		room_type += "(" + player->query_temp("contract/luban/room/type") + ")";
		room_nameid = player->query_temp("contract/luban/name") + "(" +
			      player->query_temp("contract/luban/id") + ")";
		value = player->query_temp("contract/luban/value");
		position = player->query_temp("contract/luban/position");
	} else
	{
		// û����̸
		luban_say("�Ǻǣ���λ����û�д��㽨���Ӱɡ�\n");
		return;
	}

	ob = get_object(position);
	if (! objectp(ob))
	{
		write("������Ľ��췿�ݵĵط�(" + position + ")�Ѿ��������ˣ������ʦ��ϵ!\n");
		return;
	}
	
	msg = "�ã��㿴���ɣ�\n" + "����ѡ�õ���" + room_type + "�������͵ķ��ݡ�\n" +
		  "����������" + room_nameid + "����������" + ob->query("short");
	if (wizardp(me) && wiz_level(me) > WIZLEVEL)
		msg += "(" + position + ")";
	msg += "��\n";
	luban_say(msg);

	names = keys(filesp);
	count = 0;
	for (i = 0; i < sizeof(filesp); i++)
	{
		// ���Ҹ÷��ݵ�object
		ob = get_object(filesp[names[i]]);
		if (! objectp(ob))
		{
			write("�Ҳ���ʾ���ķ���" + names[i] + "�������ʦ��ϵ��\n");
			continue;
		}
		if (! room_name || room_name == "" ||
		    ob->query("short") == room_name || names[i] == room_name)
		{
			// �����û������������Ϣ
			desc = sort_desc(descsp[names[i]]);
			write(YEL "-------------------------------------------------------------------------------\n" NOR);
			write(HIW + "����" + ob->query("short") + "(" + names[i] + ")" + HIW + "��������\n" + NOR);
			if (! desc)
			{
				// �û�û������������Ϣ����ʾȱʡ��Ϣ
				desc = "���ڻ�û������������Ϣ��ʹ��ϵͳȱʡ��������Ϣ�����£�\n";
				desc += sort_desc(ob->query("default_long"));
			}
			write(desc);
			count++;
		}
	}

	if (! count)
	{
		write("��������û��" + room_name + "������䣬����show�鿴���еķ��䣡\n");
		return ;
	}

	write(YEL "-------------------------------------------------------------------------------\n" NOR);
	write("�������������г�����Щ���ݡ�\n");

	if (! value)
		info += "\n������Щ���䲻��Ҫ�����κ�������";
	else
		info += "\n������Щ������Ҫ����" HIY + chinese_number(value/10000) + "���ƽ�" NOR;

	write(info + "\n");

	return ;
}

// ѯ����ұ�Ҫ�Ľ�����Ϣ��Ȼ���¼��������ʦ����
int quest_user(object me)
{
	message_vision("³���$N˵�����ã�����������ϸ̸̸��\n", me);
	// ѯ�ʷ�������
	luban_say("�ȸ��������뽨�ķ��ӽ�ʲô����(answer name)��\n�����ǲ���̸��(stop)��������Ҳ�޷���\n");
	me->set_temp("contract/luban/questing","quest_name");
	return 1;
}

// ѯ��������Ϣ
int quest_info(object me)
{
	message_vision("³���$N˵�����ã�������ϲ��" + me->query_temp("contract/luban/room/name") +
                        "������ʽ�ġ�\n", me);
	// ��ʾ������ʽ��Ϣ
	
	luban_say(@INFORMATION
�����Ϊ��ķ��������ϲ������������ʽ�ǣ�desc �������� ��������
Ȼ��Ҳ����ʹ��ԭ�е�������������뿴��������������������show���쿴����һ
�ж���������Ժ����finish����ok�Ϳ����ˡ�������޸�����ķ������֣����ţ�
���͵���Ϣ��������ѯ��<�޸�>�ķ�����

�ٸ����������ӣ���desc СԺ ������һ����µ�СԺ���������͸�СԺ�����һ��
�����������ȡ��СԺ���������Լ��룺��desc СԺ���Ϳ����ˡ�

����������ʹ����ɫ�����Զ��У�����ϸ�ڿ������� <����>������Ҫ��Ҫע����ǣ�
ϵͳ�Զ����������ַ�����β�˼�һ�� $NOR$ �� \n�����������Ҫ��\n����������
����̫�ࡣ���⣬ϵͳ���Զ��Ĺ淶�������������Ϣ������㲻��Ҫ��������Ϣǰ
����Ӷ�����ʼ�Ŀո�ͬʱҲ����Ҫ��һ�������ڲ�����\n��ʵ�ֻ��У����ڹ���
�Ķ���ϵͳ���Զ�����ӻ��з���

���⣬���������ַ����ڲ���Ҫ����ո�������Щ���붼�ᱻĨ����
INFORMATION );

	me->set_temp("contract/luban/questing","quest_desc");

	// ���������Ϣ
	me->delete_temp("contract/luban/descs");
	me->set_temp("contract/luban/descs", ([ ]));
	return 1;
}

// �ж��û�����ķ�������
int check_name(object me, string arg)
{
	if (! arg || arg == "")
	{
		luban_say("����ô��˵����Ҫ�ǲ���̸��(stop)����˵���ǣ�\n");
		return 0;
	}
	if (arg == "stop")
	{
		do_stop();
		return 0;
	}
	if (! check_legal_name(arg, me->query_temp("contract/luban/position"))) return 0;

	// ��¼��̸�õķ�������
	me->set_temp("contract/luban/name", arg);

	luban_say("��ȷ����ķ��ݵĴ���(3��10��Ӣ����ĸ)�����Ǻ��˾ͻش���(answer id)��\n");
	me->set_temp("contract/luban/questing", "quest_id");
	return 1;
}

// �ж��û�����ķ��ݴ���
int check_id(object me, string arg)
{
	if (! arg || arg == "")
	{
		luban_say("����ô��˵����Ҫ�ǲ���̸��(stop)����˵���ǣ�\n");
		return 0;
	}
	if (arg == "stop")
	{
		do_stop();
		return 0;
	}
	if (! check_legal_id(arg)) return 0;

	// ��¼��̸�õķ��ݴ���
	me->set_temp("contract/luban/id", arg);

	luban_say("����Ҫ������ʽ��ס��(answer type)? ���ǲ�̫���������Ե�������СԺһ�ۡ�\n");
	me->set_temp("contract/luban/questing","quest_type");	
	return 1;
}

// �ж��û�����ķ�������
int check_type(object me, string arg)
{
	mapping *example;
	int value;

	if (! arg || arg == "")
	{
		luban_say("����Ҫ������ʽ��ס��(answer type)�����ǲ�̫���������Ե�������СԺһ�ۡ�\n");
		return 0;
	}
	if (arg == "stop")
	{
		do_stop();
		return 0;
	}
	if (! (example = check_legal_type(arg)))
	{
		luban_say("��Ҫ����ʽ��ϡ�棬�������ڻ�û�С���������ٸ����ҡ�\n");
		return 0;
	}
	// ��¼�û�ѡ���ķ�������
	me->set_temp("contract/luban/room", example);

	// ���㷿�ݵļ�ֵ - ������ * 2000 gold
	value = me->query_temp("contract/luban/room/value");
	if (wizardp(me)) value = 0;
	me->set_temp("contract/luban/value", value);

	quest_info(me);
	return 1;
}

// �ж��û�����ķ������Ƿ�Ϸ�
// ͬʱ�жϸô��Ƿ��Ѿ���ס��
// Copy & modify from /adm/daemons/logind.c
int check_legal_name(string name, string position)
{
	object ob;
	int i;

	i = strlen(name);
	
	if( (strlen(name) < 4) || (strlen(name) > 16 ) ) {
		write("�Բ����㷿�ݵ����ֱ����� 2 �� 8 �������֡�\n");
		return 0;
	}
	while(i--)
	{
		if( name[i] <= ' ' )
		{
			write("�Բ�����ķ������ֲ����ÿ�����Ԫ��\n");
			return 0;
		}
		if( i % 2==0 && ! is_chinese(name[i..<0]) )
		{
			write("�Բ��������á����ġ�ȡ���֡�\n");
			return 0;
		}
	}

	ob = get_object(position);
	if (! objectp(ob)) return 1;

	if (ob->exist_room(name))
	{
		luban_say("�Բ��𣬾�����֪�������Ѿ���һ��ס������������ˣ���������һ�����֡�\n");
		return 0;
	}

	return 1;
}

// �ж��û�����ķ��ݴ����Ƿ�Ϸ�
int check_legal_id(string roomid)
{
	int i;

	i = strlen(roomid);
	
	if( (strlen(roomid) < 3) || (strlen(roomid) > 10 ) ) {
		write("�Բ����㷿�ݵĴ��ű����� 3 �� 10 ��Ӣ����ĸ��\n");
		return 0;
	}
	while(i--)
	{
		if(((roomid[i] < 'A') || (roomid[i] > 'Z')) &&
		   ((roomid[i] < 'a') || (roomid[i] > 'z')))
		{
			write("�Բ����㷿�ݵĴ��ű�����Ӣ����ĸ��\n");
			return 0;
		}
	}
	return 1;
}

// �ж��û�����ķ��������Ƿ����
// ��������򷵻��Ǹ��������Ͷ�Ӧ��mapping��ָ��
mixed check_legal_type(string type)
{
	int i;
	for (i = 0; i < sizeof(room_example); i++)
	{
		if (room_example[i]["type"] == type ||
		    room_example[i]["name"] == type )
		return room_example[i];
	}
	return;
}

// ���һ�����ݶ���
object get_object(string file_name)
{
	object ob;

	if (! file_name || file_name == "")
		return 0;

	if (! (ob = find_object(file_name)))
		ob = load_object(file_name);

	return ob;
}

// ��¼�û�����ĳһ�䷿�����Ϣ
int record_desc(object me, string room_name, string desc)
{
	mapping filesp;
	mapping descsp;

	int i;
	object ob;
	string *names;

	if (! (desc = obey_description(desc))) return 0;

	filesp = me->query_temp("contract/luban/room/files");
	descsp = me->query_temp("contract/luban/descs");

	names = keys(filesp);
	for (i = 0; i < sizeof(names); i++)
	{
		// ���Ҹ÷��ݵ�object
		ob = get_object(filesp[names[i]]);
		if (ob->query("short") == room_name || names[i] == room_name)
		{
			// �����û������������Ϣ
			if (! desc || desc =="")
			{
				write("��û����������" + room_name + "����Ϣ����ʹ��ϵͳȱʡ��������Ϣ��\n");
				write("ȱʡ��������Ϣ���£�\n" + sort_desc(ob->query("default_long")));
				map_delete(descsp, names[i]);
			} else
			{
				descsp[names[i]] = desc;
				write("��������" + ob->query("short") + "��\n");
			}
			return 1;
		}
	}
	write("û���ҵ�" + room_name + "�����֤������������Ϣ��\n");
	return 0;
}

// �����û�����Ľ�����Ϣ
void record_contract(object me)
{
	string id;
	mapping descp;

	id = me->query("id");
	if (! mapp(query("form"))) delete("form");

	set_form(id, "player", me->query("name"));
	set_form(id, "name", me->query_temp("contract/luban/name"));
	set_form(id, "id", me->query_temp("contract/luban/id"));
	set_form(id, "room", me->query_temp("contract/luban/room/name"));
	set_form(id, "type", me->query_temp("contract/luban/room/type"));
	set_form(id, "position", me->query_temp("contract/luban/position"));
	set_form(id, "value", me->query_temp("contract/luban/value"));
	set_form(id, "time", time());
	set_form(id, "status", "����");
	set_form(id, "wizard", "��");
	set_form(id, "memo", "��");

	descp = me->query_temp("contract/luban/descs");

	set_form(id, "descs", descp);
	save();
}

// �ı��������ĳһ�䷿�����Ϣ
// �޸ĵ������Ǵ����form�е�
int modify_desc_in_form(string player_id, string room_name, string desc)
{
	mapping example;
	mapping filesp;
	mapping descsp;

	int i;
	object ob;
	string *names;

	if (! (desc = obey_description(desc))) return 0;

	if (! (example = check_legal_type(query_form(player_id, "type"))))
	{
		write("���ַ��ݵ������Ѿ��������ˣ�����û�иı䷿�ݵ������������ʦ��ϵ��\n");
		return 1;
	}

	filesp = example["files"];
	descsp = query_form(player_id, "descs");
	names = keys(filesp);

	for (i = 0; i < sizeof(names); i++)
	{
		// ���Ҹ÷��ݵ�object
		ob = get_object(filesp[names[i]]);
		if (ob->query("short") == room_name || names[i] == room_name)
		{
			// �����û������������Ϣ
			if (! desc || desc =="")
			{
				write("��û����������" + room_name + "����Ϣ����ʹ��ϵͳȱʡ��������Ϣ��\n");
				write("ȱʡ��������Ϣ���£�\n" + sort_desc(ob->query("default_long")));
				map_delete(descsp, names[i]);
			} else
			{
				descsp[names[i]] = desc;
				write("������������" + ob->query("short") + "��\n");
			}
			return 1;
		}		
	}
	write("û���ҵ�" + room_name + "������û���޸�������Ϣ�����֤���޸�������Ϣ��\n");
	return 0;
}

// ��һ���������ַ������滯
string obey_description(string desc)
{
	if (strlen(desc) > 330)
	{
		luban_say("�������Ҳ̫���˰�...\n");
		return 0;
	}

	if (! desc || desc == "") return "";

	desc = replace_string(desc, "\"", "'");
	desc = replace_string(desc, "\\n", "\n");
	desc = replace_string(desc, "\t", "");
	desc = replace_string(desc, " ", "");

	desc = replace_string(desc, "$BLK$", BLK);
	desc = replace_string(desc, "$RED$", RED);
	desc = replace_string(desc, "$GRN$", GRN);
	desc = replace_string(desc, "$YEL$", YEL);
	desc = replace_string(desc, "$BLU$", BLU);
	desc = replace_string(desc, "$MAG$", MAG);
	desc = replace_string(desc, "$CYN$", CYN);
	desc = replace_string(desc, "$WHT$", WHT);
	desc = replace_string(desc, "$HIR$", HIR);
	desc = replace_string(desc, "$HIG$", HIG);
	desc = replace_string(desc, "$HIY$", HIY);
	desc = replace_string(desc, "$HIB$", HIB);
	desc = replace_string(desc, "$HIM$", HIM);
	desc = replace_string(desc, "$HIC$", HIC);
	desc = replace_string(desc, "$HIW$", HIW);
	desc = replace_string(desc, "$NOR$", NOR);

	desc = desc + NOR;

	return desc;
}

// �г���
// ��ʦʹ��
int do_list(string arg)
{
	if (! exist_form()) return 1;

	if (! arg || arg == "" || arg == "all" || arg == "ȫ��" || arg == "����")
	{
		show_apply();
		show_agree();
		show_reject();
		show_old();
		return 1;
	}

	switch (arg) {
	case "apply":
	case "����":
	case "new":
		show_apply();
		return 1;

	case "agree":
	case "ͬ��":
	case "��׼":
		show_agree();
		return 1;

	case "reject":
	case "���":
	case "����׼":
	case "û��׼":
		show_reject();
		return 1;

	case "old":
	case "��":
		show_old();
		return 1;
	}

	write("list��ʹ��˵����\nlist all   : ��ʾ���еı���\nlist apply : ��ʾ����ı���\n" +
              "list agree : ��ʾ��ʦ�Ѿ���׼�ı���\nlist reject : ��ʾ��ʦ�Ѿ�����ı���\n" +
	      "list old   : ��ʾ���ںܾõı���\n\n");
	return 1;
}

// ��ʾ������ϸ��Ϣ
// ��ʽ��type player_id room_name ��ʾ��player������ĳ�䷿��
//   ��type player_id           ��ʾ��player����������
// ��ʱ�������������������룬Ҳ���Բ쿴
int do_type(string arg)
{
	string player_id;
	string room_name;
//	int a;

	if (! wizardp(this_player()) || wiz_level(this_player()) < WIZLEVEL)
	{
		write("����Ȩ�쿴���е�������Ϣ��\n");
		return 1;
	}
	if (!arg||arg=="")
		return notify_fail("type player_id room_name\n");
	if (sscanf(arg, "%s %s", player_id, room_name) != 2)
	{
		player_id = arg;
		room_name = "";
	}

	show_desc(player_id, room_name);
	return 1;
}

// ��ʾһ������ļ�Ҫ˵��
void show_brief(string player_id)
{
	mapping form;
	string msg;
	string wizard;
	string memo;
//	int i;

	form = query("form/" + player_id);
	if (! form || ! mapp(form)) return;

	// ������ID    ����������  ����ʱ��    ��  ��  ״̬  ע�����ʦ  ��   ע
        // 10         .10        . 10        . 6      .4    .10         .16
	msg = sprintf("%10s  %10s  %10s  %6s", player_id, form["player"], ctime(form["time"])[0..9], form["type"]);

	// ��ʵ����״̬
	switch (form["status"]) {
	case "����" :
		msg += HIW;
		break;

	case "ͬ��" :
		msg += HIY;
		break;

	case "�ܾ�" :
		msg += HIR;
		break;
	}
	msg += "  " + form["status"] + NOR + "  ";

	wizard = form["wizard"];
	memo = form["memo"];

	if (! stringp(wizard) || wizard == "��" || wizard == "")
		wizard = "----------";

	if (! stringp(memo) || memo == "��" || memo == "")
		memo = "------";

	msg += sprintf("%10s  %s\n", wizard, memo);
	write(msg);
	return;
}

// �жϱ��Ƿ���ڣ��������Ƿ����ʸ���ñ�
int exist_form()
{
	if (! mapp(query("form")) || sizeof(query("form")) < 1)
	{
		write("���ڲ�û���κα���\n");
		return 0;
	}
	if (! wizardp(this_player()) || wiz_level(this_player()) < WIZLEVEL)
	{
		write("����Ȩ�������\n");
		return 0;
	}
	return 1;
}

// ��׼��
// ��ʦʹ��
int do_agree(string arg)
{
	if (! exist_form()) return 1;

	if (! arg || arg == "" || ! query("form/" + arg))
		return notify_fail("��Ҫ����˭�ı���\n");

	
	if (query("form/" + arg + "/status") == "ͬ��")
	{
		write("�Ѿ���������ʦ��׼�˱��ˡ�\n");
		return 1;
	}
	set("form/" + arg + "/status", "ͬ��");
	set("form/" + arg + "/wizard", this_player()->query("name"));
	set("form/" + arg + "/memo", "��");
	write("����׼��" + query("form/" + arg + "/player") + "(" + arg + ")�����롣\n");
	save();

	return 1;
}

// �ܾ���
// ��ʦʹ��
int do_reject(string arg)
{
	string player;
	string memo;

	if (! exist_form()) return 1;

	if (! arg || arg == "")
		return notify_fail("��Ҫ����˭�ı���\n");

	if (sscanf(arg, "%s %s", player, memo) != 2)
	{
		player = arg;
		memo = "��";
	}

	if (! query("form/" + player))
		return notify_fail("��Ҫ����˭�ı���\n");

	if (memo == "��")
	{
		write("�������ӱ�ע��Ϣ(reject player ��ע��Ϣ)��˵���ܾ������ɡ�\n");
	}

	set("form/" + player + "/status", "�ܾ�");
	set("form/" + player + "/wizard", this_player()->query("name"));
	set("form/" + player + "/memo", memo);

	write("���Ѿ��ܾ���" + query("form/" + player + "/player") + "(" + player + ")�����롣\n");
	save();

	return 1;
}

// ɾ����
// ��ʦʹ��
int do_delete(string arg)
{
	if (! exist_form()) return 1;

	if (! arg || arg == "" || (! query("form/" + arg) && arg != "old"))
		return notify_fail("��Ҫ����˭�ı���\n");

	if (query("form/" + arg + "/status") == "����")
	{
		return notify_fail("�㲻��ɾ��һ�������û�д���ı���\n");
	}

	write("" + query("form/" + arg + "/player") + "(" + arg + ")�ύ�ı���ɾ���ˡ�\n");
	delete("form/" + arg);
	save();

	return 1;
}

// ��ʾ�ո�����ı�
void show_apply()
{
	show_brief_list("����", HIW + "����������ύ������ı�" + NOR);
}

// ��ʾ����׼�ı�
void show_agree()
{
	show_brief_list("ͬ��", HIY + "��������ʦ�Ѿ���׼����ı�" + NOR);
}

// ��ʾ���ܾ��ı�
void show_reject()
{
	show_brief_list("�ܾ�", HIR + "�����Ǳ���ʦ�ܾ�����ı�" + NOR);
}

// ��ʾ�Ƚϳ¾ɵı� - ����15��ı�
void show_old()
{
	int i;
	int count;

	string *ids;

	if (! exist_form()) return;

	count = 0;
	ids = keys(query("form"));
	for (i = 0; i < sizeof(ids); i++)
	{
		if (query("form/" + ids[i] + "/time") - time() > 86400 * 15)
		{
			// ����15��ı�
			if (! count)
			{
				write(YEL "-------------------------------------------------------------------------------\n" NOR);
				write(HIC "����������ύ�˺ܾõı���\n" + NOR);
				show_brief_title();
			}
			count++;
			show_brief(ids[i]);
		}
	}
	if (count)
	{
		write("����" + ((string) count) + "�űȽϳ¾ɵı���\n");
	}
}

// ��ʾ�б�
// info����ʾ�ı������� - infoΪ�ձ�ʾ��ʾ���б�
// msg����ʾ���б������ - �硰������ʦ��׼�ı���
void show_brief_list(string info, string msg)
{
	int i;
	int count;

	string *ids;

	if (! exist_form()) return;

	count = 0;
	ids = keys(query("form"));
	for (i = 0; i < sizeof(ids); i++)
	{
		if (info == "" || query("form/" + ids[i] + "/status") == info)
		{
			if (! count)
			{
				write(YEL "-------------------------------------------------------------------------------\n" NOR);
				write(msg + "\n");
				show_brief_title();
			}
			count++;
			show_brief(ids[i]);
		}
	}
	if (count)
	{
		write("����" + ((string) count) + "�ű���\n");
	}
}

// ��ʾ�б���ͷ
void show_brief_title()
{
	write("�����ߴ���  ����������  �����ʱ��  ��  ��  ״̬  ע�����ʦ  ��   ע\n");
}

// ����һ�������췿��
void create_room(object me)
{
	mapping filesp;		// �����ԭ�ͷ����ļ�mapping
	mapping descsp;		// �����д������mapping

	string player_id;	// ���ҷ������ҵ�ID
	string room_type;	// ��������
	string room_name;	// ��������
	string room_id;		// ����ID
	string room_owner;	// ���ݵ�����
	string room_key;	// ���ݵ�Կ��
	string position;	// ���췿�ݵĵص�(·����)
	string position_short;	// ���췿�ݵĵص����������
	string entry;		// ���ݵ����

	string *content;	// Դ�ļ�������
	string *names;		// filesp�Ĺؼ��ּ���
	string filename;	// ���ɵ��ļ�����
	string dstfile;		// ���ɵ��ļ�����

	string desc;		// ĳ�䷿�ݵ�����::Կ�׵�����
	object ob;		// ���ݵ�object

	int i;
	int k;
	string ids;		// ��ݲ�ѯ�ַ���

	me = this_player();
	if (! objectp(me)) return;

	player_id = me->query("id");
	entry = "";

	if (! mapp(query("form/" + player_id)))
	{
		// û���ҵ�����ύ�ı�
		return;
	}

	// �ڱ����и�����ύ�ı�
	ids = "form/" + player_id + "/";
	room_type = query(ids + "type");
	for (i = 0; i < sizeof(room_example); i++)
	{
		if (room_example[i]["type"] == room_type)
		{
			filesp = room_example[i]["files"];
			break;
		}
	}

	if (! mapp(filesp))
	{
		write("������ķ�������(" + room_type + ")�Ѿ��������ˣ������ʦ��ϵ��\n");
		return;
	}

	descsp = query(ids + "descs");
	room_type = query(ids + "room");
	room_name = query(ids + "name");
	room_id = query(ids + "id");
	position = query(ids + "position");
	names = keys(filesp);

	room_owner = query(ids + "player");
	room_key = "key of " + player_id;

	ob = get_object(position);
	if (! objectp(ob))
	{
		write ("�㽨���ĵص��Ѿ��������ˣ������ʦ��ϵ��\n");
		return ;
	}
	position_short = ob->query("short");
	message("vision", HIY "³�������֣�˵���������ǣ��������ˣ�׬�������ӵ�ʱ���ˣ�����\n" NOR +
		       YEL "��ʱ���ذ�����ֻ������ǰģģ������ʲôҲ�����������Ȼ��֪��������ʲô���顣\n" NOR, environment(this_object()));

	// ���벢�������е��ļ�
	for (i = 0; i < sizeof(names); i++)
	{
		// long_flag ��Ϊ�˽�ԭ�ͷ��ļ��г�����@LONG��LONG֮����ַ���ȥ����ʹ�õı�־��
		int long_flag;
		// enter_receive ��Ϊ����������Ŀ���ʹ�õ�
		int enter_receive;

		if (file_size(filesp[names[i]]) <= 0)
		{
			write("ȱ���ļ�:" + filesp[names[i]] + "���������ɷ��ݣ������ʦ��ϵ��\n");
			// ɾ���Ѿ��������ļ�
			for (k = i - 1; k >= 0; k--)
				rm(to_player(player_id, filesp[names[k]]));
			return;
		}
		content = explode(read_file(filesp[names[i]]), "\n");
		long_flag = 0;
		enter_receive = 0;
		filename = to_player(player_id, filesp[names[i]]);
		dstfile = "// File(" + to_player(player_id, filesp[names[i]]) + ")" + 
			  " of " + player_id + "'s room\n// Create by LUBAN which written by Doing Lu\n";
		for (k = 0; k < sizeof(content); k++)
		{
			if (strsrch(content[k], "LONG") != -1)	// �鵽��һ��LONG��־
			{
				long_flag = ! long_flag;
				if (! long_flag)
				{
					// ����µ�long����
					desc = descsp[names[i]];
					if (! desc || desc == "")
					{
						// ������ȱʡ����
						ob=get_object(filesp[names[i]]);
						desc = ob->query("default_long");
					}
					desc = replace_string(desc, "ROOM_POSITION", position_short);
					desc = sort_desc(desc);
					dstfile += "\tset (\"long\", @LONG\n" + desc + "LONG\n";
				}
				continue;
			}
			// �����LONG���������
			if (long_flag) continue;

			// ����þ������/**/�����
			if (strsrch(content[k], "/**/") != -1) continue;

			// ȥ������е�//**
			content[k] = replace_string(content[k], "//**", "");

			// ����þ���//��ͷ����ʾע�ͣ������
			if (content[k][0..1] == "//") continue;			

			// �жϸ��ļ��Ƿ�������ļ��������ļ��Ƿ��е�������(position)�ĳ���
			if (strsrch(content[k], "/d/room/xiaoyuan") != -1)
				entry = filename;

			// �滻����е�ROOM_KEY, OWNER, position
			content[k] = replace_string(content[k], "ROOM_KEY", room_key);
			content[k] = replace_string(content[k], "ROOM_OWNER", room_owner);
			content[k] = replace_string(content[k], "ROOM_NAME", room_name);
			content[k] = replace_string(content[k], "ROOM_ID", room_id);
			content[k] = replace_string(content[k], "ROOM_POSITION", position_short);
			content[k] = replace_string(content[k], "/d/room/xiaoyuan", position);

			// ��Ӹ����
			if (content[k] == "")
				enter_receive ++;
			else 
				enter_receive = 0;
			if (enter_receive > 1) continue;
		
			dstfile += content[k] + "\n";
		}
		if (long_flag)
		{
			write("�ļ�:" + filesp[names[i]] + "��ʽ����LONG��ƥ�䣬�������ɷ��ݣ������ʦ��ϵ��\n");
			// ɾ���Ѿ��������ļ�
			for (k = i - 1; k >= 0; k--)
				rm(to_player(player_id, filesp[names[k]]));
			return;
		}

		// д�����
		seteuid(getuid());
		rm(filename);
		assure_file(filename);
		write_file(filename, dstfile);
		dstfile = "";
	}

	// �ڽ����������ڵ���ҵķ���
	if (! entry || entry == "")
	{
		message("vision", "\n����һ�ᣬ³����ڵ����������ĵĸ��˻�����\n³�������˵�����ǹ��£���Ȼ�Ҳ�����ڣ���ȥ������ʦ��������ô��ģ�\n", environment(this_object()));
		// ɾ���Ѿ��������ļ�
		for (k = i - 1; k >= 0; k--)
			rm(to_player(player_id, filesp[names[k]]));
		return;
	}

	ob = get_object(position);
    if (ob->create_room(room_name, entry))
	{
		message("vision", "\n����һ�ᣬ³����ڵ����������ĵĸ��˻�����\n³��һ��ù����������˵����а���ˣ������Ȼ���и�����һ���ķ��ӣ�������Ǳ��˱��˻�����\n���̵�ͷ���ҹ�������һǧ���껹��ͷ�����������£�\n", environment(this_object()));
		// ɾ���Ѿ��������ļ�
		for (k = i - 1; k >= 0; k--)
			rm(to_player(player_id, filesp[names[k]]));
		return;
	}
	message("vision", "\n������³����ڵ�����Ȼ������\n³��ϲ�����Ǻǣ����ݽ����ˣ�һ��˳������ϲ��ϲ��\n", environment(this_object()));
//	ob->set("exits/enter", entry );        //�޸�û�д���������ڵ�bug   ɽèAdx
	ob->save();

	// ������ҷ��ݵ�Կ���ļ�
	filename = "/data/room/" + player_id + "/key.c";
	dstfile = "// File(" + filename + ")" + 
		  " of " + player_id + "'s key\n// Create by LUBAN which written by Doing Lu\n";
	dstfile += @KEY

inherit ITEM;
#include <ansi.h>

string query_autoload() { return "1"; }

void autoload(string param)
{
}


void create()
{
	set_name(YEL "KEY_NAME" NOR, ({"key", "KEY_ID"}));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "KEY_DESCRIPTION��\n");
		set("unit", "��");
		set("no_pawn", 1);
		set("item_make", 1);
		set("value", 1);
	}
}
KEY;
	// �滻Կ�����ƣ�ID������
	desc = "һ����������" + room_name + "(" + room_id + ")��Կ�ס�\n";
	dstfile = replace_string(dstfile, "KEY_DESCRIPTION", desc);
	dstfile = replace_string(dstfile, "KEY_NAME", me->query("name") + "�ҵ�Կ��");
	dstfile = replace_string(dstfile, "KEY_ID", room_key);

	seteuid(getuid());
	rm(filename);
	assure_file(filename);
	write_file(filename, dstfile);

	// ����Կ��
	ob = clone_object(filename);
	message_vision("³���ó�һ��Կ�ף���$N˵��ŵ������Կ�ף��պ��ˣ����Ƕ��˿��Ե�����������һ�ѡ�\n", me);
	ob->move(me);

	// ɾ��³�ദ��¼�ı�
	delete("form/" + player_id);
	save();

	// ������ҵ����ݿ�
	me->set("private_room/build", 1);		// �Ѿ���������
	me->set("private_room/position", position);	// �������ڵ�λ��
	me->set("private_room/entry", entry);		// ������ڴ����ļ�·��				:: �����Ѿ���build����
	me->set("private_room/name", room_name);	// ���ݵ�����
	me->set("private_room/id", room_id);		// ���ݵ�ID
	me->set("private_room/type", room_type);	// ���ݵ�����
	me->save();
	return;
}

// ��ԭ�ͷ����ļ���ת����Ϊ�û����ݵ��ļ���
string to_player(string player_id, string file_name)
{
	string typestr;
	string retstr;

	sscanf(file_name, "/d/room/%s/%s", typestr, retstr);
	return "/data/room/" + player_id + "/" + retstr;
}

// ����Ϊ�˼ӿ������ٶ�ʹ�õĺ꺯��
// �ж��ײ����ַ����Ƿ���ͬ(�ַ���1������ַ���2��)
#define	IS_HEAD(s1,s2)	  (s1[0..strlen(s2) - 1] == s2)
// �ж��ַ����ײ��Ƿ�ΪӢ�ı�����
#define	IS_HEAD_ESIGH(s1) (s1[0] == '.' || s1[0] == '!' || s1[0] == ';' || s1[0] == ',' || s1[0] == ':')
// �ж��ַ����ײ��Ƿ�Ϊ���ı�����
#define	IS_HEAD_CSIGH(s1) (s1[0..1] == "��" || s1[0..1] == "��" || s1[0..1] == "��" || s1[0..1] == "��" || s1[0..1] == "��")
// �ж��ַ����ײ��Ƿ��������ַ�
#define	IS_HEAD_CHN(s1)	  (s1[0] >= 128)

// �淶������Ϣ
// ���������ҪΪ���û������������Ϣ��ӻس�������
string sort_desc(string desc)
{
	string res;
	int len;		// desc��ʣ�೤��
	int curlen;		// res�ĵ�ǰ�г�
	int perline = 70;	// ����г�(����б����ţ����ܻᳬ��)
	int crlen;		// ���з��ĳ���
	int escflag;		// ת�����еĳ���

	res = "\t";
	curlen = 8;		// �¶���ǰ�����񳤶�

	crlen = strlen("\n");
	escflag =0;

	if (! desc || desc =="")
		return 0;

	for (len = strlen(desc);(len + curlen > perline) && len > 0;)
	{
		// ����ַ�
		// �ж��Ƿ�Ϊ����
		while (curlen < perline)
		{
			if (IS_HEAD_CHN(desc))
			{
				res += desc[0..1];
				desc = desc[2..len - 1];
				len -=2;
				curlen += 2;
			} else
			if (desc[0] >= 32)
			{
				res += desc[0..0];
				desc = desc[1..len - 1];
				len --;
				curlen ++;
			} else
			  break;			
		}

		// �ж���һ���ַ��Ƿ�Ϊ��㣬��㲻�ܳ���������
		if (IS_HEAD_CSIGH(desc) && curlen < perline + 2)
		{
			res += desc[0..1];
			desc = desc[2..len - 1];
			len -= 2;
			curlen += 2;
		}

		if (IS_HEAD_ESIGH(desc) && curlen < perline + 2)
		{
			res += desc[0..0];
			desc = desc[1..len - 1];
			len --;
			curlen ++;
		}

		// �������һ�У�����ӻ��з�
		if (curlen >= perline)
		{
			res += "\n";
			curlen = 0;
		}

		// �ж��Ƿ�Ϊ����
		if (IS_HEAD(desc, "\n"))
		{
			if (curlen) res += "\n";	// ����ո��л���
			res += "\t";
			desc = desc[crlen..len - 1];
			len -= crlen;
			curlen = 8;
		}

		// ɨ��desc������ת���ַ�
		if (desc[0] == 27)
			while (desc[escflag] != 'm') escflag++;

		if (escflag > 0)
		{
			// ��ɫ���Ƴ���
			res += desc[0.. escflag];
			desc = desc[escflag + 1..len - 1];
			len -= escflag + 1;
			continue;
		}
	}

	// ������β�Ļ��з�
	if (len >= crlen && desc[len - crlen..len - 1] != "\n" ) desc += "\n";

	res += desc;
	return res;
}
