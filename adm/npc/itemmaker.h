// ���������� itemmaker.c 
// Written by Doing Lu    1998/11/2

#define	ITEM_DIR	"/d/item/make/"

// ���ɵ����ĵ�, ��Ҫһ���ĵ��ߴ������� item_temp (object is ITEM_DIR/origin.c)
// �����Ժ��� ITEM_DIR/???.c Ȼ��ɾ���ɵ� item_temp, ����һ���µĵ��ߣ������ļ���

// ����item_temp�������Ե�˵��
// ------ �û���������������
// name			���ߵ����ƣ� ����Ҫ
// id			���ߵ�ID��   ����Ҫ
// long			���ߵ�������ϵͳ�������ɵ���ʱ�Զ���ӹ�������ԭ�ϵ�����
// wield_msg		װ�����������������û��ϵͳ���Զ�����
// unwield_msg		�ջ�����ʱ������
// wear_msg		���ϻ���ʱ������
// unwear_msg		�ѵ�����ʱ������

// ------ �����û�����������
// owner		������
// material1		ԭ��1
// material2		ԭ��2������û��
// unit			��λ��ϵͳ�Զ�����
// point		���ߵ��˺���/������
// item_type		���ߵ����� weapon �� armor
// type			���ߵ���� weapon Ϊ sword, blade, whip, stick �� armor Ϊ armor
// ctype		���ߵ����������� weapon Ϊ ���������ޡ��� �� armor Ϊ ����
// weigth		���ߵ�����
// value		���ߵļ�ֵ

// ------ ˵�����û������ĵ��ߵ�����
// item_make		1

int save_item_file(string filename, string content);

