//andao2.c		�Ĵ����š��ص�

inherit ROOM;

void create()
{
	set("short","�ص�");
	set("long", @LONG
����,�������һ��,�����ʲô���������Ƶ�
��������,�㲻���뵽���ƺ���ÿ�����䶼��������ɱ��,̫�ֲ���
���ܺ�����Ϣ���������һ���붼����������
LONG);
	set("exits",([
		"north" : __DIR__"andao1",
		"west" : __DIR__"huayuan",
	]));
	setup();
	replace_program(ROOM);
}