// Room:ѩ��ʯ
// Write by phoenix 1999.12.5

inherit ROOM;
void create()
{
        set("short", "ѩ��ʯ");
        set("long", @LONG
������һ��ʯͷ(stone)��˵�Կ���ٵ������ʹ���,�����кܶ���ֵ�����
LONG
);
        set("exits", ([
                "down" : __DIR__"kys",
        ]));
        setup();
}
void init()
{
        int i=NATURE_D->night();
	if(i) {
	add_action("do_xue", "xuexi");}
}
int do_xue(string arg)
{
        object me=this_player();

        if(!arg||arg=="")
        return notify_fail("��Ҫ��ʲô��\n");

        if(me->query_skill("literate",1)<181)
        return notify_fail("��Ķ���д�ֻ��������޷�����ʯ���������֣�\n");

        if(me->query("combat_exp")<360000)
        return notify_fail("��ʵս����̫��,�޷�����ʯͷ�����̵����֡�\n");

        if(me->query("jingli")<50)
        return notify_fail("������̫����,ЪЪ����ѧʯͷ���������ְɣ�\n");

        if(arg=="stone")
        {
	message_vision("$N��ϸ��Ħʯͷ���������֣����к�Ȼ���ʣ��Լ���ѧ�����н���һ����\n",me);
        me->improve_skill("literate",me->query("int")); 
        me->add("jingli",-40);
	return 1;
        }
}
