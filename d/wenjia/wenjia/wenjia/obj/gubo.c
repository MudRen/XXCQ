// Item gubo.c
// Created by Zeus 1999.5.11
// Modified by Zeus 1999.5.11
// 
// 

inherit ITEM;

void create()
{
        set_name("����",({"gubo"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ�����࣬Ҳ��֪����ʲô�á�\n");
                set("unit", "��");
                set("value", 1000);
                set("remaining", 5);
        }
	
        setup();
}

