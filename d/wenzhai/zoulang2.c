// zoulang2.c
inherit ROOM;

void create()
{
  set("short","����");
  set("long",@LONG
����һ���ǳ������ĳ��ȣ����Ӻ��������û������̴ľ�Ƴɣ�����
������������ͼ�����������ɣ�����ʤ�ա��ذ岻֪����ʲô����������
�ģ��������������Ϣ����ֻ�е���������ģ��ǳ���������ȶ������
�������ˡ�
LONG );
  set("exits",([
      "east" : __DIR__"neitang",
      "west" : __DIR__"zoulang1",
  ]));
  set("valid_startroom",1);
  set("outdoors","wenzhai");
  setup();
  replace_program(ROOM);
}
