// Item card.c
// Created by Zeus 1999.3.28
// Modified by Zeus 1999.3.28
// 
// 

inherit ITEM;

void create()
{
        set_name("�¼�������", ({"wenjiacard"}));
             if( clonep() ) set_default_object(__FILE__);
        else {
        set("long",
               "���ǡ����ֺ��¼ҡ������������˵����ƣ����˴��ƿ������¼���������ͨ�С�\n");
        set("unit", "��");
        set("weight", 10);
        }
}
