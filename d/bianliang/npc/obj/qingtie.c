// qingtie.c

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(BOLD HIR"����"NOR, ({ "qing tie","tie" }) );
        set_weight(3);
        set("value", 0);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ�Ųμӻ����õ�������\n
  ����д���� ��������������ھ��ǹ㳡�Ⱥ�����ӭ����Ů��·��
\n" );
                set("unit", "��");
        }
}

