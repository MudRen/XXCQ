// paper.c ͼֽ
// Written by Doing Lu 1998/11/17
//   �����������췿��ʱʹ�õģ���Ҵ�³�ദ���������ߣ�Ȼ����������潨���ص�ķ羰��
//   ������30�����ϵ�drawing����������drawing������³��ѧ��
//   ���껭��draw��¼��������ˮƽ��position��¼�������ĵص㡣

inherit ITEM;

void create()
{
        set_name("ͼֽ", ({ "paper" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "paper");
		set("long", "����һ�Ű�ֽ��������������滭Щ������\n");
		set("ͼֽ", 1);			// �����־
		set("position", "");		// �����ĵص�
		set("draw", 0);			// ������ˮƽ -- 0 ��ʾû��
		set("value", 0);
        }
        setup();
}

void init()
{
	add_action("do_draw", "draw");
	add_action("do_draw", "��");
	add_action("do_draw", "�滭");
}

int do_draw()
{
	object me;
	int skl;
	me = this_player();
	if (me->is_busy()) return notify_fail("��������æ��ûʱ��������\n");
	if (me->is_fighting())
	{
		return notify_fail("�ߴ�ܱ�������������ó���\n");
	}
	if (query("draw") > 0)
	{
		message_vision("$N����Ľ���ֽ�ϵĺۼ�������\n", me);
		set("long", "����һ�Ű�ֽ��������������滭Щ������\n");
		set("draw", 0);	
	}
	message("vision", me->query("name") + "�ó�һ֧�ʣ����˿���Χ���������룬��ֽ�ϲ�֪����Щʲô������\n",
		environment(me), ({me}));
	skl = me->query_skill("drawing", 1);
	if (! skl) skl = 1;
	set("draw", skl);	
	set("position", base_name(environment(me)));
	if (skl < 10)
	{
		write("������ʣ�ȴ��֪����ô���֣�ֻ�ú��һ���һЩ������\n");
		set("long", "����һ��ֽ�����滭��һЩ���߰���Ķ�����\n");
		me->start_busy(4);
	} else
	if (skl < 30)
	{
		write("������ʵĻ�����������һ��ͻ����ˡ�\n");
		set("long", "����һ��ֽ����������ŤŤ�Ļ���һЩ���������ϲ�����������ʲô������\n");
		me->start_busy(8);
	} else
	if (skl < 80)
	{
		write("��������������˿����ܵķ羰����ϸ�Ļ������ˣ��ܿ�ͻ����ˡ�\n");
		set("long", "����һ��ֽ�����滭����" + environment(me)->query("short") + "�ķ羰���൱����\n");
		me->start_busy(6);
	} else
	{
		write("������ʣ����������ת�ۼ����ܵķ羰��ԾȻֽ�ϡ�\n");
		set("long", "����һ��ֽ��������" + environment(me)->query("short") + "�ķ羰�����Ǳ��档\n");
		me->start_busy(2);
	}
	return 1;
}