string create_file(object item_temp)
{
	string	buf;			// �����ļ��Ļ�����
	string	filename;
	int	i;

	// �����ļ���
	for (i = 0; i < 100; i++)
	{		
		filename = ITEM_DIR + item_temp->query("ownerid") + 
			   sprintf("%d.c", random(8999) + 1000);
		if (file_size(filename) <= 0) break;
	}
	if (i >= 100)
	{
		write("�޷����ɵ�������֪ͨ��ʦ����\n");
		return 0;
	}
	buf = "// ITEM Made by player " + filename + 
	      "\n// Written by ITEMMAKER(Doing Lu 1998/11/2)\t" + ctime(time()) + "\n";
	if (item_temp->query("item_type") == "weapon")
	{
		// �������������ļ�
		string desc;		// ����������
		if (item_temp->query("material2") == "")
		{
			desc = "������" + item_temp->query("material1") + "���ƶ��ɵ�һ" +
				item_temp->query("unit") + item_temp->query("ctype") + "��\\n";
		} else
		{
			desc = "������" + item_temp->query("material1") + "����" + 
				item_temp->query("material2") + "���ƶ��ɵ�һ" +
				item_temp->query("unit") + item_temp->query("ctype") + "\\n";
		}
		desc += item_temp->query("ctype") + "���Ͽ���һ��С�֣�" +
		        item_temp->query("owner") + "(" + item_temp->query("ownerid") + ")\\n";
		// �Զ��������Ϣ
		if (item_temp->query("wield_msg") == "")
		{
			item_temp->set("wield_msg", "$Nһ����Х������һ" +
					item_temp->query("unit") + item_temp->query("item/name") + "��");
		}
		if (item_temp->query("unwield_msg") == "")
		{
			item_temp->set("unwield_msg", "$N����һĨ��������" +
					item_temp->query("item/name") + "��");
		}
		buf += "#include <ansi.h>\n\n";
		buf += "#include <weapon.h>\n\n";
		buf += "inherit " + item_temp->query("inherit") + ";\n\n";
		buf += @ITEMCODE
string query_autoload() { return "1"; }

void autoload(string param)
{
}

void create()
{
ITEMCODE;		
		buf += sprintf("\tset_name(\"%s\", ({ \"%s\" }));\n", 
				item_temp->query("item/name"), item_temp->query("item/id"));
		buf += sprintf("\tset_weight(%d);\n", item_temp->query_weight());
		buf += @ITEMCODE
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("item_make", 1);
ITEMCODE;
		buf += sprintf("\t\tset(\"unit\", \"%s\");\n", item_temp->query("unit"));
		buf += sprintf("\t\tset(\"long\", \"%s\\n\");\n", desc + item_temp->query("long"));
		buf += sprintf("\t\tset(\"value\", %d);\n", item_temp->query("value"));
		buf += sprintf("\t\tset(\"materail\", \"%s\");\n", item_temp->query("material1"));
		buf += sprintf("\t\tset(\"wield_msg\", \"%s\\n\");\n", item_temp->query("wield_msg"));
		buf += sprintf("\t\tset(\"unwield_msg\", \"%s\\n\");\n", item_temp->query("unwield_msg"));
		buf += sprintf("\t}\n");
		buf += sprintf("\tinit_%s(%d);\n", item_temp->query("type"), item_temp->query("point"));
		buf += sprintf("\tsetup();\n");
		buf += sprintf("}\n");
	} else
	{
		// ���ɷ��������ļ�
		string desc;		// ���ߵ�����
		if (item_temp->query("material2") == "")
		{
			desc = "������" + item_temp->query("material1") + "���ƶ��ɵ�һ" +
				item_temp->query("unit") + item_temp->query("ctype") + "��\\n";
		} else
		{
			desc = "������" + item_temp->query("material1") + "����" + 
				item_temp->query("material2") + "���ƶ��ɵ�һ" +
				item_temp->query("unit") + item_temp->query("ctype") + "\\n";
		}
		desc += item_temp->query("ctype") + "�Ͽ���һ��С�֣�" +
		        item_temp->query("owner") + "(" + item_temp->query("ownerid") + ")\\n";
		// �Զ��������Ϣ
		if (item_temp->query("wear_msg") == "")
		{
			item_temp->set("wear_msg", YEL "$N����һ�ӣ�������" +
					item_temp->query("item/name") + YEL "��" NOR);
		}
		if (item_temp->query("remove_msg") == "")
		{
			item_temp->set("remove_msg", YEL "$N��΢һ����������" +
					item_temp->query("item/name") + YEL "��" NOR);
		}
		buf += "#include <armor.h>\n\n";
		buf += "inherit " + item_temp->query("inherit") + ";\n\n";
		buf += @ITEMCODE
string query_autoload() { return "1"; }

void autoload(string param)
{
}

void create()
{
ITEMCODE;		
		buf += sprintf("\tset_name(\"%s\", ({ \"%s\" }));\n", 
				item_temp->query("item/name"), item_temp->query("item/id"));
		buf += sprintf("\tset_weight(%d);\n", item_temp->query_weight());
		buf += @ITEMCODE
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("item_make", 1);
		set("item_file_name", __FILE__);
ITEMCODE;
		buf += sprintf("\t\tset(\"unit\", \"%s\");\n", item_temp->query("unit"));
		buf += sprintf("\t\tset(\"long\", \"%s\\n\");\n", desc + item_temp->query("long"));
		buf += sprintf("\t\tset(\"value\", %d);\n", item_temp->query("value"));
		buf += sprintf("\t\tset(\"materail\", \"%s\");\n", item_temp->query("material1"));
		buf += sprintf("\t\tset(\"wear_msg\", \"%s\\n\");\n", item_temp->query("wear_msg"));
		buf += sprintf("\t\tset(\"remove_msg\", \"%s\\n\");\n", item_temp->query("remove_msg"));
		buf += sprintf("\t\tset(\"armor_prop/armor\", %d);\n", item_temp->query("point"));
		buf += sprintf("\t}\n");
		buf += sprintf("\tsetup();\n");
		buf += sprintf("}\n");
	}	
	if (save_item_file(filename, buf) == 1)
	{
		return filename;
	}
	return "";
}

// filename ��д���ĵ������ƣ��Ѿ�������·��
// content ��д���ĵ�������
int save_item_file(string filename, string content)
{
	rm(filename);
	write(content);
	if ( write_file(filename, content) )
	{
		write("�ɹ����������ĵ���\n");
		return 1;
	} else
	{
		write("д�뵵��(" + filename + ")ʱ������֪ͨ��ʦ����\n");
		return 0;
	}
}

