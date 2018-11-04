#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW "����㳡" NOR);
        set("long", @LONG
��������Ӣ�۹�ƽ�������ı���㳡��ƽ������ʯ�ذ壬�������Ʈ�
���ܵ�ǽ�Ϲ���ʮ�˰��������������������ȡ�á����µ�Ӣ������Ҫһ��
�ߵͣ������˱��ԡ��й�ƽ��������Ϊ֤��˭Ҳ�޷�Ͷ��ȡ�ɣ����������
Ӣ��������Ϊ������ʿ�����ϡ�
LONG
        );
        set ("exits",([
        "down" : "/d/bianliang/guangchang",
                ]));
        setup();
}

void init()
{
        this_player()->set_temp("biwu",1);
	add_action("do_pick","pick");
}

int valid_leave(object me, string dir)
{
        if( dir=="down" )
		me->delete_temp("biwu");
        return ::valid_leave(me, dir);
}

int do_pick(string arg)
{
        object me, ob, obj;
	me = this_player();
	obj = present("drum", (environment(me)));
	if(!arg)
		return notify_fail ("��Ҫ��ʲô�أ�\n");

	if( arg=="zhujian"
	|| arg=="mudao"
	|| arg=="zhubang"
	|| arg=="baozi"
	|| arg=="cha" ) {

	if(me->is_fighting() || me->is_busy())
		return notify_fail("����æ���أ�\n");

	if( !obj||!obj->query("drum_knocked") )
		return notify_fail("���ڲ��Ǳ����ڼ䣬�����ϵĶ��������ã�\n");

	if (  present(arg, me) )
		return notify_fail("�����ϲ�������\n");

	ob = new(__DIR__"obj/" + arg);
	ob->move(me);
	message_vision(YEL ""+me->query("name")+"�Ӽ���������һ"
		+ob->query("unit")+ob->query("name")+"��\n"NOR, me);
	} else {
		return notify_fail ("��Ҫ��ʲô�أ�\n");
	}
	return 1;
}
