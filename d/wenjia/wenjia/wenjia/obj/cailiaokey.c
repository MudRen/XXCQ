// Item cailiaokey.c
// Created by Zeus 1999.5.12
// Modified by Zeus 1999.5.12
// 
// 

inherit ITEM;

void create()
{
        set_name("���Ϸ���Կ��", ({"cailiaokey"}));
             if( clonep() ) set_default_object(__FILE__);
        else {
        set("long",
               "����һƬԿ�ס�\n");
        set("unit", "Ƭ");
        set("weight", 10);
        }
}
