// yeziye.c Ҭ��Ҷ
// mlf���,lks���

#include <ansi.h>

inherit ITEM;
inherit F_AUTOLOAD;

void create()
{
	set_name(HIW"Ҭ��Ҷ"NOR,({"yeziye"}));
	set_weight(500);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "֧");
                set("long","����һ֧������Ҭ����״�Ķ��������߳ʳ�״��\n");
                set("value", 0);
                set("material", "iron");
                set("no_drop","�ⶫ�������뿪�㡣\n");
              }
}
	

int query_autoload()
{
       object ob;
	ob=this_player();
	if(objectp(ob)&&userp(ob)){
		if (wizardp(this_player()))
       return 1;
	}
       return 0;
}

