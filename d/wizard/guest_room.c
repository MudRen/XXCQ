// /d/wizard/guest_room.c

inherit ROOM;

void create()
{
	set("short", "��ʦ�����");
	set("long", @LONG
��������ʦ����ҽ����ĵط����������ʲô������Ҫ����ʦ��
�̣���������������(post)�������������ǣ�浽���ջ����Ѿ��ڰ�
���ļ�������ϸ˵������ʦ�ǾͲ�һ����ش�¥������ʦ��Ϣ�ң�
һ����ҵ��������ϲ�ȥ�ˡ�
LONG
	);

          set("no_fight",1);
	set("exits", ([
		"down" : "/d/bianliang/guangming",
		"up" : __DIR__"exitroom",
	]));

	setup();
	call_other("/clone/board/towiz_b", "???");
}

int valid_leave(object me, string dir)
{
         if( dir=="up" && !wizardp(me) )
                return notify_fail("����ֻ����ʦ���ܽ�ȥ��\n");
        return ::valid_leave(me, dir);
}

