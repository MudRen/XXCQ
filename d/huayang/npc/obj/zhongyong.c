// laozi16.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name( WHT"��ӹ"NOR, ({ "book", "shu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","�ӳ���Ի������ƫ֮ν�У�����֮νӹ�������ߣ�����֮������ӹ�ߣ�����֮����
����ƪ�˿��Ŵ����ķ�����˼����ö���Ҳ���ʱ�֮��飬�������ӡ�����ʼ��һ
����ɢΪ���£�ĩ����Ϊһ����֮���������ϣ���֮�����˲���ܡ���ζ����
����ʵѧҲ���ƶ��ߣ��������е��ɣ���������֮���в��ܾ����ӡ�\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"confu",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jingli_cost":  15, 	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	50,	// the maximum level you can learn
		]) );
	}
}