// Item yaochu.c  
// Modified by Atlus 10.14.1999
// 

inherit ITEM;

void create()
{
        set_name( "δ�������Բ����",({ "tie kuai"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ��δ�������Բ���顣\n");
                set("value", 50);
                set("material", "iron");
        }
}
