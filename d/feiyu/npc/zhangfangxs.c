// NPC: zhangfangxs.c
// Created by Atlus 1999.7.23
// Modified by atlus 1999.10.15

#include <ansi.h>

inherit NPC;

void greeting(object);
void create()
{
        set_name("�ʷ�����", ({ "xiansheng", "sir"}) );
        set("gender", "����" );
        set("age", 50+random(10));
        set("long",
                "�ʷ������Ѿ���ʮ�����ˣ���˵��ǰ�ƽ�ʿ���ڷ���ɽׯ�����Ѿ���ʮ�����ˣ�����û�г���ʲô���\n");
        set("combat_exp", 30000);
        set("attitude", "friendly");
        set("rank_info/respect", "��ʦ");

        set("qi", 500);
        set("max_qi", 500);
        set("jingli", 500);
        set("max_jingli", 500);

	create_family("������",3 , "����");

        set_skill("literate", 200);

        setup();
}



void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        say("�ʷ���������ͷ�������̣��������˽�����̧��ͷ˵��������λ" + RANK_D->query_respect(ob)
             + "������ʲô����?��\n");
}

