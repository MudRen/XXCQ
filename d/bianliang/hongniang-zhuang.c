// This is a room made by roommaker. 
//��顣
//�Ǿ�ǧʥ 199-12-4 .
inherit ROOM;
void create()
{ 
  set("short", "����ׯ");
  set("long", @LONG
����������صĺ���ׯ�����źܴ�����ã����õĸ����ûʡ�
���������ϵ���������ǰ���Ǵ���ϲ�֡�ǰ�������㰸����
�������¯��¯���������̴�㡣¯�߷���һ�Ժ����㰸ǰ��
��һ�����Ŷ�����ԧ��Ϸˮ��ͼ�����������źܶ��Բ����ż��
��һ����Ѿ�ߴ������߹�ȥ��
LONG
); 
  set("exits", ([ /* sizeof() == 1 */
"south":__DIR__"huangkudajie6",
]));
set("objects", ([ /* sizeof() == 1 */
// "/d/bianliang/npc/hongniang" : 1,
]));
  set("no_fight",1);
  set("no_roar",1);
  set("no_beg",1);
  set("no_steal",1);

  setup();
  replace_program(ROOM); 
}

