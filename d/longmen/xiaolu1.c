inherit ROOM;

void create()
{
      set("short","ɽ��С·");
      set("long",@LONG
�����Ѿ�����ɽ��������ɽ����ʪ�Ŀ���ʹ��·��ǳ�ʪ�������˶���
���Ų����������������Զ������������ԼԼ���Կ���һ����ɽ����������
֮�У�����̫���ˡ���޲��������ܿ�������®ɽ����Ŀ��
LONG);
           set("valid_startroom",1);
      set("exits",([ /* sizeof() == 1 */
          "north"  : __DIR__"sexit",
          "east"  : __DIR__"xiaolu2",
      ]));
      set("outdoors", "����");
//    set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}

