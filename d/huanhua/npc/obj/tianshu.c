//tianshu.c
//by mulan
inherit ITEM;
inherit F_UNIQUE;
#include <ansi.h>; 
void setup()
{}
void init()
{
        add_action("do_du", "du");
        add_action("do_du", "study");
}
void create()
{
        set_name(YEL"���������项"NOR"", ({ "wangqing tianshu","tianshu","book" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "paper");
                set("no_drop", "�������������뿪�㡣\n");
                set("no_get", "�������������뿪�Ƕ���\n");
                set("no_put", "�����������ܷ����Ƕ���\n");
                set("no_pawn", "�����������ܵ���\n");
                set("long",
        "����һ���ñ�ֽд�ɵ��顣���飺���������项��\n"
        "��Ƥ���ƣ������Ѿ�����ܾ��ˡ�\n", );
        }
}

int do_du(string arg)
{
        object me = this_player();
        object where = environment(me);
        int pxlevel; 
        int neili_lost;
	int i;

	if (!(arg=="wangqing tianshu" || arg == "tianshu"))
	return 0;
        if (where->query("pigging")){
                write("�㻹��ר�Ĺ���ɣ�\n");
                return 1;
        }
        if (me->is_busy()) {
                write("��������æ���ء�\n");
                return 1;
        }
        if( me->is_fighting() ) {
                write("���޷���ս����ר�������ж���֪��\n");
                return 1;
        }
        if (!id(arg)) {	
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        if( me->query_skill("literate", 1) < 180 ){
                write("������ֵ���⻹��������ѧ���Ļ�(literate)�ɡ�\n");
                return 1;
        }
        if(me->query_int() < 40){
          write("������Բ���������˸�����ؼ���\n");
          return 1;
        }
        message("vision", me->name() + "��ר�ĵ��ж��������顣\n", environment(me), me);
        if( (int)me->query("jingli") < 100 ) {
                write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
                return 1;
        }
	neili_lost = 5;
        if( (int)me->query("neili") < neili_lost) {
		write("�������������޷�������ô������书��\n");
                return 1;
        }
        pxlevel = me->query_skill("wangqing-jian", 1);
        if( (int)me->query("combat_exp") < (int)pxlevel*pxlevel*pxlevel/10 ) {
                write("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
                return 1;
        }
        if( me->query_skill("force", 1) < 180){
                write("���ж���һ��������Ƿ���������˵����ڹ�̫���ˣ�ȥѧѧforce �ɡ�\n");
                return 1;
        }
        if( me->query_skill("wangqing-jian", 1) > 199){
                write("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");
                return 1;
        }
	i=random(me->query_skill("literate",1)/2);
	if(i>90) i=90;
	if(i<10) i=10;
        me->receive_damage("jingli", (100-i));
	  me->set("neili",(int)me->query("neili")-neili_lost);
        me->improve_skill("wangqing-jian", (int)me->query_skill("literate", 1)/5+1);
        write("���ж��������飬�����еİ��������ĵá�\n");
        return 1;
}

