// miyao.c      ͭ��

inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_zhao", "zhao");
}

string *per_msg_male1 = ({
        CYN "����ΰ��Ӣͦ������֮�䣬��ɷ��\n" NOR,
        CYN "����Ӣΰ������������ȷʵ���������\n" NOR,
});

string *per_msg_male2 = ({
        CYN "Ӣ��������������档\n" NOR,
        CYN "��ò���ڣ���Ŀ���ʡ�\n" NOR,
        CYN "��ò���棬���˷��ס�\n" NOR,
});
string *per_msg_male3 = ({
        CYN "��òƽƽ��ûʲô�ÿ��ġ�\n" NOR,
        CYN "��ò�׶��������⡣\n" NOR,
        CYN "�������ۣ��������硣\n" NOR,
});
string *per_msg_male4 = ({
        CYN "����һ�����Ѳ��ۣ��˾˲�����ģ����\n" NOR,
        CYN "��������ģ�һ���޾���ɵ�ģ���� \n" NOR, 
        CYN "������֣���ͷ������������˽�ı��ҡ� \n" NOR, 
});
string *per_msg_female1 = ({
        CYN "�������ƣ�����ʤѩ����֪�㵹�˶���Ӣ�ۺ��ܡ� \n" NOR,
        CYN "������������Ŀ���飬����һЦ������������Ȼ�Ķ��� \n" NOR,
        CYN "�������֣��������ˣ��������Ҽ������� \n" NOR, 
});
string *per_msg_female2 = ({
        CYN "������������ɫ���������˶��ˡ� \n" NOR,
        CYN "���潿�ݻ���¶������ϸ�������̡� \n" NOR,
        CYN "����κ죬�ۺ��ﲨ������Ͷ��֮�䣬ȷ��һ�����ϡ� \n" NOR,
});
string *per_msg_female3 = ({
        CYN "���㲻�Ͼ������ˣ�Ҳ���м�����ɫ�� \n" NOR,
        CYN "���û��������м�����ɫ��  \n" NOR,
});
string *per_msg_female4 = ({
        CYN "���ñȽ��ѿ��� \n" NOR,
        CYN "���á���������  \n" NOR,
});

string *per_msg_kid1 = ({
        CYN "��ü���ۣ�����ʮ�㡣\n" NOR,
        CYN "������ã���̬�Ƿ���\n" NOR,
        CYN "�������£�ɫ��������\n" NOR,
});

string *per_msg_kid2 = ({
        CYN "¡����ۣ���ɫ����\n" NOR,
        CYN "�����ལ�����ϲ����\n" NOR,
        CYN "ϸƤ���⣬�ڳ�������\n" NOR,
});

string *per_msg_kid3 = ({
        CYN "����󰫣�ɵ��ɵ����\n" NOR,
        CYN "�ʷ����֣�С��С�ۡ�\n" NOR,
        CYN "��ͷ���ԣ����ֱ��š�\n" NOR,
});

string *per_msg_kid4 = ({
        CYN "��ͷ���ţ����Ƽ��ݡ�\n" NOR,
        CYN "����ľ�������в�ɫ��\n" NOR,
        CYN "��ٲ�������֫���ࡣ\n" NOR,
});

void create()
{
	set_name(HIY "ͭ��" NOR, ({"tong jing", "tong", "jing"}));
        set("unit", "��");
        set_weight(500);
	set("long", "����һ�������(zhao jing)������ò��ͭ����\n");
	set("value", 500);
        setup();
}

string per_status_msg(int age, int per, string gender)
{
	// added by snowcat 
	if (age < 16) {
		if ( per>=25 )
			return ( per_msg_kid1[random(sizeof(per_msg_kid1))]);
		else if ( per>=20 )
			return ( per_msg_kid2[random(sizeof(per_msg_kid2))]);
		else if ( per>=15 )
			return ( per_msg_kid3[random(sizeof(per_msg_kid3))]);
		else 	return ( per_msg_kid4[random(sizeof(per_msg_kid4))]);
		}
		
	if ( gender == "����" ) {
		if ( per>=25 )
			return ( per_msg_male1[random(sizeof(per_msg_male1))]);
		else if ( per>=20 )
			return ( per_msg_male2[random(sizeof(per_msg_male2))]);
		else if ( per>=15 )
			return ( per_msg_male3[random(sizeof(per_msg_male3))]);
		else 	return ( per_msg_male4[random(sizeof(per_msg_male4))]);
		}
		
	if ( gender == "Ů��" ) {
		if ( per>=25 )
                        return ( per_msg_female1[random(sizeof(per_msg_female1))]);
                else if ( per>=20 )
                        return ( per_msg_female2[random(sizeof(per_msg_female2))]);
                else if ( per>=15 )
                        return ( per_msg_female3[random(sizeof(per_msg_female3))]);
	    	else	return ( per_msg_female4[random(sizeof(per_msg_female4))]);
                }
	else return "����������ûʲô���\n";
}

int do_zhao(string arg)
{
	object me;
	string ogender, beauty;

	me = this_player();

	ogender = me->query("gender");

	if (!arg || (arg != "tong jing" && arg != "jing")) return notify_fail("������ʲô��\n");

	beauty = per_status_msg((int)me->query("age"), (int)me->query_per(), ogender);

	message_vision("$N����ͭ����ϸ�Ķ����š�\n", me);

	tell_object(me, "ͭ����ϡӳ�������ò����"+beauty);
	
	return 1;
}