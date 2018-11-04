//Npc ������
//Write by godzilla
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("������", ({ "fang geyin", "fang" }));
        set("long", "������һ�������������� \n");
        set("title", HIW"������"HIY"�����������"NOR);
        set("gender", "����");
        set("age", 20);
        set("attitude","friendly");
        set("str", 40);
        set("dex", 40);
        set("con", 40);
        set("int", 40);
        set("per", 40);
        set("tianyu_1",1);
        set("max_qi", 10000);
        set("max_jingli", 10000);
        set("max_neili", 10000);
        set("max_douzhi",1000);
        set("qi",10000);
        set("jingli",10000);
        set("jiali",400);
        set("douzhi",1000);
        
        set_skill("dodge",300);
        set_skill("finger",300);
        set_skill("parry",300);
        set_skill("blade",180);
         set_skill("yiqiguan-riyue",150);
         set_skill("jieniu-dao",150);
        set_skill("tao",300);
         set_skill("youran-bu",150);
         set_skill("changkong-zhi",150);
        set_skill("strike",300);
        set_skill("force",300);
        set_skill("sword",300);
        set_skill("tianyu-qijian",300);
        set_skill("tianyu-qigong",300);
        set_skill("tianyu-bufa",300);

        set_skill("literate",350);
        map_skill("sword", "tianyu-qijian");
        map_skill("force", "tianyu-qigong");
        map_skill("dodge", "tianyu-bufa");
        map_skill("parry", "tianyu-qijian");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}
void init()
{
        add_action("do_qiecuo","qingjiao");
        add_action("do_skills",({"skills","cha"}));
}
int do_qiecuo(string arg)
{
        object me=this_player(), ob = this_object();
        string special,name;
        int exp,jb;
        if (!arg||sscanf(arg, "%s with %s", arg, name)!=2)
        return notify_fail("�����ʽ:  qingjiao <skills> with <somebody>��\n");
;
        if (!id(name))
        return notify_fail("��Ҫ��˭��̡�\n");
        write(CYN"����"+ob->name()+"��ȭ˵����������"+me->name()+"�����򷽴������һ�¡�" + to_chinese(arg) + "�������ʡ�\n"NOR);
        if (!(special=me->query_skill_mapped(arg)))
        {
                if (arg == to_chinese(arg))
                        write( CYN+ob->name()+"˵������ˡ������������֪��" + arg + "����ʲô�书����������ϡ�\n"CYN);
                else
                        write(CYN+ob->name()+"˵�����������enable���������书�����ܺ����д衣\n"NOR);
                return 1;
        }
        if (me->is_busy() || me->is_fighting())
        {
                write(CYN+ob->name()+"˵��������æ���ء�\n"NOR);
                return 1;
        }
                if( (int)me->query("learned_points") >= (int)me->query("potential") )
        {
        write(CYN+ob->name()+"˵������Ϊ" + RANK_D->query_respect(me) + "���ǳ�ܲ����ˡ�\n"NOR)
       ;return 1;
          }
        if (!me->query_skill(arg,1))
        {
                write(CYN+ob->name()+"˵��������󲻻����ּ��ܡ�\n"NOR);
                return 1;
        }
        if( arg == "force")
        {
                write(CYN+ob->name()+"˵���������ڹ�ֻ���Լ����գ���ô�ܺ����д��أ�\n"NOR);
                return 1;
        }
        exp=me->query("combat_exp");
        jb=me->query_skill("arg",1);
         if ((int)me->query_skill(arg,1)*(int)me->query_skill(arg,1)*(int)me->query_skill(arg,1)/10 > (int)me->query("combat_exp")) 
        {
                write(CYN+ob->name()+"˵������ʵս�����������书�������޷���չ�ˡ�\n"NOR);
                return 1;
        }       
        if((int)me->query("jingli")<100)
        {
                write(CYN+ob->name()+"˵������Ϊ" + RANK_D->query_respect(me) + "����Ϣһ�°ɣ�������Ҫѭ�򽥽������ܼ�����\n"NOR);
                return 1;
        }
        write(CYN+ob->name()+"���˵�ͷ��˵����������аɣ���������ָ�㡣��\n"NOR);
        write(CYN"��ʹ��������ѧ��ʼ��"+ob->name()+"����������\n"NOR);
        write(CYN"������ʹ���Ṧ�������ζ����۲���������\n"NOR);
        write(HIM"���й������"+to_chinese(arg)+"�����������һ�㡣\n"NOR);
                        me->add("learned_points", 1);
        me->add("jingli",-30);
        me->improve_skill(arg, me->query_int()*3);
        return 1;
}
int do_skills(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg!="fang")
        return 0;
        if(wizardp(me))
        return 0;
        if (me->query("family/family_name") != "������" )
        {
                command("shake "+me->query("id"));
                return 1;
        }
        tell_object(me,"������Ŀǰ��ѧ���ļ��ܣ�\n"+
"  �����Ṧ (dodge)                         - ��ɲ� 300/    0\n"+
"  ����ָ�� (finger)                        - ��ɲ� 300/    0\n"+
"  �����ڹ� (force)                         - ��ɲ� 300/    0\n"+
"  �����м� (parry)                         - ��ɲ� 300/    0\n"+
"  һ�������� (yiqiguan-riyue)                    - ��ɲ� 150/    0\n"+
"  ��Ȼ���� (youran-bu)                     - ��ɲ� 150/    0\n"+
"  ������ָ (changkong-zhi)                     - ��ɲ� 200/    0\n"+
"  �������� (blade)                         - ��ɲ� 180/    0\n"+
"  �����Ʒ� (strike)                        - ��ɲ� 300/    0\n"+
"  ��ţ���� (jieniu-dao)                      - ��ɲ� 150/    0\n"+
"  �������� (sword)                         - ��ɲ� 300/    0\n"+
"  �����ķ� (tao)                         - ��ɲ� 300/    0\n"+
"�����𲽷� (tianyu-bufa)                   - ��ɲ� 300/    0\n"+
"�������湦 (tianyu-qigong)                 - ��ɲ� 300/    0\n"+
"�������潣 (tianyu-qijian)                 - ��ɲ� 300/    0\n"
);
        return 1; 
}
int recognize_apprentice(object ob)
{
        if(ob->query("family/family_name")!="������")
        {
                command("say �����ɵ��Ӳ���ѧ�ҹ���\n");
          return 0;
        }
        if(ob->query("combat_exp")<300000)
        {
                 command("say ���ʵս�����������Ҳ��ܴ����㹦��\n");
            return 0;
        }
           return 1;
}               
