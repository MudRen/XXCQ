//changan city

inherit ROOM;
int do_da(string);

void create ()
{
        set ("short", "���䳡");
        set ("long", @LONG
����һ�����������䳡�����䳡����������ں���䤱������Ź���
�ڳ��ӵ��������ĸ������ӣ�ÿ�����涼���ź���һ�ǧ��ֽ��������
��Χ������һȭһȭ�Ĵ�(da zhi)�ţ���ҪԸ��Ҳ���Լ��롣�����䳡��
������һ��С�ݣ����ǽ�®�ı���������Ҳ���Խ�ȥ��һ���ʺϵı�����
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"west" : __DIR__"wuchang1",
		"south" : __DIR__"wuqiku",
	]));

        set("outdoors", "xiao");

        setup();
}

void init()
{
	add_action("do_da", "da");
}

int do_da(string arg)
{
	object me;
       int a,b,my_skill;

	me = this_player();

	if ( !arg || ( arg != "zhi" ) )
                return notify_fail("�����ʲô��Ҫ��ʹ�ǧ��ֽ(zhi)�ɡ�\n");

	a = random(20)+20;
	b = random(20)+20;

        if((int)me->query("jingli") < a)
	{
                return notify_fail("�����ھ����޷����У����������˰ɣ�\n");
                return 1;
	}
        if((int)me->query("qi") < b)
	{
                return notify_fail("�㶼�������ˣ���ЪЪ�ɣ�\n");
                return 1;
	}
       my_skill=me->query_skill("cuff",1);
       if(my_skill*my_skill*my_skill/10>(int)me->query("combat_exp"))
        {
                 tell_object(me, "���ս�����鲻���޷��������书�ˣ�\n");
         return 1;
       }

        me->add("jingli", -a);
        me->add("qi", -b);

        message_vision("$N���һ�����ںü��ƣ�һȭ����ǧ��ֽ�ϡ�\n", me);

        if ( (int)me->query_skill("cuff", 1) < 101)
        {
                me->improve_skill("cuff", ((me->query("int"))+ random(me->query("int"))));
                tell_object(me, "������������Щ�ۣ�\n���ȭ�������ˣ�\n");
        }
        else
        { 
                tell_object(me, "��һȭ����ǧ��ֽ�����ˣ�����������������ûʲô�����ˡ�\n");
        }
        return 1;
}
