//key.c
inherit ITEM;
void create()
{
       set_name( "����", ({ "bai tie","tie" }));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ�����ֵİ�����\n");
                set("value", 0);
                set("material", "paper");
                set("no_drop","�ⶫ�������뿪�㡣\n");
              }
}
