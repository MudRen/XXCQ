// bajiaoye.c �Ž�Ҷ
// mlf���,lks���

#include <ansi.h>

inherit ITEM;
inherit F_AUTOLOAD;

void create()
{
	set_name(HIW"�Ž�Ҷ"NOR,({"bajiaoye"}));
	set_weight(500);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "֧");
                set("long","����һ֧�����İŽ���״�Ķ�����״��ص���\n");
                set("value", 0);
                set("material", "iron");
                set("no_drop","�ⶫ�������뿪�㡣\n");
              }
}
int query_autoload()
{
       if (wizardp(this_player()))
       return 1;
       else return 0;
}
