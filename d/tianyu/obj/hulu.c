// hulu.c 

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("��ˮ��«", ({"qingshui hulu", "hulu", "bottle"}));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ���ú�«�Ƴɵ�ˮ����\n");
                set("unit", "��");
                set("value", 100);
                set("max_liquid", 15);
        }
       
        set("liquid", ([
                "type": "water",
                "name": "��ˮ",
                "remaining": 15,
                "drunk_supply": 15,
        ]));
}
