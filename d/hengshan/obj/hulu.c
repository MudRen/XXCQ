// hulu.c 

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("���«", ({"da hulu", "hulu", }));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ���ú�«�Ƴɵ�ˮ����\n");
                set("unit", "��");
                set("value", 100);
                set("max_liquid", 55);
        }
       
        set("liquid", ([
                "type": "water",
                "name": "Ȫˮ",
                "remaining": 55,
                "drunk_supply": 55,
        ]));
}

