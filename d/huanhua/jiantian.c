//jian tian dong
//by mulan

#include <ansi.h>
inherit ROOM;
int do_ba(string arg);
int do_find(string arg);
int do_get(string arg);
int do_open(string arg);

void create ()
{
        set ("short", "���춴");
        set ("long", @LONG
���춴Ҳ�����������ã��ڲ���ɨ��һ����Ⱦ������������ڸ���
�а��˽�ȥ�ĵط���������һ������������������ǰ�����ǵƻ𣬹���
�ݼ���������ƣ�̳ǰ����һ�ѽ�����������������ƣ��������񣬿���
�Ǻ��������Ҳ������佻�����ʬ��ͣ��֮����������ʯ���ڣ�ͣ������
�ั��ľ(coffin)���ǹװ����ְ���һЩ�¾ɵ�����(yueqi)��
LONG);

        set("exits", 
        ([
                "east" : __DIR__"jiashan",
        ]));
	set("count",1);

        set("item_desc",([
                "coffin" : "ȴ�����и��ײ��ر�󣬹������ε�Ļ���(wen)Ҳ�ر�				    ��ϸ, ������·���ء�\n",
		"wen" : "ԭ���ײ������̵ģ������������ر�������������м�����				 �ֵ����ɡ�\n",
		"yueqi" : "���ǲ��÷Ͼõ�������������Щ��������(zou)�ɡ�����\n"
        ]));

        setup();
}

void init()
{
        add_action("do_ba", "qu");
	add_action("do_find","find");
	add_action("do_open","open");
	add_action("do_get","na");
}

int do_get(string arg)
{
	object obj,me = this_player();
	
	if(!arg || arg!="book")
	return notify_fail("��Ҫ��ʲô?\n");
	
	if(me->query_temp("open") < 1)
	return notify_fail("��֪�����Ķ���?\n");
 if (present("wangqing tianshu",this_player()))
    return notify_fail("���Ѿ����ˣ�����!\n");

    obj = new("/d/huanhua/npc/obj/tianshu");
  me->set_temp("open",0);
	obj->move(me);
	message("channel:rumor", MAG"��ҥ�ԡ�ĳ�ˣ���ϲ"+this_player()->query("name")+"�ĵ����������顷!\n"NOR, users());
	return 1;
}
	
int do_find(string arg)
{
	object obj;
	object me = this_player();
	
	if(!arg || (arg!="yueqi"))
		return notify_fail("��Ҫ��ʲô����\n");
        if(me->is_busy())
        return notify_fail("�㻹æ����?\n");
    if(random(me->query("kar")) != 10||this_object()->query("count") < 1)
		{
        me->start_busy(1);
		return notify_fail("���ڵ������ң�ȴʲôҲû���ҵ�!\n");
		}
	obj = new("/d/huanhua/npc/obj/yueqi");
	obj->move(me);
	this_object()->set("count",0);
        return notify_fail("���ҵ�һ�ѿ����õ�������!\n");
}

int do_open(string arg)
{
	message_vision("�׸�ͻȻ�򿪣��ڰ��з���һ֧��һ���Ķ���������....\n",this_player());
	message("channel:rumor", HIW"��ҥ�ԡ�ĳ�ˣ�"+this_player()->query("name")+"��ͼ��ȥ���������顷������������!\n"NOR, users());
	this_player()->die();
}
	
int do_ba(string arg)
{
        object obj;
        object me = this_player();

        if (!arg || (arg!="jian" && arg!="sword"))
        return notify_fail("��Ҫ��ʲô��\n");
        if ( !me->query_temp("qu_jian"))
                return notify_fail("��û�еõ����ŵ�����!\n");
      message("channel:rumor", MAG"��ҥ�ԡ���"+this_player()->query("name")+"��"+environment(me)->query("short")+"�õ���"+HIW"����\n"NOR, users());
    obj = new("/d/huanhua/npc/obj/changge");
	me->delete_temp("qu_jian");
        obj->move(me);
        return 1;
}


