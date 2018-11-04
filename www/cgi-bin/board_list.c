// board_list.c
#include <mudlib.h>
#define BOARD_LIST_HTML "/www/html/boardlist.htm"
inherit F_CLEAN_UP;

private mapping vaild_boards = ([
//	board_id : {board_name,allow post}
	"wiz_b"	: ({"���ŷ�����",0}),
	"guangming_b"  : ({"�͵����԰�",1}),
	"towiz_b"   : ({"��ҽ������԰�",1}),
]);

string gateway() {
	int i;
	string str1,str, *list;
	
	str1=read_file(BOARD_LIST_HTML);
	list = keys(vaild_boards);
	sort_array(list,1);
	str="";
	for( i=0;i<sizeof(list);i++) {
		str +=	sprintf(
				"<tr><td><center><a href=board_read?%s&0&9999>%s</td></a></center>"
				"<td><center>%s</td>",
				list[i],
				vaild_boards[list[i]][0],
				vaild_boards[list[i]][1]==1?"��д":"ֻ��"
				);
	}
	str1=replace_string(str1,"$CHINESE_MUD_NAME",CHINESE_MUD_NAME);
	str1=replace_string(str1,"$LIST_INSERT",str);
	return str1;
}

mapping query_boards() {
	return vaild_boards;
}
