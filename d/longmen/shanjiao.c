inherit ROOM;

void create()
{
      set("short","ɽ��");
      set("long",@LONG
���Ѿ�����������ʯ�ߵ�ɽ���£�������ȥ��ֻ��ɽ�屻����һƬ����
֮�У�ɷ�Ǻÿ��������Ѿ�����Ѫ���ɵ�������Χ�ˣ������ɼ�Ѫ���ɵĵ�
����Ѳ�ߣ�����ɽ�ɡ�
LONG);
            set("valid_startroom",1);
      set("exits",([ /* sizeof() == 1 */
          "northup"  : __DIR__"shanlu1",
           "west"  : __DIR__"guanka1",
      ]));
      set("outdoors", "����");
//    set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}

