//changan city

inherit ROOM;

void create ()
{
        set ("short", "Ê¯°åÂ·");
        set ("long", @LONG
ÕâÊÇÒ»ÌõÊ¯°åÂ·£¬ÓÉÓÚÃ¿ÈÕ¶¼ÓĞÎŞÊıµÄÈËÔÚÕâÀï×ß¹ı£¬Ê¯°åÒÑ±»Ä¥µÄ
·Ç³£µÄ¹âÁÁ¡£Â·ÍùÎ÷±±ÃæÓ¦¸ÃÍ¨Ïò¾ÅÇúÀÈ£¬¶øÍù¶«ÃæÏÂÁËÌ¨½×¾ÍÊÇ¿í³¨µÄ
Á·Îä³¡ÁË¡£Õ¾ÔÚÕâÀï¿ÉÒÔ¿´µ½Á·Îä³¡ÉÏµÄä½»¨µÜ×ÓÁ·µÃÈÈ»ğ³¯ÌìµÄÇé¾°¡£¬
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"north" : __DIR__"jqlang_1",
		"east" : __DIR__"moneyroom",
		"southdown" : __DIR__"wuchang1",
	]));

        set("outdoors", "xiao");
        setup();
	replace_program(ROOM);
}