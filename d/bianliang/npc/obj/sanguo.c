// laozi16.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name( WHT"����־"NOR, ({ "sanguozhi", "book", "sanguo","shu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����������������ˮ���˻��Ծ�Ӣ�ۡ��Ƿǳɰ�תͷ�ա�

������ɽ�����ڣ�����Ϧ���졣�����׷����Խ���ϣ���

���������´��硣һ���Ǿ�ϲ��ꡣ�Ž�����£�����

����Ц̸�С�

�����������ġ��ٽ��ɡ�\n");
		set("value", 2000);
		set("material", "paper");
		set("skill", ([
			"name":	"literate",
			"exp_required":	0,
			"jingli_cost":  15,
			"difficulty":	10,
			"max_skill":	55,
			"min_skill":	30,
		]) );
	}
}