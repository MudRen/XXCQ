inherit ROOM;

void create()
{
      set("short","ɽ·");
      set("long",@LONG
�����ڵ�ɽ��·���ϣ�·�����Ҹ���һ����������������������ɽ��ɽ
��������ȥ����������ֲ����ƣ�������ȥ���������֣���֪����·ͨ���
����������ɣ�
LONG);
            set("valid_startroom",1);
      set("exits",([ /* sizeof() == 1 */
          "northup"  : __DIR__"shanlu3",
          "southdown"  : __DIR__"shanlu1",
      ]));
      set("outdoors", "����");
//    set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}

