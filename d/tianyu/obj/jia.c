// Obj: ������
// Date: by godzilla 1999.11.18

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(YEL"������"NOR, ({ "bingqi jia", "jia" }) );         
        set_weight(30000000);
        if( clonep() )
                set_default_object(__FILE__);
        else{
        set("unit", "��");
        set("long", "����һ��ר�������Ÿ��ֱ����ļ��ӡ�
������ţ�\n
       ���� (changjian)��
       �̽� (duanjian)��
       \n");
         set("number",15);
        set("material","wood");
        set("no_get",1);
        }
        setup();
}
void init()
{
	add_action("do_get",({"get","na"}));
}
int do_get(string arg)
{
	object me,ob;
	string arg1,arg2;
	me=this_player();
	if(!arg || sscanf(arg,"%s from %s", arg1, arg2)!=2)
	return notify_fail("�����ʽ: get <��������> from jia��\n");
	if (arg2!="jia")
	return notify_fail("�����ʽ: get <��������> from jia��\n");
	if(present(arg1, me) || present(arg1, environment()))
	return notify_fail("�Ѿ������������ˡ�\n");
    if(this_object()->query("number")<0)
           return notify_fail("�Ѿ�û���ˡ�\n");
     if(me->query("family/family_name")!="������")
    return notify_fail("�Ѿ�û���ˡ�\n");
	switch (arg1){
          case"changjian": ob=new("/clone/weapon/changjian");
          break;             
          case"duanjian": ob=new("/clone/weapon/duanjian");
          break;   
          default :
          return notify_fail("û�����ֱ�����\n");
          }
        if(ob)
        ob->move(me);
        message_vision("$N��"YEL"������"NOR"���ó�һ��$n��\n",me,ob);  
        this_object()->add("number",-1);
        return 1;
}

