inherit ROOM;

void create()
{
      set("short","ɽ·");
      set("long",@LONG
�����ڵ�ɽ��·���ϣ�·�����Ҹ���һ����������������������ɽ��ɽ
��������ȥ����������ֲ����ƣ�������ȥ���������֣���֪����·ͨ���
����������һ��С��ֱͨѪ���ɡ�
LONG);
            set("valid_startroom",1);
      set("exits",([ /* sizeof() == 1 */
          "north"  : "/d/longmen/xuehepai/gate",
          "northdown"  : __DIR__"shanlu4",
      ]));
      set("outdoors", "����");
//    set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}

