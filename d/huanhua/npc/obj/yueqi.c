#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;
void init()
{
        add_action("do_zou","zou");
}

void create()
{
        set_name("�ƾ�����", ({ "yue qi", "qi" }) );
        set_weight(4500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("no_give","����������ܸ���");
        set("no_pawn","����������ܵ�");
        set("no_get","����������ܼ�����");
        set("value", 0);
        set("material", "wood");
        set("long", "����һ�Ѳ��õ��ƾ�������\n");

        }
        setup();
}

int do_zou(string arg)
{
    object me;
    me = this_player();
    if( !arg || arg !="wen")
	return notify_fail("�㲻�����ҵ��ٰ�!\n");
    if( me->query_skill("force",1) < 150 && me->query("max_neili") < 2000)
	return notify_fail("����ڹ�����������̫���ˣ�����������˵�����!\n");
    message_vision(HIY "\n$N��������·�����׵�����Ȼ��ø��ã�������ʱ���ǹ׸Ǳ���������������!\n"NOR, me);
    message_vision(HIW "\nԭ�������������Ǹ��һ������(book)!\n"NOR,me);
   message_vision(HIG "\n��ϸ������һ���Ǻö������ܲ����õó�ȥ!\n"NOR,me);
    me->set_temp("open",1);	
    me->start_busy(2);	
     destruct(this_object());
        return 1;
}
	
