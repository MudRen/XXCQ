#include <mudlib.h>

void create() { seteuid( getuid() ); }

string gateway(string args) {

    object ob,body;
    string str;
    int online;

    online = 0;

    if( sscanf(args,"id=%s",args) == 0)
        return "������ñ��";

    ob = new(LOGIN_OB);
    ob->set("id", args);

    if( !ob->restore() ) return "û��������"+args+"��\n";

    if( objectp(body = find_player(args)) && geteuid(body)==args ) {
        if( body->query("env/invisibility") < 1 )
            if( !body->is_ghost() )
                online = 1;
    }
    str = "<html><title>��ѯ���</title><body>";

    str += sprintf(
                "<h3 align=center><font face='��Բ' color=#ff0000>%s"
                "<font face='��Բ'color=#000000>��Ҳ�ѯ</font>"
                "</h3><p><hr></p>",
                CHINESE_MUD_NAME
                );

    str += sprintf(
        "<center><TABLE BORDER=5>"
        "<TR><TH>Ӣ�Ĵ��ţ�</TH><TD>%s</TD></TR>"
        "<TR><TH>��    ����</TH><TD>%s</TD></TR>"
        "<TR><TH>Ȩ�޵ȼ���</TH><TD>%s</TD></TR>"
        "<TR><TH>�ϴ����ߣ�</TH><TD>%s</TD></TR>"
        "<TR><TH>�Ƿ����ߣ�</TH><TD>%s</TD></TR>"
        "</TABLE>",
        body->query("id"),
        body->query("name"),
        SECURITY_D->get_status(args),
        ctime(ob->query("last_on")),
        online
? "��" : "��"
        );
    destruct(ob);
    str += "</center></body></html>";
    return str;
}
