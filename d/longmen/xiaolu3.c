inherit ROOM;

void create()
{
      set("short","ɽ��С·");
      set("long",@LONG
�����Ѿ�����ɽ��������ɽ����ʪ�Ŀ���ʹ��·��ǳ�ʪ�������˶���
���Ų����������������Զ������������ԼԼ���Կ���һ����ɽ����������
֮�У�����̫���ˡ�ͻȻ�㷢��ǰ����һ���ؿڡ�ԭ��Ѫ�������ڽ��ϣ���
ֹ������ʿ��ɽ��
LONG);
           set("valid_startroom",1);
      set("exits",([ /* sizeof() == 1 */
          "east"  : __DIR__"guanka",
          "north"  : __DIR__"xiaolu2",
      ]));
           set("objects",([
                    "/kungfu/class/xuehepai/guanshi" : 1,
           ]));
      set("outdoors", "����");
//    set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}

